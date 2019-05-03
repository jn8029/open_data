#include "arrayQueue.h"
#include "../catch2.hpp"

TEST_CASE("initiate empty Queue") {
  arrayQueue<int> queue;
  SECTION("test enqueue(): n elements"){
    int n = 10;
    for (int i = 0 ; i<n; i++){
      queue.enqueue(i);
    }
  }
  SECTION("test dequeue(): dequeue an element from empty queue"){
    REQUIRE_THROWS(queue.dequeue());
  }
}

TEST_CASE("initiate Queue with n elements") {
  arrayQueue<int> queue;
  int n = 10;
  for (int i = 0 ; i<n; i++){
    queue.enqueue(i);
  }


  SECTION("test dequeue(): dequeue n elements from queue"){
    for (int i = 0 ; i<n; i++){
      REQUIRE(queue.dequeue() == i);
    }
    queue.enqueue(10);
    REQUIRE(queue.dequeue() == 10);
  }
}
TEST_CASE("enqueue 1 and dequeue 1") {
  arrayQueue<int> queue;
  queue.enqueue(1);
  REQUIRE(queue.dequeue()==1);
  queue.enqueue(1);

}
