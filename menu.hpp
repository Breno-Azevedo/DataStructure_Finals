#ifndef MENU_HPP_
#define MENU_HPP_

/**
 * @file sortingAlgorithms.hpp
 * @author Breno, Juliana e Sofia
 * 
 * @brief Here we define the functions for the menu.
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

/*FUNÇÕES DE ÁRVORE PARA O MENU*/
struct Node * insertNodeMain(struct Node * ptrRoot) {
    int iValue;
    cout << "Type the value to be inserted (int): ";
    cin >> iValue;

    auto start = chrono::high_resolution_clock::now();
    ptrRoot = insertNode(ptrRoot, iValue);
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Resultant tree: " << endl;
    printTree(ptrRoot);
    cout << endl;

    cout << "Execution time: " << duration.count() << " microssegundos" << endl;

    return ptrRoot;
}

struct Node * buildTreeMain() {
    int iSize;
    cout << "Type the number of nodes (int): ";
    while (!(cin >> iSize) || iSize <= 0) {
        cout << "Invalid input. Please enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }   

    auto start = chrono::high_resolution_clock::now();
    struct Node* ptrRoot2 = buildTree(iSize);
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Resultant tree: " << endl;
    printTree(ptrRoot2);
    cout << endl;

    cout << "Execution time: " << duration.count() << " microssegundos" << endl;

    return ptrRoot2;
}

struct Node * createTreeTxtMain() {
    string strFile;
    cout << "Type the file name (with .txt ending): ";
    cin >> strFile;
    const char * fileName = strFile.c_str();

    auto start = chrono::high_resolution_clock::now();
    struct Node * ptrRoot1 = createTreeTxt(fileName);
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Resultant tree: " << endl;
    printTree(ptrRoot1);
    cout << endl;

    cout << "Execution time: " << duration.count() << " microssegundos" << endl;

    return ptrRoot1;
}

void heightTreeMain(struct Node * ptrRoot) {
    auto start = chrono::high_resolution_clock::now();
    int iHeight = heightTree(ptrRoot);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "The height of tree is: " << iHeight << endl;
    cout << "Execution time: " << duration.count() << " microssegundos" << endl;
}

void completeTreeMain(struct Node * ptrRoot) {
    auto start = chrono::high_resolution_clock::now();
    bool is_complete = completeTree(ptrRoot);
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    if(is_complete == true) cout << "The tree is complete." << endl;
    else cout << "The tree is not complete." << endl;

    cout << "Execution time: " << duration.count() << " microssegundos" << endl;
}

void perfectTreeMain(struct Node * ptrRoot) {
    auto start = chrono::high_resolution_clock::now();
    bool is_perfect = perfectTree(ptrRoot);
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    if(is_perfect == true) cout << "The tree is perfect." << endl;
    else cout << "The tree is not perfect." << endl;

    cout << "Execution time: " << duration.count() << " microssegundos" << endl;
}

void BFSMain(struct Node * ptrRoot) {
    cout << "Tree exhibited through the Breadth First Search Algorithm : " << endl;
    auto start = chrono::high_resolution_clock::now();
    Breadth_First_Search(ptrRoot);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Execution time: " << duration.count() << " microssegundos" << endl;
}

struct Node * searchElementMain(struct Node * ptrRoot) {
    int iValue;
    cout << "Type the value from the node whose address is to be found (int): ";
    cin >> iValue;

    auto start = chrono::high_resolution_clock::now();
    ptrRoot = SearchElement(ptrRoot, iValue);
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Execution time: " << duration.count() << " microssegundos" << endl;

    return ptrRoot;
}

void sizeTreeMain(struct Node * ptrRoot) {
    auto start = chrono::high_resolution_clock::now();
    int iSize = sizeTree(ptrRoot);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "The size of three is: " << iSize << endl;
    cout << "Execution time: " << duration.count() << " microssegundos" << endl;
}

struct Node * deleteNodeMain(struct Node * ptrRoot) {
    int iValue;
    cout << "Type the value of the node to be removed (int): ";
    cin >> iValue;

    auto start = chrono::high_resolution_clock::now();
    ptrRoot = deleteNode(ptrRoot, iValue);
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Resultant tree: " << endl;
    printTree(ptrRoot);
    cout << endl;

    cout << "Execution time: " << duration.count() << " microssegundos" << endl;

    return ptrRoot;
}


/*FUNÇÕES DE SORT PARA O MENU*/
void selectionSortMain(struct Node * ptrRoot) {
    struct ListNode * ptrHead = nullptr;
    ptrHead = treeToList(ptrRoot, ptrHead);
    cout << "Lista antes do Selection Sort: " << endl;
    printList(ptrHead);

    auto start = chrono::high_resolution_clock::now();
    selectionSort(&ptrHead);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Lista depois do Selection Sort: " << endl;
    printList(ptrHead);

    cout << "Execution time: " << duration.count() << " microssegundos" << endl;
}

void insertionSortMain(struct Node * ptrRoot) {
    struct ListNode * ptrHead = nullptr;
    ptrHead = treeToList(ptrRoot, ptrHead);
    cout << "Lista antes do Insertion Sort: " << endl;
    printList(ptrHead);

    auto start = chrono::high_resolution_clock::now();
    insertionSort(&ptrHead);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Lista depois do Insertion Sort: " << endl;
    printList(ptrHead);

    cout << "Execution time: " << duration.count() << " microssegundos" << endl;
}

void shellSortMain(struct Node * ptrRoot) {
    struct ListNode * ptrHead = nullptr;
    ptrHead = treeToList(ptrRoot, ptrHead);
    cout << "Lista antes do Shell Sort: " << endl;
    printList(ptrHead);

    auto start = chrono::high_resolution_clock::now();
    ShellSort(&ptrHead);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Lista depois do Shell Sort: " << endl;
    printList(ptrHead);

    cout << "Execution time: " << duration.count() << " microssegundos" << endl;
}

void bubbleSortMain(struct Node * ptrRoot) {
    struct ListNode * ptrHead = nullptr;
    ptrHead = treeToList(ptrRoot, ptrHead);
    cout << "Lista antes do Bubble Sort: " << endl;
    printList(ptrHead);

    auto start = chrono::high_resolution_clock::now();
    bubbleSort(ptrHead);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Lista depois do Bubble Sort: " << endl;
    printList(ptrHead);

    cout << "Execution time: " << duration.count() << " microssegundos" << endl;
}

/*FUNÇÕES DO MENU*/
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

void buildMenu() {
    int iSize = 70;

    createUpperBound(iSize);
    createMenuItem("Menu Principal", iSize);
    createHLine(iSize);
    createMenuItem("Binary Search Tree Explorer - Integer Payload", iSize);
    createMenuItem("1 - Create a BST from a text file (.txt).", iSize);
    createMenuItem("2 - Create a BST from user inputs.", iSize);
    createMenuItem("3 - Inform BST's height.", iSize);
    createMenuItem("4 - Inform BST's size.", iSize);
    createMenuItem("5 - Insert an element in the BST.", iSize);
    createMenuItem("6 - Remove an element from the BST.", iSize);
    createMenuItem("7 - Search a BST element's memory address.", iSize);
    createMenuItem("8 - Inform if the BST is complete.", iSize);
    createMenuItem("9 - Inform if the BST is perfect.", iSize);
    createMenuItem("10 - Exhibit the BST through the Breadth First Search Algorithm.", iSize);
    createMenuItem("11 - Convert the BST to a list and sort it through the Bubble Sort.", iSize);
    createMenuItem("12 - Convert the BST to a list and sort it through the Selection Sort.", iSize);
    createMenuItem("13 - Convert the BST to a list and sort it through the Insertion Sort.", iSize);
    createMenuItem("14 - Convert the BST to a list and sort it through the Shell Sort.", iSize);
    createMenuItem("0 - Finish program.", iSize);
    createLowerBound(iSize);
}

void menu() {
    int choice;
    struct Node * ptrRoot = nullptr;
    int iHeight;
    int iSize;
    do {
        buildMenu();
        cout << "Type the number of the action wanted (int): ";
        while (!(cin >> choice) || choice < 0) {
            cout << "Invalid input. Please enter a positive integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch (choice) {
            case 0:
                cout << "Program finished." << endl;
                break;
            case 1:
                ptrRoot = createTreeTxtMain();
                break;
            case 2:
                ptrRoot = buildTreeMain();
                break;
            case 3:
                heightTreeMain(ptrRoot);
                break;
            case 4:
                sizeTreeMain(ptrRoot);
                break;
            case 5:
                ptrRoot = insertNodeMain(ptrRoot);
                break;
            case 6:
                ptrRoot = deleteNodeMain(ptrRoot);
                break;
            case 7:
                ptrRoot = searchElementMain(ptrRoot);
                break;
            case 8:
                completeTreeMain(ptrRoot);
                break;
            case 9:
                perfectTreeMain(ptrRoot);
                break;
            case 10:
                BFSMain(ptrRoot);
                break;
            case 11:
                bubbleSortMain(ptrRoot);
                break;
            case 12:
                selectionSortMain(ptrRoot);
                break;
            case 13:
                insertionSortMain(ptrRoot);
                break;
            case 14:
                shellSortMain(ptrRoot);
                break;
        }
    } while (choice != 0);
}


#endif // MENU_HPP_