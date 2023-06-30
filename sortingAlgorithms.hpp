#ifndef SORTINGALGORITHMS_HPP_
#define SORTINGALGORITHMS_HPP_

/**
 * @file sortingAlgorithms.hpp
 * @author Breno, Juliana e Sofia
 * 
 * @brief Here we define the functions related to sorting algorithms.
 * 
 * @version 0.7
 * @date 2023-06-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "./treeExplorer.h"
#include <iostream>

void selectionSort(struct ListNode** ptrHead) {
    if (ptrHead == nullptr) {
        cout << "Lista vazia." << endl; //não está saindo
        return;
    }

    struct ListNode* ptrTemp = (*ptrHead);
    struct ListNode* auxNode = (*ptrHead);
    struct ListNode* ptrMin = nullptr;
    struct ListNode* ptrAux = nullptr;

    int iLength = 0;
    while (auxNode != nullptr) {
        iLength++;
        auxNode = auxNode->ptrNext;
    }
    free(auxNode);

    for (int iOuterLoop = 0; iOuterLoop < iLength - 1; iOuterLoop++) {
        ptrMin = ptrTemp;
        ptrAux = ptrTemp->ptrNext;

        for (int iInnerLoop = iOuterLoop + 1; iInnerLoop < iLength; iInnerLoop++) {
            if (ptrAux->iPayload < ptrMin->iPayload) ptrMin = ptrAux;
            ptrAux = ptrAux->ptrNext;
        }

        int iTemp = ptrTemp->iPayload;
        ptrTemp->iPayload = ptrMin->iPayload;
        ptrMin->iPayload = iTemp;

        ptrTemp = ptrTemp->ptrNext;
    }

    free(ptrAux);
}

void insertionSort(struct ListNode** ptrHead) {
    if (*ptrHead == nullptr) {
        throw std::runtime_error("Empty list.");
    }

    struct ListNode* sortedHead = nullptr;
    struct ListNode* ptrCurrent = *ptrHead;

    while (ptrCurrent != nullptr) {
        struct ListNode* next = ptrCurrent->ptrNext;

        // Inserting the current node into the sorted list
        if (sortedHead == nullptr || ptrCurrent->iPayload < sortedHead->iPayload) {
            ptrCurrent->ptrNext = sortedHead;
            sortedHead = ptrCurrent;
        } else {
            struct ListNode* sortedCurrent = sortedHead;
            while (sortedCurrent->ptrNext != nullptr && ptrCurrent->iPayload > sortedCurrent->ptrNext->iPayload) {
                sortedCurrent = sortedCurrent->ptrNext;
            }
            ptrCurrent->ptrNext = sortedCurrent->ptrNext;
            sortedCurrent->ptrNext = ptrCurrent;
        }
        ptrCurrent = next;
    }
    *ptrHead = sortedHead;
}

struct ListNode* FindNodeByPos(struct ListNode* ptrHead, int position) {
    struct ListNode* ptrNode = ptrHead;
    for (int i = 0; i < position && ptrNode != nullptr; i++) ptrNode = ptrNode->ptrNext;

    return ptrNode;
}

void ShellSort(struct ListNode** ptrHead) {
    // Empty list or list with only one node
    if (*ptrHead == nullptr || (*ptrHead)->ptrNext == nullptr) return;

    int length = 0;
    struct ListNode* ptrTemp = *ptrHead;

    while (ptrTemp != nullptr) {
        length++;
        ptrTemp = ptrTemp->ptrNext;
    }

    int gap = length / 2;
    while (gap > 0) {
        for (int iOuterLoop = gap; iOuterLoop < length; iOuterLoop++) {
            struct ListNode* ptrNodeI = FindNodeByPos(*ptrHead, iOuterLoop);
            struct ListNode* ptrNodeJ = FindNodeByPos(*ptrHead, iOuterLoop - gap);

            int temp = ptrNodeI->iPayload;
            while (iOuterLoop >= gap && ptrNodeJ->iPayload > temp) {
                ptrNodeI->iPayload = ptrNodeJ->iPayload;
                iOuterLoop -= gap;
                ptrNodeI = FindNodeByPos(*ptrHead, iOuterLoop);
                ptrNodeJ = FindNodeByPos(*ptrHead, iOuterLoop - gap);
            }
            ptrNodeI->iPayload = temp;
        }
        gap /= 2;
    }
}

//bubblesort com dados
void buBBleSort(struct DoubleNode** head)
{
    struct DoubleNode* current = (*head);    
    int iLength = 0;
    while ((*head) != nullptr)
    {
        iLength++;
        (*head) = (*head) -> ptrNext;
    }
    
    (*head) = current;
    
    for(int iOuterLoop = 0; iOuterLoop < iLength - 1; iOuterLoop++)
    {
        current = (*head);
        
        for(int iInnerLoop = 0; iInnerLoop < iLength - 1; iInnerLoop++)
        {
            if(current -> iPayload > current -> ptrNext -> iPayload)
            {
                int iTemp = current->iPayload;
                current->iPayload = current->ptrNext->iPayload;
                current->ptrNext->iPayload = iTemp;
            }
            current = current->ptrNext;
        }
    }
}

//bubblesort com ponteiros

void bubbleSort(struct DoubleNode* head)
{
    struct DoubleNode* current = (head);
    
    int iLength = 0;
    while ((head) != nullptr)
    {
        iLength++;
        (head) = (head) -> ptrNext;
    }
    
    (head) = current;
    
    for(int iOuterLoop = 0; iOuterLoop < iLength - 1; iOuterLoop++)
    {
        current = (head);
        
        for(int iInnerLoop = 0; iInnerLoop < iLength - 1; iInnerLoop++)
        {
            if(current -> iPayload > current -> ptrNext ->iPayload)
            {
                if(current == (head)) //pro primeiro nó
                {
                    current->ptrNext->ptrPrevious = nullptr;
                    current->ptrPrevious = current->ptrNext;
                    current->ptrNext->ptrNext->ptrPrevious = current;
                    current->ptrNext = current->ptrNext->ptrNext;
                    current->ptrPrevious->ptrNext = current;
                    (head) = current->ptrPrevious;
                }
                else if(current->ptrNext->ptrNext == nullptr) //pro penúltimo nó
                {
                    current->ptrNext->ptrPrevious = current->ptrPrevious;
                    current->ptrPrevious->ptrNext = current->ptrNext;
                    current->ptrNext->ptrNext = current;
                    current->ptrPrevious = current->ptrNext;
                    current->ptrNext = nullptr;
                }
                else
                {
                    //pro nó do meio
                    current->ptrNext->ptrPrevious = current->ptrPrevious;
                    current->ptrPrevious->ptrNext = current->ptrNext;
                    current->ptrNext = current->ptrNext->ptrNext;
                    current->ptrNext->ptrPrevious = current;
                    current->ptrPrevious = current->ptrPrevious->ptrNext;
                    current->ptrPrevious->ptrNext = current;
                }
               
            }
            current = current -> ptrNext;
        }
    }
}

void selectionSortMain(struct Node * ptrRoot) {
    struct ListNode * ptrHead = nullptr;
    ptrHead = treeToList(ptrRoot, ptrHead);
    cout << "Lista antes do Selection Sort: " << endl;
    printList(ptrHead);
    selectionSort(&ptrHead);
    cout << "Lista depois do Selection Sort: " << endl;
    printList(ptrHead);
}

void insertionSortMain(struct Node * ptrRoot) {
    struct ListNode * ptrHead = nullptr;
    ptrHead = treeToList(ptrRoot, ptrHead);
    cout << "Lista antes do Insertion Sort: " << endl;
    printList(ptrHead);
    insertionSort(&ptrHead);
    cout << "Lista depois do Insertion Sort: " << endl;
    printList(ptrHead);
}

void shellSortMain(struct Node * ptrRoot) {
    struct ListNode * ptrHead = nullptr;
    ptrHead = treeToList(ptrRoot, ptrHead);
    cout << "Lista antes do Shell Sort: " << endl;
    printList(ptrHead);
    ShellSort(&ptrHead);
    cout << "Lista depois do Shell Sort: " << endl;
    printList(ptrHead);
}

void bubbleSortMain(struct Node * ptrRoot) {
    struct DoubleNode * ptrHead = nullptr;
    ptrHead = treeToDoubleList(ptrRoot, ptrHead);
    cout << "Lista antes do Bubble Sort: " << endl;
    printDoubleList(ptrHead);
    buBBleSort(&ptrHead);
    cout << "Lista depois do Bubble Sort: " << endl;
    printDoubleList(ptrHead);
}

#endif // SORTINGALGORITHMS_HPP_
