/**
 * @file SLList.hpp
 * @brief Definición de la clase plantilla SLList y SLListNode para una lista simplemente enlazada con nodo centinela.
 * 
 * @tparam DataType Tipo de dato almacenado en los nodos.
 * 
 * Créditos:  
 * - Basado en el trabajo del Prof. Arturo Camacho, Universidad de Costa Rica  
 * - Modificado por el Prof. Allan Berrocal, Universidad de Costa Rica  
 */

#pragma once

// Adelanto de SLList como plantilla
template <typename DataType>
class SLList;

/**
 * @brief Nodo de una lista simplemente enlazada.
 * 
 * @tparam DataType Tipo de dato almacenado en el nodo.
 */
template <typename DataType>
class SLListNode {
 public:
  friend class SLList<DataType>;

  /**
   * @brief Constructor por defecto.
   */
  SLListNode();

  /**
   * @brief Constructor que inicializa clave y siguiente nodo.
   */
  SLListNode(DataType key, SLListNode<DataType>* next);


  /**
   * @brief Destructor del nodo.
   */
  ~SLListNode();

  /**
   * @brief Devuelve la clave almacenada en el nodo.
   * @return Valor almacenado en el nodo.
   */
  DataType getKey() const;

  /**
   * @brief Devuelve el puntero al siguiente nodo.
   * @return Puntero al siguiente nodo.
   */
  SLListNode<DataType>* getNext() const;

  /**
   * @brief Establece una nueva clave en el nodo.
   * @param key Nuevo valor para el nodo.
   */
  void setKey(DataType key);

  /**
   * @brief Establece el puntero al siguiente nodo.
   * @param newNode Puntero al nuevo nodo siguiente.
   */
  void setNext(SLListNode<DataType>* newNode);

 private:
  DataType key;                    ///< Valor almacenado en el nodo.
  SLListNode<DataType>* next;     ///< Puntero al siguiente nodo.
};

/**
 * @brief Lista simplemente enlazada con nodo centinela.
 * 
 * @tparam DataType Tipo de dato almacenado en la lista.
 */
template <typename DataType>
class SLList {
 public:
  /**
   * @brief Constructor por defecto.
   * Inicializa la lista con nodo centinela.
   */
  SLList();

  /**
   * @brief Destructor.
   * Elimina todos los nodos de la lista.
   */
  ~SLList();

  /**
   * @brief Inserta un nuevo valor al inicio de la lista.
   * @param value Valor a insertar.
   */
  void insert(const DataType& value);

  /**
   * @brief Busca un nodo con el valor dado.
   * @param value Valor a buscar.
   * @return Puntero al nodo encontrado o nullptr si no existe.
   */
  SLListNode<DataType>* search(const DataType& value) const;

  /**
   * @brief Elimina todos los nodos que contengan el valor indicado.
   * @param value Valor a eliminar.
   */
  void remove(const DataType& value);

  /**
   * @brief Obtiene el nodo centinela (nodo nil).
   * @return Puntero al nodo nil.
   */
  SLListNode<DataType>* getNil() const;

 private:
  SLListNode<DataType>* nil;  ///< Nodo centinela de la lista.
};

// Incluir la implementación
#include "SinglyLinkedList.tpp"
