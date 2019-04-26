#include "SLQueue.h"
#include "../catch2.hpp"

TEST_CASE("initiate empty Queue") {
  SLQueue<int> queue;

  SECTION("test push(): n elements"){
    int n = 10;
    for (int i = 0 ; i<n; i++){
      queue.push(i);
    }



  }
  SECTION("test pop(): remove an element from empty queue"){
    REQUIRE_THROWS(queue.pop());
  }
}

TEST_CASE("initiate Queue with n elements") {
  SLQueue<int> queue;
  int n = 10;
  for (int i = 0 ; i<n; i++){
    queue.push(i);
  }


  SECTION("test pop(): remove n elements from queue"){
    for (int i = 0 ; i<n; i++){
      REQUIRE(queue.pop() == i);
    }
  }
}
