/**
  Assignment 2, Question 4, test.cpp
  Purpose: implement a hashtable with linear probing, test with inserting elements specified by the assignment 2.
  @author Warren Cheng
  @version 2019.06.05
*/
#include "hashTable.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
  HashTable tb;
  int size = 15;
  int insertions[] = {1, 5, 21, 26, 39, 14, 15, 16, 17, 18, 19, 20, 111, 145, 146};
  for (size_t i =0 ; i <size;i++){
    tb.insert(insertions[i]);
  }
  int test;

  cout<<test<<endl;
}
