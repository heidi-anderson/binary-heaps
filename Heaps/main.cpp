#include "BinaryHeaps.cpp"

int main()
{
    // make binary heap with the given numbers
    BinaryHeap<int> heap({13, 21, 16, 24, 31, 19, 68, 65, 26, 32 });

    cout << "Current heap:" << endl;
    heap.printHeap(); // print before: 13 21 16 24 31 19 68 65 26 32
    heap.dotPrint("file1.dot"); // print .dot file

    heap.insert(14); // insert a new element
    cout << "Heap elements after inserting 14:" << endl;
    heap.printHeap(); // 13 14 16 24 21 19 68 65 26 32 31

    heap.dotPrint("file2.dot"); // creat .dot file

    cout << "Minimum element of heap: " << heap.findMin() << endl; // find min: 13

    heap.deleteMin(); // delete the min element
    cout << "Heap after deleting the minimum element" << endl;
    heap.printHeap(); // 14 21 16 24 31 19 68 65 26 32

    heap.dotPrint("file3.dot"); // create .dot file

    return 0;
}


