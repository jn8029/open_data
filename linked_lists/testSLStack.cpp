#include "SLStack.h"
#include "../catch2.hpp"



TEST_CASE("initiate empty SLStack") {
  SLStack<int> stack;
  SECTION("test push(): n elements"){
    int n = 10;
    for (int i = 0 ; i<n; i++){
      stack.push(i);
    }
  stack.printAll();
    REQUIRE(stack.getElementCount()==n);
  }
  SECTION("test pop(): pop an element from empty stack"){
    REQUIRE_THROWS(stack.pop());
  }
}

TEST_CASE("initiate SLStack with n elements") {
  SLStack<int> stack;
  int n = 10;
  for (int i = 0 ; i<n; i++){
    stack.push(i);
  }
  stack.printAll();
  REQUIRE( stack.getElementCount() == 10);
  SECTION("test pop(): pop an element from empty stack"){
    int counter = 9;
    while(stack.getElementCount()>0){
      REQUIRE(stack.pop()==counter);
      counter--;
    }
  }
}
