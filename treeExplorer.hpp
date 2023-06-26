#ifndef TREEEXPLORER_HPP_
#define TREEEXPLORER_HPP_

// Copyright message

#include "./treeExplorer.h"
#include <iostream>

using namespace std;

struct Node * createNode(int iPayload) {
    struct Node * ptrNewNode = (struct Node *)malloc(sizeof(struct Node));
    ptrNewNode->iPayload = iPayload;
    ptrNewNode->ptrLeft = nullptr;
    ptrNewNode->ptrRight = nullptr;
    return ptrNewNode;
}

struct Node * insertNode(struct Node * ptrRoot, int iPayload) {
    if (ptrRoot == nullptr) return createNode(iPayload);

    if (iPayload < ptrRoot->iPayload) {
        ptrRoot->ptrLeft = insertNode(ptrRoot->ptrLeft, iPayload);
    } else {
        ptrRoot->ptrRight = insertNode(ptrRoot->ptrRight, iPayload);
    }
    return ptrRoot;
}

struct Node * createTree(const char cList[], int iTamanho) {
    struct Node * ptrRoot = nullptr;
    for (int i = 0; i < iTamanho; i++) {
        ptrRoot = insertNode(ptrRoot, cList[i]);
    }
    return ptrRoot;
}

struct Node * createTreeTxt(const char * fileName) {
    struct Node * ptrRoot = nullptr;
    int iNum;
    ifstream inFile;
    
    inFile.open(fileName);
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    
    while (inFile >> iNum) {
        ptrRoot = insertNode(ptrRoot, iNum);
    }
    
    inFile.close();
    
    return ptrRoot;
}

struct Node * searchNode(struct Node * ptrRoot, int iPayload) {
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
    cout << ptrRoot->iPayload << " ";
    printTree(ptrRoot->ptrRight);
}

int heightTree(struct Node * ptrRoot) {
    if (ptrRoot == nullptr) return 0;

    int leftHeight = heightTree(ptrRoot->ptrLeft);
    int rightHeight = heightTree(ptrRoot->ptrRight);

    return max(leftHeight, rightHeight) + 1;
}


#endif // TREEEXPLORER_HPP_