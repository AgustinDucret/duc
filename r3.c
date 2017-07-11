#include <stdio.h>
#include <stdlib.h>

typedef struct alumno {
        char nombre[20];
        char apellido[20];
        int edad;
        struct alumno *siguiente;
};

struct alumno *primero, *ultimo;

void menu();
void anadirAlumno();
void mostrarAlumnos();


int main() {
     char opcion;

     primero = (struct alumno *) NULL;
     ultimo = (struct alumno *) NULL;

     do {
         menu();

         opcion = getch();

             switch ( opcion ) {
                case '1': anadirAlumno();
                       break;
                case '2':  mostrarAlumnos(primero);
                        break;
                case '3': exit(1);
                default: printf( "Opción no válida\n" );
                         break;
             }
     } while (opcion!='3');

    return 0;
 }


 void anadirAlumno() {
      struct alumno *nuevo;

      /* reservamos memoria para el nuevo elemento */
      nuevo = (struct alumno *) malloc (sizeof(struct alumno));
      if (nuevo==NULL) printf( "No hay memoria disponible!\n");

      printf("\nNuevo Alumno:\n");
      printf("Ingresa el nombre: \n");
      fflush(stdin);
      gets(nuevo->nombre);
      printf("Ingrese el apellido: \n");
      fflush(stdin);
      gets(nuevo->apellido);

      /* el campo siguiente va a ser NULL por ser el último elemento
         de la lista */
      nuevo->siguiente = NULL;

      /* ahora metemos el nuevo elemento en la lista. lo situamos
         al final de la lista */
      /* comprobamos si la lista está vacía. si primero==NULL es que no
         hay ningún elemento en la lista. también vale ultimo==NULL */
      if (primero==NULL) {
         printf( "Primer alumno\n");
         primero = nuevo;
         ultimo = nuevo;
         }
      else {
           /* el que hasta ahora era el último tiene que apuntar al nuevo */
           ultimo->siguiente = nuevo;
           /* hacemos que el nuevo sea ahora el último */
           ultimo = nuevo;
      }
 }

  void mostrarAlumnos() {
      struct alumno *auxiliar; /* lo usamos para recorrer la lista */
      int i;

      i=0;
      auxiliar = primero;
      printf("\nMostrando la lista de alumnos completa:\n");
      while (auxiliar!=NULL) {
            printf( "Nombre: %s, %s.\n",
                    auxiliar->nombre,auxiliar->apellido);
            auxiliar = auxiliar->siguiente;
            i++;
      }
      if (i==0) printf( "\nLa lista esta vacia!!\n" );
 }

 void menu() {
        printf("----------------\n");
        printf("Elija una opcion del menu: \n");
        printf("1_ Agregar alumno.\n");
        printf("2_ Mostrar Alumnos.\n");
        printf("3_ Salir.\n");
        printf("----------------\n");
 }
