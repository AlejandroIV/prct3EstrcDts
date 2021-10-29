/**
 * @file notacion.h
 *
 * Declaracion de la clase "Notacion" que es para la construccion de objetos que contienen una expresion
 * aritmetica en notacion Infijo y los metodos para convertirlo a notacion Prefijo y Sufijo
 *
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 1.0
 * @date 27/10/2021
 */

#pragma once

#include<iostream>
#include<stack>
#include<cstring>
#include<math.h>

using namespace std;

class Notacion
{
    private:
        string infijo;  // Expresion aritmetica en notacion infijo
        string prefijo;  // Expresion aritmetica en notacion prefijo
        string sufijo;  // Expresion aritmetica en notacion sufijo

    public:
        /**
         * @brief Constructor de la clase "Notacion"
         */
        Notacion();

        /**
         * @brief Constructor de la clase "Notacion"
         * @param infijo Expresion en notacion infijo
         */
        Notacion(string infijo);

        /**
         * @brief Metodo que asigna una cadena al atributo "infijo"
         * @param infijo Expresion aritmetica en notacion infijo
         */
        void setInfijo(string infijo);

        /**
         * @brief Metodo que asigna una cadena al atributo "prefijo"
         * @param prefijo Expresion aritmetica en notacion prefijo
         */
        void setPrefijo(string prefijo);

        /**
         * @brief Metodo que asigna una cadena al atributo "sufijo"
         * @param sufijo Expresion aritmetica en notacion sufijo
         */
        void setSufijo(string sufijo);

        /**
         * @brief Metodo que devuelve la cadena almacenada en el atributo "infijo"
         * @return Expresion en notacion infijo
         */
        string getInfijo();

        /**
         * @brief Metodo que devuelve la cadena almacenada en el atributo "prefijo"
         * @return Expresion en notacion prefijo
         */
        string getPrefijo();

        /**
         * @brief Metodo que devuelve la cadena almacenada en el atributo "sufijo"
         * @return Expresion en notacion sufijo
         */
        string getSufijo();

        /**
         * @brief Metodo que convierte la expresion en notacion infijo almacenada en el objeto
         * a notacion prefijo y lo almacena en el atributo "prefijo"
         */
        void infijoAPrefijo();

        /**
         * @brief Metodo que convierte la expresion en notacion infijo almacenada en el objeto
         * a notacion sufijo y lo almacena en el atributo "sufijo"
         */
        void infijoASufijo();

        /**
         * @brief Metodo que convierte la expresion en notacion prefijo almacenada en el objeto
         * a notacion infijo y lo devuelve
         * @return Expresion convertida de notacion prefijo a infijo
         */
        string obtenerPrefijoAInfijo();

        /**
         * @brief Metodo que convierte la expresion en notacion sufijo almacenada en el objeto
         * a notacion infijo y lo devuelve
         * @return Expresion convertida de notacion sufijo a infijo
         */
        string obtenerSufijoAInfijo();

        /**
         * @brief Metodo que evaluara la expresion en notacion prefijo
         * @pre La expresion a evaluar debe ser una expresion que contenga unicamente numeros enteros y operadores
         * @return El resultado de evaluar la expresion
         */
        int evaluarPrefijo();

        /**
         * @brief Metodo que evaluara la expresion en notacion sufijo
         * @pre La expresion a evaluar debe ser una expresion que contenga unicamente numeros enteros y operadores
         * @return El resultado de evaluar la expresion
         */
        int evaluarSufijo();
};

#include"notacion.hpp"
