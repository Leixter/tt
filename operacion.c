#include <stdio.h>
#include <string.h>
#include "operacion.h"
#include "lectura.h"

void ingresarTrabajador(char nombre[NOMBRE], char clave[NOMBRE]) {
    printf("Ingrese su nombre: ");
    scanf("%s", nombre);
    do {
        printf("Ingrese contrasena de acceso: ");
        scanf("%s", clave);
        if (strcmp(clave, CONTRASEÑA) != 0) {
            printf("Contrasena incorrecta. Intente de nuevo.\n");
        }
    } while (strcmp(clave, CONTRASEÑA) != 0);
}

void ingresarMedicamentos(int Num_med, char Name_med[][NOMBRE], int cantidades[], float precios[], float descuentos[], char caducidades[][NOMBRE]) {
    for (int i = 0; i < Num_med; i++) {
        printf(" Medicamento %d :\n", i + 1);
        printf("Nombre: ");
        getchar(); 
        fgets(Name_med[i], NOMBRE, stdin);
        Name_med[i][strcspn(Name_med[i], "\n")] = '\0';  
        cantidades[i]= leerEnteroPositivo("Cantidad: ");
        precios[i]=leerFlotantePositivo("Precio unitario: ");
        descuentos[i]=leerEnteroEntre("Porcentaje Descuento (Ingrese 0 si no lo tiene): ",-1,100);
        printf("Fecha de caducidad (DD/MM/AAAA): ");
        scanf("%s", caducidades[i]);
    }
}

void mostrarMedicamentos(char Name_med[][NOMBRE], int cantidades[], float precios[], float descuentos[], char caducidades[][NOMBRE], int Num_med) {
    printf("%-15s %8s %10s %11s %-10s %10s\n", "Nombre", "Cantidad", "Precio", "Descuento", "Caducidad", "Precio Final");
    printf("------------------------------------------------------------------------\n");
    for (int i = 0; i < Num_med; i++) {
        float precioFinal = precios[i] * (1 - descuentos[i] / 100);
        printf("%-15s %8d %10.2f %10.f% % %-10s %10.2f\n", Name_med[i], cantidades[i], precios[i], descuentos[i], caducidades[i], precioFinal);
    }
}


void BuscarMedicamentos(char Name_med[][NOMBRE], int Num_med, char Buscar[], int nombre) {
    printf("Ingrese el nombre a buscar: ");
    getchar();  
    fgets(Buscar, nombre, stdin);
    Buscar[strcspn(Buscar, "\n")] = '\0';  
    int encontrado = 0; 
    for (int i = 0; i < Num_med; i++) {
        if (strcmp(Name_med[i], Buscar) == 0) {
            printf("Encontrado\n");
            encontrado = 1;
            break; 
        }
    }

    if (!encontrado) {
        printf("No Encontrado\n");
    }
}
