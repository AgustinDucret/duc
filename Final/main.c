#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Alumno {
    char nombre[50];
    float dni;
}Alumno;


typedef struct Nodo {
    Alumno alumno;
    struct Nodo* siguiente;
}Nodo;

typedef struct Lista {
    Nodo* cabeza;
    int longitud;
}Lista;


void menu();
Nodo* crearNodo ();
void destruirNodo(Nodo* nodo);
void insertarPrincipio(Lista* lista, Alumno* alumno);
void insertarFinal(Lista* lista, Alumno* alumno);
Alumno* obtener(int n, Lista* lista);
int contar(Lista* lista);
int estaVacia(Lista* lista);
void eliminarPrincipio(Lista* lista);
void eliminarUltimo(Lista* lista);
void eliminarAlumno(int n, Lista* lista);



int main() {

 char opcion;

     do {
         menu();

         opcion = getch();

             switch (opcion) {
                case '1': crearNodo();//ver esto.
                       break;
                case '2':  //mostrarAlumnos(primero);
                        break;
                case '3':// agregarNotas(primero);
                        break;
                case '4': //cambiarNota(primero);
                        break;
                case '5': exit(1);
                default: printf( "Opción no válida\n" );
                         break;
             }
     } while (opcion!='4');

return 0;
}


 void menu() {
        printf("\n----------------\n");
        printf("Elija una opcion del menu: \n");
        printf("1_ Agregar alumno.\n");
        printf("2_ Mostrar Alumnos.\n");
        printf("3_ Agregar Notas.\n");
        printf("4_ Mostrar Notas.\n");
        printf("5_ Salir.\n");
        printf("----------------\n");
 }

Nodo* crearNodo () {
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
 //   if (nuevo==NULL) printf( "No hay memoria disponible!\n");

    printf("\nNuevo Alumno:\n");
    printf("Ingresa el nombre y apellido: \n");
    fflush(stdin);
    gets(nodo->alumno.nombre);
    printf("Ingresa el dni del alumno: \n");
    scanf("%f",nodo->alumno.dni);
    nodo->siguiente = NULL;
    return nodo;
}

void destruirNodo(Nodo* nodo) {
    free(nodo);
}

void insertarPrincipio(Lista* lista, Alumno* alumno) {
    Nodo* nodo = crearNodo(alumno);
    nodo->siguiente = lista->cabeza;
    lista->cabeza = nodo;
    lista->longitud++;
}

void insertarFinal(Lista* lista, Alumno* alumno) {
    Nodo* nodo = crearNodo(alumno);
    if(lista->cabeza == NULL) {
        lista->cabeza = nodo;
    }else {
        Nodo* puntero = lista->cabeza;
        while(puntero->siguiente == NULL) {
            puntero = puntero->siguiente;
        }
        puntero->siguiente = nodo;
    }
    lista->longitud++;
}

 Alumno* obtener(int n, Lista* lista) {
    if(lista->cabeza == NULL) {
        return NULL;
    }else {
        Nodo* puntero = lista->cabeza;
        int posicion = 0;
        while (posicion < n && puntero->siguiente) {
            puntero = puntero->siguiente;
            posicion++;
        }
        if(posicion != n) {
            return NULL;
        } else {
            return &puntero->alumno;
        }
    }
 }

 int contar(Lista* lista){
    return lista->longitud;
 }

int estaVacia(Lista* lista){
    return lista->cabeza == NULL;
}

 void eliminarPrincipio(Lista* lista) {
    if(lista->cabeza){
    Nodo* eliminado = lista->cabeza;
    lista->cabeza = lista->cabeza->siguiente;
    destruirNodo(eliminado);
    lista->longitud--;
    }
 }

 void eliminarUltimo(Lista* lista) {
    if(lista->cabeza) {
        if(lista->cabeza->siguiente) {
            Nodo* puntero = lista->cabeza;
            while(puntero->siguiente->siguiente){
                puntero = puntero->siguiente;
            }
            Nodo* eliminado = puntero->siguiente;
            puntero->siguiente = NULL;
            destruirNodo(eliminado);
            lista->longitud--;
        }else {
            Nodo* eliminado = lista->cabeza;
            lista->cabeza = NULL;
            destruirNodo(eliminado);
            lista->longitud--;
        }
    }
 }

 void eliminarAlumno(int n, Lista* lista) {
     if(lista->cabeza){
        if(n==0){
            Nodo* eliminado = lista->cabeza;
            lista->cabeza = lista->cabeza->siguiente;
            destruirNodo(eliminado);
            lista->longitud--;
        }else if (n < lista->longitud)  {
            Nodo* puntero = lista->cabeza;
            int posicion = 0;
            while (posicion < (n-1)) {           //me paro en el nodo anterior al que queremos eliminar
                 puntero = puntero->siguiente;
                 posicion++;
            }
            Nodo *eliminado = puntero->siguiente;
            puntero->siguiente = eliminado->siguiente;
            destruirNodo(eliminado);
            lista->longitud--;
        }
     }
 }
