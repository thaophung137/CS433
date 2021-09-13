#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>
#include "MaxHeap.h"

MaxHeap::MaxHeap(){
    size = 0;
}

//Recursive function to bubbles down the tree to the correct position. 
void MaxHeap::bubbleDown(int idx){
    int size = data.size();             
    //get left and right child at the index. 
    int left = 2*idx + 1;               //left child
    int right = 2*idx+2;                //right child

    int largest = idx;                  //set index as the largest
    //if existing left is smaller than index, set largest as the left child.
    if(left < size && data[left] > data[idx]){
        largest = left;
    }

    if(right < size && data[right] > data[largest]){
        largest = right;
    }

    //swap with a child of greater value and bubble down.
    if(largest != idx){
        int temp = data[idx];
        data[idx] = data[largest];
        data[largest] = temp;
        bubbleDown(idx);
    }
}

//Recursive function to bubble up the tree to the correct position
void MaxHeap::bubbleUp(int idx){
    //if idx is 0, we are at root so no need to bubble up. 
    if(idx == 0){
        return;
    }
    int parent = floor((idx - 1)/2);      //get the parent of index.

    //if the index and value of parent is less than the value of index, swap and bubble up. 
    if(idx && data[parent] < data[idx]){
        int temp = data[idx];               //temporary variable to hold index
        data[idx] = data[parent];           //set new index to be parent 
        data[parent] = temp;                //then get parent from temp
        bubbleUp(parent);                   //bubble up 
    }
}

