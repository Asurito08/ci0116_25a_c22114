/**
 * @file RedBlackTree.hpp
 * @brief Definición de la clase RBTree y RBTreeNode para árboles rojo-negro.
 * 
 * @tparam DataType Tipo de dato almacenado en los nodos del árbol.
 * 
 * Créditos:  
 * - Basado en el trabajo del Prof. Arturo Camacho, Universidad de Costa Rica  
 * - Modificado por el Prof. Allan Berrocal, Universidad de Costa Rica  
 */

#pragma once

/// @brief Colores usados por los nodos del árbol rojo-negro.
enum colors { RED, BLACK };

/// Adelanto de clase RBTree para uso como friend.
template <typename DataType>
class RBTree;

/**
 * @brief Nodo de un árbol rojo-negro.
 * 
 * @tparam DataType Tipo de dato almacenado en el nodo.
 */
template <typename DataType>
class RBTreeNode {
 public:
  friend class RBTree<DataType>;

  /// Constructor por defecto.
  RBTreeNode() = default;

  /**
   * @brief Constructor con parámetros.
   * @param value Valor a almacenar.
   * @param parent Puntero al nodo padre (default nullptr).
   * @param left Puntero al hijo izquierdo (default nullptr).
   * @param right Puntero al hijo derecho (default nullptr).
   * @param c Color del nodo (default RED).
   */
  RBTreeNode(const DataType &value, RBTreeNode<DataType> *parent = nullptr,
             RBTreeNode<DataType> *left = nullptr,
             RBTreeNode<DataType> *right = nullptr, enum colors c = RED);

  /// Destructor.
  ~RBTreeNode();

  /// @return Valor almacenado en el nodo.
  DataType getKey() const;

  /// @return Puntero al nodo padre.
  RBTreeNode<DataType> *getParent() const;

  /// @return Puntero al hijo izquierdo.
  RBTreeNode<DataType> *getLeft() const;

  /// @return Puntero al hijo derecho.
  RBTreeNode<DataType> *getRight() const;

  /// @return Color del nodo.
  enum colors getColor() const;

  /// @brief Establece el valor del nodo.
  /// @param key Nuevo valor a asignar.
  void setKey(DataType key);

  /// @brief Establece el color del nodo.
  /// @param newColor Nuevo color a asignar.
  void setColor(enum colors newColor);

  /// @brief Establece el padre del nodo.
  /// @param parent Nuevo puntero al padre.
  void setParent(RBTreeNode<DataType> *parent);

  /// @brief Establece el hijo izquierdo.
  /// @param left Nuevo puntero al hijo izquierdo.
  void setLeft(RBTreeNode<DataType> *left);

  /// @brief Establece el hijo derecho.
  /// @param right Nuevo puntero al hijo derecho.
  void setRight(RBTreeNode<DataType> *right);

 private:
  DataType key;                          ///< Valor almacenado en el nodo.
  RBTreeNode<DataType> *parent;          ///< Puntero al nodo padre.
  RBTreeNode<DataType> *left;            ///< Puntero al hijo izquierdo.
  RBTreeNode<DataType> *right;           ///< Puntero al hijo derecho.
  enum colors color;                     ///< Color del nodo.
};

/**
 * @brief Árbol rojo-negro.
 * 
 * @tparam DataType Tipo de dato almacenado en el árbol.
 */
template <typename DataType>
class RBTree {
 public:
  /// Constructor.
  RBTree();

  /// Destructor.
  ~RBTree();

  /// @brief Establece la raíz del árbol.
  /// @param r Nueva raíz.
  void setRoot(RBTreeNode<DataType>* r);

  /// @brief Establece el nodo nil (hoja nula).
  /// @param n Nodo nil.
  void setNil(RBTreeNode<DataType>* n);

  /// @brief Inserta un valor en el árbol.
  /// @param value Valor a insertar.
  void insert(const DataType &value);

  /// @brief Elimina un valor del árbol.
  /// @param value Valor a eliminar.
  void remove(const DataType &value);

  /**
   * @brief Busca un nodo con un valor dado dentro de un subárbol.
   * @param rootOfSubtree Raíz del subárbol donde se realiza la búsqueda.
   * @param value Valor a buscar.
   * @return Puntero al nodo encontrado o nullptr si no existe.
   */
  RBTreeNode<DataType> *search(const RBTreeNode<DataType> *rootOfSubtree,
                               const DataType &value) const;

  /**
   * @brief Obtiene el nodo con el valor mínimo en un subárbol.
   * @param rootOfSubtree Raíz del subárbol.
   * @return Puntero al nodo con valor mínimo.
   */
  RBTreeNode<DataType> *getMinimum(const RBTreeNode<DataType> *rootOfSubtree) const;

  /**
   * @brief Obtiene el nodo con el valor máximo en un subárbol.
   * @param rootOfSubtree Raíz del subárbol.
   * @return Puntero al nodo con valor máximo.
   */
  RBTreeNode<DataType> *getMaximum(const RBTreeNode<DataType> *rootOfSubtree) const;

  /**
   * @brief Obtiene el sucesor de un nodo.
   * @param node Nodo de referencia.
   * @return Puntero al sucesor del nodo.
   */
  RBTreeNode<DataType> *getSuccessor(const RBTreeNode<DataType> *node) const;

  /// @return Puntero a la raíz del árbol.
  RBTreeNode<DataType> *getRoot() const;

  /// @return Puntero al nodo nil.
  RBTreeNode<DataType> *getNil() const;

 private:
  RBTreeNode<DataType> *root; ///< Raíz del árbol.
  RBTreeNode<DataType> *nil;  ///< Nodo nil que representa las hojas vacías.

  /**
   * @brief Rotación a la izquierda desde un nodo dado.
   * @param x Nodo desde donde se realiza la rotación.
   */
  void rotateLeft(RBTreeNode<DataType> *x);

  /**
   * @brief Rotación a la derecha desde un nodo dado.
   * @param x Nodo desde donde se realiza la rotación.
   */
  void rotateRight(RBTreeNode<DataType> *x);

  /**
   * @brief Rebalanceo después de la inserción de un nodo.
   * @param node Nodo insertado.
   */
  void insertFixup(RBTreeNode<DataType> *node);

  /**
   * @brief Reemplaza un subárbol por otro.
   * @param u Nodo a reemplazar.
   * @param v Nodo que reemplaza a u.
   */
  void transplant(RBTreeNode<DataType> *u, RBTreeNode<DataType> *v);

  /**
   * @brief Rebalanceo después de la eliminación de un nodo.
   * @param node Nodo desde donde iniciar el rebalanceo.
   */
  void removeFixup(RBTreeNode<DataType> *node);
};

#include "RedBlackTree.tpp"
