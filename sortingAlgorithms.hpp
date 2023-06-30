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

using namespace std;

void selectionSort(struct ListNode** ptrHead) {
    if (ptrHead == nullptr) {
        cout << "Lista vazia." << endl;
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
        }
        gap /= 2;
    }
}



//Função auxiliar(pra bubble sort) que troca dois nós
void swap(ListNode* a, ListNode* b) {
    int temp = a->iPayload;
    a->iPayload = b->iPayload;
    b->iPayload = temp;
}

// Função de Bubble Sort para linked list
void bubbleSort(ListNode* head) {
    int swapped;
    ListNode* ptr1;
    ListNode* lptr = nullptr;

    // Verifica se a linked list está vazia
    if (head == nullptr)
        return;

    do {
        swapped = 0;
        ptr1 = head;

        // Executa uma passagem do Bubble Sort na linked list
        while (ptr1->ptrNext != lptr) {
            if (ptr1->iPayload > ptr1->ptrNext->iPayload) {
                swap(ptr1, ptr1->ptrNext);
                swapped = 1;
            }
            ptr1 = ptr1->ptrNext;
        }
        lptr = ptr1;
    } while (swapped);
}


void sortGraphRep(ListNode* ptrHead) {
    ListNode* current = ptrHead;

    // Determina o valor máximo na linked list
    int maxVal = 0;
    while (current != nullptr) {
        if (current->iPayload > maxVal)
            maxVal = current->iPayload;
        current = current->ptrNext;
    }

    // Exibe a representação gráfica da linked list para cada valor
    for (int i = maxVal; i > 0; i--) {
        current = ptrHead;
        while (current != nullptr) {
            if (current->iPayload >= i)
                std::cout << "*";
            else
                std::cout << " ";
            current = current->ptrNext;
        }
        std::cout << std::endl;
    }

    // Exibe os números da linked list
    current = ptrHead;
    while (current != nullptr) {
        std::cout <<" "<< current->iPayload << " ";
        current = current->ptrNext;
    }
    std::cout << std::endl;
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
    struct ListNode * ptrHead = nullptr;
    ptrHead = treeToList(ptrRoot, ptrHead);
    cout << "Lista antes do Bubble Sort: " << endl;
    printList(ptrHead);
    bubbleSort(ptrHead);
    cout << "Lista depois do Bubble Sort: " << endl;
    printList(ptrHead);
}

#endif // SORTINGALGORITHMS_HPP_
