#include <stdio.h>
#include <string.h>

void gotoxy(int x, int y) {
    printf("\x1b[%d;%dH", y, x);
}

int main() {
    
    char password[20] = "12345";
    char inputPassword[20];
    
    int option;
    int suboption;
    
    
    char elementos[118][30] = {
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
    
    float masaAtomica[118] = {
        1.008, 4.0026, 6.94, 9.0122, 10.81, 12.011, 14.007, 15.999, 18.998, 20.180,
        // Resto de masas atomicas...
    };
    
    printf("Ingrese la contraseña para acceder al programa: ");
    scanf("%s", inputPassword);
    
    if (strcmp(password, inputPassword) != 0) {
        printf("\nContraseña incorrecta. Saliendo del programa...\n");
        return 0;
    }
    
    printf("\nBienvenido al programa de cálculo de masa atómica de los elementos químicos\n");
    
    do {
        printf("\n1. Leer un elemento químico\n");
        printf("2. Calcular masa atómica de un elemento químico\n");
        printf("3. Salir\n");
        printf("\nSeleccione una opción: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                printf("\nSeleccione un elemento químico:\n");
                for (int i = 0; i < 118; i++) {
                    printf("%d. %s\n", i+1, elementos[i]);
                }
                printf("\nIngrese el número correspondiente al elemento químico que desea leer: ");
                scanf("%d", &suboption);
                printf("Elemento químico seleccionado: %s\n", elementos[suboption-1]);
                break;
            case 2:
                printf("\nSeleccione un elemento químico para calcular su masa atómica:\n");
                for (int i = 0; i < 118; i++) {
                    printf("%d. %s\n", i+1, elementos[i]);
                }
                printf("\nIngrese el número correspondiente al elemento químico del cual desea calcular la masa atómica: ");
                scanf("%d", &suboption);
                printf("Masa atómica del elemento químico seleccionado (%s): %.3f\n", elementos[suboption-1], masaAtomica[suboption-1]);
                break;
            case 3:
                break;
            default:
                printf("\nOpción inválida. Intente de nuevo.\n");
                break;
        }
    } while (option != 3);
    
    printf("\nGracias por utilizar el programa. ¡Hasta luego!\n");
    
    return 0;
}
