#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"


int main( ){
    
    // Le nombre de colonnes (columns) et de lignes (rows) du jeu
    
    unsigned int taille=10 ;
    /*
    unsigned int n_point_vivre ;

    // Saisie du nombre de colonnes et de lignes du jeu
    printf("Nombre de colonnes: ");
    scanf("%d", &taille);


    char **tab1 = malloc(sizeof(*tab1) *taille );
    for (int i = 0; i < taille; i++){
        tab1[i] = malloc(sizeof(**tab1) * taille); }
    */   
    char **tab2 = malloc(sizeof(*tab2) * taille);
    for (int i = 0; i < taille; i++)
      tab2[i] = malloc(sizeof(**tab2) * taille);
    

    // initialiser toute la matrice a 0 : 
    for (int i= 0 ; i<taille ; i++){
        for (int j= 0 ; j<taille ; j++){
            //tab1[i][j] = 0 ;
            tab2[i][j] = 0 ;
            }
    }
    /*
    //cases occupées au début du jeu
    printf("le nombre initial de cases occupées: ");
    scanf("%d", &n_point_vivre);
    for (int k = 0 ;k < n_point_vivre ;k++){
        unsigned int i , j ;
        printf("Saisir la position des cases occupées au début du jeu:i,j : ");
        scanf("%d,%d",&i,&j);
        while ((i>=taille || j>=taille)){
            printf("Vous avez choisi une position qui n'est pas dans la matrice, Saisissez une autre position:i,j:  ");
            scanf("%d,%d",&i,&j);
            }
        tab1[i][j] = 1;}
    
    

    
    nouvelle_vie(tab1 ,tab2,taille);
    for (int i=0 ; i < taille ;i++  ){
            for (int j=0 ; j < taille ;j++  ){ 
                printf("%d",tab1[i][j]);
            
            }
            printf("\n");
    }
    printf("\n---------------------------\n");
    for (int i=0 ; i < taille ;i++  ){
            for (int j=0 ; j < taille ;j++  ){ 
                printf("%d",tab2[i][j]);
            }
            printf("\n");

    }
    */
    tab2[0][0] =1 ;
    tab2[0][1] =1 ;
    tab2[0][2] =1 ;
    afichage_sd2(taille,tab2);

    return 0 ;
}