#include <stdio.h>
#include "lectura.h"
#include "operacion.h"
int main (int argc, char *argv[]) {
    char User[NOMBRE];
    char clave[NOMBRE];
    ingresarTrabajador(User,clave);
    printf("---------Bienvenido a MediStor----------\n");
    printf("Ingreso de Stock:\n");
    char Name_med[MED][NOMBRE];
    int cantidades[MED];
    float precios[MED],descuentos[MED];
    char caducidades[MED][NOMBRE];
    int Num_med = leerEnteroPositivo("Cuantos medicamentos se va a ingresar: ");
    Name_med[Num_med][NOMBRE],cantidades[Num_med];
    precios[Num_med],descuentos[Num_med];
    caducidades[Num_med][NOMBRE];
    ingresarMedicamentos(Num_med,Name_med, cantidades, precios,descuentos,  caducidades);
    printf("\n----------------------Informacion de Medicamentos ----------------------\n");
    
    mostrarMedicamentos(Name_med, cantidades,  precios, descuentos, caducidades,  Num_med);
    char Buscar[NOMBRE];
    int salir, buscar;
    buscar= leerEntero("Desea buscar medicamentos (Si = 1, No = 0)");
    if(buscar ==1){
      do{
        BuscarMedicamentos(Name_med, Num_med, Buscar, NOMBRE);
        salir = leerEntero("Deseas seguir buscando (Si = 1, No = 0)");
      }while(salir!=0);
    }
    
    return 0;
}