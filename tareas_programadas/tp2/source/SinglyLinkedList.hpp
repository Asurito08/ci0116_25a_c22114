/**
 * @file SLList.hpp
 * @brief Definición de la clase SLList y SLListNode (Lista simplemente enlazada).
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

 /// Nodo de una lista simplemente enlazada.
 template <typename DataType>
 class SLListNode {
  public:
   friend class SLList<DataType>;
 
   /// Constructor por defecto.
   SLListNode();
 
   /// Constructor con valor y siguiente nodo opcional.
   SLListNode(const DataType& value, SLListNode<DataType>* next = nullptr);
 
   /// Destructor del nodo.
   ~SLListNode();
 
   /// Devuelve la clave almacenada en el nodo.
   DataType getKey() const;
 
   /// Devuelve el puntero al siguiente nodo.
   SLListNode<DataType>* getNext() const;
 
   /// Establece una nueva clave en el nodo.
   void setKey(DataType key);
 
   /// Establece el puntero al siguiente nodo.
   void setNext(SLListNode<DataType>* newNode);
 
  private:
   DataType key;                        ///< Valor almacenado.
   SLListNode<DataType>* next;         ///< Puntero al siguiente nodo.
 };
 
 /// Lista simplemente enlazada con nodo centinela.
 template <typename DataType>
 class SLList {
  public:
   /// Constructor por defecto.
   SLList();
 
   /// Destructor.
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
    * @brief Obtiene el nodo centinela (nodo nulo).
    * @return Puntero al nodo nil.
    */
   SLListNode<DataType>* getNil() const;
 
  private:
   SLListNode<DataType>* nil;  ///< Nodo centinela.
 };
 
 // Incluir la implementación
 #include "SinglyLinkedList.tpp"
 