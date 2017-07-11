#include <stdio.h>
#include <stdlib.h>


typedef struct alumno {
        char nombre[20];
        char apellido[20];
        int edad;
        float notas[2][5];
        struct alumno *siguiente;
};

struct alumno *primero, *ultimo;

void menu();
void anadirAlumno();
void mostrarAlumnos();
void agregarNotas();
void mostrarNotas();
void cambiarNota();

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
                case '3': agregarNotas(primero);
                        printf("%f",(primero)->notas[0][0]);
                        printf("%f",(primero+1)->notas[1][0]    );
                        break;
                case '4': cambiarNota(primero);
                        printf("%f",(primero)->notas[0][0]);
                        break;
                case '5': exit(1);
                default: printf( "Opción no válida\n" );
                         break;
             }
     } while (opcion!='4');

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
            printf( "%i_ Nombre: %s, %s.\n",i+1,auxiliar->nombre,auxiliar->apellido);
            auxiliar = auxiliar->siguiente;
            i++;
      }
      if (i==0) printf( "\nLa lista esta vacia!!\n" );
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

 void agregarNotas() {   //buscamos el alumno por nombre y agregamos las notas

    int i,j,num;
    mostrarAlumnos();
    printf("Ingrese el numero de alumno al cual desea agregar las notas: \n");
    scanf("%i",&num);

    num = num-1;

    for(i=0;i<5;i++){
        switch (i){
            case 0: printf("\n1_Matematicas:\n");break;
            case 1: printf("\n2_Musica:\n");break;
            case 2: printf("\n3_Plastica:\n");break;
            case 3: printf("\n4_Lengua:\n");break;
            case 4: printf("\n5_Programacion:\n");break;
            case 5: printf("\n6_Ingles:\n");	break;
            }
            for(j=0;j<2;j++){
                printf("Ingresa la nota numero %i:\n",j+1);
                scanf("%f",&(primero+(num*sizeof(struct alumno)))->notas[i][j]);//-----> mirar esta funcion, no está guardando la nota.
        }
    }
}

void cambiarNota() {

    int opc,mat,num;
    mostrarAlumnos();
    printf("Ingrese el numero de alumno que desea cambiar la nota.\n");
    scanf("%i",&num);
    num=num-1;
    printf("Ingrese la materia que desea cambiar: \n");
    printf("\n 1. Matematicas\n");
    printf("\n 2. Musica\n");
    printf("\n 3. Plastica\n");
    printf("\n 4. Lengua\n");
    printf("\n 5. Programacion:\n");
    printf("\n 6. Ingles\n\n");
    scanf("%i",&mat);
    printf("Ingrese si desea cambiar la nota 1 o la nota 2: \n");
    scanf("%i",&opc);

    printf("Ingrese la nueva nota: \n");
    scanf("%i",&(primero+(num*sizeof(struct alumno)))->notas[mat][opc]);

}

/*void mostrarNotas() {
    struct alumno *aux; //lo usamos para recorrer la lista
    int i,j;

    i=0;
    aux = primero;
    printf("\nMostrando la lista de alumnos completa:\n");
    while (aux!=NULL) {
        printf( "%i_ Nombre: %s, %s.\n",i+1,aux->nombre,aux->apellido);
        for(i=0;i<5;i++){
            switch (i){
                case 0: printf("\nMatematicas:\n");break;
                case 1: printf("\nMusica:\n");break;
                case 2: printf("\nPlastica:\n");break;
                case 3: printf("\nLengua:\n");break;
                case 4: printf("\nProgramacion:\n");break;
                case 5: printf("\nIngles:\n");break;
                }
                    for(j=0;j<2;j++){
                        printf("Nota %i: %i\n",j+1,aux->notas[i][j]);
                    }
        aux = aux->siguiente;
        i++;

        }
    if (i==0) printf( "\nLa lista esta vacia!!\n" );
    }

}*/
