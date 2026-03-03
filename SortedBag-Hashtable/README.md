# ADT SortedBag (Hashtable)

**Implementation of a SortedBag using a Hashtable with Coalesced Chaining.**

## ⚙️ Technical Specifications
* **Collision Resolution:** Uses **Coalesced Chaining** to handle hash collisions.
* **Dynamic Resizing:** The table rehashes all elements when the load factor threshold is exceeded.
* **Order:** Maintains elements based on a custom sorting relation.
* **Constraint:** No STL containers used for the internal representation.
