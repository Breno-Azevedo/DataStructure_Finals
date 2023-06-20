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

/**
 * @brief createNode() - Creates a new node with the given payload.
 * 
 * @param iPayload The payload to be stored in the node.
 * @return struct Node* A pointer to the newly created node.
 */
Node * createNode(int iPayload);


/**
 * @brief insertNode() - Given an existing Node and its iPayload,
 * creates a new node and insert it into the existing one.
 * If the given Node is nullptr, than it creates a brand new one.
 * 
 * @param ptrRoot 
 * @param iPayload 
 * @return struct Node* 
**/
Node * insertNode(struct Node * ptrRoot, int iPayload);

/**
 * @brief createTree() - Given a char list, it creates a
 * BFS with the elements of the list.
 * 
 * @param cList 
 * @return Node* 
**/
Node * createTree(const char cList[]);


/**
 * @brief searchNode() - Given the root of a tree and an integer,
 * it search through the looking for Node that contains the respective
 * integer and returns it.
 * 
 * @param ptrRoot 
 * @param iPayload 
 * @return Node* 
**/
Node * searchNode(struct Node * ptrRoot, int iPayload);

/**
 * @brief printTree() - Prints the elements of the tree
 * 
 * @param ptrRoot 
 */
void printTree(struct Node * ptrRoot);

#include "./treeExplorer.hpp"
#endif // TREEEXPLORER_H