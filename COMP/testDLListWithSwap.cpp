/**
  Assignment 1, Question 2.a, testDLList<int> WithSwap.cpp
  Purpose: test the implementation of swap function in singly linked list

  @author Warren Cheng
  @version 2019.05.01
*/
#include "DLList.h"
#include "../catch2.hpp"
#include <vector>
TEST_CASE("initiate empty list") {
  DLList<int>  list;
  REQUIRE(list.size()==0);
  REQUIRE_THROWS(list.get(0));
  REQUIRE_THROWS(list.swap(0));
}
TEST_CASE("initiate list with 10 elements added to the front") {
  DLList<int>  list;
  REQUIRE(list.size()==0);
  REQUIRE_THROWS(list.get(0));
  int count = 10;
  for (size_t i=0; i< count; i++){
    list.insert(0,i);
  }
  SECTION("swap (0,1), (5,6), (8,9)"){
    vector<int> toSwap{0,5,8};
    list.print();
    for (auto swapIndex: toSwap){
      cout << "swapping index: "<< swapIndex << " and "<<swapIndex+1<<endl;
      int swapFront = list.get(swapIndex);
      int swapBack = list.get(swapIndex+1);
      list.swap(swapIndex);
      list.print();
      REQUIRE(list.get(swapIndex)==swapBack);
      REQUIRE(list.get(swapIndex+1)==swapFront);
    }
  }
  SECTION("swap index expecting exceptions"){
    REQUIRE_THROWS(list.swap(9));
    REQUIRE_THROWS(list.swap(100));
  }
}
