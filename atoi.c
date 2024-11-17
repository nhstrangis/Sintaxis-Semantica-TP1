#include <stdio.h>
#include <ctype.h>

const int MAX_LEN = 1000;

// Ejercicio 2

size_t stringLen(char *arr){

    size_t len = 0;

    while (arr[len] != '\0' && (len < MAX_LEN)) {
        len++;
    }          
    return len;
}

size_t stringToInt(char *arr){

    size_t len, number, finalNumber = 0;

    len = stringLen(arr);

    for (int i = 0; i < len; i++)
    {
        if(!isdigit(arr[i]) && arr[i] != '\0') {
            return -1;
        }
        number = arr[i] - '0';
        finalNumber = (finalNumber * 10) + number;
    }

    return finalNumber;
}

// Prueba ejercicio 2 
/*
int main(int argc, char*argv[]){

    char cadena[]="2500";
    int numero;

    numero = convertirCadena(cadena);

    printf("%d",numero);
    
    return 0;
}
*/