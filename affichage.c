#include "affichage.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h> //Utilisé pour le system("cls")

#define ANSI_COLOR_RED      "\x1b[1;31m\x1b[101m"
#define ANSI_COLOR_GREEN    "\x1b[32m\x1b[42m"
#define ANSI_COLOR_YELLOW   "\x1b[1;33m\x1b[103m"
#define ANSI_COLOR_BLUE     "\x1b[1;34m\x1b[104m"
#define ANSI_COLOR_PINK     "\x1b[1;35m\x1b[105m"
#define ANSI_COLOR_BLACK    "\x1b[1;30m\x1b[100m"

#define ANSI_COLOR_WHITE    "\x1b[1;37m\x1b[107m"
#define ANSI_COLOR_PURPLE   "\x1b[35m\x1b[45m"
//Void est du texte noir sur fond noir -> invisible
#define ANSI_COLOR_VOID     "\x1b[30m\x1b[40m"
#define ANSI_COLOR_RESET    "\x1b[0m"

void afficherSplashscreen()
{
    printf("\n");
    printf("\n");
    printf("\n     #             #          #           #####    ##########  #########  #####");
    printf("\n     ##           ##         # #         #     #       #       #          #    #");
    printf("\n     # #         # #        #   #        #             #       #          #    #");
    printf("\n     #  #       #  #       #######         #           #       #####      #####");
    printf("\n     #   #     #   #      #       #          #         #       #          #  #");
    printf("\n     #    #   #    #     #         #           #       #       #          #   #");
    printf("\n     #     # #     #    #           #   #       #      #       #          #    #");
    printf("\n     #      #      #   #             #   #######       #       #########  #     #");
    printf("\n");
    printf("\n");
    printf("\n                   #             #   #####   #      #   ####");
    printf("\n                   ##           ##     #     ##     #   #   #");
    printf("\n                   # #         # #     #     # #    #   #    #");
    printf("\n                   #  #       #  #     #     #  #   #   #    #");
    printf("\n                   #   #     #   #     #     #   #  #   #    #");
    printf("\n                   #    #   #    #     #     #    # #   #    #");
    printf("\n                   #     # #     #     #     #     ##   #   #");
    printf("\n                   #      #      #   #####   #      #   ####");
    printf("\n\n");

    //system("pause"); -> C'était un test, mais je préfère la manière dont enterPourContinuer fonctionne
    //Appuyez sur enter..
    enterPourContinuer();
}

void afficherRegles()
{
    printf("\n\nLe premier joueur choisit une suite de quatre couleurs differentes.");
    printf("\nEn mode un joueur, c'est l'ordinateur qui choisit.");
    printf("\nEnsuite, le deuxieme joueur essaie de trouver la suite de couleurs definie plus tot.");
    printf("\nLe joueur possede 10 essais pour trouver la suite de couleurs.");
    printf("\nPour chacun de ses essais, le joueur saura le nombre de couleurs correctes et bien placees,");
    printf("\nainsi que le nombre de couleurs correctes mais mal placees, et le nombre d'essais restants.\n\n");
}

void afficherCouleurs(char *couleurs)
{
    int i=0;
    do{
        printf(ANSI_COLOR_RESET"%c"ANSI_COLOR_RESET" : ", *couleurs);
        afficher1Couleur(*couleurs);
        if(i%2==1)
            printf("\n");
        else
            printf("\t");

        i++;
        couleurs++;
    }while(*couleurs!='\0');
    printf(ANSI_COLOR_RESET"\n\n");
}

void afficher1Couleur(char couleur)
{
    switch(couleur)
    {
    /*
   Les ANSI_COLOR_RESET ANSI_COLOR_VOID sont là pour éviter que lors d'un redimensionnement de la fenêtre, la couleur s'étire
   sur toute la console. En ayant un caractère en noir derrière, on évite le problème.
   */
    case 'R':
        printf(ANSI_COLOR_RED "a"ANSI_COLOR_RESET ANSI_COLOR_VOID"a"ANSI_COLOR_RESET);
        break;
    case 'V':
        printf(ANSI_COLOR_GREEN"a"ANSI_COLOR_RESET ANSI_COLOR_VOID"a"ANSI_COLOR_RESET);
        break;
    case 'B':
        printf(ANSI_COLOR_BLUE"a"ANSI_COLOR_RESET ANSI_COLOR_VOID"a"ANSI_COLOR_RESET);
        break;
    case 'N':
        printf(ANSI_COLOR_BLACK"a"ANSI_COLOR_RESET ANSI_COLOR_VOID"a"ANSI_COLOR_RESET);
        break;
    case 'b':
        printf(ANSI_COLOR_WHITE"a"ANSI_COLOR_RESET ANSI_COLOR_VOID"a"ANSI_COLOR_RESET);
        break;
    case 'J':
        printf(ANSI_COLOR_YELLOW"a"ANSI_COLOR_RESET ANSI_COLOR_VOID"a"ANSI_COLOR_RESET);
        break;
    case 'M':
        printf(ANSI_COLOR_PURPLE"a"ANSI_COLOR_RESET ANSI_COLOR_VOID"a"ANSI_COLOR_RESET);
        break;
    case 'r':
        printf(ANSI_COLOR_PINK"a"ANSI_COLOR_RESET ANSI_COLOR_VOID"a"ANSI_COLOR_RESET);
        break;
        default:
            printf("%c"ANSI_COLOR_VOID"a"ANSI_COLOR_RESET, couleur);
    }
}

//affichage du tableau d'essais
void afficherEssais(char tab[10][7])
{
    int i, j;

    printf("\na : couleurs bien placees\nb : couleurs mal placees\n");

    printf("\t\t\t\t  a  |  b");
    printf("\n\t\t__________________________");

    for(i=0; i<10; i++)
    {
        printf("\n\n");
        printf("Essai %d :  \t", i+1);

        for(j=0; j<4; j++)
        {
            printf("| ");
            afficher1Couleur(tab[i][j]);
        }
        printf("|");
        for(j=4; j<6; j++)
        {
            printf("| %c ", tab[i][j]);
        }
        printf("|\n");
    }
}

void afficherMenu()
{
    printf("\nMASTERMIND\n\n\n");
    printf("\n\n1. Un joueur");
    printf("\n\n2. Deux joueurs");
    printf("\n\n3. Regles du jeu");
    printf("\n\n4. Quitter\n\n");
}

void effacerEcran()
{
    system("cls");
}

void enterPourContinuer()
{
    char a;

    printf("\n\n\nAppuyez sur entree pour continuer...\n\n");
    fflush(stdin);
    scanf("%c", &a);
}
