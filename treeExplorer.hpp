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

struct ListNode * createListNode(int iPayload) {
    struct ListNode * newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
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


struct Node * buildTree(int iSize) {
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

bool fullLevel(struct Node * ptrRoot, int iLevel) {
    if (ptrRoot == nullptr)return false;    

    if (iLevel == 1) {
        ptrRoot->ptrLeft != nullptr && ptrRoot-> ptrRight != nullptr;
        return true;
    }

    bool leftSubtree = fullLevel(ptrRoot->ptrLeft, iLevel - 1);
    bool rightSubtree = fullLevel(ptrRoot->ptrRight, iLevel - 1);

    return (leftSubtree && rightSubtree);    
    
}

bool completeTree(struct Node * ptrRoot)
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

bool perfectTree(struct Node * ptrRoot) {
    int iHeight = heightTree(ptrRoot);
    for(int i = 1; i <= iHeight ; i++)
    {
        if(fullLevel(ptrRoot,i) != 1)return false;
    }
    return true;
}


bool queueEmpty(struct Queue * ptrQueue) {
    return ptrQueue->ptrFront == nullptr;
}

void queuePop(struct Queue * ptrQueue) {
    if (ptrQueue == nullptr || queueEmpty(ptrQueue)) return;
    struct QueueNode * ptrTemp = ptrQueue->ptrFront;
    ptrQueue->ptrFront = ptrQueue->ptrFront->ptrNext;
    if (ptrQueue->ptrFront == nullptr) {
        ptrQueue->ptrRear = nullptr;
    }
    delete ptrTemp;
}

void queuePush(struct Queue * ptrQueue, struct Node * ptrNode) {
    if (ptrQueue == nullptr || ptrNode == nullptr) return;
    struct QueueNode * ptrNewNode = new QueueNode;
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

struct Node * queueFront(struct Queue * ptrQueue) {
    if (ptrQueue == nullptr || queueEmpty(ptrQueue)) return nullptr;
    return ptrQueue->ptrFront->ptrNode;
}

void Breadth_First_Search(struct Node * ptrRoot) {
    if (ptrRoot == nullptr) {
        cout << "Empty Tree" << endl;
        return;
    }

    struct Queue queue;
    queue.ptrFront = nullptr;
    queue.ptrRear = nullptr;
    queuePush(&queue, ptrRoot);

    while (!queueEmpty(&queue)) {
        struct Node * ptrCurrentNode = queueFront(&queue);
        std::cout << ptrCurrentNode->iPayload << " ";
        queuePop(&queue);

        if (ptrCurrentNode->ptrLeft != nullptr) {
            queuePush(&queue, ptrCurrentNode->ptrLeft);
        }

        if (ptrCurrentNode->ptrRight != nullptr) {
            queuePush(&queue, ptrCurrentNode->ptrRight);
        }
    }

    cout << endl;
}

void SearchElement(struct Node * ptrRoot, int iPayload) {
    if (ptrRoot == nullptr) {
        return;
    }

    struct Queue queue;
    queue.ptrFront = nullptr;
    queue.ptrRear = nullptr;
    queuePush(&queue, ptrRoot);

    while (!queueEmpty(&queue)) {
        struct Node* ptrCurrentNode = queueFront(&queue);
        queuePop(&queue);

        if (ptrCurrentNode->iPayload == iPayload) {
            cout << "The node's memory address: " << ptrCurrentNode << endl;
            return;
        }

        if (ptrCurrentNode->ptrLeft != nullptr) {
            queuePush(&queue, ptrCurrentNode->ptrLeft);
        }

        if (ptrCurrentNode->ptrRight != nullptr) {
            queuePush(&queue, ptrCurrentNode->ptrRight);
        }
    }

    cout << "Element not found." << endl;
    return;
}


int sizeTree(struct Node * ptrRoot) {
    if (ptrRoot == nullptr) return 0;

    int iLeftSize = sizeTree(ptrRoot->ptrLeft);
    int iRightSize = sizeTree(ptrRoot->ptrRight);

    int iTreeSize = iLeftSize + iRightSize + 1;

    return iTreeSize;
}


struct Node * lesserNode(struct Node * ptrRoot) {
    struct Node* ptrCurrent = ptrRoot;
    
    while(ptrCurrent && ptrCurrent->ptrLeft != nullptr) ptrCurrent = ptrCurrent->ptrLeft;
    
    return ptrCurrent;
}

struct Node * deleteNode(struct Node * ptrRoot, int iData) {
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

void printList(struct ListNode * ptrHead) {
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

struct ListNode * treeToList(struct Node * ptrStartingNode, struct ListNode * ptrHead) {
    if(ptrStartingNode != nullptr) {
        insertList(&ptrHead, ptrStartingNode->iPayload);

        treeToList(ptrStartingNode->ptrLeft, ptrHead);
        treeToList(ptrStartingNode->ptrRight, ptrHead);
    }
    return ptrHead;
}


#endif // TREEEXPLORER_HPP_
