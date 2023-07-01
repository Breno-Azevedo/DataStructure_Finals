#ifndef MENU_H
#define MENU_H

/**
 * @file menu.h
 * @authors Breno, Juliana e Sofia
 * 
 * @brief header file for the menu.hpp
 * 
 * @version 0.7
 * @date 2023-06-30
 * 
 * @copyright Copyright (c) 2023
 * 
**/

#include <iostream>

/*-----------------------Functions headers for the menu.cpp---------------------------*/

/**
 * @brief insertNodeMain() - Calls the insertNode() function
 * on the main function via CLI.
 * 
 * @param ptrRoot 
 * @return struct Node * 
 */
struct Node * insertNodeMain(struct Node * ptrRoot);

/**
 * @brief createTreeTxtMain() - Calls the createTreeTxt() function
 * on the main function via CLI.
 * 
 * @return struct Node * 
 */
struct Node * createTreeTxtMain();

/**
 * @brief searchElementMain() - Calls the searchElement() function
 * on the main function via CLI.
 * 
 * @param ptrRoot 
 * @return struct Node * 
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
 * @return struct Node * 
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

/**
 * @brief BFSMain() - Calls the Breadth_First_Search() function
 * on the main function via CLI.
 * 
 * @param ptrRoot 
 */
void BFSMain(struct Node * ptrRoot);

/**
 * @brief sizeTreeMain() - Calls the sizeTree() function
 * on the main function via CLI.
 * 
 * @param ptrRoot 
 */
void sizeTreeMain(struct Node * ptrRoot);

/**
 * @brief heightTreeMain() - Calls the heightTree() function
 * on the main function via CLI.
 * 
 * @param ptrRoot 
 */
void heightTreeMain(struct Node * ptrRoot);

/*----------------------MENU ASCII--------------------------------------------*/

/**
 * @brief createUpperBound() - Creates the upper
 * horizontal line of the menu.
 * 
 * @param iSize 
 */
void createUpperBound(int iSize);

/**
 * @brief createLowerBound() - Creates the lower
 * horizontal line of the menu.
 * 
 * @param iSize 
 */
void createLowerBound(int iSize);

/**
 * @brief createMenuItem() - Creates a menu item.
 * 
 * @param cArray
 * @param iSize 
 */
void createMenuItem(char cArray[], int iSize);

/**
 * @brief createHLine() - Creates the intermediate
 * horizontal line of the menu.
 * 
 * @param iSize 
 */
void createHLine(int iSize);

/**
 * @brief buildMenu() - Creates the appearance of the menu.
 * 
 */
void buildMenu();

/**
 * @brief menu() - Creates the menu and its cases.
 * 
 */
void menu();

void sortGraphRep(struct ListNode * ptrHead);

void swap(struct ListNode * a, struct ListNode * b);

#include "./menu.hpp"
#endif // MAIN_H