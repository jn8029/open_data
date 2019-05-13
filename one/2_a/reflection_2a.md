## Implementing swap()
When swapping nodes on index and index + 1, pointers in 3 nodes need to be redirected: the node on index, the node on index-1 and the node on index+1.

I encountered a bug which revealed itself when I printed the whole list after  calling swap. I later found that when swapping index = 0 and index = 1, the head pointer needs to be updated.

I also made the decision to implement the function in a way that it takes only one argument integer index, and the swap method will swap nodes on index and index+1. This way is better than taking 2 indices and having to check whether the two indices are adjacent.



## Testing SLList

Please refer to testSLListWithSwap.cpp for the tests.

I used the unit testing framework "Catch2" to test my codes.
2 test cases are constructed to test the methods.

1. initiate an empty SLList and test all methods, especially those that are meant to throw exceptions when operating on an empty list.
2. initiate ArrayQueue with 1000 elements, and then test all methods, including swap.


test result output:
All tests passed (4018 assertions in 2 test cases)

You can compile the tests with g++:

g++ ../test-main.o testSLListWithSwap.cpp -o tests && tests -s


## Interactive SLList

I have implemented a command line interface for users to interactively test the SLList. Please refer to interactiveSLListWithSwap.cpp
