//
// Created by Diego Villanueva Fernandez on 07/10/26.
// Matricula: A01199495
//
template<typename T>

struct DoubleNode {
    T data;
    DoubleNode<T>* next;
    DoubleNode<T>* prev;

    DoubleNode(const T& value)
        : data(value), next(nullptr), prev(nullptr) {}

    DoubleNode(const T& value, DoubleNode<T>* prevNode, DoubleNode<T>* nextNode)
        : data(value), next(nextNode), prev(prevNode) {}
};
#ifndef C_MTY_TC1031_607_2613_A01199495_DOUBLENODE_H
#define C_MTY_TC1031_607_2613_A01199495_DOUBLENODE_H

#endif //C_MTY_TC1031_607_2613_A01199495_DOUBLENODE_H
