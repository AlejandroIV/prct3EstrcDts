/**
 * @file main.cpp
 *
 * Codigo para extraer una expresion aritmetica de un documento, convertirlo de notacion Infijo a Sufijo/Prefijo y viceversa,
 * evaluar la expresion, crear el arbol de expresion e imprimir los diferentes recorridos del arbol.
 *
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 1.0
 * @date 27/10/2021
 */

#include"leerArchivo.h"

int main()
{
    string cadena = "";

    cout << "Ingresa el nombre del archivo que contiene la expresion aritmetica (con extension): ";
    cin >> cadena;
    cin.clear();
    cin.ignore(1000, '\n');

    // Abre el archivo
    Archivo archivoIn(cadena);
    // Extrae la expresion del archivo
    archivoIn.extraerExpresion();

    system("clear");

    unsigned short int opcion = 0;
    cout << "En cual notacion esta escrita la expresion en el archivo?" << endl;
    cout << "1 - Infijo" << endl;
    cout << "2 - Prefijo" << endl;
    cout << "3 - Sufijo" << endl;
    do  {
        cout << "Opcion: ";
        cin >> opcion;
        cin.clear();
        cin.ignore(1000, '\n');
        // Si la opcion es valida
        if(opcion > 0 && opcion < 4)  {
            break;
        }
        // Si la opcion es invalida
        else  {
            cout << "\nOpcion invalida\n" << endl;
        }
    }  while(opcion < 1 || opcion > 3);

    system("clear");

    Notacion expr;

    // Arreglo booleano auxiliar para representar las notaciones disponibles en "expr"
    bool auxNot[3] = {false, false, false};

    // Establece la notacion de entrada
    switch (opcion) {
        // Si la notacion de la expresion escrita en el archivo es infijo
        case 1:
            expr.setInfijo(archivoIn.getExpresion());
            auxNot[0] = true;
            break;

        // Si la notacion de la expresion escrita en el archivo es prefijo
        case 2:
            expr.setPrefijo(archivoIn.getExpresion());
            auxNot[1] = true;
            break;

        // Si la notacion de la expresion escrita en el archivo es sufijo
        case 3:
            expr.setSufijo(archivoIn.getExpresion());
            auxNot[2] = true;
            break;
    }

    ArbolBinario<string> arbolExprs;
    // Variable auxiliar para saber si ya se creo el arbol de expresiones
    bool arbolCreado = false;

    do  {
        cout << "Notaciones disponibles:";
        if(auxNot[0])  {
            cout << " infijo";
        }
        if(auxNot[1])  {
            cout << " prefijo";
        }
        if(auxNot[2])  {
            cout << " sufijo";
        }

        cout << "\n\nElija una de las siguientes opciones\n" << endl;
        // Si esta la expresion en notacion infijo almacenada en el objeto "expr"
        if(auxNot[0])  {
            cout << "1 - Convertir la expresion de infijo a prefijo" << endl;
            cout << "2 - Convertir la expresion de infijo a sufijo" << endl;
        }
        if(auxNot[1])  {
            cout << "3 - Convertir la expresion de prefijo a infijo" << endl;
        }
        if(auxNot[2])  {
            cout << "4 - Convertir la expresion de sufijo a infijo" << endl;
        }
        if(auxNot[1])  {
            cout << "5 - Evaluar la expresion prefijo" << endl;
        }
        if(auxNot[2])  {
            cout << "6 - Evaluar la expresion sufijo" << endl;
        }
        if(auxNot[1])  {
            cout << "7 - Crear arbol de expresiones a partir de la expresion en notacion prefijo" << endl;
        }
        if(auxNot[2])  {
            cout << "8 - Crear arbol de expresiones a partir de la expresion en notacion sufijo" << endl;
        }
        if(arbolCreado)  {
            cout << "9 - Recorrer el arbol de expresiones en inorden" << endl;
            cout << "10 - Recorrer el arbol de expresiones en preorden" << endl;
            cout << "11 - Recorrer el arbol de expresiones en postorden" << endl;
        }
        cout << "0 - Salir" << endl;

        cout << "Opcion: ";
        cin >> opcion;
        cin.clear();
        cin.ignore(1000, '\n');

        switch (opcion) {
            case 1:
                // Condicional para evitar errores
                if(!auxNot[0])  {
                    system("clear");
                    continue;
                }
                auxNot[1] = true;
                expr.infijoAPrefijo();
                cout << "\nPrefijo: " << expr.getPrefijo() << endl;
                cout << "\nPresione Enter para continuar";
                while(cin.get() != '\n');
                system("clear");
                break;

            case 2:
                // Condicional para evitar errores
                if(!auxNot[0])  {
                    system("clear");
                    continue;
                }
                auxNot[2] = true;
                expr.infijoASufijo();
                cout << "\nSufijo: " << expr.getSufijo() << endl;
                cout << "\nPresione Enter para continuar";
                while(cin.get() != '\n');
                system("clear");
                break;

            case 3:
                // Condicional para evitar errores
                if(!auxNot[1])  {
                    system("clear");
                    continue;
                }
                // Si no hay notacion infijo aun
                if(!auxNot[0])  {
                    expr.setInfijo(expr.obtenerPrefijoAInfijo());
                    auxNot[0] = true;
                }
                cout << "\nInfijo: " << expr.getInfijo() << endl;
                cout << "\nPresione Enter para continuar";
                while(cin.get() != '\n');
                system("clear");
                break;

            case 4:
                // Condicional para evitar errores
                if(!auxNot[2])  {
                    system("clear");
                    continue;
                }
                // Si no hay notacion infijo aun
                if(!auxNot[0])  {
                    expr.setInfijo(expr.obtenerSufijoAInfijo());
                    auxNot[0] = true;
                }
                cout << "\nInfijo: " << expr.getInfijo() << endl;
                cout << "\nPresione Enter para continuar";
                while(cin.get() != '\n');
                system("clear");
                break;

            case 5:
                // Condicional para evitar errores
                if(!auxNot[1])  {
                    system("clear");
                    continue;
                }
                cout << "\nEl resultado despues de evaluar la expresion en notacion prefijo es: ";
                cout << expr.evaluarPrefijo() << endl;
                cout << "\nPresione Enter para continuar";
                while(cin.get() != '\n');
                system("clear");
                break;

            case 6:
                // Condicional para evitar errores
                if(!auxNot[2])  {
                    system("clear");
                    continue;
                }
                cout << "\nEl resultado despues de evaluar la expresion en notacion sufijo es: ";
                cout << expr.evaluarSufijo() << endl;
                cout << "\nPresione Enter para continuar";
                while(cin.get() != '\n');
                system("clear");
                break;

            case 7:
                // Condicional para evitar errores
                if(!auxNot[1])  {
                    system("clear");
                    continue;
                }
                arbolExprs.prefijoAArbol(expr.getPrefijo());
                arbolCreado = true;
                system("clear");
                cout << "Arbol creado\n" << endl;
                break;

            case 8:
                // Condicional para evitar errores
                if(!auxNot[2])  {
                    system("clear");
                    continue;
                }
                arbolExprs.sufijoAArbol(expr.getSufijo());
                arbolCreado = true;
                system("clear");
                cout << "Arbol creado\n" << endl;
                break;

            case 9:
                // Condicional para evitar errores
                if(!arbolCreado)  {
                    system("clear");
                    continue;
                }
                cout << "\nInorden: ";
                arbolExprs.inorden(arbolExprs.getNodoRaiz());
                cout << "\nPresione Enter para continuar";
                while(cin.get() != '\n');
                system("clear");
                break;

            case 10:
                // Condicional para evitar errores
                if(!arbolCreado)  {
                    system("clear");
                    continue;
                }
                cout << "\nPreorden: ";
                arbolExprs.preorden(arbolExprs.getNodoRaiz());
                cout << "\nPresione Enter para continuar";
                while(cin.get() != '\n');
                system("clear");
                break;

            case 11:
                // Condicional para evitar errores
                if(!arbolCreado)  {
                    system("clear");
                    continue;
                }
                cout << "\nPostorden: ";
                arbolExprs.postorden(arbolExprs.getNodoRaiz());
                cout << "\nPresione Enter para continuar";
                while(cin.get() != '\n');
                system("clear");
                break;

            default:
                system("clear");
                continue;
                break;
        }
    }  while(opcion > 0 && opcion < 12);

    system("pause");
    return 0;
}
