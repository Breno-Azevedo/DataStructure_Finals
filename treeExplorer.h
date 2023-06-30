#ifndef TREEEXPLORER_H
#define TREEEXPLORER_H

// Copyright message...

#include <iostream>

struct Node {
    /**
     * @brief Basic node structure for the tree.
     * 
     * 
     */
    int iPayload;
    struct Node * ptrLeft;
    struct Node * ptrRight;
};

struct ListNode {
    int iPayload;
    struct ListNode * ptrNext;
};

struct DoubleNode{
    int iPayload;
    struct DoubleNode* ptrNext;
    struct DoubleNode* ptrPrevious;
};

/**
 * @brief createNode() - Creates a new node with the given payload.
 * 
 * @param iPayload The payload to be stored in the node.
 * @return struct Node* A pointer to the newly created node.
 */
struct Node * createNode(int iPayload);

struct ListNode* createListNode(int iPayload);

struct DoubleNode* createDoubleNode(int iPayload);

/**
 * @brief insertNode() - Given an existing Node and its iPayload,
 * creates a new node and insert it into the existing one.
 * If the given Node is nullptr, than it creates a brand new one.
 * 
 * @param ptrRoot 
 * @param iPayload 
 * @return struct Node* 
**/
struct Node * insertNode(struct Node * ptrRoot, int iPayload);

/**
 * @brief createTree() - Given a char list, it creates a
 * BFS with the elements of the list.
 * 
 * @param cList 
 * @return Node* 
**/
struct Node * createTree(const char cList[], int iTamanho);

struct Node * createTreeTxt(const char * fileName);

/**
 * @brief searchNode() - Given the root of a tree and an integer,
 * it search through the looking for Node that contains the respective
 * integer and returns it.
 * 
 * @param ptrRoot 
 * @param iPayload 
 * @return Node* 
**/
struct Node * searchNode(struct Node * ptrRoot, int iPayload);

/**
 * @brief printTree() - Prints the elements of the tree
 * 
 * @param ptrRoot 
 */
void printTree(struct Node * ptrRoot);

/**
 * @brief Breadth_First_Search() - Executes the BFS algorithm
 * 
 * @param ptrRoot 
 */
void Breadth_First_Search(struct Node * ptrRoot);

/**
 * @brief searchElement() - Searchs and returns for the memory address
 * of a given element using the BFS algorithm.
 * 
 * @param ptrNode 
 * @param iPayload 
 * @return Node* 
 */
Node * SearchElement(Node* ptrRoot, int iPayload);

int heightTree(struct Node * ptrRoot);

int sizeTree(struct Node * ptrRoot);

struct Node* lesserNode(struct Node* ptrRoot);

/*Função que deleta um nó, trocando dados*/
struct Node* deleteNode(struct Node* ptrRoot, int iData);

struct ListNode * treeToList(struct Node * ptrStartingNode, struct ListNode * ptrHead);
void printList(struct ListNode* ptrHead);
struct ListNode * insertList(struct ListNode **ptrHead, int iValue);

struct DoubleNode * treeToDoubleList(struct Node * ptrStartingNode, struct DoubleNode * ptrHead);
void printDoubleList(struct DoubleNode* ptrHead);
struct DoubleNode * insertDouble(struct DoubleNode ** ptrHead, int iValue);

void selectionSort(struct ListNode** ptrHead);
void insertionSort(struct ListNode** ptrHead);
void bubbleSort(struct Node** head);
void buBBleSort(struct DoubleNode** head);

struct ListNode* FindNodeByPos(struct ListNode* ptrHead, int position);

void ShellSort(struct ListNode** ptrHead);

//MENU ASCII
/*Cria a linha de cima*/
void createUpperBound(int iSize);
/*Cria a linha debaixo*/
void createLowerBound(int iSize);
/*Cria cada item do menu*/
void createMenuItem(char cArray[], int iSize);
/*Cria uma linha horizontal*/
void createHLine(int iSize);
/*Junção de todas as funções acima para criar o menu*/
void buildMenu();
/*Menu funcionando com casos*/
void menu();

void traverseInorder(struct Node* ptrRoot);
void traversePreOrder(struct Node* ptrStartingNode);
struct Node* buildTree(int iSize);

bool completeTree(struct Node* ptrRoot);

bool fullLevel(struct Node* ptrRoot, int iLevel);
bool perfectTree(struct Node* ptrRoot);


#include "./treeExplorer.hpp"
#endif // TREEEXPLORER_H