•Significant types of errors/warnings you faced when coding programs
•Whether you were able to correct these errors/warnings quickly
•What debugging strategy you used, e.g., searched the Web for a solution, contacted tutor, solved byself, used a debugging tool, posted in forum, talked to a friend, . . .
•What commenting strategy you used, eg., Javadoc or inline commenting of key methods andvariables, . . .
•What testing strategy you used, eg., JUnit, tested for typical inputs, extensively tested the code
• What code optimization techniques you followed, if any (e.g., unused local variables, parameters, and private methods; wasteful string/string buffer usage; unnecessary if statements and for loops that could be while loops; duplicate code; . . .
• Resources that you referred to (online resources, book references, discussions, . . .)
• Other comments that reflect on the process of your learning to program

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
