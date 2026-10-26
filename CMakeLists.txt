cmake_minimum_required(VERSION 3.16)
project(C_MTY_TC1031_607_2613_A01199495)

set(CMAKE_CXX_STANDARD 20)

add_executable(C_MTY_TC1031_607_2613_A01199495
        Assignments/Act2.2-DoublyLinkedList/DoublyLinkedList.cpp
        Assignments/Act2.5-BST/BST.h
        Assignments/Act2.5-BST/main.cpp
        Assignments/Act2.5-BST/TreeNode.h
)

add_executable(Evidence2
        Evidences/Evidence2/src/main.cpp
)

add_executable(TestStructures
        Evidences/Evidence2/tests/TestStructures.cpp
)

add_executable(Act25BST
        Assignments/Act2.5-BST/main.cpp
)
