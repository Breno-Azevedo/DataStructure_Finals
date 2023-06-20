/**
 * @file main.cpp
 * @authors Breno, Juliana, Sofia
 * @brief 
 *  Aqui é onde o programa é executado.
 * 
 *  Iremos definir o CLI da nossa implementação aqui.
 * @version 0.1
 * @date 2023-06-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <string>
#include "./treeExplorer.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Node * ptrRoot = createNode(10);

    ptrRoot = insertNode(ptrRoot, 5);
    ptrRoot = insertNode(ptrRoot, 15);

    std::cout << "ptrRoot->iPayload: " << ptrRoot->iPayload << std::endl;
    std::cout << "ptrRoot->ptrLeft->iPayload: " << ptrRoot->ptrLeft->iPayload << std::endl;
    std::cout << "ptrRoot->ptrRight->iPayload: " << ptrRoot->ptrRight->iPayload << std::endl;

    const char cList[10] = {4, 5, 3, 2, 6, 7, 8, 1, 9, 10};

    Node * ptrRoot2 = createTree(cList);

    printTree(ptrRoot2);

    std::cout << std::endl;

    printTree(ptrRoot);

    std::cout << std::endl;

    Node * ptrNode = searchNode(ptrRoot2, 10);

    if (ptrNode != nullptr) {
        std::cout << ptrNode->iPayload << std::endl;
    } else {
        std::cout << "Node not found!" << std::endl;
    }

    return 0;
}