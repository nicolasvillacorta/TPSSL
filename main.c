#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void iniVec(char *pal)
{
    i=0;
    while(i<31)
    {
        pal[i]='\0';
    }
    return 0;
}

void scanner(char pal)
{
    if(pal[0]==':' && pal[1]=='=' && pal[2]=='\0')
    {
        fprintf(p2, " es el simbolo de ASIGNACION.");
    }
    if(pal[0]==',' && pal[1]=='\0')
    {
        fprintf(p2, " es un caracter de puntuación.");
    }
    if(pal[0]==';' && pal[1]=='\0')
    {
        fprintf(p2, " es un caracter de puntuación.");
    }
    if(pal[0]=='+' && pal[1]=='\0')
    {
        fprintf(p2, " es el operador de SUMA.");
    }
    if(pal[0]=='-' && pal[1]=='\0')
    {
        fprintf(p2, " es el operador de RESTA.");
    }
    if(pal[0]==')' && pal[1]=='\0')
    {
        fprintf(p2, " es el caracter: PARENDERECHO.")
    }
    if(pal[0]=='(' && pal[1]=='\0')
    {
        fprintf(p2, " es el caracter: PARENIZQUIERDO.")
    }
    if(pal[0]=='i' && pal[1]=='n' && pal[2]=='i' && pal[3]=='c' && pal[4]=='i' && pal[5]=='o' && pal[6]=='\0')
    {
        fprintf(p2, " es la palabra reservada INICIO.")
    }
    if(pal[0]=='l' && pal[1]=='e' && pal[2]=='e' && pal[3]=='r' && pal[4]=='\0')
    {
        fprintf(p2, " es la palabra reservada LEER.")
    }
    if(pal[0]=='e' && pal[1]=='s' && pal[2]=='c' && pal[3]=='r' && pal[4]=='i' && pal[5]=='b' && pal[6]=='i' && pal[7]=='r' && pal[8]=='\0')
    {
        fprintf(p2, " es la palabra reservada ESCRIBIR.")
    }
    if(pal[0]=='f' && pal[1]=='o' && pal[2]=='n' && pal[3]=='\0')
    {
        fprintf(p2, " es la palabra reservada FIN.")
    }


}


int columna(char c)
{
    switch(c)
    {
    case isalpha:
        return 1;
        break;
    case isdigit:
        return 2;
        break;
    case '+':
        return 3;
        break;
    case '-':
        return 4;
        break;
    case '(':
        return 5;
        break;
    case ')':
        return 6;
        break;
    case ',':
        return 7;
        break;
    case ';':
        return 8;
        break;
    case ':':
        return 9;
        break;
    case '=':
        return 10;
        break;
    case '\0':
        return 11;
        break;
    case isspace:
        return 12;
        break;
    default:
        return 13;
    }


}

int main()
{
    int mTT[13][15] = {{1, 3, 5, 6, 7, 8, 9, 10, 11, 14, 13, 0,14},
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
                       {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}}

    FILE* p1;
    FILE* p2;
    p1=fopen("Archivo.txt","r");
    p2=fopen("nuevoArchivo.txt","w");
    int estado=0, i=0, j;
    char pal[32];
    iniVec(pal);
    char c;
    c=fgetc(p1);

    while(!feof(p1))
    {
        while(estado!=14 && estado!=99)
        {

        pal[i]=c;

        fputc(pal[i], p2);;


        c=fgetc(p1);

        j = columna(pal[i]);

        estado = mTT[estado][j];

        i++;
        }

        i=0;

        if(estado=99)
        {
            fprintf("Se detecto un error sintactico en esta palabra.\n", p2);
        }
        if(estado=14)
        {
            scanner(pal,);
        }

    }






    return 0;
}
