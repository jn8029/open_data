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

};

#endif
