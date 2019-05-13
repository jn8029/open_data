/**
  Assignment 1, Question 6, ArrayStack.h
  Purpose: implementation of an array based stack

  @author Warren Cheng
  @version 2019.05.01
*/

#ifndef ArrayStack_H
#define ArrayStack_H
#include <stdlib.h>
#include <iostream>
using namespace std;

template <typename T>
class ArrayStack{
public:
  ArrayStack(){
    array = (T*)malloc(sizeof(T)*arraySize);
  }
  void push(T value){
    if (elementCount+1 > arraySize){
      resize(1);
    }
    array[elementCount] = value;
    elementCount++;
  }
  T pop(){
    if(elementCount==0){
      throw out_of_range ("remove: Stack is empty.");
    }
    T value = array[elementCount-1];
    elementCount--;
    if(arraySize >= 3*elementCount){
      resize(0);
    }
    return value;

  }
  T top(){
    if(elementCount==0){
      throw out_of_range ("top: Stack is empty.");
    }
    return array[elementCount-1];
  }
  void print(){
    if (!elementCount){
      return;
    }
    for (int i = 0 ; i<elementCount; i++){

      cout << array[i] << '\t';
    }
    cout<<endl;
  }
  int size(){
    return elementCount;
  }
private:
  void resize(int grow){
    // input: int grow
    // using the input grow to execute grow or shrink of resize
    T* newArray;
    int newArraySize;
    if (grow){
      newArray =(T*)malloc(sizeof(T)*arraySize*2);
      newArraySize = arraySize*2;
    } else {
      newArraySize = arraySize/2;
      //special case: if arraySize is 1 and 1/2 = 0, need to check
      //min newArraySize should be 1.
      if (newArraySize==0){
        newArraySize=1;
      }
      newArray =(T*)malloc(sizeof(T)*newArraySize);
    }
    for (int i =0; i<elementCount;i++){
      newArray[i] = array[i];
    }


    array = newArray;
    arraySize = newArraySize;
  };

  T* array;
  int elementCount = 0;
  int arraySize = 1;



};

#endif
