# ADT Matrix (Sparse Matrix)

**Implementation of a Sparse Matrix using a Dynamic Array of triples.**

## ⚙️ Technical Specifications
* **Representation:** Triples of `<line, column, value>` for all non-zero elements.
* **Storage:** Elements are stored in a **Dynamic Array**, ordered lexicographically by line and column.
* **Memory Management:** Implemented custom copy constructor, assignment operator, and destructor to handle dynamic allocation.
* **Constraint:** Developed without using `std::vector` or other STL containers.

## 📈 Complexity
* **Element Access (get/set):** $O(n)$ in the worst case, where $n$ is the number of non-zero elements.
* **Add/Modify:** $O(n)$ due to the necessity of maintaining the ordered structure in the dynamic array.
* **Space Complexity:** $O(n)$, where $n$ is the number of non-zero elements, making it much more efficient than a 2D array for sparse data.
