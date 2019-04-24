
#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#include <stdlib.h>
#include <iostream>
using namespace std;

template <typename T>
class arrayQueue{
public:
  arrayQueue(){
    array = (T*)malloc(sizeof(T)*arraySize);
  }
  void add(T value){
    if (elementCount+1 > arraySize){
      resize(1);
    }
    array[(elementCount+head)%arraySize] = value;
    elementCount++;
  }
  T remove(){
    if(elementCount==0){
      throw("remove: Queue is empty.");
    }
    T value = array[head];
    head = (head+1)%arraySize;
    elementCount--;
    if(arraySize >= 3*elementCount){
      resize(0);
    }
    return value;

  }
  void printAll(){
    if (!elementCount){
      return;
    }
    for (int i = 0 ; i<elementCount; i++){

      cout << array[(head+i) % arraySize] << '\t';
    }
    cout<<endl;
  }
private:
  void resize(int grow){
    T* newArray;
    int newArraySize;
    if (grow){
      newArray =(T*)malloc(sizeof(T)*arraySize*2);
      newArraySize = arraySize*2;
    } else {
      newArray =(T*)malloc(sizeof(T)*arraySize/2);
      newArraySize = arraySize/2;
    }
    for (int i =0; i<elementCount;i++){
      newArray[i] = array[(i+head)%arraySize];
    }

    head = 0;
    array = newArray;
    arraySize = newArraySize;
  };

  T* array;
  int elementCount = 0;
  int arraySize = 1;
  int head = 0;


};

#endif
