/**
 * @file DoublyLinkedList.hpp
 * @brief Definición de la clase DLList y DLListNode (Lista doblemente enlazada).
 * 
 * @tparam DataType Tipo de dato almacenado en los nodos.
 * 
 * Créditos:  
 * - Basado en el trabajo del Prof. Arturo Camacho, Universidad de Costa Rica  
 * - Modificado por el Prof. Allan Berrocal, Universidad de Costa Rica  
 */

#pragma once

/// Adelanto de DLList como plantilla
template <typename DataType>
class DLList;

/**
 * @brief Nodo de una lista doblemente enlazada.
 * 
 * @tparam DataType Tipo de dato almacenado en el nodo.
 */
template <typename DataType>
class DLListNode {
 public:
  friend class DLList<DataType>;

  /// Constructor por defecto.
  DLListNode() = default;

  /**
   * @brief Constructor con valor y punteros opcionales a siguiente y previo.
   * @param value Valor almacenado en el nodo.
   * @param next Puntero al siguiente nodo (default nullptr).
   * @param prev Puntero al nodo previo (default nullptr).
   */
  DLListNode(const DataType& value, DLListNode<DataType>* next = nullptr,
             DLListNode<DataType>* prev = nullptr);

  /// Destructor (vacío).
  ~DLListNode() {};

  /// Obtiene la clave almacenada.
  DataType getKey() const;

  /// Obtiene el nodo previo.
  DLListNode<DataType>* getPrev() const;

  /// Obtiene el nodo siguiente.
  DLListNode<DataType>* getNext() const;

  /// Establece una nueva clave.
  void setKey(DataType key);

  /// Establece el nodo previo.
  void setPrev(DLListNode<DataType>* prev);

  /// Establece el nodo siguiente.
  void setNext(DLListNode<DataType>* next);

 private:
  DataType key;                    ///< Valor almacenado en el nodo.
  DLListNode<DataType>* next;      ///< Puntero al siguiente nodo.
  DLListNode<DataType>* prev;      ///< Puntero al nodo previo.
};

/**
 * @brief Lista doblemente enlazada con nodo centinela.
 * 
 * @tparam DataType Tipo de dato almacenado en la lista.
 */
template <typename DataType>
class DLList {
 public:
  /// Constructor por defecto.
  DLList();

  /// Destructor.
  ~DLList();

  /**
   * @brief Inserta un valor al inicio de la lista.
   * @param value Valor a insertar.
   */
  void insert(const DataType& value);

  /**
   * @brief Busca un nodo con el valor dado.
   * @param value Valor a buscar.
   * @return Puntero al nodo encontrado o nullptr si no existe.
   */
  DLListNode<DataType>* search(const DataType& value) const;

  /**
   * @brief Elimina un nodo que contenga el valor indicado.
   * @param value Valor a eliminar.
   */
  void remove(const DataType& value);

  /**
   * @brief Elimina un nodo dado.
   * @param node Puntero al nodo a eliminar.
   */
  void remove(DLListNode<DataType>* node);

  /**
   * @brief Obtiene el nodo centinela (nodo nulo).
   * @return Puntero al nodo nil.
   */
  DLListNode<DataType>* getNil() const;

 private:
  DLListNode<DataType>* nil; ///< Nodo centinela.
};

#include "DoublyLinkedList.tpp"
