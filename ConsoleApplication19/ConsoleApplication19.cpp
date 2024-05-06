#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

//Esta funcion esta disenada para guardar la informacion entrada por el usuario en un archivo de txt.
void salvaInfo(const string& txt, const string& data) {
    ofstream texto(txt);
    //Aqui se chequea si el archivo abrio para ser escrito.
    if (texto.is_open()) {
        texto << data << "\n";
        texto.close();
    }
}
//Esta funcion esta disenada para leer la informacion dentro del archivo txt.
string subirInfo(const string& txt) {
    ifstream texto(txt);
    string data, line;
    //Aqui se chequea si el archivo txt abrio para ser leido.
    if (texto.is_open()) {
        //Este loop lee la informacion del archivo txt linea por linea y las guarda en un string.
        while (getline(texto, line)) {
            data += line + "\n";
        }
        texto.close();
    }
    return data;
}
//Usamos "class" para manejar los passwords.
class ManejadorDePassword {
private:
    unordered_map<string, string> passwords;

public:
    //Esta funcion ingresa un par nuevo de usuario-password para "passwords" en unordered map y luego imprimir el mensaje.
    void palabraSecreta(const string& usuario, const string& password) {
        passwords[usuario] = password;
        cout << "Password agregado exitosamente." << endl;
    }

    //Esta funcion chequea si hay passwords guardados, si no, imprime un mensaje confirmandolo. Si encuentra passwords guardados, los imprime todos.
    void demuestraPalabraSecretas() const {
        if (passwords.empty()) {
            cout << "Ningun password registrado." << endl;
        }
        else {
            cout << "Passwords guardados." << endl;
            for (const auto& pair : passwords) {
                cout << "usuario: " << pair.first << ", Password: " << pair.second << endl;
            }
        }
    }
};
//Esta funcion genera un password al asar.
static const char alfaNum[] =
"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
int tamano = sizeof(alfaNum) - 1;

int main()
{
    //Registramos nuestras variables
    ManejadorDePassword manager;
    int seleccion1, seleccion2;
    string cuenta, usuario, password, txt;

    cout << "---------------------------------------------" << endl;
    cout << "       Bienvenido/a GatiyuBrave" << endl;
    cout << "           Password Manager" << endl;
    cout << "---------------------------------------------" << endl;
    do {

        cout << "\n";
        cout << "\n";
        cout << "1.Password Manager \n";
        cout << "2.Password Generator \n";
        cout << "3.Salir \n";
        cout << "\n";
        cin >> seleccion1;
        system("cls");
        if (seleccion1 == 1) {
            //Usamos el loop principal del programa, un do while.
            do {
                //Escribimos nuestro "Gui" para la interaccion del usuario.
                cout << "\n";
                cout << "Password Manager: \n";
                cout << "\n";
                cout << "1.Ingrese una cuenta \n";
                cout << "2.Muestre sus cuentas \n";
                cout << "3.Salir \n";
                cout << "Seleccione: ";
                cin >> seleccion2;
                system("cls");

                //Comensamos una condicion para que el usuario seleccione las opciones
                if (seleccion2 == 1) {
                    cout << "Entre el tipo de Cuenta (Ejemplo: facebook, instagram): ";
                    cin >> cuenta;
                    cout << "Entre su Usuario: ";
                    cin >> usuario;
                    cout << "Entre su Password: ";
                    cin >> password;
                    txt = cuenta + " " + usuario + " " + password;
                    salvaInfo("data.txt", txt);
                    manager.palabraSecreta(usuario, password);
                }
                else if (seleccion2 == 2) {
                    string InformacionCargada = subirInfo("data.txt");
                    cout << "Informacion: " << endl << InformacionCargada << endl;
                }
                else if (seleccion2 == 3) {
                    system("cls");
                    cout << "Saliendo del programa... \n";
                    Sleep(2000);
                }
                else {
                    cout << "Error. Vuelva a seleccionar. \n";
                }
            } while (seleccion2 != 3);
        }
        else if (seleccion1 == 2) {
            cout << "Entre la cantidad de letras deseada: \n";
            cin >> tamano;
            if (tamano > 99) {
                cout << "Error, el numero debe ser menor a 99.";
            }
            else {
                cout << "Su password generado es: ";
                for (int i = 0; i < tamano; i++) {
                    cout << alfaNum[rand() % tamano];
                }
            }

        }
        else if (seleccion1 == 3) {
            system("cls");
            cout << "Saliendo del programa... \n";
            Sleep(2000);
        }
        else {
            cout << "Error. Vuelva a seleccionar. \n";
        }
    } while (seleccion1 != 3);
    return 0;
}