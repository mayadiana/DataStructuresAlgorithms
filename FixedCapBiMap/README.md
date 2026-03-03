# ADT BiMap (Fixed Capacity)

**Implementation of a Bidirectional Map using a dynamic array with a fixed capacity.**

## ⚙️ Technical Specifications
* **Data Structure:** Pairs of `(key, value)` stored in a dynamic array.
* **Bidirectional Mapping:** Each key is associated with a value and vice versa, maintaining a unique one-to-one relationship.
* **Fixed Capacity:** The maximum number of elements is established at the creation of the BiMap.
* **Memory Management:** Manual allocation and deallocation of the dynamic array.

## 📈 Complexity
* **Add:** $O(1)$ amortized (if capacity is not reached).
* **Remove/Search:** $O(n)$ where $n$ is the capacity.
* **Iterator:** Includes a `FixedCapBiMapIterator` for linear traversal.
