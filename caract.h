#ifndef CARACT_H_INCLUDED
#define CARACT_H_INCLUDED

//Encoder les essais et le mot initial
//Ne connait pas la dimension du tableau, être attentif aux \0 !!!
void encoderMot(char* debutMot, char couleurs[9]);

//Initialise le tableau de char avec les essais et les résultats de chacun de ceux-ci
void initTableau(char tab[10][7]);

//Initialise le mot à trouver
void initMot(char* debutMot);

//Compare deux mots -> ON SAIT QUE LES MOTS ONT UNE LONGUEUR DE 4 CHAR, Y FAIRE ATTENTION
//Retourne le nombre de caractères identiques
int comparMots(char* mot1, char* mot2);

//Vérifie si un caractère se trouve dans une chaine ou non, peu importe sa position
int charDansMot(char lettre, char* mot);


#endif // CARACT_H_INCLUDED
