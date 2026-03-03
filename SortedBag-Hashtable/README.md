# ADT SortedBag (Hashtable)

**Implementation of a SortedBag using a Hashtable with Coalesced Chaining.**

## ⚙️ Technical Specifications
* **Collision Resolution:** Uses **Coalesced Chaining** (handling collisions by finding the next empty slot in the table).
* **Dynamic Resizing:** The table automatically rehashes all elements when the load factor threshold is exceeded to maintain performance.
* **Order:** Maintains elements based on a custom sorting relation.
* **Constraint:** No STL containers used for the internal representation.

## 📈 Complexity
* **Add/Remove/Search:** $O(1)$ on average; $O(m)$ in the worst case (where $m$ is the table capacity).
* **Iterator Creation:** $O(n \log n)$ or $O(n^2)$ depending on the sorting algorithm used to create the sorted array for iteration.
* **Space Complexity:** $O(m)$ for the table, where $m$ is the capacity.
