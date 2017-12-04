#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED

//afficher un ecran de demarrage
void afficherSplashscreen();

//Dimension bien pr�cise ici; on affiche le tableau des essais joueur
void afficherEssais(char tab[10][7]);

//On affiche les r�gles du jeu
void afficherRegles();

//Donner l'adresse du premier element du tableau !
//Afficher les couleurs possibles -> Elles sont stock�es dans un tableau -> plus facile pour v�rifier � la saisie des essais !!!
void afficherCouleurs(char* couleurs);

//Affiche la couleur d'un caract�re
//Table des couleurs en fonction des caract�res
//Prend un caract�re comme param�tre. Si il fait partie des couleurs, on affiche la couleur. Sinon, on affiche le caract�re
void afficher1Couleur(char couleur);

//Affiche le menu principal du jeu avec toutes ses options
void afficherMenu();

//Efface le contenu de la console
void effacerEcran();

//Demande � l'utilisateur d'appuyer sur entr�e pour continuer le programme
void enterPourContinuer();


#endif // AFFICHAGE_H_INCLUDED
