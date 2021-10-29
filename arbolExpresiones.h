/**
 * @file arbolExpresiones.h
 *
 * Declaracion de la clase "Arbol" que es para la construccion de objetos que contienen la implementacion
 * de un arbol binario de expresiones y metodos para imprimir los diferentes recorridos del arbol binario
 *
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 1.0
 * @date 27/10/2021
 */

#include"notacion.h"

template<typename T>
class ArbolBinario
{
    private:
        class NodoArbol
        {
            public:
                T dato;  // Dato almacenado en el nodo
                NodoArbol *izq;  // Apuntador al nodo hijo izq
                NodoArbol *der;  // Apuntador al nodo hijo der

                /**
                * @brief Constructor de la clase "NodoArbol" que inicializara los valores de los punteros a "nullptr"
                * @param dato Dato que se desea almacenar
                */
                NodoArbol(const T &dato) : dato(dato), izq(nullptr), der(nullptr)  {  }

                /**
                * @brief Constructor por defecto de la clase "NodoArbol" que inicializara los valores de los punteros a "nullptr"
                */
                NodoArbol() : dato(""), izq(nullptr), der(nullptr)  {  }

                /**
                * @brief Constructor copia de la clase "NodoArbol"
                */
                NodoArbol(const NodoArbol &otro)
                {
                    this->dato = otro.dato;
                    this->izq = otro.izq;
                    this->der = otro.der;
                }
        };

        NodoArbol *raiz_;

    public:
        /**
         * @brief Constructor de la clase "ArbolBinario"
         */
        ArbolBinario() : raiz_(nullptr)  {  }

        /**
         * @brief Constructor de copia de la clase "ArbolBinario"
         */
        ArbolBinario(const ArbolBinario &otro) = delete;

        /**
         * @brief Destructor de la clase "ArbolBinario"
         */
        ~ArbolBinario();

        /**
         * @brief Metodo que regresa el nodo raiz del arbol
         */
        NodoArbol* getNodoRaiz();

        /**
         * @brief Metodo que elimina todo un subarbol completo
         * @param subarbolRaizPtr Nodo raiz del subarbol que se desea eliminar
         */
        void eliminarSubarbol(NodoArbol *subarbolRaizPtr);

        /**
         * @brief Metodo que elimina todo el arbol completo
         */
        void eliminarArbol();

        /**
         * @brief Metodo que crea el arbol binario almacenado en el objeto a partir de una expresion aritmetica en notacion prefijo
         * @pre Se debe construir un objeto de tipo "ArbolBinario" con template "string" para poder llamar este metodo
         * @param expresionPrefijo Expresion aritmetica en notacion prefijo
         */
        void prefijoAArbol(string expresionPrefijo);

        /**
         * @brief Metodo que crea el arbol binario almacenado en el objeto a partir de una expresion aritmetica en notacion sufijo
         * @pre Se debe construir un objeto de tipo "ArbolBinario" con template "string" para poder llamar este metodo
         * @param expresionSufijo Expresion aritmetica en notacion sufijo
         */
        void sufijoAArbol(const string &expresionSufijo);

        /**
         * @brief Metodo que imprime el contenido de un nodo
         * @param act Nodo del arlbol
         */
        void imprimirNodo(NodoArbol *act);

        /**
         * @brief Metodo que contiene la implementacion del recorrido recursivo inorden del arbol binario
         * @param act Nodo del arlbol
         */
        void inorden(NodoArbol *act);

        /**
         * @brief Metodo que contiene la implementacion del recorrido recursivo preorden del arbol binario
         * @param act Nodo del arlbol
         */
        void preorden(NodoArbol *act);

        /**
         * @brief Metodo que contiene la implementacion del recorrido recursivo postorden del arbol binario
         * @param act Nodo del arlbol
         */
        void postorden(NodoArbol *act);
};

#include"arbolExpresiones.hpp"
