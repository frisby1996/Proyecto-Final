//MATEO PELAEZ
//BRAHIAN CARDONA
//LIBRERIAS O PAQUETES
#include <stdio.h>
#include <stdlib.h>
#define num 50

//FUNCIONES
void menu();

void menuFutbol();
void registroFutbol();
void mostrarFutbol();
void maximoGoleador();
void mejorEquipoFutbol();

void menuBaloncesto();
void registroBaloncesto();
void mostrarBaloncesto();
void maximoTriplista();
void mejorEquipoBaloncesto();

//VARIABLES GLOBALES
int vacioFutbol = 0, vacioBaloncesto = 0, cantidadLigaFutbol, cantidadLigaBaloncesto;
int numero; // ESTA VARIABLE NOS PERMITE TOMAR EL VALOR DE LOS FOR PARA EXTRAER EL NOMBRE DEL STRUCT
int puntos; // CANTIDAD DE PUNTOS COSECHADOS EN LA LIGA FUTBOL

//STRUCT LIGA 1# FUTBOL
struct ligaFutbol
{
    char nombreEquipo[num];
    int numVictorias,numDerrotas,numEmpates,numGolesFavor,numGolesContra,golesGoleador;
    char nombreGoleador[num];

};ligaFutbol futbol[num],*p_futbol=futbol;

//STRUCT LIGA 2# BALONCESTO
struct ligaBaloncesto
{
    char nombreEquipo[num];
    int numVictorias,numDerrotas,numPerdidasBalon,numRebotesCogidos,numMejorTriplista;
    char nombreMejorTriplista[num];

};ligaBaloncesto baloncesto[num],*p_baloncesto=baloncesto;

int main()
{
    menu();
    return 0;
}

void menu(){
    int opcion = 0;
    do{

        printf("\n                                             ");
        printf("\n 1. LIGA DE FUTBOL   2. LIGA DE BALONCESTO   ");
        printf("\n                                             ");
        printf("\n                     0. CERRAR CONSOLA       ");
        printf("\n                                             ");
        printf("\n\nELIJA UNA OPCION: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 0:
                system("cls");
                printf("PROFE NO NOS DEJE MORIR.\n");
                exit(0);
            case 1:
                system("cls");
                menuFutbol();
                break;
            case 2:
                system("cls");
                menuBaloncesto();
                break;
            default:
                system("cls");
                printf("LA OPCION NO ES VALIDA.\n");
        }
    }while(opcion != 0);
}

void menuFutbol(){
    if(vacioFutbol == 0){
        printf("\n\nINGRESE LA CANTIDAD DE EQUIPOS QUE PARTICIPARAN EN LA LIGA?: ");
        scanf("%d", &cantidadLigaFutbol);
        vacioFutbol = 1;
        menuFutbol();
    }else{
        int opcion = 0;
        do{

            printf("\n                                                ");
            printf("\n 1. AGREGAR INFORMACION    2. VER INFORMACION   ");
            printf("\n                                                ");
            printf("\n 3. MAYOR ANOTADOR         4. MEJOR EQUIPO      ");
            printf("\n                                                ");
            printf("\n                           0. REGRESAR          ");
            printf("\n                                                ");
            printf("\n\nELIJA UNA OPCION: ");
            scanf("%d", &opcion);
            switch(opcion){
                case 0:
                    system("cls");
                    menu();
                case 1:
                    system("cls");
                    registroFutbol();
                    break;
                case 2:
                    system("cls");
                    mostrarFutbol();
                    break;
                 case 3:
                    system("cls");
                    maximoGoleador();
                    break;
                 case 4:
                    system("cls");
                    mejorEquipoFutbol();
                    break;
                default:
                    system("cls");
                    printf("LA OPCION NO ES VALIDA.\n");
            }
        }while(opcion != 0);
    }
}

void registroFutbol(){
    printf("\nINFORMACION A REGISTRAR\n\n");
    for(int i=0;i<cantidadLigaFutbol;i++){
        printf("INGRESE EL NOMBRE DEL EQUIPO: ");
        scanf("%s", &(*(p_futbol+i)).nombreEquipo);
        printf("INGRESE EL NUMERO DE VICTORIAS: ");
        scanf("%d", &(*(p_futbol+i)).numVictorias);
        printf("INGRESE EL NUMERO DE DERROTAS: ");
        scanf("%d", &(*(p_futbol+i)).numDerrotas);
        printf("INGRESE EL NUMERO DE EMPATES: ");
        scanf("%d", &(*(p_futbol+i)).numEmpates);
        printf("INGRESE EL NUMERO DE GOLES ANOTADOS: ");
        scanf("%d", &(*(p_futbol+i)).numGolesFavor);
        printf("INGRESE EL NUMERO DE GOLES RECIBIDOS: ");
        scanf("%d", &(*(p_futbol+i)).numGolesContra);
        printf("INGRESE EL NOMBRE DEL GOLEADOR: ");
        scanf("%s", &(*(p_futbol+i)).nombreGoleador);
        printf("INGRESE EL NUMERO DE GOLES: ");
        scanf("%d", &(*(p_futbol+i)).golesGoleador);
        printf("\n");
    }
}

void mostrarFutbol(){
    printf("\nINFORMACION A MOSTRAR\n");
    for(int i=0;i<cantidadLigaFutbol;i++){
        printf("\nINFORMACION EQUIPO #%d\n", i+1);
        printf("NOMBRE DE EQUIPO: %s", (*(p_futbol+i)).nombreEquipo);
        printf("\nNUMERO DE VICTORIAS: %d", (*(p_futbol+i)).numVictorias);
        printf("\nNUMERO DE DERROTAS: %d", (*(p_futbol+i)).numDerrotas);
        printf("\nNUMERO DE EMPATES: %d", (*(p_futbol+i)).numEmpates);
        printf("\nNUMERO DE GOLES ANOTADOS: %d", (*(p_futbol+i)).numGolesFavor);
        printf("\nNUMERO DE GOLES RECIBIDOS: %d", (*(p_futbol+i)).numGolesContra);
        printf("\nNOMBRE DEL GOLEADOR: %s", (*(p_futbol+i)).nombreGoleador);
        printf("\nNUMERO DE GOLES: %d", (*(p_futbol+i)).golesGoleador);
        printf("\n");
    }
    printf("\n");
}

void maximoGoleador(){
    int mayorGoleador;

    mayorGoleador = (*(p_futbol+0)).golesGoleador;
    for(int i=0;i<cantidadLigaFutbol;i++){
        if((*(p_futbol+i)).golesGoleador > mayorGoleador){
            mayorGoleador = (*(p_futbol+i)).golesGoleador;
            numero = i;
        }
    }

    printf("\nGOLES ANOTADOS: %d", mayorGoleador);
    printf("\nNOMBRE MAYOR GOLEADOR: %s", (*(p_futbol+numero)).nombreGoleador);
    printf("\n");
}

void mejorEquipoFutbol(){
    int mEquipoFutbol;

    mEquipoFutbol = (*(p_futbol+0)).numVictorias;
    for(int i=0;i<cantidadLigaFutbol;i++){
        if((*(p_futbol+i)).numVictorias > mEquipoFutbol){
            mEquipoFutbol = (*(p_futbol+i)).numVictorias;
            numero = i;
        }
    }

    puntos = (mEquipoFutbol*3) + ((*(p_futbol+numero)).numEmpates);

    printf("\nPUNTOS CONSEGUIDOS: %d PUNTOS", puntos);
    printf("\nVICTORIAS CONSEGUIDAS: %d", mEquipoFutbol);
    printf("\nNOMBRE DEL EQUIPO CAMPEON: %s", (*(p_futbol+numero)).nombreEquipo);
    printf("\n");
}

void menuBaloncesto(){
    if(vacioBaloncesto == 0){
        printf("\n\nINGRESE LA CANTIDAD DE EQUIPOS QUE PARTICIPÁRAN EN LA LIGA?: ");
        scanf("%d", &cantidadLigaBaloncesto);
        vacioBaloncesto = 1;
        menuBaloncesto();
    }else{
        int opcion = 0;
        do{

            printf("\n|                           |                       |");
            printf("\n| 1. AGREGAR INFORMACION    | 2. VER INFORMACION    |");
            printf("\n|                           |                       |");
            printf("\n| 3. MAYOR TRIPLISTA        | 4. MEJOR EQUIPO       |");
            printf("\n|                           |                       |");
            printf("\n|                           | 0. REGRESAR           |");
            printf("\n|                           |                       |");
            printf("\n\nELIJA UNA OPCION: ");
            scanf("%d", &opcion);
            switch(opcion){
                case 0:
                    system("cls");
                    menu();
                case 1:
                    system("cls");
                    registroBaloncesto();
                    break;
                case 2:
                    system("cls");
                    mostrarBaloncesto();
                    break;
                case 3:
                    system("cls");
                    maximoTriplista();
                    break;
                case 4:
                    system("cls");
                    mejorEquipoBaloncesto();
                    break;
                default:
                    system("cls");
                    printf("LA OPCION NO ES VALIDA.\n");
            }
        }while(opcion != 0);
    }
}

void registroBaloncesto(){
    printf("\nINFORMACION A REGISTRAR\n\n");
    for(int i=0;i<cantidadLigaBaloncesto;i++){
        printf("INGRESE EL NOMBRE DEL EQUIPO: ");
        scanf("%s", &(*(p_baloncesto+i)).nombreEquipo);
        printf("INGRESE EL NUMERO DE VICTORIAS: ");
        scanf("%d", &(*(p_baloncesto+i)).numVictorias);
        printf("INGRESE EL NUMERO DE DERROTAS: ");
        scanf("%d", &(*(p_baloncesto+i)).numDerrotas);
        printf("INGRESE EL NUMERO DE PERDIDAS DE BALON: ");
        scanf("%d", &(*(p_baloncesto+i)).numPerdidasBalon);
        printf("INGRESE EL NUMERO DE INTERCEPCIONES: ");
        scanf("%d", &(*(p_baloncesto+i)).numRebotesCogidos);
        printf("INGRESE EL NOMBRE DEL MAYOR TRIPLISTA: ");
        scanf("%s", &(*(p_baloncesto+i)).nombreMejorTriplista);
        printf("INGRESE EL NUMERO DE TRIPLES REALIZADOS: ");
        scanf("%d", &(*(p_baloncesto+i)).numMejorTriplista);
        printf("\n");
    }
}

void mostrarBaloncesto(){
    printf("\nINFORMACION A MOSTRAR\n");
    for(int i=0;i<cantidadLigaBaloncesto;i++){
        printf("\nINFORMACION EQUIPO #%d\n", i+1);
        printf("NOMBRE EQUIPO: %s", (*(p_baloncesto+i)).nombreEquipo);
        printf("\nNUMERO DE VICTORIAS: %d", (*(p_baloncesto+i)).numVictorias);
        printf("\nNUMERO DE DERROTAS: %d", (*(p_baloncesto+i)).numDerrotas);
        printf("\nNUMERO DE PERDIDAS DE BALON: %d", (*(p_baloncesto+i)).numPerdidasBalon);
        printf("\nNUMERO DE INTERCEPCIONES: %d", (*(p_baloncesto+i)).numRebotesCogidos);
        printf("\nNOMBRE DEL MAYOR TRIPLISTA: %s", (*(p_baloncesto+i)).nombreMejorTriplista);
        printf("\nNUMERO DE TRIPLES: %d", (*(p_baloncesto+i)).numMejorTriplista);
        printf("\n");
    }
    printf("\n");
}

void maximoTriplista(){
    int mayorTriplista;

    mayorTriplista = (*(p_baloncesto+0)).numMejorTriplista;
    for(int i=0;i<cantidadLigaBaloncesto;i++){
        if((*(p_baloncesto+i)).numMejorTriplista > mayorTriplista){
            mayorTriplista = (*(p_baloncesto+i)).numMejorTriplista;
            numero = i;
        }
    }

    printf("\nTRIPLES REALIZADOS: %d", mayorTriplista);
    printf("\nNOMBRE MAYOR TRIPLISTA: %s", (*(p_baloncesto+numero)).nombreMejorTriplista);
    printf("\n");
}

void mejorEquipoBaloncesto(){
    int mEquipoBaloncesto;

    mEquipoBaloncesto = (*(p_baloncesto+0)).numVictorias;
    for(int i=0;i<cantidadLigaBaloncesto;i++){
        if((*(p_baloncesto+i)).numVictorias > mEquipoBaloncesto){
            mEquipoBaloncesto = (*(p_baloncesto+i)).numVictorias;
            numero = i;
        }
    }

    printf("\nVICTORIAS CONSEGUIDAS: %d", mEquipoBaloncesto);
    printf("\nNOMBRE EQUIPO CAMPEON: %s", (*(p_baloncesto+numero)).nombreEquipo);
    printf("\n");
}
