#include <stdio.h>
// cette fonction sert a compter les cases occupées autour de la case donnée
// imaginer que ? est la case que l'on cherche avec les cases occupées autour de celle-ci
// donc on viriver comme ça
// ____________
//| 1 | 2 | 3  |
//|____________|
//| 4 | 5?| 6  |
//|____________|
//| 7 | 8 |  9 |
//|____________|

int num_voisines_occupees(char **tab1, int i, int j, unsigned int taille)
{
      int cept = 0;
      int i_copi = i - 1;
      for (int k = 0; k < 3; k++)
      {
            int j_copi = j - 1;
            for (int m = 0; m < 3; m++)
            {

                  if ((i_copi >= 0) && (i_copi < taille) && (j_copi >= 0) && (j_copi < taille))
                  {

                        if (tab1[i_copi][j_copi] == 1)
                        {
                              cept++;
                        }
                  }
                  j_copi++;
            }
            i_copi++;
      }
      if (tab1[i][j] == 1)
      {
            cept--;
      }

      return cept;
}