## Queue data structure

The implementation is identical to the one implemented in question 1.b's "RandomQueue.h" except for the random nature of the remove method.

the add(x) method is the same as the enqueue method in question 1.b's "RandomQueue.h" and it runs at constant time O(1) because a circular array is used and it is always adding items to the end of the array, and therefore no shifting elements is needed.

the remove() method runs in constant time too because the item on the random index is swapped with the item at the end of the array container first, and then the item at the end of array container is removed. Swapping two items runs in constant time and removing an item from the end of the array runs in constant time, so the remove() method runs in constant time.

## Uniformly At Random
I initially implemented the remove() method with the rand() function with % size, but the modulo here makes the result non uniformly at random.

int src = rand(); // assume uniform [0, 32767]
int dst = src % 100; // non uniform [0-99]
when src is in [0,99], dst = [0,99],
when src is in [100, 199], dst = [0, 99],
etc...
BUT when src is in [32700, 32767], dst = [0, 67]
Because input range is not exact multiple of output range, modulo makes the result non uniformly at random.

This concept is explained in a stackoverflow thread:
https://stackoverflow.com/questions/288739/generate-random-numbers-uniformly-over-an-entire-range

and I used the recommended method in my implementation.

## Testing randomQueue

Please refer to testRandomQueue.cpp for the tests.

I used the unit testing framework "Catch2" to test my codes.
2 test cases are constructed to test the methods.

1. initiate an empty RandomQueue
2. initiate RandomQueue with 1000 elements, and then dequeue all.


At the end of each test case, an additional dequeue()
is called to the empty RandomQueue, which in turn should throw an exception.

test result output:
All tests passed (3 assertions in 2 test cases)

You can compile the tests with g++:

g++ ../test-main.o testRandomQueue.cpp -o tests && tests -s



## Interactive RadnomQueue

I have implemented a command line interface for users to interactively test the RandomQueue. Please refer to interactiveRandomQueue.cpp
