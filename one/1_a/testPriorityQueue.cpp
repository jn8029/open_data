/**
  Assignment 1, Question 1.a, testPriorityQueue.cpp
  Purpose: testing the implementation of priorityQueue with singly linked list

  @author Warren Cheng
  @version 2019.05.01
*/


#include "priorityQueue.h"
#include "../catch2.hpp"
int size = 1000;

TEST_CASE("initiate empty PriorityQueue") {
  PriorityQueue pQueue;
  REQUIRE(pQueue.size()==0);
  REQUIRE_THROWS(pQueue.deleteMin());
}

TEST_CASE("initiate PriorityQueue with <size> elements in descending orders.") {
  PriorityQueue pQueue;

  int comparisonArray[size];
  for (size_t i = size ; i > 0; i--){
    pQueue.add(i);
    comparisonArray[i-1] = i;
  }
  sort(comparisonArray, comparisonArray+size);
  SECTION("test size()"){
    REQUIRE(pQueue.size()==size);
  }
  SECTION("test deleteMin()"){
    for (size_t i =0 ; i < size; i++){
      int popped = pQueue.deleteMin();
      REQUIRE(popped==comparisonArray[i]);
    }
    REQUIRE_THROWS(pQueue.deleteMin());
  }
}

TEST_CASE("initiate PriorityQueue with <size> elements in ascending orders.") {
  PriorityQueue pQueue;
  int comparisonArray[size];
  for (size_t i = 0 ; i < size; i++){
    pQueue.add(i);
    comparisonArray[i] = i;
  }
  sort(comparisonArray, comparisonArray+size);


  SECTION("test size()"){
    REQUIRE(pQueue.size()==size);
  }
  SECTION("test deleteMin()"){
    for (size_t i =0 ; i < size; i++){
      int popped = pQueue.deleteMin();
      REQUIRE(popped==comparisonArray[i]);
    }
    REQUIRE_THROWS(pQueue.deleteMin());
  }
}

TEST_CASE("initiate PriorityQueue with <size> elements in random order") {
  PriorityQueue pQueue;
  int comparisonArray[size];
  for (size_t i = 0 ; i < size; i++){
    int value = rand()%size;
    pQueue.add(value);
    comparisonArray[i] = value;
  }
  sort(comparisonArray, comparisonArray+size);


  SECTION("test size()"){
    REQUIRE(pQueue.size()==size);
  }
  SECTION("test deleteMin()"){
    for (size_t i =0 ; i < size; i++){
      int popped = pQueue.deleteMin();
      REQUIRE(popped==comparisonArray[i]);
    }
    REQUIRE_THROWS(pQueue.deleteMin());
  }
}
