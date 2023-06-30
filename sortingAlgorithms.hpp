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
        std::cout << "Lista vazia." << std::endl;
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
            if (ptrAux->iPayload < ptrMin->iPayload)
                ptrMin = ptrAux;
            ptrAux = ptrAux->ptrNext;
        }

        int iTemp = ptrTemp->iPayload;
        ptrTemp->iPayload = ptrMin->iPayload;
        ptrMin->iPayload = iTemp;

        ptrTemp = ptrTemp->ptrNext;

        // Print the list after each iteration
        /*
        std::cout << "Intermediate list: ";
        struct ListNode* ptrCurrent = *ptrHead;
        while (ptrCurrent != nullptr) {
            std::cout << ptrCurrent->iPayload << " ";
            ptrCurrent = ptrCurrent->ptrNext;
        }
        std::cout << std::endl;
        */
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

        // Print the list after each iteration
        /*
        std::cout << "Intermediate list: ";
        struct ListNode* ptrPrint = sortedHead;
        while (ptrPrint != nullptr) {
            std::cout << ptrPrint->iPayload << " ";
            ptrPrint = ptrPrint->ptrNext;
        }
        std::cout << std::endl;
        */
    }
    *ptrHead = sortedHead;
}


struct ListNode* FindNodeByPos(struct ListNode* ptrHead, int position) {
    struct ListNode* ptrNode = ptrHead;
    for (int i = 0; i < position && ptrNode != nullptr; i++) ptrNode = ptrNode->ptrNext;

    return ptrNode;
}

#include <iostream>

void ShellSort(struct ListNode** ptrHead) {
    if (*ptrHead == nullptr || (*ptrHead)->ptrNext == nullptr)
        return;

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

            // Print the list after each iteration
            /*
            cout << "Intermediate list: ";
            struct ListNode* ptrCurrent = *ptrHead;
            while (ptrCurrent != nullptr) {
                cout << ptrCurrent->iPayload << " ";
                ptrCurrent = ptrCurrent->ptrNext;
            }
            cout << endl;
            */
        }
        gap /= 2;
    }
}


//bubblesort com dados
void bubbleSort(struct DoubleNode** head) {
    struct DoubleNode* current = (*head);
    int iLength = 0;
    while ((*head) != nullptr) {
        iLength++;
        (*head) = (*head)->ptrNext;
    }

    (*head) = current;

    for (int iOuterLoop = 0; iOuterLoop < iLength - 1; iOuterLoop++) {
        current = (*head);

        for (int iInnerLoop = 0; iInnerLoop < iLength - 1; iInnerLoop++) {
            if (current->iPayload > current->ptrNext->iPayload) {
                int iTemp = current->iPayload;
                current->iPayload = current->ptrNext->iPayload;
                current->ptrNext->iPayload = iTemp;
            }
            current = current->ptrNext;
        }

        // Print the list after each iteration
        /*
        std::cout << "Intermediate list: ";
        struct DoubleNode* ptrPrint = (*head);
        while (ptrPrint != nullptr) {
            std::cout << ptrPrint->iPayload << " ";
            ptrPrint = ptrPrint->ptrNext;
        }
        std::cout << std::endl;
        */
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
    bubbleSort(&ptrHead);
    cout << "Lista depois do Bubble Sort: " << endl;
    printDoubleList(ptrHead);
}

#endif // SORTINGALGORITHMS_HPP_
