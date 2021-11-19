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

void deleteCharacters(char *cadena, char *caracteres);

void fillCharacters();

void newYear();

void countingVowels();

void properName();

void prueba();


int main() {
    menu();
    return 0;
}

void menu() {
    int op;

    char *cadena1[45];
    char *cadena2[30];
    int i= 0;

    char frase[45], caracteres[20];

    char cadena[80];
    char* val;
    char* val1;

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
                ///listo
                prueba();
                break;

            case 2 :
                //listo
                printf("Ingrese la cadena de texto: \n");
                fflush(stdin);
                fgets(cadena1,45,stdin);

                printf("Ingrese la cadena a comparar: \n");
                fflush(stdin);
                fgets(cadena2,45,stdin);


                char *buscar = strstr(cadena1, cadena2);

                while (buscar != NULL){
                    i++;
                    buscar = strstr(buscar + 1, cadena2);

                }
                printf("Total de coincidencias: %i\n", i);
                break;
            case 3:
                countingVowels();
                break;
            case 4 :
                //listo
                newYear();
                break;
            case 5:
                fillCharacters();
                break;
            case 6:
                //listo
                printf("Ingrese la cadena de texto: \n");
                fflush(stdin);
                fgets(frase,45,stdin);

                printf("\nIngrese el caracter: ");
                fflush(stdin);
                fgets(caracteres,20,stdin);

                printf("La cadena es: '%s'\n", frase);
                printf("Y el caracter que se quitara es: %s\n", caracteres);
                deleteCharacters(&frase, &caracteres);

                printf("Despues de remover el caracter, la frase es: '%s'\n", frase);

                break;
            case 7:
                //liestp
                intersection();
                break;
            case 8:
                //listp
                deleteRepeats();
                break;
            case 9:
                wordCount();
                break;
            case 10 :
                //listo
                printf("Ingrese su correo electronico\n>>");
                fflush(stdin);
                fgets(cadena,80,stdin);

                for (int i = 0; i <= strlen(cadena); i++) {
                    val = strchr(cadena, '@');
                    if (val != NULL) {
                        break;
                    }
                }
                /////////
                for (int i = 0; i <= strlen(cadena); i++) {
                    val1 = strchr(cadena, '.');
                    if (val1 != NULL && &val1 > &val) {
                        printf("si esta ingresando");
                        break;
                    }
                }

                if (val != NULL) {
                    if (val1 != NULL && val1 > val) {
                        printf("Correo valido.");
                    }
                    else {
                        printf("Su correo es invalido, por favor reviselo.");
                    }
                }
                else {
                    printf("Su correo es invalido, por favor reviselo.");
                }

                break;
            case 0:
                op = 0;
                printf("Gracias! :)");
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


//metodos contar vocales...............................................................
int contarVocales(char *cadena);
int contarVocales(char *cadena){
    int vocales = 0;
    for (int indice = 0; cadena[indice] != '\0'; ++indice){
        //tolower: convierte un tipo de dato carácter a minúscula
        char letraActual = tolower(cadena[indice]);
        if (    letraActual == 'a' ||
                letraActual == 'e' ||
                letraActual == 'i' ||
                letraActual == 'o' ||
                letraActual == 'u'
                ){
            vocales++;
        }
    }
    return vocales;
}

void countingVowels() {

    char cadena1[1000];
    printf("\n-----|Escriba una cadena| ");
    scanf(" %[^\n]",cadena1);
    int vocales = contarVocales(cadena1);
    printf("\n-----|Numero de vocales en la cadena es| %d\n", vocales);

}
//.............................................................
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
//agregar caracteres..............................................

void insertarSubcadena(char *original, char *subcadena, int indice) {
    char inicio[100] = "";
    strncpy(inicio, original, indice);
    char fin[100] = "";
    strncpy(fin, original + indice, strlen(original) - indice);
    //agrega la subcadena al inicio
    strcat(inicio, subcadena);
    strcat(inicio, fin);
    //Copea dentro de la cadena recibida
    strcpy(original, inicio);
}

void inicio(char *cadena,char *caracter,int cuantos){
    //pone las letras al inicio
    for (int indice = 0; indice <=(cuantos-1) ; ++indice){
        insertarSubcadena(cadena, caracter, 0);
    }
    printf("|cadena concatenada| %s\n", cadena);
}
void final(char *cadena,char *caracter,int cuantos){
    //pone las letras al final
    int longi = strlen(cadena);//determina el tamaño
    for (int indice = 0; indice <=(cuantos-1) ; ++indice){
        insertarSubcadena(cadena, caracter, longi);
    }
    printf("|cadena concatenada| %s\n", cadena);
}


void fillCharacters() {
    printf("\n-----| escriba una cadena     | ");
    char cadena[50] ;
    scanf(" %[^\n]",cadena);

    printf("\n-----| escriba un caracter    | ");
    char caracter[50] ;
    scanf("%s", caracter);

    printf("\n-----| cuantas veces          | ");
    int cuantos ;
    scanf("%i", &cuantos);

    printf("\n-----|seleccione la ubicacion |\n-----|inicio=1 final=2|");
    int opcion;
    scanf(" %i",&opcion);

    switch (opcion) {
        case 1: {
            inicio(cadena,caracter,cuantos);
            break;
        }
        case 2: {
            final(cadena,caracter,cuantos);
            break;
        }
    }
}
//...........................................................


void deleteCharacters(char *cadena, char *caracteres) {
    int indiceCadena = 0, indiceCadenaLimpia = 0;
    int deberiaAgregarCaracter = 1;
    // Recorrer cadena carácter por carácter
    while (cadena[indiceCadena]) {
        // Primero suponemos que la letra sí debe permanecer
        deberiaAgregarCaracter = 1;
        int indiceCaracteres = 0;
        // Recorrer los caracteres prohibidos
        while (caracteres[indiceCaracteres]) {
            // Y si la letra actual es uno de los caracteres, ya no se agrega
            if (cadena[indiceCadena] == caracteres[indiceCaracteres]) {
                deberiaAgregarCaracter = 0;
            }
            indiceCaracteres++;
        }
        // Dependiendo de la variable de arriba, la letra se agrega a la "nueva
        // cadena"
        if (deberiaAgregarCaracter) {
            cadena[indiceCadenaLimpia] = cadena[indiceCadena];
            indiceCadenaLimpia++;
        }
        indiceCadena++;
    }
    // Al final se agrega el carácter NULL para terminar la cadena
    cadena[indiceCadenaLimpia] = 0;
}

void intersection() {
    int contador = 0, acumulado = 0;
    char auxiliar1[200], auxiliar2[200],cadena1[200], cadena2[200];
    char *final = "";
    printf("ingrese su cadena\n");
    fflush(stdin);
    fgets(cadena1, 200, stdin);
    printf("ingrese su cadena dos\n");
    fflush(stdin);
    fgets(cadena2, 200, stdin);


    for (int i = strlen(cadena2) - 1; i >= 0; --i) {
        for (int j = 0; j <  strlen(cadena2) - 1; ++j) {
            if (cadena2[i] == cadena2[j]) contador++;
        }
        if (contador > 1) {
            memset(auxiliar1, 0, 200);
            memset(auxiliar2, 0, 200);
            for (int j = i + 1; j <  strlen(cadena2) - 1; ++j) {
                auxiliar1[acumulado] = cadena2[j];
                acumulado++;
            }
            acumulado = 0;
            for (int j = 0; j < i; ++j) {
                auxiliar2[j] = cadena2[j];
            }
            memset(cadena2, 0, 200);
            strcat(strcpy(cadena2, auxiliar2), auxiliar1);
        }
        contador = 0;
    }

    memset(auxiliar1, 0, 200);
    contador = 0;
    acumulado = 0;
    for (int i = 0; i < strlen(cadena2); ++i) {
        for (int j = 0; j < strlen(cadena1); ++j) {
            if (cadena2[i] == cadena1[j]) contador++;
        }
        if (contador > 0) {
            auxiliar1[acumulado] = cadena2[i];
            acumulado++;
            contador = 0;
        }
    }
    final = auxiliar1;
    printf("la interseccion de las cadenas son: \n%s \n", final);


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

//contar palabras repetidas.....................


int toLower(char *cadena) {
    int n = 0;
    for(int i = 0; i < strlen(cadena); i++) {
        cadena[i] = tolower(cadena[i]);
        if(cadena[i] == ' ') {
            n++;
        }
    }
    return n+1;
}
int toLower(char *cadena);

void wordCount() {
    char cadena[1000];
    printf("\n-----|Escriba una cadena| ");
    scanf(" %[^\n]",cadena);
    char cadena2[20];
    printf("\n-----|Escriba una palabra| ");
    scanf(" %[^\n]",&cadena2);

    char aux[strlen(cadena)]; //cadena auxiliar
    strcpy(aux, cadena); //Copiamos  la cadena original en la cadena auxiliar

    int nPalabras = toLower(aux); // es el numero de palabras
    char cadena3[nPalabras][30]; //Variable que almacena cada palabra en un espacio
    char *cadena4 = strtok(aux, " ,.!?"); //Función que convierte una cadena a cadena3.
    nPalabras = 0;
    while(cadena4 != NULL) {
        strcpy(cadena3[nPalabras++], cadena4); //Se almacena cada palabra en un espacio
        cadena4 = strtok(NULL, " ,.-!?");
    }

    int contPal[nPalabras]; // numero de repeticiones de cada palabra
    int palRep = 0; //Variable auxiliar para saber cuantas se repiten.

    for(int i = 0; i <nPalabras; i++) {
        contPal[i] = 0;
    }
    for(int i = 0; i < nPalabras ; i++) {
        if(strcmp(cadena2  , cadena3[i]) == 0  ){
            //compara las cadenas si son iguales
            strcpy(cadena3[i],"*");
            contPal[palRep]++;
        }
    }

    printf("\n%s\n", cadena);
    printf("Las palabra repetida es");
    for(int i = 0; i <nPalabras; i++) { // muestra la palabra y su numero de repeticiones
        if(strcmp(cadena3[i], "*") == 0 && contPal[palRep] != 0 ) {
            printf(" %s:  %d veces.\n", cadena2, contPal[palRep++]);
        }
    }

}
//....................................