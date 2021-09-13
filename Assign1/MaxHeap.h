#pragma once
#include "PCB.h"
#include <vector>

class MaxHeap{
    std::vector<int> data;

    void insert(int value);                   //Insert Value into heap
    void extractMax();                          //Extract the value at root of heap
    void display();                             //Display Heap as an array
    int getMax();                              //Return the largest value 

    MaxHeap();                                  //Default Constructor

    private:
        int size;
        void bubbleDown(int idx);
        void bubbleUp(int idx);

        int PARENT(int i){
           return(2*i +1);
        }

};