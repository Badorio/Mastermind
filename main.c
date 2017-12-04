#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Pour srand
#include "affichage.h"
#include "caract.h"

/*****************************************************/
/* Auteur : BELLUZ Benjamin                          */
/* Groupe : 2105                                     */
/* Application : Mastermind dossier 1                */
/* Date dernière mise à jour : 04/12/2017            */
/*****************************************************/

void jeu(char* mot, char essais[10][7], char couleurs[9]);

int finJeu(int couleursBienPlacees, int nbEssais);

int main()
{
    //Definition des couleurs possibles
    char couleurs[9]={'R', 'V', 'B', 'N', 'b', 'J', 'M', 'r', '\0'};
    //Tableau contenant les essais joueur
    char essais[10][7];
    //Liste de 4 couleurs à trouver
    char mot[5];
    mot[4]='\0';

    int choixMenuInit;
    int i, i2;

    //Seed pour le rand, histoire de ne pas jouer à chaque fois les même parties en solo
    srand(time(NULL));

    afficherSplashscreen();
    effacerEcran();

    //boucle principale du jeu
    do{
        afficherMenu();

        fflush(stdin);
        scanf("%d", &choixMenuInit);

        effacerEcran();

        //Initialisation tableau et mot à trouver
        initTableau(essais);
        initMot(&mot[0]);


        switch(choixMenuInit)
        {
        case 1: //Mode 1 joueur
            //Création de la suite de couleurs aléatoire
            for(i=0; i<4; i++)
            {

                do{
                    i2=rand()%8; //Prendre une couleur dans les 8
                }
                while(charDansMot(couleurs[i2], mot)==1); //Tant que la lettre est dans le mot on recommence
                mot[i]=couleurs[i2];
            }

            //Jeu
            jeu(&mot[0], essais, couleurs);

            break;
        case 2: //Mode 2 joueurs
            //Saisie de la suite de couleurs
            printf("\n\nJoueur 1, encodez la suite de couleurs : \n\n");
            afficherCouleurs(couleurs);
            encoderMot(&mot[0], couleurs);

            //Jeu
            jeu(&mot[0], essais, couleurs);

            break;
        case 3: //Regles
            afficherRegles();

            enterPourContinuer();
            effacerEcran();
            break;
        case 4: //Quitter
            break;
        default:
            printf("\n\nCHOIX INCORRECT ! Recommencez !\n\n");
            enterPourContinuer();
        }

        effacerEcran();
    }
    while(choixMenuInit != 4); //4 est l'option quitter

    return 0;
}

void jeu(char* mot, char essais[10][7], char couleurs[9])
{
    int numEssai=0, i;
    int colBienPlac=0, colMalPlac=0, victoire=0;

    do{
        effacerEcran();

        afficherCouleurs(couleurs);
        afficherEssais(essais);
        encoderMot(&essais[numEssai][0], couleurs);

        colMalPlac=0;
        colBienPlac=comparMots(&essais[numEssai][0], &mot[0]);

        //Comptage des couleurs mal placees
        for(i=0; i<4; i++)
        {
            if(charDansMot(essais[numEssai][i], &mot[0])==1)
                colMalPlac++;
        }
        //Nombre de couleurs mal placees : nb coul bien placees - nb occurrences des bonnes couleurs
        colMalPlac-= colBienPlac;

        //Nombre de couleurs bien placees et mal placees
        //IL FAUT TRANSFORMER LE INT EN CHAR pour afficher la bonne valeur!! -> +48
        essais[numEssai][4]=colBienPlac+48;
        essais[numEssai][5]=colMalPlac+48;

        numEssai++;
        victoire = finJeu(colBienPlac, numEssai);
    }
    while(victoire == 0);

    //On efface tout à la fin du jeu pour afficher le message de fin ainsi que la grille finale
    effacerEcran();

    //Afficher la grille de nouveau à la fin du jeu
    afficherEssais(essais);

    if(victoire == 1)
        printf("\n\nVous avez gagne !\nLa suite de couleurs a trouver etait bien ");
    else
        printf("\n\nVous n'avez plus d'essais, dommage !\n La suite de couleurs a trouver etait ");

    for(i=0; i<4; i++)
    {
        //CREER UNE FONCTION AFFICHER COULEUR void afficherCouleurChar(char a)
        afficher1Couleur(mot[i]);
    }
    printf("\n\n");

    enterPourContinuer();

}

int finJeu(int couleursBienPlacees, int nbEssais)
{
    int valeurRetour;
    //partie pas finie
    if(couleursBienPlacees < 4 && nbEssais < 10)
        valeurRetour=0;
    else
    {
        //Fini mais perdu
        if(nbEssais >= 10 && couleursBienPlacees < 4)
            valeurRetour = -1;
        //Victoire
        else
            valeurRetour = 1;
    }
    return valeurRetour;
}




