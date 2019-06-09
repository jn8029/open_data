#ifndef BHEAP_H
#define BHEAP_H

#include <iostream>
class priorityQueue {
public:
  priorityQueue():n(0),arraySize(16){
    array = new int[arraySize];
  };
  bool add(int i){
    if (n+1 > arraySize){

      resize();
    }
    array[n] = i;
    n++;
    bubbleUp(n-1);
    return true;
  }
  int remove(){
    int toRemove = array[0];
    array[0] = array[n-1];
    trickleDown(0);
    n--;
    return toRemove;
  }
  void print(){
    for (int i = 0 ; i <n ; i++){
      std::cout<<array[i]<<'\t';
    }
    std::cout<<std::endl;
  }
private:
  int left(int i ){
    return 2*i+1;
  }
  int right(int i){
    return 2*i+2;
  }
  int parent(int i){
    return (i-1)/2;
  }
  void bubbleUp(int i){
    int p = parent(i);
    int temp;
    while (i>0 && array[p]>array[i]){
      temp = array[p];
      array[p] = array[i];
      array[i] = temp;
      i = p;
      p = parent(i);
    }
  }
  void trickleDown(int i){

    while(i>=0){
      int j = -1;
      int l = left(i);
      int r = right(i);
      
      if (r<n && array[r]<array[i]){
        if (array[r]>array[l]){
          j = l;
        } else {
          j = r;
        }
      } else {
        if (l<n && array[l]<array[i]){
          j = l;
        }
      }
      if (j>=0){
        int temp = array[j];
        array[j] = array[i];
        array[i] = temp;
      }
      i = j;
    }
  }
  void resize(){
    if (n+1 > arraySize){
      int newArraySize = arraySize*2;
      int* newArray = new int[newArraySize];
      for (int i =0 ; i < n; i++){
        newArray[i] = array[i];
      }
      array = newArray;
      arraySize = newArraySize;

      return;
    }
    if (n < arraySize/3){

      int smallerArraySize = arraySize/2 > 0 ? arraySize/2 : 1;
      int* newArray = new int[smallerArraySize];
      for (int i =0 ; i < n; i++){
        newArray[i] = array[i];
      }
      array = newArray;
      arraySize = smallerArraySize;
    }

  }
  int n;
  int arraySize;
  int* array;
};

#endif
