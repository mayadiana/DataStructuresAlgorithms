# ADT SortedSet (Binary Search Tree)

**Implementation of a SortedSet using a Binary Search Tree (BST) with linked representation.**

## ⚙️ Technical Specifications
* **Data Structure:** **Binary Search Tree** with dynamic allocation for each individual node.
* **Order:** Elements are maintained in a sorted order based on a custom relation.
* **Memory Management:** Manual handling of BST nodes, including a recursive or iterative approach to cleanup.

## 📈 Complexity
* **Add/Remove/Search:** $O(h)$ on average, where $h$ is the height of the tree.
* **Worst Case:** $O(n)$ if the tree becomes unbalanced (degenerated into a list).
* **Space Complexity:** $O(n)$ to store $n$ elements, with each node storing two child pointers.
