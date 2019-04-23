#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdlib.h>
#include <iostream>
using namespace std;

template <typename T>
class arrayList{
public:

  arrayList(){
    array = (T*)malloc(sizeof(T)*arraySize);
  };

  T get(size_t index){
    if (index>=elements_in_array){
      throw("get: index out of range;");
    }
    return array[index];
  };

  void set(int index, T value){
  
    if (index>=arraySize){
      throw("set: index out of range;");
    }
    array[index] = value;
  }

  void add(int index, T value){

    grow();
    for (int i = elements_in_array; i>index;i--){
      array[i] = get(i-1);
    }

    set(index, value);

    elements_in_array++;
  };

  T remove(int index){
    if (index>=elements_in_array){
      throw("remove: index out of range;");
    } else {
      shrink();
      T element = get(index);
      for (size_t i = index; i<elements_in_array-1;i++){
        array[i] = get(i+1);
      }
      elements_in_array--;
      return element;
    }
  };

  int getElementCount(){
    return elements_in_array;
  };;

  int getArraySize(){
    return arraySize;
  };

  void printAll(){
    for (size_t i =0 ; i<elements_in_array; i++){
      cout << get(i) <<"\t";
    }
    cout<<endl;
  };

private:
  int arraySize = 1;
  int elements_in_array = 0;
  T* array;
  void shrink(){
    T* new_array;
    if (arraySize > elements_in_array*3){
      new_array = (T*)malloc(arraySize/2*sizeof(T));
      arraySize = arraySize/2;
    } else{
      return;
    }
    for (size_t i = 0 ; i < elements_in_array ; i++){
      new_array[i] = get(i);
    }


  }
  void grow(){
    T* new_array;
    if (arraySize < elements_in_array+1){
      new_array = (T*)malloc(arraySize*2*sizeof(T));
      arraySize = arraySize*2;
    } else {
      return;
    }

    for (size_t i = 0 ; i < elements_in_array ; i++){
      new_array[i] = get(i);
    }
    array = new_array;
  };

};

#endif
