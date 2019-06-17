
#ifndef ARRAYLISTBETTER_H
#define ARRAYLISTBETTER_H
#include <stdlib.h>
#include <iostream>
using namespace std;

template <typename T>
class arrayListBetter{
public:
  ArrayList(){
    array = (T*)malloc(sizeof(T)*arraySize);
  }
  T get(int index){
    return array[(index+head)%arraySize];
  }
  void set(int index, T value){
    array[(index+head)%arraySize] = value;
  }
  void add(int index, T value){
    if (elementCount+1 > arraySize){
      resize(1);
    }
    if (index< elementCount/2){
      if (head == 0){
        head = arraySize -1 ;
      } else {
        head--;
      }
      for (int i =0; i<=index-1; i++){
        array[(head+i)%arraySize] = array[(head+i+1)%arraySize];
      }
    } else {
      for (int i=elementCount ; i>index; i--){
        array[(head+i)%arraySize] = array[(head+i-1)%arraySize];
      }
    }
    array[(head+index)%arraySize] = value;
    elementCount++;
  }
  T remove(int index){
    if (index>=elementCount){
      throw("remove: index out of range.");
    }
    T value = array[(head+index)%arraySize];
    if(index<elementCount/2){
      for (int i = index; i>0; i--){
        array[(head+i)%arraySize] = array[(head+i-1)%arraySize];
      }
      head = (head+1)%arraySize;
    } else {
      for (int i =index; i<elementCount-1; i++){
        array[(head+i)%arraySize] = array[(head+i+1)%arraySize];
      }
    }
    elementCount--;
    if(3*elementCount<arraySize){
      resize(0);
    }
    return value;
  }
  int getElementCount(){
    return elementCount;
  };;

  int getArraySize(){
    return arraySize;
  };

  void printAll(){
    for (size_t i =0 ; i<elementCount; i++){
      cout << get(i) <<"\t";
    }
    cout<<endl;
  };


private:
  T* array;
  int arraySize=1;
  int head = 0;
  int elementCount = 0;
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

};

#endif
