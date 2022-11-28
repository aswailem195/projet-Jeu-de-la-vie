
#include <stdio.h>

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

void nouvelle_vie(char **tab1, char **tab2, unsigned int taille)
{
      int cept = 0;

      for (int i = 0; i < taille; i++)
      {
            for (int j = 0; j < taille; j++)
            {
                  // printf("%d",tab1[i][j]);
                  // printf("[%d]",num_voisines_occupees(tab1 ,i, j,taille));
                  cept = num_voisines_occupees(tab1, i, j, taille);
                  if ((tab1[i][j] == 0) && (cept == 3))
                  {
                        *(*(tab2 + i) + j) = 1;
                  }

                  if ((tab1[i][j] == 1))
                  {
                        if ((cept == 3) || (cept == 2))
                        {
                              *(*(tab2 + i) + j) = 1;
                        }
                        else
                        {
                              *(*(tab2 + i) + j) = 0;
                        }
                  }

                  // printf("\n");
            }
      }
}