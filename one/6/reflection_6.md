## MinStack Data Structure

I implemented the MinStack data structure with 2 ArrayStacks, which are implemented with an array. The ArrayStack's push and pop methods run in constant time because the methods always add and remove items from the end of the array, and therefore no element shifting is needed and the resize method runs on amortized O(1) time, as described in the textbook. The testing of the arrayStack is identical to the testing of the DualQueueStack because the interface is identical, except for the additional method top() that allows users to quickly see what's the next item to be popped without actually popping it.


## The min() Method
In order to achieve O(1) for the min() method. A complete traversal of the stack is not acceptable.

Therefore I used 2 stacks. One stack is for the items that are pushed (let's call it stack1), and the other is used for keeping track of the minimums (let's call it stack2).

Let's call the MinStack stack0.  When stack0's push method is called, the item is checked against the top item in stack2, and if the item to be pushed  is smaller than the top item in stack2 or when stack2 is empty, we push the item to both stack1 and stack2.

When stack0's pop is called, we call stack1's pop and compare the value with the top item of stack2. If the popped value is the same as top item of stack2, we call pop on stack2 too.

This way we can keep track of the min value without a complete traversal of stack1, and the min method can retrieve the minimum value from the top of stack2 at constant time.

##  Testing the min() Method
