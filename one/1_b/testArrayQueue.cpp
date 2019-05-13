/**
  Assignment 1, Question 1.b, testArrayQueue.cpp
  Purpose: testing the implementation of an array based queue

  @author Warren Cheng
  @version 2019.05.01
*/
#include "arrayQueue.h"
#include "../catch2.hpp"

#define SIZE 1000

TEST_CASE("initiate empty Queue") {
  ArrayQueue<int> queue;
  REQUIRE(queue.size()==0);
  REQUIRE_THROWS(queue.dequeue());

}

TEST_CASE("initiate Queue with n elements") {
  ArrayQueue<int> queue;

  for (int i = 0 ; i<SIZE; i++){
    queue.enqueue(i);
  }
  SECTION("test dequeue(): dequeue n elements from queue"){
    for (int i = 0 ; i<SIZE; i++){
      REQUIRE(queue.dequeue() == i);
    }
    REQUIRE_THROWS(queue.dequeue());
  }
}
