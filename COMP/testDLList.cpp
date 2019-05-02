#include "DLList.h"
#include "../catch2.hpp"

TEST_CASE("initiate empty DLList") {
  DLList<int> dlList;
  REQUIRE(dlList.size()==0);
  REQUIRE_THROWS(dlList.get(0));
  REQUIRE_THROWS(dlList.swap(0));
}

TEST_CASE("initiate DLList with n elements") {
  DLList<int> dlList;
  int n = 10;
  for (int i = 0 ; i<n; i++){
    dlList.add(i,i);
  }

  SECTION("test swap()"){
    dlList.print();
    for(size_t i =0; i <dlList.size()-1; i++){
      cout << "swapping index "<<i <<" and "<<i+1<<endl;
      dlList.swap(i);
      dlList.print();
    }

  }
}
