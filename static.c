#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct alumno {
        char nombre[50];
        int dni;
        char sexo[20];
        float notas[12];
        int lleno;
}t_alumno;


t_alumno agregarAlumno();
void mostrarAlumnos(t_alumno x[]);
t_alumno agregarNotas(t_alumno x[]);
void mostrarNotasAlumno(t_alumno x[]);
t_alumno cambiarNota(t_alumno x[]);
void promedioNotas(t_alumno x[]);
void materiasAprovadas(t_alumno x[]);
int promedioIngles(t_alumno x);
int promedioLengua(t_alumno x);
int promedioMatematicas(t_alumno x);
int promedioPlastica(t_alumno x);
int promedioProgramacion(t_alumno x);
int promedioMusica(t_alumno x);


int main(){

    t_alumno alumnos[3];
    t_alumno alumno;
    int opc,cant = 0;


   do {
        menu();
        scanf("%i",&opc);

        switch(opc){
            case 1:
                alumno = agregarAlumno();
                alumnos[cant++] = alumno;
                system("cls");
                break;
            case 2:
                mostrarAlumnos(alumnos);
                break;
            case 3:
                mostrarAlumnos(alumnos);
                agregarNotas(alumnos);
                break;
            case 4:
                mostrarAlumnos(alumnos);
                mostrarNotasAlumno(alumnos);
                break;
            case 5:
                mostrarAlumnos(alumnos);
                cambiarNota(alumnos);
                break;
            case 6:
                mostrarAlumnos(alumnos);
                promedioNotas(alumnos);
                break;
            case 7:
                mostrarAlumnos(alumnos);
                materiasAprovadas(alumnos);
                break;
            case 8:
                printf("Hasta la proxima!");
                exit(8);
            default:
                printf("Opción no valida.\n");
                break;
        }
    }while (opc != 8);

    return 0;
}


  void menu() {
        printf("\n----------------\n");
        printf("Elija una opcion del menu: \n");
        printf("1_ Agregar alumno.\n");
        printf("2_ Mostrar alumnos.\n");
        printf("3_ Agregar notas.\n");
        printf("4_ Mostrar notas de un alumno.\n");
        printf("5_ Cambiar nota.\n");
        printf("6_ Promedio de un alumno.\n");
        printf("7_ Materias aprovadas de un alumno.\n");
        printf("8_ Salir.\n");
        printf("----------------\n");
 }




t_alumno agregarAlumno() {

    t_alumno p;
    char entrada[80];

    printf("Ingresa el nombre y apellido del alumno: \n");
    fflush(stdin);
    fgets(p.nombre,50,stdin);
    if(p.nombre[strlen(p.nombre)-1] == '/n') {
        p.nombre[strlen(p.nombre)-1] = '/0';
    }

    printf("Ingresa el dni del alumno: \n");
    fflush(stdin);
    scanf("%d",&p.dni);

    printf("Ingresa si es hombre o mujer: \n");
    fflush(stdin);
    fgets(p.sexo,50,stdin);
    if(p.sexo[strlen(entrada)-1] == '/n') {
        p.sexo[strlen(entrada)-1] = '/0';
    }
    p.lleno = 1;
    return p;
}


void mostrarAlumnos(t_alumno x[]){
    int i;

    for(i = 0; i<3 && x[i].lleno == 1; i++) {
        printf("%i_Nombre: %sDNI: %li\nSexo: %s\n",i+1,x[i].nombre, x[i].dni, x[i].sexo);
    }
}

t_alumno agregarNotas(t_alumno x[]) {
    int i,j,opc;
    printf("Elige el alumno al cual deseas agrear las notas: \n");
    scanf("%i",&opc);
    opc = opc-1;
    printf("Ingrese las notas: \n");
    if (x[opc].lleno == 1) {
        for(i = 0; i<6; i++) {
            switch (i){
            case 0: printf("\n1_Matematicas:\n");
                    printf("Primer nota: \n");
                    scanf("%f",&x[opc].notas[0]);
                    printf("Segunda nota: \n");
                    scanf("%f",&x[opc].notas[1]);
                    break;
            case 1: printf("\n2_Musica:\n");
                    printf("Primer nota: \n");
                    scanf("%f",&x[opc].notas[2]);
                    printf("Segunda nota: \n");
                    scanf("%f",&x[opc].notas[3]);
                    break;
            case 2: printf("\n3_Lengua:\n");
                    printf("Primer nota: \n");
                    scanf("%f",&x[opc].notas[4]);
                    printf("Segunda nota: \n");
                    scanf("%f",&x[opc].notas[5]);
                    break;
            case 3: printf("\n4_Plastica:\n");
                    printf("Primer nota: \n");
                    scanf("%f",&x[opc].notas[6]);
                    printf("Segunda nota: \n");
                    scanf("%f",&x[opc].notas[7]);
                    break;
            case 4: printf("\n5_Ingles:\n");
                    printf("Primer nota: \n");
                    scanf("%f",&x[opc].notas[8]);
                    printf("Segunda nota: \n");
                    scanf("%f",&x[opc].notas[9]);
                    break;
            case 5: printf("\n6_Programacion:\n");
                    printf("Primer nota: \n");
                    scanf("%f",&x[opc].notas[10]);
                    printf("Segunda nota: \n");
                    scanf("%f",&x[opc].notas[11]);
                    break;
            }
        }
    }else printf("Error.");
    system("cls");
}

void mostrarNotasAlumno(t_alumno x[]) {
    int i,opc;
    printf("Elige el alumno del que desea ver la nota: \n");
    scanf("%i",&opc);
    opc = opc-1;

    for(i=0; i<6; i++) {
        switch (i){
            case 0: printf("\n1_ Matematicas:\n");
                    printf("Nota 1: %.2f.\nNota 2: %.2f.\n",x[opc].notas[0],x[opc].notas[1]);
                    break;
            case 1: printf("\n_2 Musica:\n");
                    printf("Nota 1: %.2f.\nNota 2: %.2f.\n",x[opc].notas[2],x[opc].notas[3]);
                    break;
            case 2: printf("\n3_ Lengua:\n");
                    printf("Nota 1: %.2f.\nNota 2: %.2f.\n",x[opc].notas[4],x[opc].notas[5]);
                    break;
            case 3: printf("\n4_ Plastica:\n");
                    printf("Nota 1: %.2f.\nNota 2: %.2f.\n",x[opc].notas[6],x[opc].notas[7]);
                    break;
            case 4: printf("\n5_ Ingles:\n");
                    printf("Nota 1: %.2f.\nNota 2: %.2f.\n",x[opc].notas[8],x[opc].notas[8]);
                    break;
            case 5: printf("\n6_ Programacion:\n");
                    printf("Nota 1: %.2f.\nNota 2: %.2f.\n",x[opc].notas[10],x[opc].notas[11]);
                    break;
                    }
    }
}

t_alumno cambiarNota(t_alumno x[]) {

    int opc,mat,not;

    printf("Ingrese el alumno que desea cambiar: \n");
    scanf("%i",&opc);
    opc = opc-1;
    printf("Ingrese la materia que desea cambiar: \n");
    printf("\n 1. Matematicas\n");
    printf("\n 2. Musica\n");
    printf("\n 3. Plastica\n");
    printf("\n 4. Lengua\n");
    printf("\n 5. Programacion:\n");
    printf("\n 6. Ingles\n\n");
    scanf("%i",&mat);
    printf("Ingrese 1 o 2 segun la nota que quiera cambiar.\n");
    scanf("%i",&not);
    switch(mat) {
        case 1:
            switch (not) {
                case 1: printf("Ingrese la nueva nota: \n");
                        scanf("%f",&x[opc].notas[0]);
                        break;
                case 2: printf("Ingrese la nueva nota: \n");
                        scanf("%f",&x[opc].notas[1]);
                        break;
            }
            break;
        case 2:
            switch (not) {
                case 1: printf("Ingrese la nueva nota: \n");
                        scanf("%f",&x[opc].notas[2]);
                        break;
                case 2: printf("Ingrese la nueva nota: \n");
                        scanf("%f",&x[opc].notas[3]);
                        break;
            }
            break;
        case 3:
            switch (not) {
                case 1: printf("Ingrese la nueva nota: \n");
                        scanf("%f",&x[opc].notas[4]);
                        break;
                case 2: printf("Ingrese la nueva nota: \n");
                        scanf("%f",&x[opc].notas[5]);
                        break;
            }
            break;
        case 4:
            switch (not) {
                case 1: printf("Ingrese la nueva nota: \n");
                        scanf("%f",&x[opc].notas[6]);
                        break;
                case 2: printf("Ingrese la nueva nota: \n");
                        scanf("%f",&x[opc].notas[7]);
                        break;
            }
            break;
        case 5:
            switch (not) {
                case 1: printf("Ingrese la nueva nota: \n");
                        scanf("%f",&x[opc].notas[8]);
                        break;
                case 2: printf("Ingrese la nueva nota: \n");
                        scanf("%f",&x[opc].notas[9]);
                        break;
            }
            break;
        case 6:
            switch (not) {
                case 1: printf("Ingrese la nueva nota: \n");
                        scanf("%f",&x[opc].notas[10]);
                        break;
                case 2: printf("Ingrese la nueva nota: \n");
                        scanf("%f",&x[opc].notas[11]);
                        break;
            }
        break;
    }
    system("cls");
}

void promedioNotas(t_alumno x[]) {
    int opc,i;
    float suma = 0;

    printf("Ingrese el numero de alumno del cual quiere el promedio: \n");
    scanf("%i",&opc);
    opc = opc-1;

    for(i=0;i<12;i++) {
        suma = suma + x[opc].notas[i];
    }
    suma = suma/12;
    printf("El promedio de notas del alumno %s es de: %.2f. \n",x[opc].nombre,suma);
}

int promedioMatematicas (t_alumno x) {
    float suma = 0,promedio = 0;

    suma = x.notas[0] + x.notas[1];
    promedio = suma/2;
    return promedio;
}
int promedioMusica (t_alumno x) {
    float suma = 0,promedio = 0;

    suma = x.notas[2] + x.notas[3];
    promedio = suma/2;
    return promedio;
}
int promedioPlastica (t_alumno x) {
    float suma = 0,promedio = 0;

    suma = x.notas[4] + x.notas[5];
    promedio = suma/2;
    return promedio;
}
int promedioLengua (t_alumno x) {
    float suma = 0,promedio = 0;

    suma = x.notas[6] + x.notas[7];
    promedio = suma/2;
    return promedio;
}

int promedioProgramacion (t_alumno x) {
    float suma = 0,promedio = 0;

    suma = x.notas[10] + x.notas[11];
    promedio = suma/2;
    return promedio;
}
int promedioIngles (t_alumno x) {
    float suma = 0,promedio = 0;

    suma = x.notas[0] + x.notas[1];
    promedio = suma/2;
    return promedio;
}

void materiasAprovadas(t_alumno x[]) {

    int opc;
    printf("Ingrese el numero de alumno que desea ver las materias aprovadas.\n");
    scanf("%i",&opc);
    opc = opc-1;
    printf("Las materias aprovadas son: \n");

    if(promedioMatematicas(x[opc]) >= 6) printf(".Matematicas: \n");
    if(promedioMusica(x[opc])>=6)printf(".Musica\n");
    if(promedioPlastica(x[opc])>=6)printf(".Plastica\n");
    if(promedioLengua(x[opc])>=6)printf(".Lengua\n");
    if(promedioProgramacion(x[opc])>=6)printf(".Programacion\n");
    if(promedioIngles(x[opc])>=6)printf(".Ingles\n");

}

