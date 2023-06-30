#ifndef TREEEXPLORER_HPP_
#define TREEEXPLORER_HPP_

/**
 * @file treeExplorer.hpp
 * @author Breno, Juliana e Sofia
 
 * @brief Here we define the functions related to tree explorer in general.
 
 * @version 0.7
 * @date 2023-06-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "./treeExplorer.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;

struct Node * createNode(int iPayload) {
    struct Node * ptrNewNode = (struct Node *)malloc(sizeof(struct Node));
    ptrNewNode->iPayload = iPayload;
    ptrNewNode->ptrLeft = nullptr;
    ptrNewNode->ptrRight = nullptr;
    return ptrNewNode;
}

struct ListNode* createListNode(int iPayload) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->iPayload = iPayload;
    newNode->ptrNext = nullptr;
    return newNode;
}


struct Node * insertNode(struct Node * ptrRoot, int iPayload) {
    struct Node * ptrNode = searchNode(ptrRoot, iPayload);
    if (ptrNode != nullptr) {
        cout << "Invalid input. The node is already on the tree." << endl;
        return ptrRoot;
    }
    free(ptrNode);

    if (ptrRoot == nullptr) return createNode(iPayload);

    if (iPayload < ptrRoot->iPayload) {
        ptrRoot->ptrLeft = insertNode(ptrRoot->ptrLeft, iPayload);
    } else {
        ptrRoot->ptrRight = insertNode(ptrRoot->ptrRight, iPayload);
    }
    return ptrRoot;
}

struct Node * insertNodeMain(struct Node * ptrRoot) {
    int iValue;
    cout << "Type the value to be inserted (int): ";
    cin >> iValue;

    auto start = chrono::high_resolution_clock::now();
    ptrRoot = insertNode(ptrRoot, iValue);
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Resultant tree: " << endl;
    printTree(ptrRoot);
    cout << endl;

    cout << "Execution time: " << duration.count() << endl;

    return ptrRoot;
}

struct Node* buildTree(int iSize) {
    int* iArray = new int[iSize];
    struct Node * newTree = nullptr;

    cout << "Type the elements from the tree (int):" << endl;
    for (int i = 1; i < iSize+1; i++) {
        cout << "Element " << i << ": ";
        cin >> iArray[i]; 
        if(searchNode(newTree, iArray[i])!=0){
            cout << "Invalid Number. Please enter a different number. " << endl;
             i--;
        }
        else newTree = insertNode(newTree, iArray[i]);        
    }
    return newTree;
}

struct Node * buildTreeMain() {
    int iSize;
    cout << "Type the number of nodes (int): ";
    while (!(cin >> iSize) || iSize <= 0) {
        cout << "Invalid input. Please enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }   

    auto start = chrono::high_resolution_clock::now();
    struct Node* ptrRoot2 = buildTree(iSize);
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Resultant tree: " << endl;
    printTree(ptrRoot2);
    cout << endl;

    cout << "Execution time: " << duration.count() << endl;

    return ptrRoot2;
}

struct Node * createTreeTxt(const char * fileName) {
    struct Node * ptrRoot = nullptr;
    int iNum;
    ifstream inFile;
    
    inFile.open(fileName);
    if (!inFile) {
        cout << "Unable to open file.";
        exit(1); // termina com erro
    }
    
    while (inFile >> iNum) {
        ptrRoot = insertNode(ptrRoot, iNum);
    }
    
    inFile.close();
    
    return ptrRoot;
}

struct Node * createTreeTxtMain() {
    string strFile;
    cout << "Type the file name (with .txt ending): ";
    cin >> strFile;
    const char * fileName = strFile.c_str();

    auto start = chrono::high_resolution_clock::now();
    struct Node * ptrRoot1 = createTreeTxt(fileName);
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Resultant tree: " << endl;
    printTree(ptrRoot1);
    cout << endl;

    cout << "Execution time: " << duration.count() << endl;

    return ptrRoot1;
}

struct Node * searchNode(struct Node * ptrRoot, int iPayload) {
    if (ptrRoot == nullptr) return nullptr;
    if (ptrRoot->iPayload == iPayload) return ptrRoot;

    if (iPayload < ptrRoot->iPayload) {
        return searchNode(ptrRoot->ptrLeft, iPayload);
    } else {
        return searchNode(ptrRoot->ptrRight, iPayload);
    }

    cout << "Node not found." << endl;
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

    int iLeftHeight = heightTree(ptrRoot->ptrLeft);
    int iRightHeight = heightTree(ptrRoot->ptrRight);

    int iTreeHeight = max(iLeftHeight, iRightHeight) + 1;
    
    return iTreeHeight;
}

void heightTreeMain(struct Node * ptrRoot) {
    auto start = chrono::high_resolution_clock::now();
    int iHeight = heightTree(ptrRoot);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "The height of tree is: " << iHeight << endl;
    cout << "Execution time: " << duration.count() << endl;
}

//Função auxiliar para dizer se um determinado nível de uma árvore é completo ou não

bool fullLevel(struct Node* ptrRoot, int iLevel) {
    if (ptrRoot == nullptr)return false;
    

    if (iLevel == 1) {
        ptrRoot->ptrLeft != nullptr && ptrRoot-> ptrRight != nullptr;
        return true;
    }

    bool leftSubtree = fullLevel(ptrRoot->ptrLeft, iLevel - 1);
    bool rightSubtree = fullLevel(ptrRoot->ptrRight, iLevel - 1);

    return (leftSubtree && rightSubtree);    
    
}

bool completeTree(struct Node* ptrRoot)
{
    if(ptrRoot == nullptr)return false;
    
    int iHeight = heightTree(ptrRoot);

    if (iHeight == 1) {
        (ptrRoot->ptrLeft != nullptr && ptrRoot-> ptrRight != nullptr) || (ptrRoot->ptrLeft == nullptr && ptrRoot-> ptrRight == nullptr);
        return true;
    }
    bool leftSubtree = completeTree(ptrRoot->ptrLeft);
    bool rightSubtree = completeTree(ptrRoot->ptrRight);   

    return (leftSubtree && rightSubtree); 
    
}

void completeTreeMain(struct Node * ptrRoot) {
    auto start = chrono::high_resolution_clock::now();
    bool is_complete = completeTree(ptrRoot);
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    if(is_complete == true) cout << "The tree is complete." << endl;
    else cout << "The tree is not complete." << endl;

    cout << "Execution time: " << duration.count() << endl;
}

//função que diz se a árvore é perfeita
//usa a função de altura e de completa em níveis
//analisa todos os níveis e se todos forem completos retorna que a árvore é perfeita
bool perfectTree(struct Node* ptrRoot) {
    int iHeight = heightTree(ptrRoot);

    for(int i = 1; i <= iHeight ; i++)
    {
        if(fullLevel(ptrRoot,i) != 1)return false;
    }
    return true;
}

void perfectTreeMain(struct Node * ptrRoot) {
    auto start = chrono::high_resolution_clock::now();
    bool is_perfect = perfectTree(ptrRoot);
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    if(is_perfect == true) cout << "The tree is perfect." << endl;
    else cout << "The tree is not perfect." << endl;

    cout << "Execution time: " << duration.count() << endl;
}

bool queueEmpty(Queue* ptrQueue) {
    return ptrQueue->ptrFront == nullptr;
}

void queuePop(Queue* ptrQueue) {
    if (ptrQueue == nullptr || queueEmpty(ptrQueue)) return;
    QueueNode* ptrTemp = ptrQueue->ptrFront;
    ptrQueue->ptrFront = ptrQueue->ptrFront->ptrNext;
    if (ptrQueue->ptrFront == nullptr) {
        ptrQueue->ptrRear = nullptr;
    }
    delete ptrTemp;
}

void queuePush(Queue* ptrQueue, Node* ptrNode) {
    if (ptrQueue == nullptr || ptrNode == nullptr) return;
    QueueNode* ptrNewNode = new QueueNode;
    ptrNewNode->ptrNode = ptrNode;
    ptrNewNode->ptrNext = nullptr;
    if (queueEmpty(ptrQueue)) {
        ptrQueue->ptrFront = ptrNewNode;
        ptrQueue->ptrRear = ptrNewNode;
    } else {
        ptrQueue->ptrRear->ptrNext = ptrNewNode;
        ptrQueue->ptrRear = ptrNewNode;
    }
}

Node* queueFront(Queue* ptrQueue) {
    if (ptrQueue == nullptr || queueEmpty(ptrQueue)) return nullptr;
    return ptrQueue->ptrFront->ptrNode;
}

void Breadth_First_Search(Node* ptrRoot) {
    if (ptrRoot == nullptr) {
        std::cout << "Empty Tree" << std::endl;
        return;
    }

    Queue queue;
    queue.ptrFront = nullptr;
    queue.ptrRear = nullptr;
    queuePush(&queue, ptrRoot);

    while (!queueEmpty(&queue)) {
        Node* ptrCurrentNode = queueFront(&queue);
        std::cout << ptrCurrentNode->iPayload << " ";
        queuePop(&queue);

        if (ptrCurrentNode->ptrLeft != nullptr) {
            queuePush(&queue, ptrCurrentNode->ptrLeft);
        }

        if (ptrCurrentNode->ptrRight != nullptr) {
            queuePush(&queue, ptrCurrentNode->ptrRight);
        }
    }

    std::cout << std::endl;
}

void BFSMain(struct Node * ptrRoot) {
    cout << "Tree exhibited through the Breadth First Search Algorithm : " << endl;
    auto start = chrono::high_resolution_clock::now();
    Breadth_First_Search(ptrRoot);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Execution time: " << duration.count() << endl;
}

Node* SearchElement(Node* ptrRoot, int iPayload) {
    if (ptrRoot == nullptr) {
        return nullptr;
    }

    Queue queue;
    queue.ptrFront = nullptr;
    queue.ptrRear = nullptr;
    queuePush(&queue, ptrRoot);

    while (!queueEmpty(&queue)) {
        Node* ptrCurrentNode = queueFront(&queue);
        queuePop(&queue);

        if (ptrCurrentNode->iPayload == iPayload) {
            std::cout << "The node's memory address: " << ptrCurrentNode << std::endl;
            return ptrCurrentNode;
        }

        if (ptrCurrentNode->ptrLeft != nullptr) {
            queuePush(&queue, ptrCurrentNode->ptrLeft);
        }

        if (ptrCurrentNode->ptrRight != nullptr) {
            queuePush(&queue, ptrCurrentNode->ptrRight);
        }
    }

    std::cout << "Element not found." << std::endl;
    return nullptr;
}

struct Node * searchElementMain(struct Node * ptrRoot) {
    int iValue;
    cout << "Type the value from the node whose address is to be found (int): ";
    cin >> iValue;

    auto start = chrono::high_resolution_clock::now();
    ptrRoot = SearchElement(ptrRoot, iValue);
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Execution time: " << duration.count() << endl;

    return ptrRoot;
}

int sizeTree(struct Node * ptrRoot) {
    if (ptrRoot == nullptr) return 0;

    int iLeftSize = sizeTree(ptrRoot->ptrLeft);
    int iRightSize = sizeTree(ptrRoot->ptrRight);

    int iTreeSize = iLeftSize + iRightSize + 1;

    return iTreeSize;
}

void sizeTreeMain(struct Node * ptrRoot) {
    auto start = chrono::high_resolution_clock::now();
    int iSize = sizeTree(ptrRoot);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "The size of three is: " << iSize << endl;
    cout << "Execution time: " << duration.count() << endl;
}

struct Node* lesserNode(struct Node* ptrRoot)
{
    /*Vai para a esquerda toda vida e pega o menor elemento*/
    struct Node* ptrCurrent = ptrRoot;
    
    while(ptrCurrent && ptrCurrent->ptrLeft != nullptr) ptrCurrent = ptrCurrent->ptrLeft;
    
    return ptrCurrent;
}

// Função recursiva para deletar nós de árvores binárias de busca
struct Node* deleteNode(struct Node* ptrRoot, int iData)
{
    struct Node * ptrNode = searchNode(ptrRoot, iData);
    if (ptrNode == nullptr) {
        cout << "Invalid input. The node is not on the tree." << endl;
        return ptrRoot;
    }

    if (ptrRoot == nullptr) return ptrRoot; 

    if (iData < ptrRoot->iPayload) ptrRoot->ptrLeft = deleteNode(ptrRoot->ptrLeft, iData);
    else if (iData > ptrRoot->iPayload) ptrRoot->ptrRight = deleteNode(ptrRoot->ptrRight, iData);
    else {  
        struct Node* ptrTemp = nullptr;
        
        if (ptrRoot->ptrLeft == nullptr) {
            ptrTemp = ptrRoot->ptrRight;
            free(ptrRoot);
            
            return ptrTemp;
        } else if (ptrRoot->ptrRight == nullptr) {
            ptrTemp = ptrRoot->ptrLeft;
            free(ptrRoot);
            
            return ptrTemp;
        } else {
            ptrTemp = lesserNode(ptrRoot->ptrRight);
            ptrRoot->iPayload = ptrTemp->iPayload;
            ptrRoot->ptrRight = deleteNode(ptrRoot->ptrRight, ptrTemp->iPayload);
        }
    }
    return ptrRoot;
 }

struct Node * deleteNodeMain(struct Node * ptrRoot) {
    int iValue;
    cout << "Type the value of the node to be removed (int): ";
    cin >> iValue;

    auto start = chrono::high_resolution_clock::now();
    ptrRoot = deleteNode(ptrRoot, iValue);
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Resultant tree: " << endl;
    printTree(ptrRoot);
    cout << endl;

    cout << "Execution time: " << duration.count() << endl;

    return ptrRoot;
}

void printList(struct ListNode* ptrHead) {
    if (ptrHead == nullptr) {
        cout << "Empty List." << endl;
        return;
    }

    while (ptrHead != nullptr) {
        cout << ptrHead->iPayload << " ";
        ptrHead = ptrHead->ptrNext;
    }
    cout << endl;
}

struct ListNode * insertList(struct ListNode ** ptrHead, int iValue) {
    struct ListNode * newNode = createListNode(iValue);

    if(*ptrHead == nullptr) {
        *ptrHead = newNode;
        return *ptrHead;
    }

    struct ListNode * ptrCurrent = *ptrHead;
    while (ptrCurrent -> ptrNext != nullptr) ptrCurrent = ptrCurrent -> ptrNext;
    
    ptrCurrent -> ptrNext = newNode;

    return *ptrHead;
}


//Transformando a arvore em lista encadeada
struct ListNode * treeToList(struct Node * ptrStartingNode, struct ListNode * ptrHead) {
    if(ptrStartingNode != nullptr) {
        insertList(&ptrHead, ptrStartingNode->iPayload);

        treeToList(ptrStartingNode->ptrLeft, ptrHead);
        treeToList(ptrStartingNode->ptrRight, ptrHead);
    }
    return ptrHead;
}



/*FUNÇÕES DO MENU*/
void createUpperBound(int iSize) {
    cout << char(201);
    for(int i = 0; i < iSize; i++) cout << char(205);
    cout << char(187) << endl;
}

void createLowerBound(int iSize) {
    cout << char(200);
    for(int i = 0; i < iSize; i++) cout << char(205);
    cout << char(188) << endl;
}

void createMenuItem(const char cArray[], int iSize) {
    cout << char(186);
    cout << setw(iSize) << left << cArray;
    cout << char(186) << endl;
}

void createHLine(int iSize) {
    cout << char(204);
    for(int i = 0; i < iSize; i++) cout << char(205);
    cout << char(185) << endl;
}

void buildMenu() {
    int iSize = 70;

    createUpperBound(iSize);
    createMenuItem("Menu Principal", iSize);
    createHLine(iSize);
    createMenuItem("Binary Search Tree Explorer - Integer Payload", iSize);
    createMenuItem("1 - Create a BST from a text file (.txt).", iSize);
    createMenuItem("2 - Create a BST from user inputs.", iSize);
    createMenuItem("3 - Inform BST's height.", iSize);
    createMenuItem("4 - Inform BST's size.", iSize);
    createMenuItem("5 - Insert an element in the BST.", iSize);
    createMenuItem("6 - Remove an element from the BST.", iSize);
    createMenuItem("7 - Search a BST element's memory address.", iSize);
    createMenuItem("8 - Inform if the BST is complete.", iSize);
    createMenuItem("9 - Inform if the BST is perfect.", iSize);
    createMenuItem("10 - Exhibit the BST through the Breadth First Search Algorithm.", iSize);
    createMenuItem("11 - Convert the BST to a list and sort it through the Bubble Sort.", iSize);
    createMenuItem("12 - Convert the BST to a list and sort it through the Selection Sort.", iSize);
    createMenuItem("13 - Convert the BST to a list and sort it through the Insertion Sort.", iSize);
    createMenuItem("14 - Convert the BST to a list and sort it through the Shell Sort.", iSize);
    createMenuItem("15 - Graphic representation of the sort.", iSize);
    createMenuItem("0 - Finish program.", iSize);
    createLowerBound(iSize);
}

void menu() {
    int choice;
    struct Node * ptrRoot = nullptr;
    int iHeight;
    int iSize;
    do {
        buildMenu();
        cout << "Type the number of the action wanted (int): ";
        cin >> choice;
        switch (choice) {
            case 0:
                cout << "Program finished." << endl;
                break;
            case 1:
                ptrRoot = createTreeTxtMain();
                break;
            case 2:
                ptrRoot = buildTreeMain();
                break;
            case 3:
                heightTreeMain(ptrRoot);
                break;
            case 4:
                sizeTreeMain(ptrRoot);
                break;
            case 5:
                ptrRoot = insertNodeMain(ptrRoot);
                break;
            case 6:
                ptrRoot = deleteNodeMain(ptrRoot);
                break;
            case 7:
                ptrRoot = searchElementMain(ptrRoot);
                break;
            case 8:
                completeTreeMain(ptrRoot);
                break;
            case 9:
                perfectTreeMain(ptrRoot);
                break;
            case 10:
                BFSMain(ptrRoot);
                break;
            case 11:
                bubbleSortMain(ptrRoot);
                break;
            case 12:
                selectionSortMain(ptrRoot);
                break;
            case 13:
                insertionSortMain(ptrRoot);
                break;
            case 14:
                shellSortMain(ptrRoot);
                break;
            case 15:
                cout << "Aqui vai ter a representação gráfica da árvore." << endl;
                break;
        }
    } while (choice != 0);
}

#endif // TREEEXPLORER_HPP_
