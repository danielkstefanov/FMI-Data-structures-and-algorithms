#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// Queue - ADT with the following operations (push, pop, peek) FIFO
//		peek - returns the value of the first added element. 
//		pop - removes the first added element.
//		push - add element to the collection
// 
//	real implementation by - Linked List, Circular array
// 
// 
// Stack - ADT -||-
//		peek - get the value of the last added element
//		pop - removes the last added element
//		push - add element to the collection
// 
// real implementation by - Linked List, dynamic array
// 
//	
// Deque - ADT which works like a double ended quque with the operations
//	(pop_front, peek_front, pop_front, peek_back, pop_back, push_back)
//
// Monotonic stack - a stack in which if we want to push some new element which 
//	breaks the monotonic rule we just remove them.
// d
//