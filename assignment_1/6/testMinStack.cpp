/**
  Assignment 1, Question 6, testMinStack.cpp
  Purpose: testing the implementation of MinStack

  @author Warren Cheng
  @version 2019.05.01
*/


#include "minStack.h"
#include "../catch2.hpp"
#include <limits>
#define SIZE 1000
int findMin(int comparisonArray[], int start, int finish){
  if (start == finish){
    return comparisonArray[start];
  }
  int min = numeric_limits<int>::max();
  for (size_t i =start; i<=finish; i++){
    if (comparisonArray[i]<min){
      min = comparisonArray[i];
    }
  }
  return min;
};

TEST_CASE("initiate empty MinStack<int>") {
  MinStack<int> mStack;
  REQUIRE(mStack.size()==0);
  REQUIRE_THROWS(mStack.min());
  REQUIRE_THROWS(mStack.pop());
}

TEST_CASE("initiate MinStack<int> with <size> elements in descending order.") {
  MinStack<int> mStack;

  int comparisonArray[SIZE];
  for (size_t i = SIZE ; i > 0; i--){
    mStack.push(i);
    comparisonArray[i-1] = i;
  }
  SECTION("test size()"){
    REQUIRE(mStack.size()==SIZE);
  }
  SECTION("test min()"){
    mStack.print();
    for (size_t i =0 ; i < SIZE; i++){
      int found_min = mStack.min();
      REQUIRE(found_min==findMin(comparisonArray, i , SIZE-1));
      mStack.pop();
    }
    REQUIRE_THROWS(mStack.min());
  }
}

TEST_CASE("initiate MinStack<int> with <size> elements in ascending orders.") {
  MinStack<int> mStack;
  int comparisonArray[SIZE];
  for (size_t i = 0 ; i < SIZE; i++){
    mStack.push(i);
    comparisonArray[i] = i;
  }

  SECTION("test size()"){
    REQUIRE(mStack.size()==SIZE);
  }
  SECTION("test min()"){
    for (size_t i =0 ; i < SIZE; i++){
      int min= mStack.min();
      REQUIRE(min==findMin(comparisonArray, 0 , SIZE-1-i));
      mStack.pop();
    }
    REQUIRE_THROWS(mStack.pop());
  }
}

TEST_CASE("initiate MinStack<int> with <size> elements in random order") {
  MinStack<int> mStack;
  int comparisonArray[SIZE];
  for (size_t i = 0 ; i < SIZE; i++){
    const int range_from  = 0;
    const int range_to  = SIZE;
    random_device rand_dev;
    mt19937 generator(rand_dev());
    uniform_int_distribution<int> distro(range_from, range_to);
    int value = distro(generator);

    mStack.push(value);
    comparisonArray[i] = value;
  }

  SECTION("test size()"){
    REQUIRE(mStack.size()==SIZE);
  }
  SECTION("test min()"){
    for (size_t i =0 ; i < SIZE; i++){
      int min= mStack.min();
      REQUIRE(min==findMin(comparisonArray, 0 , SIZE-1-i));
      mStack.pop();
    }
    REQUIRE_THROWS(mStack.pop());
  }
}
