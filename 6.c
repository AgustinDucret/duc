#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT 3
#define NOMBRE 25


typedef struct {
	char nombre[NOMBRE];
	float dni;
	float notas[2][6];
	int lleno;
}alumno;


alumno alumnos[CANT];

void agregarAlumno();
void mostrarAlumnos(alumno alumnos[]);

int main() {
	
	int op;
	char key;
	

	
	
	do {
		do {
		
		printf("********\n");
		printf("Seleccione la opcion del menu: \n");
		printf("1_ Agregar alumno.\n");
		printf("2_ Mostrar alumnos.\n");
		printf("3_ Cargar notas\n");
		printf("********\n");
		
		scanf("%i",&op);
		
		} while (op < 1 || op > 3);
	
		switch(op){
			case 1: 
				agregarAlumno();
				break;
			case 2:
				mostrarAlumnos(&alumnos[CANT]);
				break;
			case 3: 
				buscarAlumno(&alumnos[CANT]);
		}
		printf("Deseas realizar otra operacion? (S/N): \n");
		scanf("%c",&key);
		
	}while (key == 's' || key == 'S');

	
	
	
	return 0;
}



void agregarAlumno() {
 
    int index = 0;
    int agregaAlumno = 1;
 	int i;
 	
    do {
 
        int op;
 
        printf("Nuevo alumno (1. Si): ");
        scanf("%i", &op);
 
        switch(op) {
            case 1:
 				printf("Ingresa el nombre del alumno: \n");
 				fflush(stdin);
 				fgets(alumnos[index].nombre,50,stdin);
 				cambio(alumnos[index].nombre);
 				printf("Ingrese el dni del alumno: \n");
 				scanf("%f",&alumnos[index].dni);
				index++;				
                // agrega un alumno nuevo
               // iniAlumno(&alumnos[index]);
            break;
            default:
           
                // continua tu codigo
                agregaAlumno = 0;
 
                printf("Termino de agregar alumnos!\n");
            break;
        }
 
    } while(agregaAlumno);
 
}


void mostrarAlumnos(alumno alumnos[]) {
	
	int i;
	
    for(i = 0; i < 10; i++) {
        if(alumnos[i].lleno == 1) {
			printf("\n El nombre del alumno es: %i \n",alumnos[i].nombre);
			printf("\n El dni del alumno es: %i \n",alumnos[i].dni);
        }
    }
	
}


void cargarNotas(alumno x) {  //cargo las notas del alumno.
	
	int i,j;
	
	printf("Ingrese las notas del alumno: \n");
	for(i=0;i<6;i++){
		switch (i){
			case 0: printf("\nMatematicas:\n");break;
			case 1: printf("\nMusica\n");break;
			case 2: printf("\nPlastica\n");break;
			case 3: printf("\nLengua\n");break;
			case 4: printf("\nProgramacion\n");break;
			case 5: printf("\nIngles\n");	break;
		}	
		for(j=0;j<2;j++){
			printf("Ingresa la nota numero: %i\n",j+1);
			scanf("%f",x.notas[i][j]);
		}
	}
	
}

void buscarAlumno(alumno alumnos[]) { //genero una funcio buscarAlumnos para luego pasarsela a cargarNotas y que busque el alumno del cual buscamos cargar la nota
									 // la consigna tiene es cargar un alumno, mostrarlo, luego subirle las notas, por eso es que genero las funciones por separado
	int i,j,k,aux;
	
	char nombre[NOMBRE];
	printf("Ingrese el nombre del alumno que desea agregar las notas.\n");
	fflush(stdin);
	fgets(nombre,NOMBRE,stdin);
	cambio(nombre[NOMBRE]);
	
	for(i = 0; i<CANT; i++) {
			aux = 1;
			aux = strcmp(nombre,alumnos[i].nombre);
			if (aux==0) {
				cargarNotas(alumnos[i]);
			}
	}						 
									 
}

void cambio(char palabra[NOMBRE]) { //genero esta funcion para cambiar los nombres guardados debido a que cuando tomo un string con fgets, me lo guarda con \n
	int i;
	for(i=0; i<NOMBRE;i++) {
		if(palabra[i] == '\n') {
			palabra[i] = '\0';
		}
	}
}


































