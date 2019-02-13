/**
 * @file    quicksort.h
 * @brief   This is a implementation file for quick sort algorithms
 *          and its template. Their templates are supposed to work with
 *          any data type.
 *
 * @author  Daiki Itoh
 * @date    4/24/2018
 */
#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <cstdlib>
#include <utility>
using std::swap;

/**
 * @brief     It moves the smaller elements than the pivot to its left and
 *            larger elements to its right.
 *
 * @param     array          It is an array to be sorted.
 * @param     left           It is a left index.
 * @param     right          It is a right index.
 * 
 * @return    It returns the pivot index.
 */
template<typename T>
int partition(T array[], int left, int right)
{
    int pivot_index;
    T pivot_value;
    // get a pivot at an index produced randomly
    pivot_index = (rand() % (right - left + 1)) + left;
    // get a pivot value
    pivot_value = array[pivot_index];
    // move the pivot to the end
    swap(array[pivot_index], array[right]);
    // start looking for the correct location
    pivot_index = left;
    // loop through the entire array
    for(int i = left; i <= right-1; i++)
    {
        // if the value is smaller than the pivot
        if(array[i] < pivot_value)
        {
            // swap it to the left partition
            swap(array[i], array[pivot_index]);
            // move the pivot
            pivot_index++;
        }
    }
    // move back the pivot to the correct location
    swap(array[pivot_index], array[right]);
    // return the pivot
    return pivot_index;
}

/**
 * @brief     It sorts the array by quick sort algorithns.
 *
 * @param     array          It is an array to be sorted.
 * @param     left           It is a left index.
 * @param     right          It is a right index.
 */
template<typename T>
void quicksort(T array[], int left, int right)
{
    
    int division;
    
    if(left < right)
    {
        // smaller values to the left of division and larger values to right
        division = partition(array, left, right);
        // quicksort on the left side
        quicksort(array, left, division-1);
        // quicksort on the right side
        quicksort(array, division+1, right);
    }
}

/**
 * @brief     It is a simple user interface for the user for quicksort.
 *
 * @param     array          It is an array to be sorted.
 * @param     size           It is an array's size.
 */
template<typename T>
void quicksort(T array[], int size)
{
    // if there is more then 1 element in the array, it calls the more
    // general version of quicksort
    if(size > 1)
    {
        quicksort(array, 0, size-1);
    }
}

#endif