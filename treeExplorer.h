#ifndef TREEEXPLORER_H
#define TREEEXPLORER_H

/**
 * @file treeExplorer.h
 * @authors Breno, Juliana e Sofia
 * 
 * @brief header file for the treeExplorer.hpp and sortingAlgorithms.hpp
 * 
 * @version 0.7
 * @date 2023-06-30
 * 
 * @copyright Copyright (c) 2023
 * 
**/

#include <iostream>

// Structs
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
    /**
     * @brief Basic node structure for the list.
     * The lists are used to sort the tree.
     */
    int iPayload;
    struct ListNode * ptrNext;
};

struct QueueNode {
    Node* ptrNode;
    QueueNode* ptrNext;
};

struct Queue {
    QueueNode* ptrFront;
    QueueNode* ptrRear;
};

// Functions headers for the treeExplorer.cpp

/**
 * @brief createNode() - Creates a new node with the given payload.
 * 
 * @param iPayload The payload to be stored in the node.
 * @return struct Node* A pointer to the newly created node.
 */
struct Node * createNode(int iPayload);

/**
 * @brief createListNode() - Creates a List Node object with the given payload.
 * 
 * @param iPayload
 * @return struct ListNode*
 */
struct ListNode* createListNode(int iPayload);


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
 * @brief createTreeTxt() - Given a txt file, it creates a
 * BST with the elements of the txt file.
 * 
 * @param fileName 
 * @return struct Node* 
 */
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
 * @brief queueEmpty() - Checks if the queue is empty.
 * 
 * @param ptrQueue 
 * @return bool 
 */
bool queueEmpty(Queue* ptrQueue);

/**
 * @brief queuePop() - Removes the first element of the queue.
 * 
 * @param ptrQueue 
 */
void queuePop(Queue* ptrQueue);

/**
 * @brief queuePush() - Inserts a new element into the queue.
 * 
 * @param ptrQueue 
 * @param ptrNode 
 */
void queuePush(Queue* ptrQueue, Node* ptrNode);

/**
 * @brief queueFront() - Returns the first element of the queue.
 * 
 * @param ptrQueue 
 * @return Node* 
 */
Node* queueFront(Queue* ptrQueue);

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
struct Node * SearchElement(struct Node* ptrRoot, int iPayload);

/**
 * @brief heightTree() - Returns the height of the tree.
 * 
 * @param ptrRoot 
 * @return int 
 */
int heightTree(struct Node * ptrRoot);

/**
 * @brief sizeTree() - Returns the size of the tree.
 * 
 * @param ptrRoot 
 * @return int 
 */
int sizeTree(struct Node * ptrRoot);

/**
 * @brief lesserNode() - Returns the lesser node of the tree.
 * 
 * @param ptrRoot 
 * @return struct Node* 
 */
struct Node* lesserNode(struct Node* ptrRoot);

/**
 * @brief deleteNode() - Deletes a node from the tree by its payload.
 * Auxiliary function for the deleteNode().
 * 
 * @param ptrRoot 
 * @param iData 
 * @return struct Node* 
 */
struct Node* deleteNode(struct Node* ptrRoot, int iData);

/**
 * @brief treeToList() - Given a tree, it creates a list with the elements
 * of the tree. This function is used in the sorting algorithms.
 * 
 * @param ptrStartingNode 
 * @param ptrHead 
 * @return struct ListNode* 
 */
struct ListNode * treeToList(struct Node * ptrStartingNode, struct ListNode * ptrHead);

/**
 * @brief printList() - Prints the elements of the list.
 * 
 * @param ptrHead 
 */
void printList(struct ListNode* ptrHead);

/**
 * @brief insertList() - Inserts a new node into the list.
 * 
 * @param ptrHead 
 * @param iValue 
 * @return struct ListNode* 
 */
struct ListNode * insertList(struct ListNode **ptrHead, int iValue);

/**
 * @brief buildTree() - Builds a tree with the given size.
 * 
 * @param iSize 
 * @return struct Node* 
 */
struct Node* buildTree(int iSize);

/**
 * @brief completeTree() - Checks if the tree is complete.
 * A complete tree is a tree where all the levels are full,
 * except for the last one, which is filled from left to right.
 * 
 * @param ptrRoot 
 * @return true 
 * @return false 
 */
bool completeTree(struct Node* ptrRoot);

/**
 * @brief fullLevel() - Checks if the given level is full.
 * A full level is a level where all the nodes are filled.
 * Auxiliary function for the perfectTree().
 * 
 * @param ptrRoot 
 * @param iLevel 
 * @return true 
 * @return false 
 */
bool fullLevel(struct Node* ptrRoot, int iLevel);

/**
 * @brief perfectTree() - Checks if the tree is perfect.
 * A perfect tree is a tree where all the levels are full.
 * 
 * @param ptrRoot 
 * @return true 
 * @return false 
 */
bool perfectTree(struct Node* ptrRoot);


// Functions headers for the sortingAlgorithms.cpp

/**
 * @brief selectionSort() - Sorts the list using the selection sort algorithm.
 * 
 * @param ptrHead 
 */
void selectionSort(struct ListNode** ptrHead);

/**
 * @brief insertionSort() - Sorts the list using the insertion sort algorithm.
 * 
 * @param ptrHead 
 */
void insertionSort(struct ListNode** ptrHead);

/**
 * @brief bubbleSort() - Sorts the list using the bubble sort algorithm.
 * 
 * @param head 
 */
void bubbleSort(struct ListNode* head);



/**
 * @brief FindNodeByPos() - Given a list and a position, it returns the node
 * that is in the given position. Auxiliary function for the ShellSort().
 * 
 * @param ptrHead 
 * @param position 
 * @return struct ListNode* 
 */
struct ListNode* FindNodeByPos(struct ListNode* ptrHead, int position);

/**
 * @brief ShellSort() - Sorts the list using the shell sort algorithm.
 * 
 * @param ptrHead 
 */
void ShellSort(struct ListNode** ptrHead);

// Functions headers for the menu.cpp

/**
 * @brief insertNodeMain() - Calls the insertNode() function
 * on the main function via CLI.
 * 
 * @param ptrRoot 
 * @return struct Node* 
 */
struct Node * insertNodeMain(struct Node * ptrRoot);

/**
 * @brief createTreeTxtMain() - Calls the createTreeTxt() function
 * on the main function via CLI.
 * 
 * @return struct Node* 
 */
struct Node * createTreeTxtMain();

/**
 * @brief searchElementMain() - Calls the searchElement() function
 * on the main function via CLI.
 * 
 * @param ptrRoot 
 * @return struct Node* 
 */
struct Node * searchElementMain(struct Node * ptrRoot);

/**
 * @brief selectionSortMain() - Calls the selectionSort() function
 * on the main function via CLI.
 * 
 * @param ptrRoot 
 */
void selectionSortMain(struct Node * ptrRoot);

/**
 * @brief buildTreeMain() - Calls the buildTree() function
 * on the main function via CLI.
 * 
 * @return struct Node* 
 */
struct Node * buildTreeMain();

/**
 * @brief insertionSortMain() - Calls the insertionSort() function
 * on the main function via CLI.
 * 
 * @param ptrRoot 
 */
void insertionSortMain(struct Node * ptrRoot);

/**
 * @brief bubbleSortMain() - Calls the bubbleSort() function
 * on the main function via CLI.
 * 
 * @param ptrRoot 
 */
void bubbleSortMain(struct Node * ptrRoot);

/**
 * @brief shellSortMain() - Calls the ShellSort() function
 * on the main function via CLI.
 * 
 * @param ptrRoot 
 */
void shellSortMain(struct Node * ptrRoot);

/**
 * @brief completeTreeMain() - Calls the completeTree() function
 * on the main function via CLI.
 * 
 * @param ptrRoot 
 */
void completeTreeMain(struct Node * ptrRoot);

/**
 * @brief perfectTreeMain() - Calls the perfectTree() function
 * on the main function via CLI.
 * 
 * @param ptrRoot 
 */
void perfectTreeMain(struct Node * ptrRoot);

void BFSMain(struct Node * ptrRoot);

void sizeTreeMain(struct Node * ptrRoot);

void heightTreeMain(struct Node * ptrRoot);

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

void sortGraphRep(ListNode* ptrHead);
void swap(ListNode* a, ListNode* b);



#include "./treeExplorer.hpp"
#include "./sortingAlgorithms.hpp"

#endif // TREEEXPLORER_H
