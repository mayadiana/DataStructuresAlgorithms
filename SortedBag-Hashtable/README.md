# ADT SortedBag (Hashtable)

**Implementation of a SortedBag using a Hashtable with Coalesced Chaining.**

## ⚙️ Technical Specifications
* **Collision Resolution:** Uses **Coalesced Chaining** to handle hash collisions.
* **Dynamic Resizing:** The table automatically rehashes all elements when the load factor threshold is exceeded.
* **Order:** Maintains elements based on a custom sorting relation.
* **Constraint:** No STL containers used for the internal representation.

## 📈 Complexity
* **Add/Remove/Search:** $O(1)$ on average; $O(m)$ in the worst case, where $m$ is the table capacity.
* **Iterator:** In the constructor, it creates a sorted array of elements for iteration, resulting in $O(n \log n)$ or $O(n^2)$ complexity.
