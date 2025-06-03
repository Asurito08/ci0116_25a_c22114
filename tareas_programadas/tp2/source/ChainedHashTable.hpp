/**
 * @file ChainedHashTable.hpp
 * @brief Implementación de una tabla hash con encadenamiento usando listas doblemente enlazadas.
 * 
 * @tparam DataType Tipo de dato almacenado en la tabla hash.
 * 
 * Créditos:  
 * - Basado en el trabajo del Prof. Arturo Camacho, Universidad de Costa Rica  
 * - Modificado por el Prof. Allan Berrocal, Universidad de Costa Rica  
 */

#pragma once
#include <cstdint>
#include <vector>

#include "DoublyLinkedList.hpp"

/**
 * @brief Clase que implementa una tabla hash con encadenamiento usando listas doblemente enlazadas.
 * 
 * @tparam DataType Tipo de dato almacenado en la tabla.
 */
template <typename DataType>
class ChainedHashTable {
 public:
  /**
   * @brief Constructor que inicializa la tabla con un tamaño dado.
   * 
   * @param size Tamaño de la tabla hash.
   */
  ChainedHashTable(size_t size);

  /**
   * @brief Destructor de la tabla hash.
   */
  ~ChainedHashTable();

  /**
   * @brief Inserta un valor en la tabla hash si no existe previamente.
   * 
   * @param value Valor a insertar.
   */
  void insert(const DataType& value);

  /**
   * @brief Busca un valor en la tabla hash.
   * 
   * @param value Valor a buscar.
   * @return Puntero al nodo que contiene el valor si se encuentra, nullptr en caso contrario.
   */
  DLListNode<DataType>* search(const DataType& value) const;

  /**
   * @brief Elimina un valor de la tabla hash si existe.
   * 
   * @param value Valor a eliminar.
   */
  void remove(const DataType& value);

  /**
   * @brief Obtiene el tamaño de la tabla hash.
   * 
   * @return Tamaño de la tabla.
   */
  size_t getSize() const;

  /**
   * @brief Obtiene la tabla completa (vector de listas).
   * 
   * @return Vector con las listas que componen la tabla hash.
   */
  std::vector<DLList<DataType>> getTable() const;

  /**
   * @brief Reemplaza la tabla actual con una nueva.
   * 
   * @param newTable Nuevo vector de listas para la tabla hash.
   */
  void setTable(std::vector<DLList<DataType>> newTable);

 private:
  size_t size; ///< Tamaño de la tabla hash.

  std::vector<DLList<DataType>> table; ///< Vector de listas doblemente enlazadas que almacenan los valores.

  /**
   * @brief Función de dispersión k mod m.
   * 
   * @param value Valor para calcular el índice.
   * @return Índice calculado en la tabla hash.
   */
  size_t kmodm(const DataType& value) const;
};

#include "ChainedHashTable.tpp"
