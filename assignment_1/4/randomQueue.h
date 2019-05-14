#ifndef RQUEUE_H
#define RQUEUE_H

#include <iostream>
#include <limits>
#include <random>
using namespace std;

template <typename T>
class RandomQueue {
public:
  RandomQueue(){
    array = (T*)malloc(sizeof(T)*arraySize);
  }
  void add(T value){

    if (elementCount+1 > arraySize){
      resize(1);
    }
    array[elementCount] = value;
    elementCount++;

  }
  T remove(){
    if(elementCount==0){
      throw out_of_range("remove: Queue is empty.");
    }

    int randomIndex =getRandomIndex();
    cout << "random index = "<<randomIndex<<endl;
    T toRemove = array[randomIndex];
    array[randomIndex] = array[elementCount-1];

    elementCount--;
    if(arraySize >= 3*elementCount){
      resize(0);
    }
    return toRemove;
  }
  int size(){
    return elementCount;
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
  int getRandomIndex(){
    const int range_from  = 0;
    const int range_to   = elementCount-1;
    random_device rand_dev;
    mt19937 generator(rand_dev());
    uniform_int_distribution<int> distro(range_from, range_to);
    return distro(generator);
  }

private:

  void resize(int grow){
    T* newArray;
    int newArraySize;
    if (grow){
      newArray =(T*)malloc(sizeof(T)*arraySize*2);
      newArraySize = arraySize*2;
    } else {
      //special case: check if new array size is 0, min should be 1.
      newArraySize = arraySize/2;
      if (newArraySize==0){
        newArraySize=1;
      }
      newArray =(T*)malloc(sizeof(T)*newArraySize);
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
