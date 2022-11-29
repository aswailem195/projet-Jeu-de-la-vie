#ifndef HEADER_AFFICHAGE_TESTER_VOISINES
#define HEADER_AFFICHAGE_TESTER_VOISINES

afichage_sd2(unsigned int taille, char **tab1,char **tab2, unsigned int num_tour);
int num_voisines_occupees(char **tab1, int i, int j, unsigned int taille);
void nouvelle_generation(char **tab1, char **tab2, unsigned int taille);

#endif
