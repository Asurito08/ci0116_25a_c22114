/*
 Credits
 Based on: Prof. Arturo Camacho, Universidad de Costa Rica
 Modified by: Prof. Allan Berrocal, Universidad de Costa Rica
 */

#pragma once
#include <cstddef>

/**
 * @brief Forward declaration of BSTree class template.
 * 
 * @tparam DataType The type of data stored in the tree nodes.
 */
template <typename DataType>
class BSTree;

/**
 * @brief Represents a node in a Binary Search Tree.
 * 
 * @tparam DataType The type of data stored in the node.
 */
template <typename DataType>
class BSTreeNode {
 public:
  friend class BSTree<DataType>;

  /**
   * @brief Default constructor.
   */
  BSTreeNode() = default;

  /**
   * @brief Constructs a node with a given value and optional parent, left and right children.
   * 
   * @param value The data value stored in the node.
   * @param parent Pointer to the parent node (default nullptr).
   * @param left Pointer to the left child node (default nullptr).
   * @param right Pointer to the right child node (default nullptr).
   */
  BSTreeNode(const DataType &value, BSTreeNode<DataType> *parent = nullptr,
             BSTreeNode<DataType> *left = nullptr,
             BSTreeNode<DataType> *right = nullptr);

  /**
   * @brief Destructor.
   * Deletes left and right children recursively.
   */
  ~BSTreeNode();

  /**
   * @brief Gets the key stored in the node.
   * @return The data value stored in the node.
   */
  DataType getKey() const;

  /**
   * @brief Gets the parent node.
   * @return Pointer to the parent node.
   */
  BSTreeNode<DataType> *getParent() const;

  /**
   * @brief Gets the left child node.
   * @return Pointer to the left child node.
   */
  BSTreeNode<DataType> *getLeft() const;

  /**
   * @brief Gets the right child node.
   * @return Pointer to the right child node.
   */
  BSTreeNode<DataType> *getRight() const;

  /**
   * @brief Sets the parent node.
   * @param parent Pointer to the new parent node.
   */
  void setParent(BSTreeNode<DataType> *parent);

  /**
   * @brief Sets the left child node.
   * @param left Pointer to the new left child node.
   */
  void setLeft(BSTreeNode<DataType> *left);

  /**
   * @brief Sets the right child node.
   * @param right Pointer to the new right child node.
   */
  void setRight(BSTreeNode<DataType> *right);

 private:
  DataType key; ///< Data stored in the node.

  BSTreeNode<DataType> *parent = nullptr; ///< Pointer to parent node.

  BSTreeNode<DataType> *left = nullptr; ///< Pointer to left child node.

  BSTreeNode<DataType> *right = nullptr; ///< Pointer to right child node.
};

/**
 * @brief Binary Search Tree class template.
 * 
 * @tparam DataType The type of data stored in the tree.
 */
template <typename DataType>
class BSTree {
 public:
  /**
   * @brief Default constructor, initializes an empty tree.
   */
  BSTree();

  /**
   * @brief Destructor, deletes all nodes in the tree.
   */
  ~BSTree();

  /**
   * @brief Inserts a value into the binary search tree.
   * @param value The value to insert.
   */
  void insert(const DataType &value);

  /**
   * @brief Removes a value from the binary search tree.
   * @param value The value to remove.
   */
  void remove(const DataType &value);

  /**
   * @brief Performs an inorder traversal starting from a given subtree root.
   * @param rootOfSubtree Pointer to the root node of the subtree.
   */
  void inorderWalk(BSTreeNode<DataType> *rootOfSubtree) const;

  /**
   * @brief Performs a preorder traversal starting from a given subtree root.
   * @param rootOfSubtree Pointer to the root node of the subtree.
   */
  void preorderWalk(BSTreeNode<DataType> *rootOfSubtree) const;

  /**
   * @brief Performs a postorder traversal starting from a given subtree root.
   * @param rootOfSubtree Pointer to the root node of the subtree.
   */
  void postorderWalk(BSTreeNode<DataType> *rootOfSubtree) const;

  /**
   * @brief Searches for a value starting from a given subtree root.
   * @param rootOfSubtree Pointer to the root node of the subtree.
   * @param value The value to search for.
   * @return Pointer to the node containing the value, or nullptr if not found.
   */
  BSTreeNode<DataType> *search(const BSTreeNode<DataType> *rootOfSubtree,
                               const DataType &value) const;

  /**
   * @brief Finds the minimum value node in a subtree.
   * @param rootOfSubtree Pointer to the root node of the subtree.
   * @return Pointer to the node with the minimum value.
   */
  BSTreeNode<DataType> *getMinimum(
      const BSTreeNode<DataType> *rootOfSubtree) const;

  /**
   * @brief Finds the maximum value node in a subtree.
   * @param rootOfSubtree Pointer to the root node of the subtree.
   * @return Pointer to the node with the maximum value.
   */
  BSTreeNode<DataType> *getMaximum(
      const BSTreeNode<DataType> *rootOfSubtree) const;

  /**
   * @brief Finds the successor of a given node in the BST.
   * @param node Pointer to the node whose successor is to be found.
   * @return Pointer to the successor node, or nullptr if none exists.
   */
  BSTreeNode<DataType> *getSuccessor(const BSTreeNode<DataType> *node) const;

  /**
   * @brief Gets the root node of the tree.
   * @return Pointer to the root node.
   */
  BSTreeNode<DataType> *getRoot() const;

  /**
   * @brief Inserts n random values in the tree for testing purposes.
   * @param n Number of random values to insert.
   */
  void fastInsert(size_t n);
  
 private:
  BSTreeNode<DataType> *root; ///< Pointer to the root node of the tree.

  /**
   * @brief Recursively deletes all nodes in a subtree.
   * @param node Pointer to the root of the subtree to delete.
   */
  void deleteSubtree(BSTreeNode<DataType> *node);

  /**
   * @brief Removes a node from the tree, adjusting links accordingly.
   * @param node Pointer to the node to remove.
   */
  void removeNode(BSTreeNode<DataType> *node);
};

#include "BinarySearchTree.tpp"
