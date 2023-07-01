#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

/**
 * @file sortingAlgorithms.h
 * @authors Breno, Juliana e Sofia
 * 
 * @brief header file for the sortingAlgorithms.hpp
 * 
 * @version 0.7
 * @date 2023-06-30
 * 
 * @copyright Copyright (c) 2023
 * 
**/

#include <iostream>

/**
 * @brief selectionSort() - Sorts the linked list using the selection sort algorithm.
 * 
 * @param ptrHead 
 */
void selectionSort(struct ListNode ** ptrHead);

/**
 * @brief insertionSort() - Sorts the linked list using the insertion sort algorithm.
 * 
 * @param ptrHead 
 */
void insertionSort(struct ListNode ** ptrHead);

/**
 * @brief bubbleSort() - Sorts the linked list using the bubble sort algorithm.
 * 
 * @param head 
 */
void bubbleSort(struct ListNode * head);

/**
 * @brief FindNodeByPos() - Given a list and a position, it returns the node
 * that is in the given position. Auxiliary function for the ShellSort().
 * 
 * @param ptrHead 
 * @param position 
 * @return struct ListNode * 
 */
struct ListNode * FindNodeByPos(struct ListNode * ptrHead, int position);

/**
 * @brief ShellSort() - Sorts the list using the shell sort algorithm.
 * 
 * @param ptrHead 
 */
void ShellSort(struct ListNode ** ptrHead);

#include "./sortingAlgorithms.hpp"
#endif // SORTINGALGORITHMS_H