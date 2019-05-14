# 1.a


## Writing the deleteMin Method

When implementing deleteMin, I initially tried to implement a private findMin method, but then I figured in a singly-linked list I had to actually find the node before the min node so that I can redirect the pointers corrently.

I also encountered a bug in the edge case where the head node is the min node itself. In this case updating the head node is necessary.

## Testing
Please refer to testPriorityQueue.cpp for the tests.

I used the unit testing framework "Catch2" to test my codes.
4 test cases are constructed to test the 3 methods.

1. initiate an empty PriorityQueue
2. initiate PriorityQueue with 1000 elements in descending order
3. initiate PriorityQueue with 1000 elements in ascending order
4. initiate PriorityQueue with 1000 elements in random order

In each test case, a sorted comparison array is used to confirm the
implementation is correct.

At the end of each test case, an additional pop()
is called to the empty priorityQueue, which in turn should throw an exception.

test result output:
All tests passed (3008 assertions in 4 test cases)

You can compile the tests with g++:

g++ ../test-main.o testPriorityQueue.cpp -o tests && tests -s

I have placed the pre-compiled catch2 object in the root folder of this assignment.

## Interactive Priority Queue

I have implemented a command line interface for users to interactively test the priority queue. Please refer to interactivePriorityQueue.cpp

# 1.b

## ArrayQueue

A circular array is used to implement the arrayQueue so that the enqueue() and dequeue() methods can run at constant time. I specifically used the verb enqueue and dequeue for the methods because they are better representation of the methods than the add and remove verbs used in the textbook. Since items are added and removed from the two ends of the array, there's no element shifting needed.

## Testing ArrayQueue

Please refer to testArrayQueue.cpp for the tests.

I used the unit testing framework "Catch2" to test my codes.
2 test cases are constructed to test the methods.

1. initiate an empty ArrayQueue
2. initiate ArrayQueue with 1000 elements, and then dequeue all.


At the end of each test case, an additional dequeue()
is called to the empty arrayQueue, which in turn should throw an exception.

test result output:
All tests passed (1003 assertions in 2 test cases)

You can compile the tests with g++:

g++ ../test-main.o testArrayQueue.cpp -o tests && tests -s

## DualQueueStack

When implementing the pop() method, all elements are dequeued from q1 and enqueued in q2, except for the last item in q1. I intentionally redirect the pointers of q2 and q1 so that q1 again becomes the queue that contains element. This way I do not need to check which queue is the right one to use when implementing the push(x) method.

## Testing DualQueueStack  

Please refer to testDualQueueStack.cpp for the tests.

I used the unit testing framework "Catch2" to test my codes.
3 test cases are constructed to test the 2 methods.

1. initiate an empty DualQueueStack
2. initiate DualQueueStack  with 1000 elements, and then dequeue all.
3. mixing push(x) and pop().


At the end of each test case, an additional pop()
is called to the empty DualQueueStack, which in turn should throw an exception.

test result output:
All tests passed (1016 assertions in 2 test cases)

You can compile the tests with g++:

g++ ../test-main.o testDualQueueStack.cpp -o tests && tests -s


## Interactive DualQueueStack

I have implemented a command line interface for users to interactively test the DualQueueStck. Please refer to interactiveDualQueueStack.cpp

# 2.a

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

# 2.b

## Implementing swap()
When swapping nodes on index and index + 1, pointers in 4 nodes need to be redirected: the node on index, the node on index-1, the node on index+1 and the node on index+2.

I encountered a bug which revealed itself when I printed the whole list after  calling swap. I later found that when swapping index = 0 and index = 1, the head pointer needs to be updated.


## Testing DLList

Please refer to testDLListWithSwap.cpp for the tests.

The tests are identical to SLList since the interfaces are the same.

I used the unit testing framework "Catch2" to test my codes.
2 test cases are constructed to test the methods.

1. initiate an empty DLList and test all methods, especially those that are meant to throw exceptions when operating on an empty list.

2. initiate DLList with 1000 elements, and then test all methods, including swap.


test result output:
All tests passed (4018 assertions in 2 test cases)

You can compile the tests with g++:

g++ ../test-main.o testDLListWithSwap.cpp -o tests && tests -s


## Interactive DLList

I have implemented a command line interface for users to interactively test the DLList. Please refer to interactiveDLListWithSwap.cpp

# 4
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

# 6

## MinStack Data Structure

I implemented the MinStack data structure with 2 ArrayStacks, which are implemented with an array. The ArrayStack's push and pop methods run in constant time because the methods always add and remove items from the end of the array, and therefore no element shifting is needed and the resize method runs on amortized O(1) time, as described in the textbook. The testing of the arrayStack is identical to the testing of the DualQueueStack because the interface is identical, except for the additional method top() that allows users to quickly see what's the next item to be popped without actually popping it.


## The min() Method
In order to achieve O(1) for the min() method. A complete traversal of the stack is not acceptable.

Therefore I used 2 stacks. One stack is for the items that are pushed (let's call it stack1), and the other is used for keeping track of the minimums (let's call it stack2).

Let's call the MinStack stack0.  When stack0's push method is called, the item is checked against the top item in stack2, and if the item to be pushed  is smaller than the top item in stack2 or when stack2 is empty, we push the item to both stack1 and stack2.

When stack0's pop is called, we call stack1's pop and compare the value with the top item of stack2. If the popped value is the same as top item of stack2, we call pop on stack2 too.

This way we can keep track of the min value without a complete traversal of stack1, and the min method can retrieve the minimum value from the top of stack2 at constant time.

##  Testing the min() Method

Please refer to testMinStack.cpp for the tests.

I used the unit testing framework "Catch2" to test my codes.
2 test cases are constructed to test the methods.

1. initiate an empty MinStack
2. initiate MinStack with 1000 elements in  descending  order.
3. initiate MinStack with 1000 elements in ascending order.
4. initiate MinStack with 1000 uniformly random elements


In tests 2 and 3, a comparisonArray is used and a simple findMin function is implemented to traverse the comparisonArray and find the minimum. This way we can compare whether my implementation of min in the MinStack is working correctly.



test result output:
All tests passed (3009 assertions in 4 test cases)

You can compile the tests with g++:

g++ ../test-main.o testMinStack.cpp -o tests && tests -s

## Interactive MinStack

I have implemented a command line interface for users to interactively test the MinStack. Please refer to interactiveMinStack.cpp
