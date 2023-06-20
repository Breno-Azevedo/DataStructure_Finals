#ifndef TREEEXPLORER_HPP_
#define TREEEXPLORER_HPP_

// Copyright message

#include "./treeExplorer.h"
#include <iostream>

Node * createNode(int iPayload) {
    struct Node * ptrNewNode = (struct Node *) malloc(sizeof(struct Node));
    ptrNewNode->iPayload = iPayload;
    ptrNewNode->ptrLeft = nullptr;
    ptrNewNode->ptrRight = nullptr;
    return ptrNewNode;
}

Node * insertNode(struct Node * ptrRoot, int iPayload) {
    if (ptrRoot == nullptr) return createNode(iPayload);

    if (iPayload < ptrRoot->iPayload) {
        ptrRoot->ptrLeft = insertNode(ptrRoot->ptrLeft, iPayload);
    } else {
        ptrRoot->ptrRight = insertNode(ptrRoot->ptrRight, iPayload);
    }
    return ptrRoot;
}

Node * createTree(const char cList[]) {
    struct Node * ptrRoot = nullptr;
    for (int i = 0; i < 10; i++) {
        ptrRoot = insertNode(ptrRoot, cList[i]);
    }
    return ptrRoot;
}

Node * searchNode(struct Node * ptrRoot, int iPayload) {
    if (ptrRoot == nullptr) return nullptr;
    if (ptrRoot->iPayload == iPayload) return ptrRoot;

    if (iPayload < ptrRoot->iPayload) {
        return searchNode(ptrRoot->ptrLeft, iPayload);
    } else {
        return searchNode(ptrRoot->ptrRight, iPayload);
    }

    return nullptr;
}

void printTree(struct Node * ptrRoot) {
    
    if (ptrRoot == nullptr) return;
    printTree(ptrRoot->ptrLeft);
    std::cout << ptrRoot->iPayload << " ";
    printTree(ptrRoot->ptrRight);
}

#endif // TREEEXPLORER_HPP_