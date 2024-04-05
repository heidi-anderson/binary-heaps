//
// Created by 101061875 on 3/6/2024.
//

#ifndef HEAPS_BINARYHEAPS_H
#define HEAPS_BINARYHEAPS_H


#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

template <typename Comparable>
class BinaryHeap {
public:
    // constructors
    explicit BinaryHeap(int capacity = 100) : currentSize(0), array(capacity + 1) {}

    // constructor that takes a vector of items
    // initializes array w a size larger than the num of items
    // sets currentSize to the size of the vector
    explicit BinaryHeap(const vector<Comparable>& items)
            : array(items.size() + 10), currentSize(static_cast<int>(items.size()))
    {
        for (size_t i = 0; i < items.size(); ++i) // iterate
            array[i + 1] = items[i]; // copy items from vector to the array
        // build heap from the array
        buildHeap();
    }

    bool isEmpty() const;

    const Comparable& findMin() const
    {
        if (isEmpty()) // if empty
            throw logic_error("Heap is empty"); // error
        return array[1]; // return first element, as this is the minimum
    }

    void insert(const Comparable& x);
    void deleteMin();
    void deleteMin(Comparable& minItem);
    void printHeap() const;
    void dotPrint(string fileName) const;

private:
    int currentSize; // number of elements in heap
    vector<Comparable> array; // the heap array

    void buildHeap();
    void percolateDown(int hole);
};

#endif //HEAPS_BINARYHEAPS_H
