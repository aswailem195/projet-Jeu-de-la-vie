#ifndef HEADER_AFFICHAGE_TESTER_VOISINES
#define HEADER_AFFICHAGE_TESTER_VOISINES

typedef struct jeu_de_vie
{   
    unsigned int taille  ;
    char **A ;
    char **B ;
    
}tab;
afichage_sd2(tab tab, unsigned int num_tour);
int num_voisines_occupees(tab tab ,int i ,int j);
void nouvelle_generation(tab tab);

#endif
