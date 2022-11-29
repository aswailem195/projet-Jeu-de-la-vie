#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"

int main()
{ // Le nombre de colonnes  et de lignes du jeu
    unsigned int n_point_vivre, num_tour;
    tab tab;

    // Saisie du nombre de colonnes et de lignes du jeu
    printf("Nombre de colonnes: ");
    scanf("%d", &tab.taille);

    // declarer deux matrices de taille (taille*taille) dans lesquelles on peux stocker char (8bits) parce qu'on va juste stocker 0 ou 1
    tab.A = malloc(sizeof(*tab.A) * tab.taille);
    tab.B = malloc(sizeof(*tab.B) * tab.taille);
    for (int i = 0; i < tab.taille; i++)
    {
        tab.A[i] = malloc(sizeof(char) * tab.taille);
        tab.B[i] = malloc(sizeof(char) * tab.taille);
    }

    // initialiser toute les matrice a 0 :
    for (int i = 0; i < tab.taille; i++)
    {
        for (int j = 0; j < tab.taille; j++)
        {
            tab.A[i][j] = 0;
            tab.A[i][j] = 0;
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
        while ((i >= tab.taille || j >= tab.taille))
        {
            printf("Vous avez choisi une position qui n'est pas dans la matrice, Saisissez une autre position:i,j:  ");
            scanf("%d,%d", &i, &j);
        }
        tab.A[i][j] = 1;
    }

    // demande le nombre de tour a l'utilisateur
    printf("Nombre de tour: ");
    scanf("%d", &num_tour);

    afichage_sd2(tab, num_tour);

    return 0;
}