# ADT Map (Singly Linked List)

**Implementation of a Map ADT using a Singly Linked List (SLL) with dynamic allocation.**

## ⚙️ Technical Specifications
* **Data Structure:** **Singly Linked List (SLL)** where each node is dynamically allocated.
* **Representation:** Each node in the list stores a `(key, value)` pair and a pointer to the next element.
* **Memory Management:** Manual handling of node creation and deletion to ensure zero memory leaks.
* **Constraint:** Implemented from scratch without using `std::list` or any other STL containers.

## 📈 Complexity
* **Add/Remove/Search:** $O(n)$ in the worst case, where $n$ is the number of elements in the map.
* **Iterator:** Provides a linear traversal of the map with $O(1)$ complexity for `next()` and `getCurrent()` operations.
