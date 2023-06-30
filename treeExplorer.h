#ifndef TREEEXPLORER_H
#define TREEEXPLORER_H

/**
 * @file treeExplorer.h
 * @authors Breno, Juliana e Sofia
 * @brief header file for the treeExplorer.hpp and sortingAlgorithms.hpp
 * @version 0.7
 * @date 2023-06-30
 * 
 * @copyright Copyright (c) 2023
 * 
**/

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

/**
 * @brief Basic node structure for the list.
 * The lists are used to sort the tree.
 */
struct ListNode {
    int iPayload;
    struct ListNode * ptrNext;
};

/**
 * @brief Basic node structure for the double list.
 * This struct is also used to sort the tree.
 */
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

/**
 * @brief createListNode() - Creates a List Node object with the given payload.
 * 
 * @param iPayload
 * @return struct ListNode*
 */
struct ListNode* createListNode(int iPayload);

/**
 * @brief createDoubleNode() - Creates a Double Node object with the given payload.
 * 
 * @param iPayload 
 * @return struct DoubleNode* 
 */
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
 * @brief insertNodeMain() - Calls the insertNode() function
 * on the main function via CLI.
 * 
 * @param ptrRoot 
 * @return struct Node* 
 */
struct Node * insertNodeMain(struct Node * ptrRoot);

/**
 * @brief createTree() - Given a char list, it creates a
 * BFS with the elements of the list.
 * 
 * @param cList 
 * @return Node* 
**/
struct Node * createTree(const char cList[], int iTamanho);

/**
 * @brief createTreeTxt() - Given a txt file, it creates a
 * BST with the elements of the txt file.
 * 
 * @param fileName 
 * @return struct Node* 
 */
struct Node * createTreeTxt(const char * fileName);

/**
 * @brief createTreeTxtMain() - Calls the createTreeTxt() function
 * on the main function via CLI.
 * 
 * @return struct Node* 
 */
struct Node * createTreeTxtMain();

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
struct Node * SearchElement(struct Node* ptrRoot, int iPayload);

/**
 * @brief searchElementMain() - Calls the searchElement() function
 * on the main function via CLI.
 * 
 * @param ptrRoot 
 * @return struct Node* 
 */
struct Node * searchElementMain(struct Node * ptrRoot);

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
 * @brief deleteNodeMain() - Calls the deleteNode() function
 * on the main function via CLI.
 * 
 * @param ptrRoot 
 * @return struct Node* 
 */
struct Node * deleteNodeMain(struct Node * ptrRoot);

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
 * @brief treeToDoubleList() - Given a tree, it creates a double list with the elements
 * of the tree. This function is used in the sorting algorithms.
 * 
 * @param ptrStartingNode 
 * @param ptrHead 
 * @return struct DoubleNode* 
 */
struct DoubleNode * treeToDoubleList(struct Node * ptrStartingNode, struct DoubleNode * ptrHead);

/**
 * @brief printDoubleList() - Prints the elements of the double list.
 * 
 * @param ptrHead 
 */
void printDoubleList(struct DoubleNode* ptrHead);

/**
 * @brief insertDouble() - Inserts a new node into the double list.
 * 
 * @param ptrHead 
 * @param iValue 
 * @return struct DoubleNode* 
 */
struct DoubleNode * insertDouble(struct DoubleNode ** ptrHead, int iValue);

/**
 * @brief selectionSort() - Sorts the list using the selection sort algorithm.
 * 
 * @param ptrHead 
 */
void selectionSort(struct ListNode** ptrHead);

/**
 * @brief selectionSortMain() - Calls the selectionSort() function
 * on the main function via CLI.
 * 
 * @param ptrRoot 
 */
void selectionSortMain(struct Node * ptrRoot);

/**
 * @brief insertionSort() - Sorts the list using the insertion sort algorithm.
 * 
 * @param ptrHead 
 */
void insertionSort(struct ListNode** ptrHead);

/**
 * @brief insertionSortMain() - Calls the insertionSort() function
 * on the main function via CLI.
 * 
 * @param ptrRoot 
 */
void insertionSortMain(struct Node * ptrRoot);

/**
 * @brief bubbleSort() - Sorts the list using the bubble sort algorithm.
 * 
 * @param head 
 */
void bubbleSort(struct DoubleNode* head);

/**
 * @brief buBBleSort() - Sorts the double list using the bubble sort algorithm.
 * 
 * @param head 
 */
void buBBleSort(struct DoubleNode** head);

/**
 * @brief bubbleSortMain() - Calls the bubbleSort() function
 * on the main function via CLI.
 * 
 * @param ptrRoot 
 */
void bubbleSortMain(struct Node * ptrRoot);

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

/**
 * @brief shellSortMain() - Calls the ShellSort() function
 * on the main function via CLI.
 * 
 * @param ptrRoot 
 */
void shellSortMain(struct Node * ptrRoot);

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
struct Node * buildTreeMain();

bool completeTree(struct Node* ptrRoot);

void completeTreeMain(struct Node * ptrRoot);

bool fullLevel(struct Node* ptrRoot, int iLevel);
bool perfectTree(struct Node* ptrRoot);
void perfectTreeMain(struct Node * ptrRoot);

#include "./treeExplorer.hpp"
#endif // TREEEXPLORER_H