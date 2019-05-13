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
