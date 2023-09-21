
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int get_number_type(char number[], int number_size)
{
    // retorna si el numero es Entero (0), decimal (1), o rut(2) o salir del programa(3) }
    for (int i = 1; i < number_size; i++)
    { // empieza en el indice 1 para q no tope con el - de un menos de un entero.
             // char character = number[i];
        if (number[i] == '-')
        {
            return 2;
        }
        if (number[i] == '.')
        {
            return 1;
        }
        if (number[i] == 'r')
        {
            return 3;
        }
    } // cuando sale del for, si no ha topado con un guion o ., siginifca q esentero 
    return 0;
}
int whole_to_int(char *word, char *input)
{
    /*vamos a transofmar nuestro numero a un int, y manejamos el menos, si esq
    hay,
    agregandolo a nuestra string final
    pasamos un puntero con el string para poder cabialo desde la funcion
    y que se cambie por el resto del programa */
    // char input[] = "-100";
    int number_length = (int)strlen(input);
    char input_to_number[50];
    int number;
    // verificamos si hay un menos
    if (input[0] == '-')
    {
        strcpy(word, strcat(word, "menos "));
        // printf("%s", *word);
        // transformamos el input a un entero, para ello creamos una copia
        // del input que no tenga el menos y usaremos la funcion atoi()
        for (int i = 0; i < number_length - 1; i++)
        {
            input_to_number[i] = input[i + 1];
        }
    }
    else
    {
        // si no hay un menos, hacemos una copia exacta nada mas
        for (int i = 0; i < number_length; i++)
        {
            input_to_number[i] = input[i];
        }
    }
    // ahora si usamos la funcion atoi para tener el numero en int
    number = atoi(input_to_number);
    // printf("%d", number);
    // una vez tenemos el numero en int es mas facil,
    return number;
}
void int_to_word(char *word, int number)
{
    // creamos la string frist words , pq strcat solo concatena al final de la
    string char first_words[100] = "";
    // int original_number = number;
    // primeros tres digitos
    int unit = number % 10;
    number = number / 10;
    // printf("%d\n", unit);
    int ten = (number) % 10;
    // printf("%d\n", ten);
    number = number / 10;
    int hundred = number % 10;
    number = number / 10;
    char units[][20] = {"cero", "uno ", "dos ", "tres ", "cuatro ", "cinco ",
                        "seis ", "siete ", "ocho ", "nueve "};
    char teens[][20] = {"", "once ", "doce ", "trece ", "catorce ", "quince ",
                        "dieciseis ", "diecisiete ", "dieciocho ", "diecinueve "};
    char twenties[][20] = {"", "veintiuno ", "veintidos ", "veintitres ",
                           "veinticuatro ", "veinticinco ", "veintiseis ", "veintisiete ", "veintiocho ",
                           "veintinueve "};
    char tens[][20] = {"", "diez ", "veinte ", "treinta ", "cuarenta ",
                       "cincuenta ", "sesenta ", "setenta ", "ochenta ", "noventa "};
    char hundreds[][20] = {"", "cien ", "docientos ", "trescientos
                                                      "," cuatrocientos ", " quinientos ", " seiscientos ", " setecientos "," ochocientos ",
                                                      "novecientos "};
    if ((hundred == 1) && ((unit != 0) || (ten != 0)))
    {
        strcat(first_words, "ciento ");
    }
    else
    {
        strcat(first_words, hundreds[hundred]);
    }
    if ((unit != 0) && (ten == 1))
    {
        strcat(first_words, teens[unit]);
    }
    else if ((unit != 0) && (ten == 2))
    {
        strcat(first_words, twenties[unit]);
    }
    else if (unit == 0)
    {
        strcat(first_words, tens[ten]);
    }
    else if (ten == 0)
    {
        strcat(first_words, units[unit]);
    }
    else
    {
        strcat(first_words, tens[ten]);
        strcat(first_words, "y ");
        strcat(first_words, units[unit]);
    }
    int umil = number % 10;
    number = number / 10;
    int dmil = number % 10;
    number = number / 10;
    int cmil = number % 10;
    number = number / 10;
    // miles (misma logica anterior)
    strcpy(units[1], "un ");
    strcpy(twenties[1], "veintiun ");
    char next_words[100] = "";
    if ((cmil == 1) && ((umil != 0) || (dmil != 0)))
    {
        strcat(next_words, "ciento ");
    }
    else
    {
        strcat(next_words, hundreds[cmil]);
    }
    if ((umil != 0) && (dmil == 1))
    {
        strcat(next_words, teens[umil]);
    }
    else if ((umil != 0) && (dmil == 2))
    {
        strcat(next_words, twenties[umil]);
    }
    else if ((umil == 1) && (dmil == 0) && (cmil == 0))
    {
        strcat(next_words, "");
    }
    else if (umil == 0)
    {
        strcat(next_words, tens[dmil]);
    }
    else if (dmil == 0)
    {
        strcat(next_words, units[umil]);
    }
    else
    {
        strcat(next_words, tens[dmil]);
        strcat(next_words, "y ");
        strcat(next_words, units[umil]);
    }
    if ((umil != 0) || (dmil != 0) || (cmil != 0))
    {
        strcat(next_words, "mil ");
    }
    strcat(next_words, first_words);
    // millones, misma logica
    int umill = number % 10;
    number = number / 10;
    int dmill = number % 10;
    char last_words[100] = "";
    if ((umill != 0) && (dmill == 1))
    {
        strcat(last_words, teens[umill]);
    }
    else if ((umill != 0) && (dmill == 2))
    {
        strcat(last_words, twenties[umill]);
    }
    else if ((umill == 1) && (dmill == 0))
    {
        strcat(last_words, "");
    }
    else if (umill == 0)
    {
        strcat(last_words, tens[dmill]);
    }
    else if (dmill == 0)
    {
        strcat(last_words, units[umill]);
    }
    else
    {
        strcat(last_words, tens[dmill]);
        strcat(last_words, "y ");
        strcat(last_words, units[umill]);
    }
    if ((umill == 1) && (dmill == 0))
    {
        strcat(last_words, "un millon ");
    }
    else if ((umill != 0) || (dmill != 0))
    {
        strcat(last_words, "millones ");
    }
    strcat(last_words, next_words);
    strcat(word, last_words);
    if (strcmp(word, "") == 0)
    {
        strcat(word, "cero ");
    }
}
void decimal_to_word(char *word, char *number)
{
    // recibimos la palabra para partirla en dos enteros, que luego seran llevadosa la palabra final 
    int decimal_or_int = 0; // decimal = 1 int = 0
    char decimal[30] = "";
    char integer[30] = "";
    int number_length = (int)strlen(number);
    for (int i = 0; i < number_length; i++)
    {
        if (number[i] == '.')
        {
            decimal_or_int = 1;
            continue;
        }
        if (decimal_or_int == 1)
        {
            strncat(decimal, &number[i], 1);
        }
        else
        {
            strncat(integer, &number[i], 1);
        }
    }
    // una vez tenemnos los dos int:
    int whole_number = whole_to_int(word, integer);
    int decimal_number = atoi(decimal);
    char word1[100] = "";
    char word2[100] = "";
    int_to_word(word1, whole_number);
    int_to_word(word2, decimal_number);
    // printf("%s\n, ", word1);
    // printf("%s\n, ", word2);
    strcat(word, word1);
    strcat(word, "coma ");
    int decimal_len = (int)strlen(decimal);
    if (decimal_len >= 2)
    {
        if (decimal[0] == '0')
        {
            strcat(word, "cero ");
        }
        if ((decimal[0] == '0') && (decimal[1] == '0'))
        {
            strcat(word, "cero ");
        }
    }
    strcat(word, word2);
}
void rut_to_word(char *word, char *rut)
{
    // despues de todos estos este ya es el mas facil
    char verificador = rut[strlen(rut) - 1];
    // printf("%s\n", rut);
    char word1[100] = "";
    char rut_str_number[20] = "";
    for (int i = 0; rut[i] != '-'; i++)
    {
        strncat(rut_str_number, &rut[i], 1);
    }
    int rut_number = atoi(rut_str_number);
    int_to_word(word1, rut_number);
    // logica del verificador
    char units[][20] = { "", "uno ", "dos ", "tres ", "cuatro ", "cinco ", "seis
                                                                           ", " siete ", " ocho ", " nueve "};
    strcat(word1, "raya ");
    if (verificador == 'k')
    {
        strncat(word1, &verificador, 1);
    }
    else
    {
        int i_ver = verificador - '0';
        // printf("%c\n", verificador);
        // printf("%d\n", i_ver);
        strcat(word1, (units[i_ver]));
    }
    strcpy(word, word1);
}
int main()
{
    char word1[100] = "";
    char input[100];
    while (1)
    {
        printf("\ningrese el numero. (ingrese salir para salir): ");
        scanf("%s", input);
        int input_size = (int)strlen(input);
        int number_type = get_number_type(input, input_size);
        // printf("nt = %d\n", number_type);
        if (number_type == 3)
        {
            break;
        }
        if (number_type == 0)
        {
            int number = whole_to_int(word1, input);
            int_to_word(word1, number);
        }
        if (number_type == 1)
        {
            decimal_to_word(word1, input);
        }
        if (number_type == 2)
        {
            rut_to_word(word1, input);
        }
        printf("%s\n", word1);
        strcpy(word1, "");
        strcpy(input, "");
    }
    return 0;
}