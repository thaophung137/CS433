#include <iostream>
#include <cmath>
#include <iomanip>
#include "ReadyQueue.h"
#include "PCB.h"

using namespace std;
// TODO: Add your implementation of ReadyQueue functions here
ReadyQueue::ReadyQueue(){

}

ReadyQueue::~ReadyQueue(){
    
}
int ReadyQueue::size(){
    return data.size();
}

//Recursive function to bubbles down the tree to the correct position. 
void ReadyQueue::bubbleDown(int idx){
    int size = data.size();
    //get left and right child at the index. 
    int left = 2*idx + 1;              //left child
    int right = 2*idx + 2;              //right child

    int largest = idx;
    //if existing left is smaller than index, set largest as the left child.
    if(left < size && data[left].getPriority() > data[idx].getPriority()){
        largest = left;
    }

    if(right < size && data[right].getPriority() > data[largest].getPriority()){
        largest = right;
    }
    //swap with a child of greater value and bubble down.
    if(largest != idx){
        PCB temp = data[idx];
        data[idx] = data[largest];
        data[largest] = temp;
        bubbleDown(idx);
    }
}

//Recursive function to bubble up the tree to the correct position
void ReadyQueue::bubbleUp(int idx){
    //if idx is 0, we are at root so no need to bubble up. 
    if(idx == 0){
        return;
    }
    int parent = floor((idx - 1)/2);      //get the parent of index.

    //if the index and value of parent is less than the value of index, swap and bubble up. 
    if(idx && data[parent].getPriority() < data[idx].getPriority()){
        PCB temp = data[idx];               //temporary variable to hold index
        data[idx] = data[parent];           //set new index to be parent 
        data[parent] = temp;                //then get parent from temp
        bubbleUp(parent);                   //bubble up 
    }
}


//Insert a new value into the heap
void ReadyQueue::addPCB(PCB value){
    for(int i = 0; i<data.size(); i++){
        if(value.getID() == data[i].getID()){
            return;
        }
    }
    value.setState(READY);
    data.emplace_back(value);
    bubbleUp(data.size()-1);
}
/*
PCB ReadyQueue::removehighestPCB(){
    PCB temp = data[0];
    deleteMax();
    temp.setState(RUNNING);
    return temp;
}

void ReadyQueue::deleteMax(){
    if(data.empty()){
        return;
    }
    data[0] = data.back();
    data.pop_back();
    bubbleDown(0);
}*/
void ReadyQueue::display(){
    cout << "Queue: ";
    for(int i = 0; i < data.size(); i++){
        cout << data[i].getID() << endl;
    }
}
