/**
  Assignment 1, Question 2.a, testSLListWithSwap.cpp
  Purpose: test the implementation of swap function in singly linked list

  @author Warren Cheng
  @version 2019.05.01
*/
#include "slList.h"
#include "../catch2.hpp"
#include <vector>
#define SIZE 1000

TEST_CASE("initiate empty list") {
  SLList<int> list;
  REQUIRE(list.size()==0);
  REQUIRE_THROWS(list.get(0));
  REQUIRE_THROWS(list.set(0,100));
  REQUIRE_THROWS(list.swap(0));
  REQUIRE_THROWS(list.remove(1));
  list.insert(0,100);
  REQUIRE(list.size() == 1);
  REQUIRE(list.get(0) == 100);
  list.remove(0);
  REQUIRE_THROWS(list.remove(0));
}

TEST_CASE("initiate empty list and insert SIZE elements to the front"){
  SLList<int> list;
  for (int i =0; i < SIZE; i++){
    list.insert(0, i);
  }
  REQUIRE(list.size() == SIZE);

  SECTION("test insert in the middle"){
    int index = 50;
    int value_at_index = list.get(50);
    list.insert(50, 1000);
    REQUIRE(list.get(50)==1000);
    REQUIRE(list.get(51) == value_at_index);
  }
  SECTION("test get(i)"){
    for (int i =0; i < SIZE; i++){
      REQUIRE(list.get(i) == SIZE-1-i);
    }
  }
  SECTION("test set(i,x)"){
    for (int i =0; i < SIZE; i++){
      list.set(i, i*2);
    }
    for (int i =0; i < SIZE; i++){
      REQUIRE(list.get(i) == i*2);
    }
  }
  SECTION("test remove(i) at tail, head, and middle"){
    list.print();
    REQUIRE(0==list.remove(SIZE-1));
    REQUIRE_THROWS(list.get(SIZE-1));
    REQUIRE(list.remove(0)==SIZE-1);
    REQUIRE(list.get(0) == SIZE-2);
    int removed = list.remove(30);
    REQUIRE(list.get(30)+1 == removed);
  }

  SECTION("test swap(i)"){
    for (int i = 0 ; i < SIZE-1; i++){

      int front = list.get(i);
      int back = list.get(i+1);
      list.swap(i);
      REQUIRE(list.get(i) == back);
      REQUIRE(list.get(i+1) == front);

    }
  }


}
