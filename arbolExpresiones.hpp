/**
 * @file arbolExpresiones.hpp
 *
 * Definicion de la clase "Arbol"
 *
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 1.0
 * @date 27/10/2021
 */

template <typename T>
ArbolBinario<T>::~ArbolBinario()
{
    // Llama al metodo "eliminarArbol" para eliminar el arbol completo
    eliminarArbol();
}

template<typename T>
typename ArbolBinario<T>::NodoArbol* ArbolBinario<T>::getNodoRaiz()
{
    return raiz_;
}

template <typename T>
void ArbolBinario<T>::eliminarSubarbol(NodoArbol *subarbolRaizPtr)
{
    // Condicion de paro de recursion
    if(!subarbolRaizPtr)  {
        return;
    }

    // Llama al metodo "eliminarSubarbol" de forma recursiva para eliminar todos los nodos
    eliminarSubarbol(subarbolRaizPtr->izq);
    eliminarSubarbol(subarbolRaizPtr->der);

    // Se iran eliminando las hojas del arbol
    subarbolRaizPtr->izq = nullptr;
    subarbolRaizPtr->der = nullptr;

    // Elimina el nodo padre
    delete subarbolRaizPtr;
}

template <typename T>
void ArbolBinario<T>::eliminarArbol()
{
    // Llama al metodo "eliminarSubarbol" y pasa como arumento a la raiz para eliminar el arbol completo
    eliminarSubarbol(raiz_);
    raiz_ = nullptr;
}

template <typename T>
void ArbolBinario<T>::prefijoAArbol(string expresionPrefijo)
{
    // Pila que contendra los operadores de la expresion (definido en el heap)
    stack<NodoArbol> *P = new stack<NodoArbol>();
    // Contador de digitos
    int auxContDig = 1;
    // Vacia el arbol en caso de tener algo
    eliminarArbol();

    // Bucle que recorrera la cadena "expresionSufijo" de derecha a izquierda
    for(int i = (expresionPrefijo.length() - 1); i >= 0 ; i--)  {
        // Condicional que se saltara los espacios
        if(expresionPrefijo[i] == ' ')  {
            continue;
        }

        // Si el siguiente caracter es un operando
        if(!esOperador(expresionPrefijo[i]))  {
            // En caso de que el numero tenga mas de un digito
            while(esDigito(expresionPrefijo[i - auxContDig]) && expresionPrefijo[i - auxContDig] != ' ')  {
                auxContDig++;
            }
            // Si hay un numero con mas de un digito
            if(auxContDig != 1)  {
                // Ingresa el nodo a la pila el operando (numero de mas de un diigto) a la pila "P"
                P->push(NodoArbol(string(expresionPrefijo.substr((i - auxContDig), auxContDig + 1))));
                // Actualiza "i"
                i -= auxContDig;
            }
            // Pero si el numero solo tiene un digito
            else{
                // El operando (un digito o letra) entra a la pila "P"
                P->push(NodoArbol(string(1, expresionPrefijo[i])));
            }

            // Reinicia contador
            auxContDig = 1;
        }
        // Si el siguiente caracter es un operador
        else  {
            // Extrae dos elementos de la pila "P"
            NodoArbol *A = new NodoArbol(P->top());
            P->pop();
            NodoArbol *B = new NodoArbol(P->top());
            P->pop();
            // Crea el nodo que contendra el operador y sus hijos seran los operandos
            string operador;
            operador = expresionPrefijo[i];
            NodoArbol *C = new NodoArbol(operador);
            C->izq = A;
            C->der = B;
            P->push(*C);
        }
    }

    // Se almacena la raiz del arbol resultante en "raiz_"
    raiz_ = &P->top();
}

template <typename T>
void ArbolBinario<T>::sufijoAArbol(const string &expresionSufijo)
{
    // Pila que contendra los operadores de la expresion (definido en el heap)
    stack<NodoArbol> *P = new stack<NodoArbol>();
    // Contador de digitos
    int auxContDig = 1;
    // Vacia el arbol en caso de tener algo
    eliminarArbol();

    // Bucle que recorrera la cadena "expresionSufijo" de izquierda a derecha
    for(int i = 0; i < expresionSufijo.length(); i++)  {
        // Condicional que se saltara los espacios
        if(expresionSufijo[i] == ' ')  {
            continue;
        }

        // Si el siguiente caracter es un operando
        if(!esOperador(expresionSufijo[i]))  {
            // En caso de que el numero tenga mas de un digito
            while(esDigito(expresionSufijo[i + auxContDig]) && expresionSufijo[i + auxContDig] != ' ')  {
                auxContDig++;
            }
            // Si hay un numero con mas de un digito
            if(auxContDig != 1)  {
                // Ingresa el nodo a la pila el operando (numero de mas de un diigto) a la pila "P"
                P->push(NodoArbol(string(expresionSufijo.substr(i, auxContDig))));
                // Actualiza "i"
                i += auxContDig;
            }
            // Pero si el numero solo tiene un digito
            else{
                // El operando (un digito o letra) entra a la pila "P"
                P->push(NodoArbol(string(1, expresionSufijo[i])));
            }

            // Reinicia contador
            auxContDig = 1;
        }
        // Si el siguiente caracter es un operador
        else  {
            // Extrae dos elementos de la pila "P"
            NodoArbol *A = new NodoArbol(P->top());
            P->pop();
            NodoArbol *B = new NodoArbol(P->top());
            P->pop();
            // Crea el nodo que contendra el operador y sus hijos seran los operandos
            string operador;
            operador = expresionSufijo[i];
            NodoArbol *C = new NodoArbol(operador);
            C->izq = B;
            C->der = A;
            P->push(*C);
        }
    }

    // Se almacena la raiz del arbol resultante en "raiz_"
    raiz_ = &P->top();
}

template <typename T>
void ArbolBinario<T>::imprimirNodo(NodoArbol *act)
{
    // Condicion para evitar un error al tratar de imprimir un dato nulo
    if(act)  {
        // Imprime el dato
        cout << act->dato;
    }

    // Imprime un espacio (para la visualizacion de los recorridos)
    cout << " ";
}

template <typename T>
void ArbolBinario<T>::inorden(NodoArbol *act)
{
    // Condicion de paro de recursion
    if(!act)  {
        return;
    }

    // Llama al metodo "inorden" de forma recursiva para recorrer todos los nodos
    inorden(act->izq);
    imprimirNodo(act);
    inorden(act->der);
}

template <typename T>
void ArbolBinario<T>::preorden(NodoArbol *act)
{
    {
        // Condicion de paro de recursion
        if(!act)  {
            return;
        }

        // Llama al metodo "inorden" de forma recursiva para recorrer todos los nodos
        imprimirNodo(act);
        preorden(act->izq);
        preorden(act->der);
    }
}

template <typename T>
void ArbolBinario<T>::postorden(NodoArbol *act)
{
    // Condicion de paro de recursion
    if(!act)  {
        return;
    }

    // Llama al metodo "inorden" de forma recursiva para recorrer todos los nodos
    postorden(act->izq);
    postorden(act->der);
    imprimirNodo(act);
}
