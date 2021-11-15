#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "stdlib.h"

//Buenos dias compañeros este es en el proyecto sobre el cual vamos a trabajar
//gracias



void menu();

void validateMail();

void wordCount();

void deleteRepeats();

void intersection();

void deleteCharacters();

void fillCharacters();

void newYear();

void countingVowels();

void searchString();

void properName();

int main() {
    menu();
    return 0;
}

void menu() {
    int op;
    char *main = "\n==========MENU==========\n"
                 "1->Texto a nombre propio \n"
                 "2->Buscar cadena\n"
                 "3->Contar las Vocales\n"
                 "4->Año Nuevo\n"
                 "5->llenar caracteres \n"
                 "6->Borrar caracteres \n"
                 "7->Interseccion\n"
                 "8->Eliminar repetidos\n"
                 "9->Contar Palabras \n"
                 "10->Validar correo\n"
                 "0->Salir\n"
                 "Digite Opcion:  \n";

    do {
        printf(main);
        scanf("%d", &op);
        switch (op) {
            case 1 :
                properName();
                break;

            case 2 :
                searchString();
                break;
            case 3:
                countingVowels();
                break;
            case 4 :
                newYear();
                break;
            case 5:
                fillCharacters();
                break;
            case 6:
                deleteCharacters();
                break;
            case 7:
                intersection();
                break;
            case 8:
                deleteRepeats();
                break;
            case 9:
                wordCount();
                break;
            case 10 :
                validateMail();
                break;
            case 0:
                op = 0;
                printf("Gracias");
                break;

        }
    } while(toupper(op) != 0);

}

void properName() {
    int cont=0,z, letras=0;
    char texto[30];
    char textoFinal[30];
    printf("Ingrese la cadena a converrtir\n");
    fflush(stdin);
    scanf("%s",texto);
    /*fgets(texto,30,stdin);
    getchar();*/

    z = strlen(texto);
    //printf("%d",z,"\n");
    if(z > 1) {
        //for para contar
        for (int i = 0; i <= z; ++i) {
            if(texto[i] == ' '){
                cont++;
            }
        }
        letras = z-cont;
        printf("las letras son: %d",letras);

        //for para convertir
        for (int i = 0; i < letras; ++i) {
            textoFinal[i] = toupper(texto[i]);
        }

        //for para mostrar
        printf("\nel resultado es: ");
        for (int i = 0; i < letras; ++i) {
            printf("%c",textoFinal[i]);
        }

    } else{
        printf("\nLa cadena es muy corta :(");
    }

}

void searchString() {

}

void countingVowels() {

}

void newYear() {
    int horas =0;
    int minutos=0;
    char cadena3[4],*num1;
    char cadena4[1];
    printf("Ingrese la hora actual  \n");
    scanf("%s",&cadena3);
    printf("%s",cadena3);
    //horas= atoi(cadena3);
    minutos= atoi(cadena4);
    num1 = &cadena3[3];
    printf("%s",num1);
    //cadena4[1]=cadena3[4];
    //printf("\n%s",cadena4);
    int horatotal=(23-horas)*60;
    int minutostotales=60-minutos;
    int minutosrestantestotales=horatotal+minutostotales;
    getchar();


}

void fillCharacters() {

}

void deleteCharacters() {

}

void intersection() {

}

void deleteRepeats() {
    int z;
    char cadena[20];
    printf("=====Eliminar repetidos=====\n");
    printf("ingrese una cadena: ");
    scanf("%s",&cadena);
    z = strlen(cadena);


    for (int i = 0; i < z; ++i) {
        for (int j = 0; j < z-1; ++j) {
            if(i!=j){
                if(cadena[i] == cadena[j]){
                    cadena[j] = ' ';
                }
            }
        }

    }
    ////////////////////////////////
    for (int i = 0; i < z; ++i) {
        printf("%c",cadena[i]);
    }


    getchar();
}

void wordCount() {

}

void validateMail() {

}
