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

/*--------------------------Struct Declaration-------------------------------*/
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
     * @brief Basic node structure for the linked list.
     * The linked lists are used to sort the tree.
     */
    int iPayload;
    struct ListNode * ptrNext;
};

struct QueueNode {
    /**
     * @brief Basic node structure for the queue.
     * The queues are used in the Breadth First Search Algorithm.
     */
    struct Node * ptrNode;
    struct QueueNode * ptrNext;
};

struct Queue {
    /**
     * @brief Structure for the queue.
     * The queues are used in the Breadth First Search Algorithm.
     */
    struct QueueNode * ptrFront;
    struct QueueNode * ptrRear;
};

/*-----------------Functions headers for the treeExplorer.cpp-----------------*/

/**
 * @brief createNode() - Creates a new node with the given payload.
 * 
 * @param iPayload The payload to be stored in the node.
 * @return struct Node * A pointer to the newly created node.
 */
struct Node * createNode(int iPayload);

/**
 * @brief createListNode() - Creates a List Node object with the given payload.
 * 
 * @param iPayload
 * @return struct ListNode *
 */
struct ListNode* createListNode(int iPayload);

/**
 * @brief insertNode() - Given an existing Node (root) and a iPayload,
 * creates a new node and insert it into the existing one (into the tree).
 * If the given Node is nullptr, than it creates a brand new one.
 * 
 * @param ptrRoot 
 * @param iPayload 
 * @return struct Node * 
**/
struct Node * insertNode(struct Node * ptrRoot, int iPayload);


/**
 * @brief createTreeTxt() - Given a .txt file, it creates a
 * BST with the elements of the txt file.
 * 
 * @param fileName 
 * @return struct Node * 
 */
struct Node * createTreeTxt(const char * fileName);

/**
 * @brief searchNode() - Given the root of a tree and an integer,
 * it search through the tree looking for a Node that contains the respective
 * integer and returns it.
 * 
 * @param ptrRoot 
 * @param iPayload 
 * @return struct Node * 
**/
struct Node * searchNode(struct Node * ptrRoot, int iPayload);

/**
 * @brief printTree() - Prints the elements of the tree.
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
bool queueEmpty(struct Queue * ptrQueue);

/**
 * @brief queuePop() - Removes the first element of the queue.
 * 
 * @param ptrQueue 
 */
void queuePop(struct Queue * ptrQueue);

/**
 * @brief queuePush() - Inserts a new element into the queue.
 * 
 * @param ptrQueue 
 * @param ptrNode 
 */
void queuePush(struct Queue* ptrQueue, struct Node* ptrNode);

/**
 * @brief queueFront() - Returns the first element of the queue.
 * 
 * @param ptrQueue 
 * @return struct Node * 
 */
struct Node * queueFront(struct Queue * ptrQueue);

/**
 * @brief Breadth_First_Search() - Executes the BFS algorithm.
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
 * @return struct Node * 
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
 * The element with the smaller iPayload.
 * 
 * @param ptrRoot 
 * @return struct Node * 
 */
struct Node * lesserNode(struct Node * ptrRoot);

/**
 * @brief deleteNode() - Deletes a node from the tree by its payload.
 * 
 * @param ptrRoot 
 * @param iData 
 * @return struct Node * 
 */
struct Node * deleteNode(struct Node * ptrRoot, int iData);

/**
 * @brief treeToList() - Given a tree, it creates a linked list with the elements
 * of the tree. This function is used in the sorting algorithms.
 * 
 * @param ptrStartingNode 
 * @param ptrHead 
 * @return struct ListNode * 
 */
struct ListNode * treeToList(struct Node * ptrStartingNode, struct ListNode * ptrHead);

/**
 * @brief printList() - Prints the elements of the linked list.
 * 
 * @param ptrHead 
 */
void printList(struct ListNode * ptrHead);

/**
 * @brief insertList() - Inserts a new node into the linked list.
 * 
 * @param ptrHead 
 * @param iValue 
 * @return struct ListNode * 
 */
struct ListNode * insertList(struct ListNode ** ptrHead, int iValue);

/**
 * @brief buildTree() - Builds a tree with the given size and
 * inputs from the user.
 * 
 * @param iSize 
 * @return struct Node * 
 */
struct Node * buildTree(int iSize);

/**
 * @brief completeTree() - Checks if the tree is complete.
 * A complete tree is a tree where all the levels are full,
 * except for the last one, which is filled from left to right.
 * 
 * @param ptrRoot 
 * @return true 
 * @return false 
 */
bool completeTree(struct Node * ptrRoot);

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
bool fullLevel(struct Node * ptrRoot, int iLevel);

/**
 * @brief perfectTree() - Checks if the tree is perfect.
 * A perfect tree is a tree where all the levels are full.
 * 
 * @param ptrRoot 
 * @return true 
 * @return false 
 */
bool perfectTree(struct Node * ptrRoot);

#include "./treeExplorer.hpp"
#endif // TREEEXPLORER_H
