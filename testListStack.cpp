#include "listStack.h"
#include "catch2.hpp"

TEST_CASE("initiate empty listStack") {
  listStack<int> stack;
  REQUIRE( stack.getArraySize() == 1 );
  REQUIRE( stack.getElementCount() == 0);
  SECTION("test push(): n elements"){
    int n = 10;
    for (int i = 0 ; i<n; i++){
      stack.push(i);
    }
    REQUIRE(stack.getElementCount()==n);
  }
  SECTION("test pop(): pop an element from empty stack"){
    REQUIRE_THROWS(stack.pop());
  }
}

TEST_CASE("initiate listStack with n elemen ts") {
  listStack<int> stack;
  int n = 10;
  for (int i = 0 ; i<n; i++){
    stack.push(i);
  }

  REQUIRE( stack.getArraySize() == 16 );
  REQUIRE( stack.getElementCount() == 10);
  SECTION("test pop(): pop an element from empty stack"){
    int counter = 9;
    while(stack.getElementCount()>0){
      REQUIRE(stack.pop()==counter);
      
      counter--;
    }
  }
}
