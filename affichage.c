#include <SDL2/SDL.h>
#include "header.h"

int afichage_sd2(tab tab, unsigned int num_tour)
{
  
  

  // Les dimensions de la fenetre (zone d'affichage) en pixels
  unsigned int frame_width = 800;  // Largeur
  unsigned int frame_height = 800; // Hauteur

  // La largeur d'une colonne et la hauteur d'une ligne en pixel
  // ces tailles son fonction des dimensions de la fenetre et du
  // nombre de colonnes et de lignes
  unsigned int column_width = 0;
  unsigned int row_height = 0;

  // Calcul des largeur de colonnes et hauteur de lignes en pixel
  column_width = frame_width / tab.taille;
  row_height = frame_height / tab.taille;

  printf("Taille de la grille                     : %d x %d\n", tab.taille, tab.taille);
  printf("Taille d'une cellule (largeur x hauteur): %dpx x %dpx\n", column_width, row_height);

  printf("\nLancement de l'interface graphique\n");
  SDL_Window *fenetre;
  SDL_Renderer *renderer; // Déclaration du renderer

  // Initialisation de la SDL
  if (SDL_VideoInit(NULL) < 0)
  {
    printf("Erreur d'initialisation de la SDL : %s", SDL_GetError());
    return EXIT_FAILURE;
  }

  // Création de la fenêtre
  // la fonction de creation renvoie NULL si la fenetre n'a pas pu etre cree
  fenetre = SDL_CreateWindow("Une fenetre SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, frame_width, frame_height, 0);

  // Si la fenetre n'a pas pu etre cree, le programme ne peut continuer
  if (fenetre == NULL)
  {
    printf("Erreur lors de la creation d'une fenetre : %s", SDL_GetError());
    return EXIT_FAILURE;
  }

  // Création du renderer
  // Le renderer est l'objet qui permet de dessiner dans la fenetre.
  // la fonction de creation du renderer renvoie NULL si le renderer n'a pu etre cree
  renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); // Création du renderer

  // Si le renderer n'a pu etre creer, le programme ne peut pas continuer
  if (renderer == NULL)
  {
    printf("Erreur lors de la creation d'un renderer : %s", SDL_GetError());
    return EXIT_FAILURE;
  }


  // La structure qui permet de representer un rectangle
  // Cette structure contient les champs suivants:
  // x: abcisse du coin supérieur gauche du rectangle
  // y: ordonnee du coin superieur droit du rectangle
  // w: largeur du rectangle (taille selon l'axe x)
  // h: hauteur du rectangle (taille selon l'axe y))
  SDL_Rect cell;
  char **t ;
  for (int i = 0; i < num_tour; i++)
  {
  // Initialisation du contenu de la fenetre en demandant au renderer de s'effacer avec la couleur noire
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
  // Choix de la couleur utilisee pour le tracage
  SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); // (RGB 255, 0, 255)
    for (unsigned int col = 0; col < tab.taille; col++)
    {
      for (unsigned int row = 0; row < tab.taille; row++)
      {

        // Initialisation du rectangle a la bonne position
        if (tab.A[row][col] == 1)
        {
          cell.x = col * column_width;
          cell.y = row * row_height;
          cell.w = column_width;
          cell.h = row_height;
          // Dessin du rectangle sur le renderer
          SDL_RenderFillRect(renderer, &cell);

          // Demande au renderer de se rafraichir
        }

        


      }
      // Attente de 500ms
      SDL_Delay(500/tab.taille);
    
    }
    SDL_RenderPresent(renderer);
    nouvelle_generation(tab);
    t = tab.A ;
    tab.A =tab.B;
    tab.B = t ;
  }

  SDL_Delay(2000); // Pause de 2 secondes, pour admirer notre œuvre autant que l'on veut

  // Destruction du renderer et de la fenêtre :
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(fenetre);
  SDL_Quit(); // On quitte la SDL
}
