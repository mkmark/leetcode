# priority queue

https://www.programiz.com/dsa/priority-queue
https://en.cppreference.com/w/cpp/container/priority_queue

## scene

```cpp
#include <queue>        // std::priority_queue
priority_queue<T> pq;
pq.push(value);         // add element to a set, $O(log(n))$
pq.top();               // get the largest element of the set, $O(1)$
pq.pop();               // remove the largest element of the set, $O(log(n))$
```

## mechnism

A binary tree of unordered set, where each parent is always larger than its childs - heapified.

### void push(T value)

Append element to the end node. Swap with parent until heapified. $O(log(n))$.

### void top()

Get the top node. $O(1)$.

### void pop()

Remove the top node. Append the smaller child to the larger child, swap until heapified. $O(log(n))$.
