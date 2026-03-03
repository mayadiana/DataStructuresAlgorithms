# ADT SortedMultiMap (SLLA)

**Implementation of a SortedMultiMap using a Singly Linked List on Array (SLLA).**

## ⚙️ Technical Specifications
* **Data Structure:** **Singly Linked List on Array (SLLA)**.
* **Representation:** Uses a dynamic array to store elements and a "next" array to manage links between nodes, simulating pointers with indices.
* **MultiMap Capability:** A single key can be associated with multiple values, stored as separate `(key, value)` pairs ordered by a custom relation on keys.
* **Memory Management:** Manual management of a "Free List" within the array to handle empty slots efficiently.

## 📈 Complexity
* **Add/Remove/Search:** $O(n)$ where $n$ is the number of pairs.
* **Space Efficiency:** Fixed memory overhead for links within the dynamic array, avoiding multiple small heap allocations.
