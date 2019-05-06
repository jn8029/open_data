#ifndef LISTSTACK_H
#define LISTSTACK_H
#include "arrayList.h"

template <typename T>
class listStack: public arrayList<T>{
public:
  void push(T value){
    arrayList<T>::add(arrayList<T>::getElementCount(), value);
  }
  T pop(){
    return arrayList<T>::remove(arrayList<T>::getElementCount()-1);
  }
  T top(){
    return arrayList<T>::get(arrayList<T>::getElementCount()-1);
  }
  int size(){
    return arrayList<T>::getElementCount();
  }

};

#endif
