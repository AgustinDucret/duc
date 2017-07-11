#include <stdio.h>     //esta compilando sin errores, chequear codigo y seguir programando.
#include <stdlib.h>
#define C 4


typedef struct {
    int edad;
    long dni;
    char nombre[25];
    char apellido[25];
    int ano;
    float notas[2][6];
    int lleno;
} alumno;

alumno alumnos[C];

void lineaDePuntos();
void agregarAlumno(alumno *ptr_alumnos, int cant);//cuantos alumnos agregamos y los datos.
void mostrarAlumnos(alumno *ptr_alumnos, int cant);
void llenarArray(alumno *ptr_alunos, int cant);

int main() {
    int op;


    do {
        llenarArray(alumnos,C);
        lineaDePuntos();
        printf("Elija una opcion del menu: \n");
        printf("1_ Agregar alumno.\n");
        printf("2_ Mostrar Alumnos.\n");
        lineaDePuntos();
        scanf("%i",&op);

        switch(op) {
            case 1:
            agregarAlumno(alumnos,C);
            printf("%s\n",alumnos->apellido);
            break;
           case 2: mostrarAlumnos(alumnos,C);
        }
    }while(op != 2);

    return 0;

};

void agregarAlumno(alumno *ptr_alumnos, int cant) {
      int i,op;

      do {
        lineaDePuntos();
        printf("Elige la opcion para seguir");
        printf("\n1_ introducir datos de un nuevo alumno\n");
        printf("\n2_ salir\n");
        lineaDePuntos();
        scanf("%d",&op);

        switch(op) {
        case 1:

            for (i=0; i<cant && ptr_alumnos->edad == 0; i++) {
                printf ("\nIntroduce el nombre del alumno n%d\n", i+1);   //alumnos 1.2.. count+1  va sumando 1 a medida que introducimos los datos del cliente
                scanf ( "%s", &ptr_alumnos->nombre);
                printf ("\nIntroduce el apellido del alumno n%d\n", i+1);
                scanf ("%s", &ptr_alumnos->apellido);
                printf ("\nIntroduce la edad del alumno  n%d\n", i+1);
                scanf ("%i", &ptr_alumnos->edad);
                ptr_alumnos->lleno = 1;
             }
            ptr_alumnos++;
      }
    }while(op !=2);
}



void mostrarAlumnos(alumno *ptr_alumnos, int cant){

    int i,op;

    printf("1_ Imprimir alumnos\n.");
    printf("2_ Salir.\n");
    scanf("%i",&op);

    do{
        for( i=0; i<C; i++ ) {
            printf( "El nombre del alumno es: %s. \n", ptr_alumnos->nombre );
            printf( "El apellido del alumno es: %s.\n", ptr_alumnos->apellido );
            printf( "La edad del alumno es: %i.\n",ptr_alumnos->edad );
            ptr_alumnos++;
            }
    }while (op =! 2);
}

void lineaDePuntos() {
    printf("*******************\n");
}

void llenarArray(alumno *ptr_alumnos, int cant){
    int i;
    for(i = 0; i < C; i++){
        ptr_alumnos->lleno = 0;
    }
}
