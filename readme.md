<!-- g++ test-main.o arrayList.cpp -o tests && tests -r console
g++ -std=c++14 *.cpp  -->
## class arrayList

```arrayList``` is a array based list data structure that implements:

| Public Function      | big-O         |
| :-: |:-:|
| get(i)     | O(1)|
| set(i,x)     | O(1)      |  
| add(i,x) | O(n)      |   
| remove(i) | O(n)      |

The O(n) of the ```add``` and ```remove``` stems from element shifting. i.e. when ```add(i,x)``` is called, every element from index i to the last element in the list will be shifted backward by one position; when remove(i) is called, every element from index i+1 to the last element in the list will be shifted forward by one position.

The resizing of the array runs at O(1) (amortized)

| Private Function      | big-O         |
| :-: |:-:|
| grow()|O(1)|
| shrink()|O(1)|


## class listStack
```listStack``` is a list based data structure that implements below function on a LIFO(last-in-first-out) basis.

| Public Function      | big-O         |
| :-: |:-:|
| push(x)     | O(1)|
| pop()     | O(1)      |  
