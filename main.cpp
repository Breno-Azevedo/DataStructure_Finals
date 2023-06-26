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
#include <fstream>
#include "./treeExplorer.h"

using namespace std;

int main() {
    
    struct Node * ptrRoot = createNode(10);

    ptrRoot = insertNode(ptrRoot, 5);
    ptrRoot = insertNode(ptrRoot, 15);

    cout << "ptrRoot->iPayload: " << ptrRoot->iPayload << endl;
    cout << "ptrRoot->ptrLeft->iPayload: " << ptrRoot->ptrLeft->iPayload << endl;
    cout << "ptrRoot->ptrRight->iPayload: " << ptrRoot->ptrRight->iPayload << endl;

    const char cList[10] = {4, 5, 3, 2, 6, 7, 8, 1, 9, 10};
    int iTamanho = sizeof(cList)/sizeof(char);
    struct Node * ptrRoot2 = createTree(cList, iTamanho);

    printTree(ptrRoot2);

    cout << endl;

    printTree(ptrRoot);

    cout << endl;

    struct Node * ptrNode = searchNode(ptrRoot2, 10);

    if (ptrNode != nullptr) {
        cout << ptrNode->iPayload << endl;
    } else {
        cout << "Node not found!" << endl;
    }

    struct Node * ptrRoot3 = createTreeTxt("test.txt");

    printTree(ptrRoot3);
    cout << endl;

    cout << "Height of tree 2: " << heightTree(ptrRoot2) << endl;

    return 0;
}