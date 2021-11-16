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

void prueba();


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
                //properName();
                prueba();
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

void prueba() {
    char cad[200], *p=cad; //el puntero p comienza desde el principio de cad
    printf("Teclea una frase: ");
    fflush(stdin);
    fgets(cad,200,stdin);
    while (*p!=0) //mientras p no alcance el character \0 de final de cadena
    { if (p==cad || (*p!=' ' && *(p-1)==' ')) //condicion de primera letra de una palabra
            if (*p>='a' && *p<='z') //si es una letra minúscula
                *p = *p - ('a'-'A'); //también podría ser: *p -= 'a'-'A';
        p++; //p pasa a apuntar a la siguiente letra
    }
    printf("\nLa frase corregida es: %s", cad);
}

void properName() {
    int cont=0,z, letras=0;
    char texto[50];
    char textoFinal[30];
    printf("Ingrese la cadena a converrtir\n");
    fflush(stdin);
    fgets(texto,50,stdin);
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
    const int yearNew = 1439;
    int z;
    char hora[5];
    int horasMIn, min, faltante;
    int conversion, horaFinal;
    char p = *hora;
    printf("ingrese la hora en el formato de 24 horas (00:00): ");
    scanf("%s",&hora);
    horasMIn = atoi(hora);
    min = atoi(hora+3);
    conversion = horasMIn*60;
    horaFinal = conversion+min;
   faltante = yearNew - horaFinal;

    printf("los minutos faltantes para año nuevo son: %i minutos", faltante);

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
    char cadena[20],aux;
    printf("=====Eliminar repetidos=====\n");
    printf("ingrese una cadena: ");
    fflush(stdin);
    fgets(cadena,20,stdin);
    //scanf("%s",&cadena);
    z = strlen(cadena);


    for (int i = 0; i < z; ++i) {
        for (int j = 0; j < z-1; ++j) {
            if(i != j){
                if(cadena[j] == cadena[i]){
                    cadena[i] = ' ';
                }
            }
        }

    }

   ///metodo borbuja :)
    for (int i = 0; i < z-1; ++i) {
        for (int j = 0; j < (z-1); ++j) {
            if(cadena[j] == ' ' && cadena[j+1] != ' '){//si posicion actual es ' '> numero siguiente
                aux = cadena[j];
                cadena[j] = cadena[j+1];
                cadena[j+1] = aux;
            }
        }
    }

    //////////////
    printf("de manera normal=");
    for (int i = 0; i < z; ++i) {
        printf("%c",cadena[i]);
    }
    printf("\nAl reves=");
    for (int i = z; i >= 0; --i) {
        printf("%c",cadena[i]);
    }

    getchar();
}

void wordCount() {

}

void validateMail() {

}
