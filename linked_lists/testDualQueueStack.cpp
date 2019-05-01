/**
  Assignment 1, Question 1.b, DualQueueStack.cpp
  Purpose: testing the implementation of a stack with two queues

  @author Warren Cheng
  @version 2019.05.01
  3 test cases are constructed.
  1. initiate empty stack, test size() and pop()
  2. initiate PriorityQueue with 10 elements
  3. initiate PriorityQueue, push 4 items, pop 3 items, push 2 items, pop 3 items

  At the end of each test case, an additional pop()
  is called to the empty stack, which in turn should throw an exception.
*/
#include "DualQueueStack.h"
#include "../catch2.hpp"
using namespace std;


TEST_CASE("initiate empty DualQueueStack") {
  DualQueueStack stack;
  REQUIRE(stack.size()==0);
  REQUIRE_THROWS(stack.pop());

}
TEST_CASE("initiate DualQueueStack with n elements") {
  DualQueueStack stack;
  int n = 10;
  for (int i = 0 ; i<n; i++){
    stack.push(i);
  }
  REQUIRE(stack.size() == 10);

  SECTION("test pop(): pop all elements from empty stack"){
    int counter = 9;
    while(stack.size()>0){
      REQUIRE(stack.pop()==counter);
      counter--;
    }
    REQUIRE(stack.size() == 0);
    REQUIRE_THROWS(stack.pop());
  }
}

TEST_CASE("mixing push and pop") {
  DualQueueStack stack;
  stack.push(1);
  stack.push(1);
  stack.push(1);
  stack.push(1);
  REQUIRE(stack.pop()==1);
  REQUIRE(stack.pop()==1);
  REQUIRE(stack.pop()==1);
  stack.push(100);
  stack.push(100);
  REQUIRE(stack.pop()==100);
  REQUIRE(stack.pop()==100);
  REQUIRE(stack.pop()==1);
  REQUIRE_THROWS(stack.pop());

}
