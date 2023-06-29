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
    
    //menu();

    
    cout << "\n" << endl;

    struct Node * ptrRoot = createNode(10);
    
    ptrRoot = insertNode(ptrRoot, 5);
    ptrRoot = insertNode(ptrRoot, 15);
    ptrRoot = insertNode(ptrRoot, 1);
    ptrRoot = insertNode(ptrRoot, 8);
    ptrRoot = insertNode(ptrRoot, 12);
    ptrRoot = insertNode(ptrRoot, 17);
    ptrRoot = insertNode(ptrRoot, 18);
    

    Node* sTree = buildTree(3);    
    printTree(sTree);

    /*
    cout << "ptrRoot->iPayload: " << ptrRoot->iPayload << endl;
    cout << "ptrRoot->ptrLeft->iPayload: " << ptrRoot->ptrLeft->iPayload << endl;
    cout << "ptrRoot->ptrRight->iPayload: " << ptrRoot->ptrRight->iPayload << endl;

    const char cList[10] = {4, 5, 3, 2, 6, 7, 8, 1, 9, 10};
    int iLength = sizeof(cList)/sizeof(char);
    struct Node * ptrRoot2 = createTree(cList, iLength);

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

    cout << "Size of tree 3: " << sizeTree(ptrRoot3) << endl;

    ptrRoot = deleteNode(ptrRoot, 1);

    */

    //printTree(ptrRoot);

    cout << endl;
    

    

    return 0;
}