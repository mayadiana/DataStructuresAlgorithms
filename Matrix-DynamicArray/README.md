# ADT Matrix (Sparse Matrix)

**Implementation of a Sparse Matrix using a Dynamic Array of triples.**

## ⚙️ Technical Specifications
* **Representation:** Triples of `<line, column, value>` for all non-zero elements.
* **Storage:** Elements are stored in a **Dynamic Array**, ordered lexicographically by line and column.
* **Memory Management:** Implemented custom copy constructor, assignment operator, and destructor to handle dynamic allocation.
* **Constraint:** Developed without using `std::vector` or other STL containers.
