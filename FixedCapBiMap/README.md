# ADT BiMap (Fixed Capacity)

**A Bidirectional Map implementation using a dynamic array with a fixed capacity.**

## 📝 Description
This project implements a BiMap where each key is associated with a value, and each value is associated with a key, ensuring a one-to-one mapping. It was designed as an introductory project to understand the basics of Abstract Data Types and array-based storage.

## ⚙️ Implementation Details
* **Storage:** Uses a dynamic array of pairs `(key, value)`.
* **Fixed Capacity:** The maximum number of elements is defined at initialization.
* **Complexity:** * Add: $O(1)$ amortized (if not full).
  * Search: $O(n)$ where $n$ is the capacity.
* **Iterator:** Includes a dedicated iterator (`FixedCapBiMapIterator`) for safe traversal of the map.
