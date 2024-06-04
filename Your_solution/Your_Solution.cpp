#include <iostream>
#include <chrono> 
#include <thread>  
using namespace std;
// Función para mover el cursor a una posición específica en la consola
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}
// Función para limpiar la pantalla y establecer un fondo blanco
void clearScreen() {
    cout << "\033[2J\033[1;1H"; // Limpiar la pantalla
    cout << "\033[47m"; // Establecer fondo 
}

// Función de animación de bienvenida
void animacionBienvenida() {
     cout << "\033[47m"; // Establecer fondo 
    string mensaje = "Bienvenido a Your Solution";
    int longitud = mensaje.length();

    // Obtener las dimensiones de la consola (dependiendo del sistema)
    int consola_ancho = 80;  
    int consola_alto = 24;   

    // Calcular la posición para centrar el mensaje
    int x = (consola_ancho - longitud) / 2;
    int y = consola_alto / 2;

    clearScreen(); // Limpiar pantalla y establecer fondo blanco

    // Mostrar la animación del mensaje
    cout << "\033[30m"; // Establecer texto negro
    for (int i = 0; i < longitud; ++i) {
        gotoxy(x + i + 1, y);
        cout << mensaje[i];
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(100)); 
    }
    cout << "\033[0m" << endl; // Restaurar el color predeterminado
}

//Funcion de animacion de salida
void animacionSalida() {
    string mensaje = "Saliendo de Your Solution";
    int longitud = mensaje.length();

    // Obtener las dimensiones de la consola (dependiendo del sistema)
    int consola_ancho = 80;  
    int consola_alto = 24;   

    // Calcular la posición para centrar el mensaje
    int x = (consola_ancho - longitud) / 2;
    int y = consola_alto / 2;

    clearScreen(); // Limpiar pantalla y establecer fondo blanco

    // Mostrar la animación del mensaje
    cout << "\033[30m"; // Establecer texto negro
    for (int i = 0; i < longitud; ++i) {
        gotoxy(x + i + 1, y);
        cout << mensaje[i];
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(100)); 
    }
    cout << "\033[0m" << endl; // Restaurar el color predeterminado
}
int main() {

    animacionBienvenida();

    clearScreen();
    // Variables
    int op = 1;
    int intentos = 0;
    int Copcion_menu = 0 ;
    int menu_elemento;
    //Matriz de simbolos quimicos 
   string simbolos[118] = {
    "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne",
    "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca",
    "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
    "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr",
    "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
    "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
    "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
    "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg",
    "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
    "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
    "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
    "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"
};

string nombres[118] = {
    "Hidrógeno", "Helio", "Litio", "Berilio", "Boro", "Carbono", "Nitrógeno", "Oxígeno", "Flúor", "Neón",
    "Sodio", "Magnesio", "Aluminio", "Silicio", "Fósforo", "Azufre", "Cloro", "Argón", "Potasio", "Calcio",
    "Escandio", "Titanio", "Vanadio", "Cromo", "Manganeso", "Hierro", "Cobalto", "Níquel", "Cobre", "Zinc",
    "Galio", "Germanio", "Arsénico", "Selenio", "Bromo", "Kriptón", "Rubidio", "Estroncio", "Itrio", "Zirconio",
    "Niobio", "Molibdeno", "Tecnecio", "Rutenio", "Rodio", "Paladio", "Plata", "Cadmio", "Indio", "Estaño",
    "Antimonio", "Telurio", "Yodo", "Xenón", "Cesio", "Bario", "Lantano", "Cerio", "Praseodimio", "Neodimio",
    "Prometio", "Samario", "Europio", "Gadolinio", "Terbio", "Disprosio", "Holmio", "Erbio", "Tulio", "Iterbio",
    "Lutecio", "Hafnio", "Tantalio", "Wolframio", "Renio", "Osmio", "Iridio", "Platino", "Oro", "Mercurio",
    "Talio", "Plomo", "Bismuto", "Polonio", "Astato", "Radón", "Francio", "Radio", "Actinio", "Torio",
    "Protactinio", "Uranio", "Neptunio", "Plutonio", "Americio", "Curio", "Berkelio", "Californio", "Einstenio", "Fermio",
    "Mendelevio", "Nobelio", "Laurencio", "Rutherfordio", "Dubnio", "Seaborgio", "Bohrio", "Hassio", "Meitnerio", "Darmstadtio",
    "Roentgenio", "Copernicio", "Nihonio", "Flerovio", "Moscovio", "Livermorio", "Tenesino", "Oganesón"
};
int numerosAtomicos[118] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
    31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
    41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
    51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
    61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
    71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
    81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
    91, 92, 93, 94, 95, 96, 97, 98, 99, 100,
    101, 102, 103, 104, 105, 106, 107, 108, 109, 110,
    111, 112, 113, 114, 115, 116, 117, 118
};

float masasAtomicas[118] = {
    1.008, 4.0026, 6.94, 9.0122, 10.81, 12.011, 14.007, 15.999, 18.998, 20.180,
    22.99, 24.305, 26.982, 28.085, 30.974, 32.06, 35.45, 39.948, 39.098, 40.078,
    44.956, 47.867, 50.942, 51.996, 54.938, 55.845, 58.933, 58.693, 63.546, 65.38,
    69.723, 72.63, 74.922, 78.971, 79.904, 83.798, 85.468, 87.62, 88.906,91.224,
    92.906, 95.95, 98, 101.07, 102.91, 106.42, 107.87, 112.41, 114.82, 118.71,
    121.76, 127.6, 126.9, 131.29, 132.91, 137.33, 138.91, 140.12, 140.91, 144.24,
    145, 150.36, 151.96, 157.25, 158.93, 162.5, 164.93, 167.26, 168.93, 173.05,
    174.97, 178.49, 180.95, 183.84, 186.21, 190.23, 192.22, 195.08, 196.97, 200.59,
    204.38, 207.2, 208.98, 209, 210, 222, 223, 226, 227, 232.04,
    231.04, 238.03, 237, 244, 243, 247, 247, 251, 252, 257,
    258, 259, 262, 267, 268, 271, 272, 277, 276, 281,
    280, 285, 285, 287, 289,291,294,294
}; 



    // Credenciales requeridas 
    string password = "pass12345";
    string user = "user";
    string Cuser, Cpass;
    
    clearScreen(); 
    while (op != 2 && intentos < 3) {
        gotoxy(13, 9);
        cout << "DIGITA TU USUARIO : "; 
        getline(cin, Cuser); 
        gotoxy(10, 13);
        cout << "DIGITA TU CONTRASEÑA : ";
        getline(cin, Cpass); 

        // Login
        if (Cuser == user && Cpass == password) {
            clearScreen(); 
            gotoxy(10, 5);
            cout << "Bienvenido " + user + "!\n\n";
             gotoxy(10, 7);
            cout<<"------------MENU------------\n"<<endl;
            cout<<"1) Leer un elemento químico\n\n2) Calcular masa atómica de un elemento químico\n\n3) Salir.\n\n";

            
            cout<<"Digita una opcion : ";
            cin>>Copcion_menu;

           switch (Copcion_menu) {
                case 1: {
                    cout << "Lista de elementos químicos:\n";
                    for (int i = 0; i < 118; i++) {
                        cout << i + 1 << ": " << nombres[i] << endl;
                    }
                    cout << "Digite una opción dentro del rango 1-118: ";
                    int opcionElemento;
                    cin >> opcionElemento;

                    if (opcionElemento >= 1 && opcionElemento <= 118) {
                    cout << "Elemento " << opcionElemento << ": " << nombres[opcionElemento - 1] << endl;
                    cout << "Simbolo  " << opcionElemento << ": " << simbolos[opcionElemento - 1]<< endl;
                    cout << "Numero Atomico "<< opcionElemento <<":  "<<numerosAtomicos[opcionElemento -1] <<endl;
                    } else {
                    cout << "Opción inválida.\n";
                    animacionSalida();
                }
                break;
                }
                case 2:{
                    for (int i = 0; i < 118; i++) {
                        cout << i + 1 << ": " << nombres[i] << endl;
                    }
                    cout << "Digite una opción dentro del rango 1-118: ";
                    int opcionElemento;
                    cin >> opcionElemento;
                    cout << "\nSeleccione un elemento químico para calcular su masa atómica:\n";

                    if (opcionElemento >= 1 && opcionElemento <= 118) {
                    cout << "Elemento " << opcionElemento << ": " << nombres[opcionElemento - 1] <<" : "<<" Masa Atomica "<<" : " << masasAtomicas[opcionElemento-1]<< endl;
                    } else {
                    cout << "Opción inválida.\n";
                    animacionSalida();
                }
                    break;
                }                   
                    
                case 3:
                    cout << "Adiós!\n";
                    animacionSalida();
                    break;
                default:
                    cout << "Opción inválida. Intente de nuevo.\n";
                    animacionSalida();
                break;
            }
            break;
        } else {
            clearScreen();
            cout << "Credenciales incorrectas. Intenta de nuevo." << endl;
            intentos++; // Incrementar el contador de intentos
            
        }
    }

    if (intentos == 3) {
        cout << "Has excedido el número máximo de intentos. Adiós.";
        animacionSalida();
    }

    return 0;
}