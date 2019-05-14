/**
  Assignment 1, Question 6, testArrayStack.cpp
  Purpose: testing the implementation of a stack with array.

  @author Warren Cheng
  @version 2019.05.01
*/
#include "ArrayStack.h"
#include "../catch2.hpp"
using namespace std;

#define SIZE 1000

TEST_CASE("initiate empty ArrayStack<int>") {
  ArrayStack<int> stack;
  REQUIRE(stack.size()==0);
  REQUIRE_THROWS(stack.pop());
}
TEST_CASE("initiate ArrayStack<int> with n elements") {
  ArrayStack<int> stack;

  for (int i = 0 ; i<SIZE; i++){
    stack.push(i);
  }
  REQUIRE(stack.size() == SIZE);
  REQUIRE(stack.top() == SIZE-1);

  SECTION("test pop(): pop all elements from empty stack"){
    int counter = SIZE-1;
    while(stack.size()>0){
      REQUIRE(stack.pop()==counter);
      counter--;
    }
    REQUIRE(stack.size() == 0);
    REQUIRE_THROWS(stack.pop());
    REQUIRE_THROWS(stack.top());
  }
}

TEST_CASE("mixing push and pop") {
  ArrayStack<int> stack;
  stack.push(1);
  stack.push(1);
  stack.push(1);
  stack.push(1);
  REQUIRE(stack.top()==1);
  REQUIRE(stack.size()==4);
  REQUIRE(stack.pop()==1);
  REQUIRE(stack.pop()==1);
  REQUIRE(stack.pop()==1);
  REQUIRE(stack.size()==1);
  stack.push(100);
  stack.push(100);
  REQUIRE(stack.top()==100);
  REQUIRE(stack.size()==3);
  REQUIRE(stack.pop()==100);
  REQUIRE(stack.pop()==100);
  REQUIRE(stack.pop()==1);
  REQUIRE(stack.size()==0);
  REQUIRE_THROWS(stack.pop());
  REQUIRE_THROWS(stack.top());

}
