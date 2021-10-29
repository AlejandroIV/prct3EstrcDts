/**
 * @file notacion.hpp
 *
 * Definicion de la clase "Notacion"
 *
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 1.0
 * @date 27/10/2021
 */

#include"notacion.h"

// Funcion que regresara "True" en caso de "x" sea un operador
inline bool esOperador(char x)
{
    return (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '%');
}

// Funcion que regresara "True" en caso de "x" sea digito de un numero
inline bool esDigito(char x)
{
    return (x == '0' || x == '1' || x == '2' || x == '3' || x == '4' || x == '5' || x == '6' || x == '7' || x == '8' || x == '9');
}

// Funcion que regresara un numero asociado a la precedencia de los operadores
int precedencia(char x)
{
    // '^' tiene mayor precedencia que '*' y '/' tiene mayor precedencia que '+' y '-'
    if(x == '+' || x == '-')  return 0;
    if(x == '*' || x == '/')  return 1;
    if(x == '^')  return 2;
    return -1;
}

// Funcion que regresara un numero asociado a la asociacion de los operadores
int asociacion(char x)
{
    // Si la asociacion es der-izq
    if(x == '^')  return -1;
    // Si la asociacion es izq-der
    if(x == '+' || x == '-' || x == '*' || x == '/' || x == '%')  return 1;
    return 0;
}

int strToInt(string strNumero, int cantDigitos)
{
    // Para las unidades, decenas, centenas, etc
    int cifra = 1;
    int numero = 0;

    // Bucle que convierte la cadena en un entero
    while(cantDigitos > 0)  {
        // Identifica la cifra
        switch(strNumero[cantDigitos - 1])  {
            case '0':
                numero += 0;
                break;

            case '1':
                numero += 1 * cifra;
                break;

            case '2':
                numero += 2 * cifra;
                break;

            case '3':
                numero += 3 * cifra;
                break;

            case '4':
                numero += 4 * cifra;
                break;

            case '5':
                numero += 5 * cifra;
                break;

            case '6':
                numero += 6 * cifra;
                break;

            case '7':
                numero += 7 * cifra;
                break;

            case '8':
                numero += 8 * cifra;
                break;

            case '9':
                numero += 9 * cifra;
                break;

            case '-':
                numero *= -1;
                break;
        }
        cifra *= 10;  // Para la siguiente cifra
        cantDigitos--;
    }

    return numero;
}

// Funcion que evaluara una expresion aritmetica en forma de cadena y regresa una cadena con el resultado
string evaluarOp(string operando1, char operador, string operando2)
{
    int resultado = 0;

    // Pirmero identifica que operador esta almacenado en "operador" para realizar la operacion
    switch(operador)  {
        case '+':
            resultado = strToInt(operando1, operando1.length()) + strToInt(operando2, operando2.length());
            break;

        case '-':
            resultado = strToInt(operando1, operando1.length()) - strToInt(operando2, operando2.length());
            break;

        case '*':
            resultado = strToInt(operando1, operando1.length()) * strToInt(operando2, operando2.length());
            break;

        case '/':
            resultado = strToInt(operando1, operando1.length()) / strToInt(operando2, operando2.length());
            break;

        case '^':
            resultado = pow(strToInt(operando1, operando1.length()), strToInt(operando2, operando2.length()));
            break;

        case '%':
            resultado = strToInt(operando1, operando1.length()) % strToInt(operando2, operando2.length());
            break;
    }

    // Regresa el resultado convertido a cadena
    return(to_string(resultado));
}

Notacion::Notacion()
{
    // Inicializa los atributos del objeto con una cadena vacia
    infijo = "";
    prefijo = "";
    sufijo = "";
}

Notacion::Notacion(string infijo)
{
    // Inicializa los atributos del objeto
    this->infijo = infijo;
    prefijo = "";
    sufijo = "";
}

void Notacion::setInfijo(string infijo)
{
    // Asigna una cadena al atributo "infijo"
    this->infijo = infijo;
}

void Notacion::setPrefijo(string prefijo)
{
    // Asigna una cadena al atributo "prefijo"
    this->prefijo = prefijo;
}

void Notacion::setSufijo(string sufijo)
{
    // Asigna una cadena al atributo "sufijo"
    this->sufijo = sufijo;
}

string Notacion::getInfijo()
{
    // Regresa la cadena almacenada en el atributo "Infijo"
    return infijo;
}

string Notacion::getPrefijo()
{
    // Regresa la cadena almacenada en el atributo "Prefijo"
    return prefijo;
}

string Notacion::getSufijo()
{
    // Regresa la cadena almacenada en el atributo "Sufijo"
    return sufijo;
}

void Notacion::infijoAPrefijo()
{
    // Pila que contendra los operadores
    stack<char> P;
    // Vacia (en caso de tener algo) la cadena del atributo "sufijo"
    prefijo = "";

    // Bucle que se repetira hasta que llegue al final de la cadena "infijo"
    for(int i = infijo.length(); i >= 0 ; i--)  {
        // Condicional que se saltara los espacios
        if(infijo[i] == ' ')  {
            continue;
        }

        // Si el siguiente caracter es un parentesis que cierra
        if(infijo[i] == ')')  {
            // Entra a la pila "P"
            P.push(infijo[i]);
        }
        // Si el siguiente caracter es un parentesis que abre
        else if(infijo[i] == '(')  {
            // Saca los operadores de la pila "P" y los concatena con "prefijo" hasta encontrar ')'
            while(!P.empty() && P.top() != ')')  {
                prefijo += ' ';
                prefijo += P.top();
                P.pop();
            }
            // Elimina el parentesis ')' que queda
            P.pop();
        }
        // Si el siguiente caracter es un operando lo concatena con "prefijo"
        else if(!esOperador(infijo[i]))  {
            prefijo += ' ';
            prefijo += infijo[i];
            // En caso de que el numero tenga mas de un digito
            while(esDigito(infijo[i - 1]) && infijo[i - 1] != ' ')  {
                i--;
                prefijo += infijo[i];
            }
        }
        // Si el siguiente caracter es un operador
        else  {
            // Mientras al frente de la pila "P" haya un operador de mayor precedencia y no este vacia
            while(!P.empty() && precedencia(P.top()) > precedencia(infijo[i]))  {
                // Concatena el frente de la pila "P" con "prefijo" y saca ese nodo de la pila
                prefijo += ' ';
                prefijo += P.top();
                P.pop();
            }
            /* Si la pila "P" esta vacia o tiene un parentesis al frente, o el operador al frente de la pila
               es de menor precedencia que "infijo[i]" */
            if(P.empty() || precedencia(P.top()) < precedencia (infijo[i]))  {
                // "infijo[i]" entra a la pila
                P.push(infijo[i]);
            }
            // Si al frente de la pila "P" hay un operador de igual precedencia
            else  {
                // Si la asociacion es der-izq
                if(asociacion(infijo[i]) < 0)  {
                    // Concatena el operador al frente de la pila "P" con "prefijo" y saca ese nodo de la pila
                    prefijo += ' ';
                    prefijo += P.top();
                    P.pop();
                }
                // El nuevo operador entra a la pila
                P.push(infijo[i]);
            }
        }
    }

    // Termina de vaciar la pila "P"
    while(!P.empty())  {
        prefijo += ' ';
        prefijo += P.top();
        P.pop();
    }

    // Invirte la cadena "prefijo"
    string auxTmp(prefijo);
    int tamanho = prefijo.length();
    prefijo = "";
    for(int y = (tamanho - 1); y >= 0; y--)  {
        if(esOperador(auxTmp[y]) || esDigito(auxTmp[y]) || auxTmp[y] == ' ')  {
            prefijo += auxTmp[y];
        }
    }

    // Elimina el espacio al final de "prefijo"
    sufijo = sufijo.substr(0, (tamanho - 1));
}

void Notacion::infijoASufijo()
{
    // Pila que contendra los operadores
    stack<char> P;
    // Vacia (en caso de tener algo) la cadena del atributo "sufijo"
    sufijo = "";

    // Bucle que se repetira hasta que llegue al final de la cadena "infijo"
    for(int i = 0; i < infijo.length(); i++)  {
        // Condicional que se saltara los espacios
        if(infijo[i] == ' ')  {
            continue;
        }

        // Si el siguiente caracter es un parentesis que abre
        if(infijo[i] == '(')  {
            // Entra a la pila "P"
            P.push(infijo[i]);
        }
        // Si el siguiente caracter es un parentesis que cierra
        else if(infijo[i] == ')')  {
            // Saca los operadores de la pila "P" y los concatena con "sufijo" hasta encontrar '('
            while(!P.empty() && P.top() != '(')  {
                sufijo += ' ';
                sufijo += P.top();
                P.pop();
            }
            // Elimina el parentesis '(' que queda
            P.pop();
        }
        // Si el siguiente caracter es un operando lo concatena con "sufijo"
        else if(!esOperador(infijo[i]))  {
            sufijo += ' ';
            sufijo += infijo[i];
            // En caso de que el numero tenga mas de un digito
            while(esDigito(infijo[i + 1]) && infijo[i + 1] != ' ')  {
                i++;
                sufijo += infijo[i];
            }
        }
        // Si el siguiente caracter es un operador
        else  {
            // Mientras al frente de la pila "P" haya un operador de mayor precedencia y no este vacia
            while(!P.empty() && precedencia(P.top()) > precedencia(infijo[i]))  {
                // Concatena el frente de la pila "P" con "sufijo" y saca ese nodo de la pila
                sufijo += ' ';
                sufijo += P.top();
                P.pop();
            }
            /* Si la pila "P" esta vacia o tiene un parentesis al frente, o el operador al frente de la pila
               es de menor precedencia que "infijo[i]" */
            if(P.empty() || precedencia(P.top()) < precedencia (infijo[i]))  {
                // "infijo[i]" entra a la pila
                P.push(infijo[i]);
            }
            // Si al frente de la pila "P" hay un operador de igual precedencia
            else  {
                // Si la asociacion es izq-der
                if(asociacion(infijo[i]) > 0)  {
                    // Concatena el operador al frente de la pila "P" con "sufijo" y saca ese nodo de la pila
                    sufijo += ' ';
                    sufijo += P.top();
                    P.pop();
                }
                // El nuevo operador entra a la pila
                P.push(infijo[i]);
            }
        }
    }

    // Termina de vaciar la pila "P"
    while(!P.empty())  {
        sufijo += ' ';
        sufijo += P.top();
        P.pop();
    }

    // Elimina el espacio al principio de "sufijo"
    sufijo = sufijo.substr(1);
}

string Notacion::obtenerPrefijoAInfijo()
{
    // Pila que contendra las expresiones que se vayan formando
    stack<string> P;
    // Contador de digitos
    int auxContDig = 1;

    // Bucle que recorrera "prefijo" de derecha a izquierda
    for(int i = (prefijo.length() - 1); i >= 0; i--)  {
        // Condicional que se saltara los espacios
        if(prefijo[i] == ' ')  {
            continue;
        }

        // Si el siguiente caracter es un operador
        if(esOperador(prefijo[i]))  {
            // Saca dos operandos de la pila
            string op1 = P.top();  P.pop();
            string op2 = P.top();  P.pop();

            // Concatena los operandos y agrupa la expresion entre parentesis
            string tmp = "(" + op1 + prefijo[i] + op2 + ")";

            // "tmp" entra a la pila "P"
            P.push(tmp);
        }
        // Si el siguiente caracter es un operando
        else  {
            // En caso de que el numero tenga mas de un digito
            while(esDigito(prefijo[i - auxContDig]) && prefijo[i - auxContDig] != ' ')  {
                auxContDig++;
            }
            // Si hay un numero con mas de un digito
            if(auxContDig != 1)  {
                // El operando (numero de mas de un diigto) entra a la pila "P"
                P.push(string(prefijo.substr((i - auxContDig), auxContDig + 1)));
                // Actualiza "i"
                i -= auxContDig;
            }
            // Pero si el numero solo tiene un digito
            else{
                // El operando (un digito o letra) entra a la pila "P"
                P.push(string(1, prefijo[i]));
            }

            // Reinicia contador
            auxContDig = 1;
        }
    }

    // Regresa la expresion en notacion infijo
    return P.top();
}

string Notacion::obtenerSufijoAInfijo()
{
    // Pila que contendra las expresiones que se vayan formando
    stack<string> P;
    // Contador de digitos
    int auxContDig = 1;

    // Bucle que recorrera "sufijo" de izquierda a derecha
    for(int i = 0; i < sufijo.length(); i++)  {
        // Condicional que se saltara los espacios
        if(sufijo[i] == ' ')  {
            continue;
        }

        // Si el siguiente caracter es un operador
        if(esOperador(sufijo[i]))  {
            // Saca dos operandos de la pila
            string op2 = P.top();  P.pop();
            string op1 = P.top();  P.pop();

            // Concatena los operandos y agrupa la expresion entre parentesis
            string tmp = "(" + op1 + sufijo[i] + op2 + ")";

            // "tmp" entra a la pila "P"
            P.push(tmp);
        }
        // Si el siguiente caracter es un operando
        else  {
            // En caso de que el numero tenga mas de un digito
            while(esDigito(sufijo[i + auxContDig]) && sufijo[i + auxContDig] != ' ')  {
                auxContDig++;
            }
            // Si hay un numero con mas de un digito
            if(auxContDig != 1)  {
                // El operando (numero de mas de un diigto) entra a la pila "P"
                P.push(string(sufijo.substr(i, auxContDig)));
                // Actualiza "i"
                i += auxContDig;
            }
            // Pero si el numero solo tiene un digito
            else{
                // El operando (un digito o letra) entra a la pila "P"
                P.push(string(1, sufijo[i]));
            }

            // Reinicia contador
            auxContDig = 1;
        }
    }

    // Regresa la expresion en notacion infijo
    return P.top();
}

int Notacion::evaluarPrefijo()
{
    // Pila que contendra los resultados de las evaluaciones
    stack<string> P;
    // Contador de digitos
    int auxContDig = 1;

    // Bucle que recorrera "prefijo" de derecha a izquierda
    for(int i = (prefijo.length() - 1); i >= 0; i--)  {
        // Condicional que se saltara los espacios
        if(prefijo[i] == ' ')  {
            continue;
        }

        // Si el sigiuente caracter es un operador
        if(esOperador(prefijo[i]))  {
            // Extrae dos operandos para aplicarles un operador
            string A = P.top();
            P.pop();
            string B = P.top();
            P.pop();
            // El resultado de aplicar el operador a los operandos extraidos se almacena en "C"
            string C = evaluarOp(A, prefijo[i], B);
            P.push(C);
        }
        // Si el siguiente caracter es un operando
        else{
            // En caso de que el numero tenga mas de un digito
            while(esDigito(prefijo[i - auxContDig]) && prefijo[i - auxContDig] != ' ')  {
                auxContDig++;
            }
            // Si hay un numero con mas de un digito
            if(auxContDig != 1)  {
                // El operando (numero de mas de un diigto) entra a la pila "P"
                P.push(string(prefijo.substr((i - auxContDig), auxContDig + 1)));
                // Actualiza "i"
                i -= auxContDig;
            }
            // Pero si el numero solo tiene un digito
            else{
                // El operando (un digito o letra) entra a la pila "P"
                P.push(string(1, prefijo[i]));
            }

            // Reinicia contador
            auxContDig = 1;
        }
    }

    return strToInt(P.top(), P.top().length());
}

int Notacion::evaluarSufijo()
{
    // Pila que contendra los resultados de las evaluaciones
    stack<string> P;
    // Contador de digitos
    int auxContDig = 1;

    // Bucle que recorrera "sufijo" de izquierda a derecha
    for(int i = 0; i < sufijo.length(); i++)  {
        // Condicional que se saltara los espacios
        if(sufijo[i] == ' ')  {
            continue;
        }

        // Si el sigiuente caracter es un operador
        if(esOperador(sufijo[i]))  {
            // Extrae dos operandos para aplicarles un operador
            string A = P.top();
            P.pop();
            string B = P.top();
            P.pop();
            // El resultado de aplicar el operador a los operandos extraidos se almacena en "C"
            string C = evaluarOp(B, sufijo[i], A);
            P.push(C);
        }
        // Si el siguiente caracter es un operando
        else{
            // En caso de que el numero tenga mas de un digito
            while(esDigito(sufijo[i + auxContDig]) && sufijo[i + auxContDig] != ' ')  {
                auxContDig++;
            }
            // Si hay un numero con mas de un digito
            if(auxContDig != 1)  {
                // El operando (numero de mas de un diigto) entra a la pila "P"
                P.push(string(sufijo.substr(i, auxContDig)));
                // Actualiza "i"
                i += auxContDig;
            }
            // Pero si el numero solo tiene un digito
            else{
                // El operando (un digito o letra) entra a la pila "P"
                P.push(string(1, sufijo[i]));
            }

            // Reinicia contador
            auxContDig = 1;
        }
    }

    return strToInt(P.top(), P.top().length());
}
