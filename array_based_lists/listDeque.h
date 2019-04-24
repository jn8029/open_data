#ifndef LISTDEQUE_H
#define LISTDEQUE_H
#include "arrayListBetter.h"


template <typename T>
class listDeque: public arrayListBetter<T>{
public:
  void pushFront(T value){
    arrayListBetter<T>::add(0, value);
  }
  T popFront(){
    if (arrayListBetter<T>::getElementCount()==0){
      throw("Deque is empty.");
    }
    T value = arrayListBetter<T>::remove(0);
    return value;
  }
  void pushBack(T value){
    arrayListBetter<T>::add(arrayListBetter<T>::getElementCount(), value);
  }
  T popBack(){
    if (arrayListBetter<T>::getElementCount()==0){
      throw("Deque is empty.");
    }
    T value = arrayListBetter<T>::remove(arrayListBetter<T>::getElementCount()-1);
    return value;
  }

};

#endif
