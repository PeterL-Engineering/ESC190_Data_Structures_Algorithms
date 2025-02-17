// Worked in test_mystr.c

/* Abstract Data Types

Any collection of values together with operations on those values Eg:
  int wiht operations + - * / %
  lists with operations "insert, remove, get"

An ADT specifies what values are represented and what operations can be 
performed, but not how to store the values or how to do operations

ADTs are improtant for specificationL they provide modularity and reuse
ie. usage is independent of implementation

A "Data structure" is an implementation of an ADT ie. a way to represent
the values and algorithms for the operations



Lists is an ordered collection of data items that supports the following operations:
    insert(list, i, x): add item x at index i of list.
    remove(list, i): remove the item at index i in list
    get(list, i): return the item at index i in list.

For implementing the list ADT (get, insert, remove)
Considerations:
    1. Speed/complexity
    2. Space
    3. Easy of implementation/use

(10, 12, 45, 12, 20, 125)

Complexity of Remove element at index i is O(n) (n is size of list)
Because in the worst case, we have to remove i = 0, and shift everything over

Space requirement for block-of-memory implementation?
n*sizeof(int) so O(n)

Compleixty of Insert at index i?
O(n) (need to move n-i elements to the right) but really O(n)

Complexity of Get at index i?
O(1) you just have to get the element

Linked list: eg data is 5, 10, 2 it will be stored as
1000 next 3000 
1020 data 5
2000 next NULL
2020 data 2
3000 next 2000
3020 data 10
5 -> 10 -> 2 (linked list starts at next = 1000 and ends at NULL)
*/


