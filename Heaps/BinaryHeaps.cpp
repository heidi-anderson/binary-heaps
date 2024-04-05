//
// Created by 101061875 on 3/6/2024.
//

#include "BinaryHeaps.h"

template <typename Comparable>
bool BinaryHeap<Comparable>::isEmpty() const
{
    return currentSize == 0; // if heap is empty this will return true
}
// inserts item, allows duplicates
// 6.8 - "Data Structures and Algorithms in C++" Mark Allen Weiss
template <typename Comparable>
void BinaryHeap<Comparable>::insert(const Comparable& x)
{
    if (currentSize == array.size() - 1) // if the size is equal to the array.size
        array.resize(array.size() * 2); // resize array to make room

    int hole = ++currentSize; // starting hole
    Comparable copy = x; // make a copy of the comparable item
    array[0] = move(copy); // placeholder

    for (; x < array[hole / 2]; hole /= 2)
        array[hole] = move(array[hole / 2]); // move parent down to hole

    array[hole] = move(array[0]); // insert determined by hole
}

//internal method to percolate down in the heap.
// 6.12 - "Data Structures and Algorithms in C++" Mark Allen Weiss
template <typename Comparable>
void BinaryHeap<Comparable>::percolateDown(int hole)
{
    int child; // child node
    Comparable temp = move(array[hole]); // holds element to be moved down

    for (;hole * 2 <= currentSize; hole = child) // until hole has at least one child
    {
        child = hole * 2; // get index of the left child
        if (child != currentSize && array[child + 1] < array[child]) // if right < left
            ++child; // move to right child
        if (array[child] < temp) // if child < element to be moved down
            array[hole] = move(array[child]); // move child up to fill hold
        else
            break; // stop the loop
    }

    array[hole] = move(temp); // place element in the correct position
}

// establishes heap order property from an arbituary arrangement of items
template <typename Comparable>
void BinaryHeap<Comparable>::buildHeap()
{
    // start from the last node
    for (int i = currentSize / 2; i > 0; --i)
        percolateDown(i); // percolate down each node from the last node
                                // to the root
}

//removes the minimum item. throws underflow exception if empty
// 6.12 - "Data Structures and Algorithms in C++" Mark Allen Weiss
template <typename Comparable>
void BinaryHeap<Comparable>::deleteMin()
{
    if (isEmpty()) // check if empty
        throw logic_error("Heap is empty"); // error message

    array[1] = move(array[currentSize--]); // move last elem to the root
    percolateDown(1); // percolate down root
}

// remove the minimum item and place it in minItem
// 6.12 - "Data Structures and Algorithms in C++" Mark Allen Weiss
template <typename Comparable>
void BinaryHeap<Comparable>::deleteMin(Comparable& minItem)
{
    if (isEmpty()) // check if empty
        throw logic_error("Heap is empty"); // error message

    minItem = move(array[1]); // store minimum element
    array[1] = move(array[currentSize--]); // replace root with last element
                                           // decrement size
    percolateDown(1); // percolate down the root
}

// prints heap to terminal
template <typename Comparable>
void BinaryHeap<Comparable>::printHeap() const
{
    for (int i = 1; i <= currentSize; ++i) // iterate over elems of heap
        cout << array[i] << " "; // print element followed by a space
    cout << endl; // end line
}

// prints heap to a .dot file
template <typename Comparable>
void BinaryHeap<Comparable>::dotPrint(string fileName) const
{
    ofstream file(fileName); // open file
    file << "digraph G {" << endl; // header for .dot file

    for (int i = 1; i <= currentSize; ++i) // iterate over elems of heap
    {
        if (i * 2 <= currentSize) // if left child exists write from curr elem to its left child
            file << "  " << array[i] << " -> " << array[i * 2] << ";" << endl;

        if (i * 2 + 1 <= currentSize) // if right child exists write from curr elem to its right child
            file << "  " << array[i] << " -> " << array[i * 2 + 1] << ";" << endl;
    }
    file << "}"; // closing brackets
    cout << "(" << fileName << " created)" << endl; // print to terminal indicating creaiton
}


