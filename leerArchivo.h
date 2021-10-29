/**
 * @file leerArchivo.h
 *
 * Declaracion de la clase "Archivo" que es para abrir un archivo, extraer una expresion aritmetica
 * dentro del documento y lo devuelve
 *
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 3.0
 * @date 27/10/2021
 */

#pragma once

#include"arbolExpresiones.h"

#include<fstream>

using namespace std;

class Archivo
{
    private:
        ifstream archivo;  // Archivo
        string expresion;  // Cadena que contendra la expresion aritmetica

    public:
        /**
         * @brief Constructor de la clase "Archivo" que abrira el archivo con el nombre "nombreAch"
         * @param nombreArch Nombre del archivo
         */
        Archivo(string nombreArch);

        /**
         * @brief Metodo que extraera la expresion del documento y lo almacena en el atributo "expresion"
         */
        void extraerExpresion();

        /**
         * @brief Metodo que regresara la cadena "expresion"
         * @return Expresion extraida del documento
         */
        string getExpresion();
};

#include"leerArchivo.hpp"
