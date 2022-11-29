#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"

int main()
{ // Le nombre de colonnes  et de lignes du jeu
    unsigned int taille;
    unsigned int n_point_vivre, num_tour;

    // Saisie du nombre de colonnes et de lignes du jeu
    printf("Nombre de colonnes: ");
    scanf("%d", &taille);

    // declarer deux matrices de taille (taille*taille) dans lesquelles on peux stocker char (8bits) parce qu'on va juste stocker 0 ou 1
    char **tab1 = malloc(sizeof(*tab1) * taille);
    char **tab2 = malloc(sizeof(*tab2) * taille);
    for (int i = 0; i < taille; i++)
    {
        tab2[i] = malloc(sizeof(char) * taille);
        tab1[i] = malloc(sizeof(char) * taille);
    }

    // initialiser toute les matrice a 0 :
    for (int i = 0; i < taille; i++)
    {
        for (int j = 0; j < taille; j++)
        {
            tab1[i][j] = 0;
            tab2[i][j] = 0;
        }
    }

    // cases occupées au début du jeu
    // chaque case sera  sous la forme i,j
    printf("le nombre initial de cases occupées: ");
    scanf("%d", &n_point_vivre);
    for (int k = 0; k < n_point_vivre; k++)
    {
        unsigned int i, j;
        printf("Saisir la position des cases occupées au début du jeu:i,j : ");
        scanf("%d,%d", &i, &j);
        while ((i >= taille || j >= taille))
        {
            printf("Vous avez choisi une position qui n'est pas dans la matrice, Saisissez une autre position:i,j:  ");
            scanf("%d,%d", &i, &j);
        }
        tab1[i][j] = 1;
    }

    // demande le nombre de tour a l'utilisateur
    printf("Nombre de tour: ");
    scanf("%d", &num_tour);

    afichage_sd2(taille, tab1, tab2, num_tour);

    return 0;
}