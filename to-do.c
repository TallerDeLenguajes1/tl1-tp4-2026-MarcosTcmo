#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
typedef struct Tarea
{
    int TareaId;       // Númerico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion;      // Entre 10 - 100
} Tarea;
typedef struct Nodo
{
    Tarea T;
    struct Nodo *Siguiente;
} Nodo;
Nodo *CrearListaVacia()
{
    return NULL;
}
Nodo *CrearNodo(int idRecibido, char *descripcionRecibida, int duracionRecibida);
void insertarNodo(Nodo **StartRecibido, Nodo *NNodo);
int main()
{
    int idIncremental = 999, decision = 1, duracion = 50;
    char ingresoDescripcion[50],confirmacion;
    Nodo *Start;
    Start = CrearListaVacia();
    while (decision != 0)
    {
        idIncremental += 1;
        puts("Ingreso de una tarea pendiente: \nIngrese una descripcion de la tarea pendiente: ");
        fgets(ingresoDescripcion, 50, stdin);
        ingresoDescripcion[strcspn(ingresoDescripcion, "\n")] = 0; // limpiara el residuo '\n' y colocara '\0' by MarcosTcmo
        puts("Ingrese la duracion de la tarea de 10 a 100");
        do
        {
            if (duracion < 10 || duracion > 100)
            {
                printf("la duracion no esta en el rango");
            }

            scanf("%d", &duracion);
            limpiarBuffer();
        } while (duracion < 10 || duracion > 100);
        Nodo *nuevoNodo = CrearNodo(idIncremental, ingresoDescripcion, duracion);
        insertarNodo(&Start, nuevoNodo);
        puts("Desea ingresar otro nodo o finalizar la carga?: (s/n)");
        scanf(" %c", &confirmacion);
        limpiarBuffer();
        if (confirmacion == 'n' || confirmacion == 'N')
        {
            decision = 0;
        }
    } 
    getchar();
    return 0;
}
Nodo *CrearNodo(int idRecibido, char *descripcionRecibida, int duracionRecibida)
{
    Nodo *NNodo = (Nodo *)malloc(sizeof(Nodo));
    NNodo->T.TareaId = idRecibido;
    NNodo->T.Descripcion = (char *)malloc((strlen(descripcionRecibida) + 1) * (sizeof(char)));
    strcpy(NNodo->T.Descripcion, descripcionRecibida);
    NNodo->T.Duracion = duracionRecibida;
    NNodo->Siguiente = NULL;
    return NNodo;
}
void insertarNodo(Nodo **StartRecibido, Nodo *NNodo)
{
    NNodo->Siguiente = *StartRecibido;
    *StartRecibido = NNodo;
}