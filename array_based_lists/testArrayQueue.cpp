#include "arrayQueue.h"
#include "catch2.hpp"

TEST_CASE("initiate empty Queue") {
  arrayQueue<int> queue;

  SECTION("test add(): n elements"){
    int n = 10;
    for (int i = 0 ; i<n; i++){
      queue.add(i);
    }


  }
  SECTION("test remove(): remove an element from empty queue"){
    REQUIRE_THROWS(queue.remove());
  }
}

TEST_CASE("initiate Queue with n elements") {
  arrayQueue<int> queue;
  int n = 10;
  for (int i = 0 ; i<n; i++){
    queue.add(i);
  }


  SECTION("test remove(): remove n elements from queue"){
    for (int i = 0 ; i<n; i++){
      REQUIRE(queue.remove() == i);
    }
  }
}
