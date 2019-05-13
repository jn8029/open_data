#ifndef SLLIST_H
#define SLLIST_H

#include "skipList.h"
#include "arrayList.h"
#include <iostream>

using namespace std;



class USet: public skipList{
public:
  USet():skipList(100){}
  bool add(int value){
    skipList::insert(value);
    return true;
  }
  int remove(int value){
    return skipList::remove(value);
  }
  int find(int value){
    if (skipList::exists(value)){
        return value;
    } else {
      throw out_of_range("find: element not found.");
    }
  }
  arrayList<int> findAll(int value){
    if (skipList::exists(value)){
      arrayList<int> list;
      Node* node = skipList::findSmaller(value);
      while (node->next[0] && node->next[0]->value==value){
        list.add(0,node->next[0]->value);
        node = node->next[0];
      }
      return list;
    } else {
      throw out_of_range("findAll: element not found.");
  }
}

};


#endif
