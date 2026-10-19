//
// Created by Diego Villanueva Fernandez on 04/10/26.
// Matricula: A01199495
//

#ifndef C_MTY_TC1031_607_2613_A01199495_NODE_H
#define C_MTY_TC1031_607_2613_A01199495_NODE_H

template<typename T>
struct Node {
    T data;
    Node<T>* next;
    Node(const T& value) : data(value), next(nullptr){}
    Node(const T& value, Node<T>* nextNode) : data(value),next(nextNode){}
};
#endif //C_MTY_TC1031_607_2613_A01199495_NODE_H
