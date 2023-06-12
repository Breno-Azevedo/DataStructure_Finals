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


#include "./treeExplorer.hpp"
#endif // TREEEXPLORER_H