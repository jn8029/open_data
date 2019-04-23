#include "arrayList.h"
#include <assert.h>
#include "../catch2.hpp"

TEST_CASE("Initiate arrayList") {
    arrayList<int> list;
    REQUIRE( list.getArraySize() == 1 );
    REQUIRE( list.getElementCount() == 0);

}
