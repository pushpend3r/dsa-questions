# Tree

A Tree is a non-linear data structure and a hierarchy consisting of a collection of nodes such that each node of the tree stores a value and a list of references to other nodes (the “children”).
<br />
<br />

![](https://media.geeksforgeeks.org/wp-content/uploads/20221124153129/Treedatastructure.png)

---

## Few Important Terms

- **Number of edges**: N nodes = N-1 edges.
- **Depth of a node**: No.s of edges between root to node.Each edge adds 1 unit of length to the path.
- **Height of a node**: The height of a node can be defined as the length of the longest path from the node to a leaf node of the tree.
- **Height of the Tree**: The height of a tree is the length of the longest path from the root of the tree to a leaf node of the tree.
- **Degree of a Node**: no of childrens of that node.
- **Degree of a Tree**: maximum no of childrens of any node among all nodes in a tree.

---

## Types

- **General tree** -
  A general tree data structure has no restriction on the number of nodes. It means that a parent node can have any number of child nodes.

- **Binary tree** -
  A node of a binary tree can have a **maximum of two child nodes**.

- **Balanced tree** -
  If the height of the left sub-tree and the right sub-tree of any node is equal or differs _at most by 1_, the tree is known as a balanced tree.

- **Binary search tree** -
  the value of the left node is less than its parent, while the value of the right node is greater than its parent. It helps in maintaining a sorted stream of data.

---

## Applications

- Spanning trees - It is the shortest path tree used in the routers to direct the packets to the destination.

- It used to store the hierarchical data.

- The syntax tree represents the structure of the program’s source code, which is used in **compilers**.

- Trie: It is a fast and efficient way for dynamic spell checking. It is also used for locating specific keys from within a set.

- Heap: It is also a tree data structure that can be represented in a form of an array. It is used to implement priority queues.

---

## Binary Tree

each node has at most, two childrens.

```cpp
class Node {
public:
    int data;
    Node* left;
    Node* right;
};
```

We can also represent Binary Tree with **Array Representation**

Every indices represent Tree nodes from 0 to n - 1.
0 being root node.

```
I = index of node
so left_son's index=(2*I)+1;
and right_son's index=(2*I)+2;
```

### Properties

- at any level ‘L’. The maximum number of nodes will be 2^L.
- height 'H', The maximum number of nodes will be 2^H - 1.
- with N nodes, the minimum possible height is Log2(N+1).
- with L leaf nodes,tree has at least | Log2L |+ 1 levels.
- internal nodes = total no of nodes - leaf nodes [(2^H - 1) - (2^(H-1))].
- Leaf Nodes = internal nodes + 1.

### Types (basis of childrens)

- Full - every node has 0 or 2 child.
- Degenerate - every internal node has 1 child.
- Skewed - tree is either dominated by the left nodes or the right nodes.
  ![](https://media.geeksforgeeks.org/wp-content/uploads/20221130172501/skewed1.png)

### Types (basis of the completion of levels)

- Complete

1. Every level must be completely filled
2. All the leaf elements must lean towards the left.
3. The last leaf element might not have a right sibling i.e. a complete binary tree doesn’t have to be a full binary tree.

- Perfect - all internal nodes have two children and all leaf nodes are at the same level.
- Balanced - that maintains O(Log N) height by making sure that the difference between the heights of the left and right subtrees is at **most 1**.

### Types (basis of node values)

- Binary Search Tree (BST) - for every node, left child value < node's value < right child's value.

1. AVL - is a self-balancing BST where the difference between heights of left and right subtrees cannot be more than one for all nodes.
2. Red Black

- B Tree
- B+ Tree
- Segment Tree

### Application

- useful for indexing segmented at the database is useful in storing cache in the system.
- to perform encoding and decoding operations.
- Priority Queue is another application of binary tree that is used for searching maximum or minimum in O(1) time complexity.

### Traversals

1. Depth-First Search (DFS) Algorithms

- Preorder Traversal (current-left-right) [Click here for Code](/130.%20PreOrder%20Traversal.cpp)

- Postorder Traversal (left-right-current) [Click here for Code](/131.%20Postorder%20Traversal.cpp)
- Inorder Traversal (left-current-right) [Click here for Code](/129.%20Inorder%20Traversal.cpp)

2. Breadth-First Search (BFS) Algorithms

- Level Order Traversal: Visit nodes level-by-level and left-to-right fashion at the same level. [Click here for Code](/127.%20Level%20order%20traversal.cpp)

---

### General/Generic Tree

- Many children at every node.
- The number of nodes for each node is not known in advance.

#### Node Structure

```c
struct Node{
    int data;
    struct Node *firstChild;
    struct Node *nextSibling;
}
```

Above is called **First child / Next sibling representation**

#### Visual representation

![](https://media.geeksforgeeks.org/wp-content/uploads/20190612122325/generictree_gfg.png)

#### Convert it to Binary Tree (Algo)

Steps

- The root of the Binary Tree is the Root of the Generic Tree.
- The left child of a node in the Generic Tree is the Left child of that node in the Binary Tree.
- The right sibling of any node in the Generic Tree is the Right child of that node in the Binary Tree.

Generic Tree
![](https://media.geeksforgeeks.org/wp-content/uploads/20200324122406/GenricTree.png)

Binary Tree
![](https://media.geeksforgeeks.org/wp-content/uploads/20200323153641/output163.png)

Code

```cpp
// Need to do
```

---

## Forest

collection of trees
