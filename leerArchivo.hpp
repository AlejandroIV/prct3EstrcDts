/**
 * @file leerArchivo.hpp
 *
 * Definicion de la clase "Archivo"
 *
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 3.0
 * @date 27/10/2021
 */

Archivo::Archivo(string nombreArch)
{
    // Abre el archivo
    archivo.open(nombreArch, ios::in);

    // Comprueba si se abrio correctamente el archivo
    if(!archivo.is_open())  {
        cout << "No fue posible abrir el archivo" << endl;
        exit(1);
    }

    // Inicializa las demas variables de clase
    expresion = "";
}

void Archivo::extraerExpresion()
{
    // Extrae la expresion que esta en la primera linea del documento
    getline(archivo, expresion);

    // Se posiciona al inicio del archivo
    archivo.clear();
    archivo.seekg(0, archivo.beg);

    // Cierra el archivo
    archivo.close();
}

string Archivo::getExpresion()
{
    // Regresa la cadena almacenada en el atributo "expresion"
    return expresion;
}
