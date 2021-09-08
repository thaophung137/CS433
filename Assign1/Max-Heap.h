#pragma once 
#include "PCB.h"
#include <vector>


class MaxHeap{
public: 
    void insert(PCB & value);
    void display();
    PCB* getMax();
    int getSize();
    void extractMax();
    MaxHeap();

private:
    void heapifyUp(int index);
    void heapifyDown(int index);
    int size;
};