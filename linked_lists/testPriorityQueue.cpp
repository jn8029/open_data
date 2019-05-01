/**
  Assignment 1, Question 1.a, testPriorityQueue.cpp
  Purpose: testing the implementation of priorityQueue with singly linked list

  @author Warren Cheng
  @version 2019.05.01

  4 test cases are constructed to test the 3 methods implemented
  1. initiate empty PriorityQueue
  2. initiate PriorityQueue with 10 elements in descending order
  3. initiate PriorityQueue with 10 elements in acending order
  4. initiate PriorityQueue with 10 elements in random order
  In each test case, a sorted comparison array is used to confirm the
  implementation is correct. At the end of each test case, an additional pop()
  is called to the empty priorityQueue, which in turn should throw an exception.
*/


#include "PriorityQueue.h"
#include "../catch2.hpp"


TEST_CASE("initiate empty PriorityQueue") {
  PriorityQueue pQueue;
  REQUIRE(pQueue.size()==0);
  REQUIRE_THROWS(pQueue.deleteMin());

}

TEST_CASE("initiate PriorityQueue with 10 elements in descending orders.") {
  PriorityQueue pQueue;
  int size = 10;
  int comparisonArray[size];
  for (size_t i = size ; i > 0; i--){
    pQueue.add(i);
    comparisonArray[i-1] = i;
  }
  sort(comparisonArray, comparisonArray+size);

  SECTION("print implemented priorityQueue and comparisonArray"){
    cout<<"pQueue"<<endl;
    pQueue.print();
    cout<<"Compare"<<endl;
    for (size_t i = 0 ; i < size; i++){
      cout<<comparisonArray[i] <<'\t';
    }
    cout<<"\n------------------------------------\n";
  }
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

TEST_CASE("initiate PriorityQueue with 10 elements in ascending orders.") {
  PriorityQueue pQueue;
  int size = 10;
  int comparisonArray[size];
  for (size_t i = 0 ; i < size; i++){
    pQueue.add(i);
    comparisonArray[i] = i;
  }
  sort(comparisonArray, comparisonArray+size);

  SECTION("print implemented priorityQueue and comparisonArray"){
    INFO("pQueue")
    pQueue.print();
    INFO("comparisonArray");
    for (size_t i = 0 ; i < size; i++){
      cout<<comparisonArray[i] <<'\t';
    }
    cout<<"\n------------------------------------\n";
  }
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

TEST_CASE("initiate PriorityQueue with 10 elements in random order") {
  PriorityQueue pQueue;
  int size = 10;
  int comparisonArray[size];
  for (size_t i = 0 ; i < size; i++){
    int value = rand()%size;
    pQueue.add(value);
    comparisonArray[i] = value;
  }
  sort(comparisonArray, comparisonArray+size);

  SECTION("print implemented priorityQueue and comparisonArray"){
    cout<<"pQueue"<<endl;
    pQueue.print();
    cout<<"Compare"<<endl;
    for (size_t i = 0 ; i < size; i++){
      cout<<comparisonArray[i] <<'\t';
    }
    cout<<"\n------------------------------------\n";
  }
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
