#include "caract.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void encoderMot(char* debutMot, char couleurs[9])
{
    int i;
    char tmp;
    //variable permettant d'optimiser un peu le code..
    int cond;


    //On a besoin de cette instruction pour la condition charDansMot avec debutMot
    //Je n'ai pas testé sans, mais ça me paraît logique.
    debutMot[4]='\0';

    for(i=0; i<4; i++)
    {
        do{
            cond=0;
            printf("\nCouleur %d : ", i+1);
            fflush(stdin);
            scanf("%c", &tmp);


            //Couleur incorrecte
            if(charDansMot(tmp, couleurs)==0)
            {
                printf("\n\nCOULEUR INVALIDE ! Recommencez...\n\n");
                cond++;
            }

            //Repetition
            else
            {
                if(charDansMot(tmp, debutMot)==1)
                {
                    printf("\n\nCOULEUR DEJA ENCODEE ! Choisissez une autre couleur...\n\n");
                    cond++;
                }
            }
            //A la base on avait les deux conditions ici en plus, mais j'ai préféré ajouter une variable cond pour eviter les repetitions
            }while(cond>0);

        debutMot[i]=tmp;
    }
}

void initTableau(char tab[10][7])
{
    int i, j;

    for(i=0; i<10; i++)
    {
        for(j=0; j<6; j++)
        {
            tab[i][j]='_';
        }
        tab[i][6]='\0';
    }
}

void initMot(char* debutMot)
{
    short i=0;
    while(debutMot[i]!='\0')
    {
        debutMot[i]='_';
        i++;
    }
}

int charDansMot(char lettre, char* mot)
{
    int i=0;
    int returnValue; //On comprend ce qu'elle fait.. c'est pour n'avoir qu'un seul return. -> Demander au prof

    while(mot[i]!=lettre && mot[i]!='\0')
    {
        i++;
    }
    //Si la lettre n'est pas dans le mot
    if(mot[i]=='\0' && mot[i-1]!=lettre)
        returnValue=0;
    else
        returnValue=1;

    return returnValue;
}

int comparMots(char* mot1, char* mot2)
{
    int i=0;
    int cpt=0;

    while(i<4)
    {
        if(mot1[i]==mot2[i])
            cpt++;

        i++;
    }

    return cpt;
}

