/**
  Assignment 1, Question 4, testRandomQueue.cpp
  Purpose: testing the implementation of a randomQueue

  @author Warren Cheng
  @version 2019.05.01
*/
#include "randomQueue.h"
#include "../catch2.hpp"

#define SIZE 1000

TEST_CASE("initiate empty Queue") {
  RandomQueue<int> queue;
  REQUIRE(queue.size()==0);
  REQUIRE_THROWS(queue.remove());

}

TEST_CASE("initiate Queue with n elements") {
  RandomQueue<int> queue;

  for (int i = 0 ; i<SIZE; i++){
    queue.add(i);
  }
  SECTION("test dequeue(): dequeue n elements from queue"){
    for (int i = 0 ; i<SIZE; i++){
      queue.remove();
    }
    REQUIRE_THROWS(queue.remove());
  }
}
