#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef enum { INICIO, FIN, LEER, ESCRIBIR, ID, CONSTANTE, PARENIZQUIERDO,
               PERENDERECHO, PUNTOYCOMA, COMA, ASIGNACION, SUMA, RESTA, FDT} TOKEN;

int mTT[15][13] = {{1, 3, 5, 6, 7, 8, 9, 10, 11, 14, 13, 0,14},
                   {1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                   {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
                   {4, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
                   {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
                   {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
                   {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
                   {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
                   {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
                   {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
                   {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
                   {14, 14, 14, 14, 14, 14, 14, 14, 14, 12, 14, 14, 14},
                   {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
                   {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
                   {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}};

char buffer[40];

void agregarCaracter(char c)
{
    int i = 0;
    while(buffer[i]!='\0')
    {
        i++;
    }
    buffer[i] = c;

}

TOKEN esReservada()
{
    if(buffer[0]=='i' && buffer[1] == 'n' && buffer[2] == 'i' && buffer[3] == 'c' && buffer[4] == 'i' && buffer[5] == 'o' && buffer[6] == '\0')
    {
        return INICIO;
    }
    if(buffer[0]=='f' && buffer[1] == 'i' && buffer[2] == 'n' && buffer[3] == '\0')
    {
        return FIN;
    }
    if(buffer[0]=='l' && buffer[1] == 'e' && buffer[2] == 'e' && buffer[3] == 'r' && buffer[4] == '\0')
    {
        return LEER;
    }
    if(buffer[0]=='e' && buffer[1] == 's' && buffer[2] == 'c' && buffer[3] == 'r' && buffer[4] == 'i' && buffer[5]=='b' && buffer[6] == 'i' && buffer[7] == 'r' && buffer[8] =='\0')
    {
        return ESCRIBIR;
    }
    return ID;
}

void limpiarBuffer()
{
    int i=0;
    while (i<39)
    {
        buffer[i]='\0';
        i++;
    }
}

int columna(char c)
{

   if ( isalpha(c) ) return 0;
   if ( isdigit(c) ) return 1;
   if ( c == '+' ) return 2;
   if ( c == '-' ) return 3;
   if ( c == '(' ) return 4;
   if ( c == ')' ) return 5;
   if ( c == ',' ) return 6;
   if ( c == ';' ) return 7;
   if ( c == ':' ) return 8;
   if ( c == '=' ) return 9;
   if ( c == EOF ) return 10;
   if ( isspace(c) ) return 11;
   return 12;

}

bool idCorrecto()
{
    int cont = 0, i = 0;
    while(buffer[i]!='\0')
    {
        cont++;
        i++;
    }
    if(cont<32)
    {
        return true;
    }
    else
    {
        return false;
    }


}

void mostrarBuffer(FILE *p2)
{
    int i=0;
    while(buffer[i]!='\0')
    {
        fputc(buffer[i], p2);
        i++;
    }


}

void scanner(FILE* p1, FILE* p2)
{
    int estado = 0, j;
    char c;
    c = fgetc(p1);
    limpiarBuffer;

    while(!feof(p1))
    {
        j = columna(c);
        estado = mTT[estado][j];

        switch(estado)
        {
        case 0:
            limpiarBuffer;
            c = fgetc(p1);
            break;
        case 1:
            agregarCaracter(c);
            c = fgetc(p1);
            break;
        case 2:
            ungetc(c, p1);
            if(esReservada()!=ID)
            {
                mostrarBuffer(p2);
                fprintf(p2, "  |    Palabra Reservada.\n");
                estado = 0;
            }
            else
            {
                if(idCorrecto)
                {
                    mostrarBuffer(p2);
                    fprintf(p2, "  |    IDENTIFICADOR.\n");
                    estado = 0;
                }
                else
                {
                    fprintf(p2, "  |    Se detecto un error lexico, los identificadores deben tener un maximo de 32 caracteres.\n");
                    estado = 0;
                }
            }
            limpiarBuffer(p2);
            c = fgetc(p1);
            break;

        case 3:
            agregarCaracter(c);
            c = fgetc(p1);
            break;
        case 4:
            ungetc(c, p1);
            mostrarBuffer(p2);
            c = fgetc(p1);
            fprintf(p2, "  |    DIGITO.\n");
            estado = 0;
            limpiarBuffer;
            break;
        case 5:
            mostrarBuffer(p2);
            c = fgetc(p1);
            fprintf(p2, "  |    SUMA.\n");
            estado = 0;
            break;
        case 6:
            mostrarBuffer(p2);
            c = fgetc(p1);
            fprintf(p2, "  |    RESTA.\n");
            estado = 0;
            break;
        case 7:
            mostrarBuffer(p2);
            c = fgetc(p1);
            fprintf(p2, "  |    PARENIZQUIERDO.\n");
            estado = 0;
            break;
        case 8:
            mostrarBuffer(p2);
            c = fgetc(p1);
            fprintf(p2, "  |    PARENDERECHO.\n");
            estado = 0;
            break;
        case 9:
            mostrarBuffer(p2);
            c = fgetc(p1);
            fprintf(p2, "  |    COMA.\n");
            estado = 0;
            break;
        case 10:
            mostrarBuffer(p2);
            c = fgetc(p1);
            fprintf(p2, "  |    PUNTOYCOMA.\n");
            estado = 0;
            break;
        case 11:
            mostrarBuffer(p2);
            c = fgetc(p1);
            fprintf(p2, "  |    Signo de puntuación.\n");
            estado = 0;
            break;
        case 12:
            mostrarBuffer(p2);
            c = fgetc(p1);
            fprintf(p2, "  |    Signo de puntuación.\n");
            estado = 0;
            break;
        case 14:
            mostrarBuffer(p2);
            c = fgetc(p1);
            fprintf(p2, "  |    Se encontro un error léxico.\n");
            estado = 0;
            break;
        }
        }



    }

int main()
{
    FILE* p1;
    FILE* p2;
    p1=fopen("Archivo.txt","r");
    p2=fopen("nuevoArchivo.txt","w");
    scanner(p1, p2);
    return 0;

}
