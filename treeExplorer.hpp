#ifndef TREEEXPLORER_HPP_
#define TREEEXPLORER_HPP_

// Copyright message

#include "./treeExplorer.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <bits/stdc++.h>

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

struct DoubleNode* createDoubleNode(int iPayload) {
    struct DoubleNode* newNode = (struct DoubleNode*)malloc(sizeof(struct DoubleNode));
    newNode->iPayload = iPayload;
    newNode->ptrNext = nullptr;
    newNode->ptrPrevious = nullptr;
    return newNode;
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

struct Node* buildTree(int iSize)
{
    int* iArray = new int[iSize];
    struct Node * newTree = nullptr;

    cout << "Digite os elementos da árvore:" << endl;
    for (int i = 1; i < iSize+1; i++) {
        cout << "Elemento " << i << ": ";
        cin >> iArray[i]; 
        newTree = insertNode(newTree, iArray[i]);        
        
    }
    return newTree;   

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

    int iLeftHeight = heightTree(ptrRoot->ptrLeft);
    int iRightHeight = heightTree(ptrRoot->ptrRight);

    int iTreeHeight = max(iLeftHeight, iRightHeight) + 1;
    
    return iTreeHeight;
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

//função que percorre a lista pelo trajeto Inorder
//primeiro vemos tudo à esquerda, depois o nó que estamos e depois tudo à direita
void traverseInorder(struct Node* ptrRoot)
{
    if(ptrRoot != nullptr)
    {
        //Função que usa recursao
        traverseInorder(ptrRoot->ptrLeft);
        cout << " " << ptrRoot->iPayload;
        traverseInorder(ptrRoot->ptrRight);
    }
}

//primeiro vemos o nó que estamos, vendo tudo à esquerda e depois tudo à direita
void traversePreOrder(struct Node* ptrStartingNode)
{
    if(ptrStartingNode != nullptr)
    {
        //Função que usa recursão
        //o caso base é o nullptr
        cout << " " << ptrStartingNode->iPayload;
        traversePreOrder(ptrStartingNode->ptrLeft);
        traversePreOrder(ptrStartingNode->ptrRight);
    }
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

//função que diz se a árvore é perfeita
//usa a função de altura e de completa em níveis
//analisa todos os níveis e se todos forem completos retorna que a árvore é perfeita
bool perfectTree(struct Node* ptrRoot)
{
    int iHeight = heightTree(ptrRoot);

    for(int i = 1; i <= iHeight ; i++)
    {
        if(fullLevel(ptrRoot,i) != 1)return false;
    }
    return true;
}

void Breadth_First_Search(struct Node* ptrRoot) {
    if (ptrRoot == nullptr) {
        cout << "Empty Tree" << endl;
        return;
    }

    queue<Node*> qQueue;
    qQueue.push(ptrRoot);

    while (!qQueue.empty()) {
        Node* ptrNode = qQueue.front();
        cout << ptrNode->iPayload << " ";
        qQueue.pop();

        if (ptrNode->ptrLeft != nullptr) qQueue.push(ptrNode->ptrLeft);
        if (ptrNode->ptrRight != nullptr) qQueue.push(ptrNode->ptrRight);
    }
    cout << endl;
}

Node* SearchElement(Node* ptrRoot, int iPayload) {
    if (ptrRoot == nullptr) {
        return nullptr;
    }

    queue<Node*> qQueue;
    qQueue.push(ptrRoot);

    while (!qQueue.empty()) {
        Node* ptrCurrentNode = qQueue.front();
        qQueue.pop();

        if (ptrCurrentNode->iPayload == iPayload) {
            cout << "The memory address is: " << ptrCurrentNode << endl;
            return ptrCurrentNode;
        }

        if (ptrCurrentNode->ptrLeft != nullptr) qQueue.push(ptrCurrentNode->ptrLeft);
        if (ptrCurrentNode->ptrRight != nullptr) qQueue.push(ptrCurrentNode->ptrRight);
    }

    cout << "Element Not found." << endl;
    return nullptr;
}



int sizeTree(struct Node * ptrRoot) {
    if (ptrRoot == nullptr) return 0;

    int iLeftSize = sizeTree(ptrRoot->ptrLeft);
    int iRightSize = sizeTree(ptrRoot->ptrRight);

    int iTreeSize = iLeftSize + iRightSize + 1;

    return iTreeSize;
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
    if (ptrRoot == nullptr) return ptrRoot; 

    if (iData < ptrRoot->iPayload) ptrRoot->ptrLeft = deleteNode(ptrRoot->ptrLeft, iData);
    else if (iData > ptrRoot->iPayload) ptrRoot->ptrRight = deleteNode(ptrRoot->ptrRight, iData);

    else
    {  
        //estamso no nó certo
        struct Node* ptrTemp = nullptr;

        //caso tenha um filho ou nenhum
        
        if (ptrRoot->ptrLeft == nullptr) // Quando o nó deletado só tem filhos à direita ou nenhum filho
        {
            ptrTemp = ptrRoot->ptrRight; // Salvamos os filhos do nó deletado
            free(ptrRoot); // Deletamos o nó
            
            return ptrTemp; // Reconectamos a árvore
        }
        else if (ptrRoot->ptrRight == nullptr) // Quando o nó deletado só tem filhos à esquerda
        {
            ptrTemp = ptrRoot->ptrLeft; // Salvamos os filhos do nó deletado
            free(ptrRoot); // Deletamos o nó
            
            return ptrTemp; // Reconectamos a árvore
        }
        else // Caso o nó tenha dois filhos
        {
            //queremos pegar o cara mais a esquerda da árvore direita
            //é mais fácil sempre deixar a árvore balanceada
            
            //precisamos encontrar o candidato que vai substituir o nó que estamos e queremos apagar
            
            ptrTemp = lesserNode(ptrRoot->ptrRight); //menor elemento maior que eu
            
            //Fica para casa a versão com ponteiros
            ptrRoot->iPayload = ptrTemp->iPayload;
            
            ptrRoot->ptrRight = deleteNode(ptrRoot->ptrRight, ptrTemp->iPayload);
        }
     }

     return ptrRoot;
 }   


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




/*APENAS UM MENU TESTE*/

void buildMenu() {
    int iSize = 60;

    createUpperBound(iSize);
    createMenuItem("Menu Principal", iSize);
    createHLine(iSize);
    createMenuItem("1 - Criar uma BST a partir de um .txt", iSize);
    createMenuItem("2 - Criar uma BST a partir de inputs", iSize);
    createMenuItem("3 - Informar altura da BST", iSize);
    createMenuItem("4 - Informar tamanho da BST", iSize);
    createMenuItem("5 - Inserir um elemento na BST", iSize);
    createMenuItem("6 - Remover um elemento na BST", iSize);
    createMenuItem("7 - Buscar o endereco de memoria um elemento na BST", iSize);
    createLowerBound(iSize);
}

void menu() {
    int choice;
    do {
        buildMenu();
        cin >> choice;
        switch (choice) {
            case 0:
                cout << "Tchau" << endl;
                break;
            case 1:
                cout << "Cadastrando" << endl;
                break;
            case 2:
                cout << "Pesquisando" << endl;
                break;
            case 3:
                cout << "Excluindo" << endl;
                break;
        }
    } while (choice != 0);
}

void printList(struct ListNode* ptrHead) {
    if (ptrHead == nullptr) {
        cout << "Lista vazia." << endl;
        return;
    }

    while (ptrHead != nullptr) {
        cout << ptrHead->iPayload << " ";
        ptrHead = ptrHead->ptrNext;
    }
    cout << endl;
}

void printDoubleList(struct DoubleNode* ptrHead) {
    if(ptrHead == nullptr)
    {
        cout << "Não é possível exibir: lista vazia!" << endl;
        return;
    }
    
    if(ptrHead->ptrPrevious != nullptr)
    {
        cout << "Não é possível exibir: meio da lista!" << endl;
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

    if(*ptrHead == nullptr){
        *ptrHead = newNode;
        return *ptrHead;
    }

    struct ListNode * ptrCurrent = *ptrHead;
    while (ptrCurrent -> ptrNext != nullptr) ptrCurrent = ptrCurrent -> ptrNext;
    
    ptrCurrent -> ptrNext = newNode;

    return *ptrHead;
}

struct DoubleNode * insertDouble(struct DoubleNode ** ptrHead, int iValue) {
    struct DoubleNode* newNode = createDoubleNode(iValue);
    
    if(*ptrHead == nullptr) //newNode é o novo head
    {
        newNode->ptrPrevious = nullptr;
        (*ptrHead) = newNode;
        return *ptrHead;
    }
    
    //chegando no último nó da lista
    struct DoubleNode* ptrTemp = (*ptrHead);
    while(ptrTemp->ptrNext != nullptr) ptrTemp = ptrTemp->ptrNext;
    
    ptrTemp->ptrNext = newNode;
    newNode->ptrPrevious = ptrTemp;


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

//Transformando a arvore em lista duplamente encadeada
struct DoubleNode * treeToDoubleList(struct Node * ptrStartingNode, struct DoubleNode * ptrHead) {
    if(ptrStartingNode != nullptr) {
        insertDouble(&ptrHead, ptrStartingNode->iPayload);

        treeToDoubleList(ptrStartingNode->ptrLeft, ptrHead);
        treeToDoubleList(ptrStartingNode->ptrRight, ptrHead);
    }
    return ptrHead;
}

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
        cout << "Lista vazia." << endl;
        return;
    }

    struct ListNode* sortedHead = nullptr;
    struct ListNode* ptrCurrent = *ptrHead;

    while (ptrCurrent != nullptr) {
        struct ListNode* next = ptrCurrent->ptrNext;

        //Inserindo o current na sorted list
        if (sortedHead == nullptr || ptrCurrent->iPayload < sortedHead->iPayload) {
            ptrCurrent->ptrNext = sortedHead;
            sortedHead = ptrCurrent;
        } else {
            struct ListNode* sortedCurrent = sortedHead;
            while (sortedCurrent->ptrNext->ptrNext != nullptr && ptrCurrent->iPayload > sortedCurrent->ptrNext->iPayload) {
                sortedCurrent = sortedCurrent->ptrNext;
            }
            ptrCurrent->ptrNext = sortedCurrent->ptrNext;
            sortedCurrent->ptrNext = ptrCurrent;
        }

        ptrCurrent = next;
    }

    *ptrHead = sortedHead;

    free(ptrCurrent);
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

//bubblesort com ponteiros
/*
void bubbleSort(struct DoubleNode** head)
{
    struct DoubleNode* current = (*head);
    
    int iLength = 0;
    while ((*head) != nullptr)
    {
        iLength++;
        (*head) = (*head) -> ptrNext;
    }
    
    (*head) = current;
    
    for(int iOuterLoop = 0; iOuterLoop < iLength - 2; iOuterLoop++)
    {
        current = (*head);
        
        for(int iInnerLoop = 0; iInnerLoop < iLength - 2; iInnerLoop++)
        {
            if(comparison(current->iPayload,current->ptrNext->iPayload) == false)
            {
                if(current == (*head)) //pro primeiro nó
                {
                    current->ptrNext->ptrPrevious = nullptr;
                    current->ptrPrevious = current->ptrNext;
                    current->ptrNext->ptrNext->ptrPrevious = current;
                    current->ptrNext = current->ptrNext->ptrNext;
                    current->ptrPrevious->ptrNext = current;
                    (*head) = current->ptrPrevious;
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
            current = current->ptrNext;
        }
    }
}
*/

#endif // TREEEXPLORER_HPP_