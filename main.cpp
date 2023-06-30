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

    //Criando um no
    struct Node * ptrRoot = createNode(10);

    //Inserindo nos na arvore
    
    ptrRoot = insertNode(ptrRoot, 5);
    ptrRoot = insertNode(ptrRoot, 15);
    ptrRoot = insertNode(ptrRoot, 1);
    ptrRoot = insertNode(ptrRoot, 8);
    ptrRoot = insertNode(ptrRoot, 12);
    ptrRoot = insertNode(ptrRoot, 17);
    //ptrRoot = insertNode(ptrRoot, 2);
        

    /*
    cout << "ptrRoot->iPayload: " << ptrRoot->iPayload << endl;
    cout << "ptrRoot->ptrLeft->iPayload: " << ptrRoot->ptrLeft->iPayload << endl;
    cout << "ptrRoot->ptrRight->iPayload: " << ptrRoot->ptrRight->iPayload << endl;

    //Criando a arvore a partir de array
    const char cList[10] = {4, 5, 3, 2, 6, 7, 8, 1, 9, 10};
    int iLength = sizeof(cList)/sizeof(char);
    struct Node * ptrRoot2 = createTree(cList, iLength);

    printTree(ptrRoot2);
    cout << endl;

    //Printando a arvore
    printTree(ptrRoot);
    cout << endl;
    

    //Achando o endereco de um no da arvore
    struct Node * ptrNode = searchNode(ptrRoot2, 10);

    if (ptrNode != nullptr) {
        cout << "O endereço do nó é: " << ptrNode << endl;
    } else {
        cout << "Node not found!" << endl;
    }

    

    //Criando um arvore a partir de .txt
    struct Node * ptrRoot3 = createTreeTxt("test.txt");

    printTree(ptrRoot3);
    cout << endl;

    //Altura da arvore
    cout << "Height of tree 2: " << heightTree(ptrRoot2) << endl;

    //Tamanho da arvore
    cout << "Size of tree 3: " << sizeTree(ptrRoot3) << endl;

    //Removendo um no da arvore
    ptrRoot = deleteNode(ptrRoot, 18);

    printTree(ptrRoot);
    cout << endl;

    */
    

   //criando uma lista encadeada a partir da arvore
    struct ListNode * ptrHead = nullptr;
    
    ptrHead = treeToList(ptrRoot,ptrHead);
    printList(ptrHead);


    struct DoubleNode * ptrHead2 = nullptr;
    
    //ptrHead2 = treeToDoubleList(ptrRoot,ptrHead2);
    //printDoubleList(ptrHead2);
    //buBBleSort(&ptrHead2);
    //printDoubleList(ptrHead2);

    //selectionSort(&ptrHead);
    //printList(ptrHead);

    //insertionSort(&ptrHead);
    //printList(ptrHead);
    

    return 0;
}