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

void selectionSort(struct ListNode ** ptrHead) {
    if (ptrHead == nullptr) {
        cout << "Lista vazia." << endl;
        return;
    }

    struct ListNode * ptrTemp = (*ptrHead);
    struct ListNode * auxNode = (*ptrHead);
    struct ListNode * ptrMin = nullptr;
    struct ListNode * ptrAux = nullptr;

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


void insertionSort(struct ListNode ** ptrHead) {
    if (*ptrHead == nullptr) {
        throw runtime_error("Empty list.");
    }

    struct ListNode * sortedHead = nullptr;
    struct ListNode * ptrCurrent = *ptrHead;

    while (ptrCurrent != nullptr) {
        struct ListNode * next = ptrCurrent->ptrNext;

        // Inserting the current node into the sorted list
        if (sortedHead == nullptr || ptrCurrent->iPayload < sortedHead->iPayload) {
            ptrCurrent->ptrNext = sortedHead;
            sortedHead = ptrCurrent;
        } else {
            struct ListNode * sortedCurrent = sortedHead;
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


struct ListNode * FindNodeByPos(struct ListNode * ptrHead, int position) {
    struct ListNode * ptrNode = ptrHead;
    for (int i = 0; i < position && ptrNode != nullptr; i++) ptrNode = ptrNode->ptrNext;

    return ptrNode;
}


void ShellSort(struct ListNode ** ptrHead) {
    if (*ptrHead == nullptr || (*ptrHead)->ptrNext == nullptr)
        return;

    int length = 0;
    struct ListNode * ptrTemp = *ptrHead;

    while (ptrTemp != nullptr) {
        length++;
        ptrTemp = ptrTemp->ptrNext;
    }

    int gap = length / 2;
    while (gap > 0) {
        for (int iOuterLoop = gap; iOuterLoop < length; iOuterLoop++) {
            struct ListNode * ptrNodeI = FindNodeByPos(*ptrHead, iOuterLoop);
            struct ListNode * ptrNodeJ = FindNodeByPos(*ptrHead, iOuterLoop - gap);

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
void swap(struct ListNode * a, struct ListNode * b) {
    int temp = a->iPayload;
    a->iPayload = b->iPayload;
    b->iPayload = temp;
}

// Função de Bubble Sort para linked list
void bubbleSort(struct ListNode * ptrHead) {
    int swapped;
    struct ListNode* ptr1;
    struct ListNode* ptrLast = nullptr;

    // Verifica se a linked list está vazia
    if (ptrHead == nullptr)
        return;

    do {
        swapped = 0;
        ptr1 = ptrHead;

        // Executa uma passagem do Bubble Sort na linked list
        while (ptr1->ptrNext != ptrLast) {
            if (ptr1->iPayload > ptr1->ptrNext->iPayload) {
                swap(ptr1, ptr1->ptrNext);
                swapped = 1;
            }
            ptr1 = ptr1->ptrNext;
        }
        ptrLast = ptr1;
    } while (swapped);
}


void sortGraphRep(struct ListNode * ptrHead) {
    struct ListNode * current = ptrHead;

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
                cout << "*";
            else
                cout << " ";
            current = current->ptrNext;
        }
        cout << endl;
    }

    // Exibe os números da linked list
    current = ptrHead;
    while (current != nullptr) {
        cout <<" "<< current->iPayload << " ";
        current = current->ptrNext;
    }
    cout << endl;
}



#endif // SORTINGALGORITHMS_HPP_
