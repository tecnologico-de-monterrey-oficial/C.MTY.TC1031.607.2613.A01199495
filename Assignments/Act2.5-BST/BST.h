#ifndef BST_H
#define BST_H

#include "TreeNode.h"
#include <iostream>
#include <queue>
#include <algorithm>

template<typename T>
class BST {
private:
    TreeNode<T>* root;

    void clear(TreeNode<T>* aux) {
        if (aux == nullptr) return;
        clear(aux->left);
        clear(aux->right);
        delete aux;
    }

    void inorder(TreeNode<T>* aux) const {
        if (aux == nullptr) return;
        inorder(aux->left);
        std::cout << aux->data << " ";
        inorder(aux->right);
    }

    void preorder(TreeNode<T>* aux) const {
        if (aux == nullptr) return;
        std::cout << aux->data << " ";
        preorder(aux->left);
        preorder(aux->right);
    }

    void postorder(TreeNode<T>* aux) const {
        if (aux == nullptr) return;
        postorder(aux->left);
        postorder(aux->right);
        std::cout << aux->data << " ";
    }

    int getHeight(TreeNode<T>* aux) const {
        if (aux == nullptr) return 0;
        return 1 + std::max(getHeight(aux->left), getHeight(aux->right));
    }

public:
    BST() : root(nullptr) {}
    ~BST() { clear(root); }
    BST(const BST&) = delete;
    BST& operator=(const BST&) = delete;

    void insert(const T& value) {
        if (root == nullptr) {
            root = new TreeNode<T>(value);
            return;
        }
        TreeNode<T>* aux = root;
        while (true) {
            if (value == aux->data) return;
            if (value < aux->data) {
                if (aux->left == nullptr) {
                    aux->left = new TreeNode<T>(value);
                    return;
                }
                aux = aux->left;
            } else {
                if (aux->right == nullptr) {
                    aux->right = new TreeNode<T>(value);
                    return;
                }
                aux = aux->right;
            }
        }
    }

    bool find(const T& value) const {
        TreeNode<T>* aux = root;
        while (aux != nullptr) {
            if (aux->data == value) return true;
            if (value < aux->data) aux = aux->left;
            else aux = aux->right;
        }
        return false;
    }

    void remove(const T& value) {
        TreeNode<T>* aux = root;
        TreeNode<T>* padre = nullptr;
        while (aux != nullptr && aux->data != value) {
            padre = aux;
            if (value < aux->data) aux = aux->left;
            else aux = aux->right;
        }
        if (aux == nullptr) return;

        if (aux->left != nullptr && aux->right != nullptr) {
            TreeNode<T>* sucesorPadre = aux;
            TreeNode<T>* sucesor = aux->right;
            while (sucesor->left != nullptr) {
                sucesorPadre = sucesor;
                sucesor = sucesor->left;
            }
            aux->data = sucesor->data;
            padre = sucesorPadre;
            aux = sucesor;
        }

        TreeNode<T>* hijo = (aux->left != nullptr) ? aux->left : aux->right;
        if (padre == nullptr) root = hijo;
        else if (padre->left == aux) padre->left = hijo;
        else padre->right = hijo;
        delete aux;
    }

    void print() const { visit(2); }

    void visit(int tipo) const {
        if (root == nullptr) {
            std::cout << "El arbol esta vacio\n";
            return;
        }
        if (tipo == 1) preorder(root);
        else if (tipo == 2) inorder(root);
        else if (tipo == 3) postorder(root);
        else if (tipo == 4) {
            std::queue<TreeNode<T>*> fila;
            fila.push(root);
            while (!fila.empty()) {
                TreeNode<T>* aux = fila.front();
                fila.pop();
                std::cout << aux->data << " ";
                if (aux->left != nullptr) fila.push(aux->left);
                if (aux->right != nullptr) fila.push(aux->right);
            }
        } else {
            std::cout << "Opcion invalida";
        }
        std::cout << "\n";
    }

    int height() const { return getHeight(root); }

    void ancestors(const T& value) const {
        if (!find(value)) {
            std::cout << "No se encontro el valor\n";
            return;
        }
        TreeNode<T>* aux = root;
        while (aux != nullptr && aux->data != value) {
            std::cout << aux->data << " ";
            if (value < aux->data) aux = aux->left;
            else aux = aux->right;
        }
        std::cout << "\n";
    }

    int whatLevelAmI(const T& value) const {
        TreeNode<T>* aux = root;
        int nivel = 1;
        while (aux != nullptr) {
            if (aux->data == value) return nivel;
            if (value < aux->data) aux = aux->left;
            else aux = aux->right;
            nivel++;
        }
        return -1;
    }
};

#endif
