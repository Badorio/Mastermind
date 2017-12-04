#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED

//afficher un ecran de demarrage
void afficherSplashscreen();

//Dimension bien précise ici; on affiche le tableau des essais joueur
void afficherEssais(char tab[10][7]);

//On affiche les règles du jeu
void afficherRegles();

//Donner l'adresse du premier element du tableau !
//Afficher les couleurs possibles -> Elles sont stockées dans un tableau -> plus facile pour vérifier à la saisie des essais !!!
void afficherCouleurs(char* couleurs);

//Affiche la couleur d'un caractère
//Table des couleurs en fonction des caractères
//Prend un caractère comme paramètre. Si il fait partie des couleurs, on affiche la couleur. Sinon, on affiche le caractère
void afficher1Couleur(char couleur);

//Affiche le menu principal du jeu avec toutes ses options
void afficherMenu();

//Efface le contenu de la console
void effacerEcran();

//Demande à l'utilisateur d'appuyer sur entrée pour continuer le programme
void enterPourContinuer();


#endif // AFFICHAGE_H_INCLUDED
