
#include <stdio.h>
#include "header.h"
// cette fonction modifie le matrice2 par suivi le regle du joue de vie 
void nouvelle_generation(char **tab1, char **tab2, unsigned int taille)
{     //la variable  dont on stock le nmb des voisines
      int cept = 0;
      // deux boucle pour parcourir le matrice 
      for (int i = 0; i < taille; i++)
      {
            for (int j = 0; j < taille; j++)
            {     // on calcule le nmb de voisines qui sont occupees (vivre)
                  cept = num_voisines_occupees(tab1, i, j, taille);
                  //Si elle est vide  
                  if (tab1[i][j] == 0)
                  {     //si elle  a exactement 3 cases voisines occupées elle devient occupée
                        if (cept == 3)

                        {
                              tab2[i][j] = 1;
                        }
                        //sinon elle reste vide
                        else
                        {
                              tab2[i][j] = 0;
                        }
                  }
                  
                  //Si elle est occupée:
                  if ((tab1[i][j] == 1))
                  {     //Si elle a deux ou trois cellules voisines occupée, elle reste occupée
                        if ((cept == 3) || (cept == 2))
                        {
                              tab2[i][j] = 1;
                        }
                        //Sinon elle devient vide
                        else
                        {
                              tab2[i][j] = 0;
                        }
                  }
            }
      }
}