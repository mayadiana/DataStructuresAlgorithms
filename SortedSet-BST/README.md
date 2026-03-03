# ADT SortedSet (Binary Search Tree)

**Implementation of a SortedSet using a Binary Search Tree (BST) with linked representation.**

## ⚙️ Technical Specifications
* **Data Structure:** **Binary Search Tree** with dynamic allocation for each individual node.
* **Order:** Elements are maintained in a sorted order based on a custom relation.
* **Memory Management:** Manual management of tree nodes, including a recursive or iterative approach to deletion and cleanup.

## 📈 Complexity
* **Add/Remove/Search:** $O(h)$ on average, where $h$ is the height of the tree.
* **Worst Case:** $O(n)$ if the tree becomes unbalanced (degenerated into a list).
* **Space Complexity:** $O(n)$ to store $n$ elements, with each element requiring an additional two pointers for the children.
