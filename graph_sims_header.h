#ifndef GRAPH_SIMS_HEADER_H_INCLUDED
#define GRAPH_SIMS_HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <allegro.h>
#include <stdbool.h>
typedef struct graph{
    BITMAP *constr;
    BITMAP *bufferDeDetection;
    BITMAP* page;               //buffer
    BITMAP* outils;
    BITMAP* route;
    BITMAP* chateau;
    BITMAP* centrale;
    BITMAP* chateauD;
    BITMAP* centraleD;
    BITMAP* terrain;
    BITMAP* pause;
    BITMAP* sauvegarde;
    BITMAP* quitter;
    BITMAP* niveau_1;
    BITMAP* niveau_2;
    BITMAP* niveau0;
    BITMAP* croixrouge;

}Bitmaps;
typedef struct cases
{
    int type;    //type du sommet( 0:vide 1:route 2:habitations 3:clefenmain )
    int x;
    int y;
    int passage;
    int intersection;
}cases;
struct Arc
{
    int num_voisin; // numero de sommet d'un arc adjacent au sommet initial
    int distance;
    struct Arc* arc_suivant;
};

/* Alias de pointeur sur un Arc */
typedef struct Arc* pArc;

typedef struct habitation {
    int taxe;
    int couts_hab;
    int eau;   // apprivisionnement  eau (borner)
    int electricite; // apprivisionnement electricit� (borner)
    int demande_eau;
    int demande_electricite;
    int habitants; // nombre d'habitant
    int temps; // temps de construction
    int regression; // etat de l'habitation
}habitation;

typedef struct clefEnMain {
    int capa; // capacité a distribuer de l'eau ou de l'électricité
    int approvisionnement;
    int temps; // temps de construction
    int couts_cle; // cout de construction

}ClefEnMain;


/* Structure d'un sommet*/
struct Sommet
{
    struct Arc* arc;
    int num;     //numero du sommet
    int type;    //type du sommet(0:ruine 1:terrain vague 2:cabane 3:maison 4:immeuble 5:gratte-ciel 6:centrale 7:chateau d'eau)
    int marque;
    habitation* habitation;
    ClefEnMain* ClefEnMain;
};



/* Alias de pointeur sur un Sommet */
typedef struct Sommet* pSommet;

/* Alias d'un Graphe */
typedef struct Graphe
{
    int taille;
    int ordre;
    pSommet* pSommet;

}Graphe;

/*
void initAllegro();
void MAJ_graph(int ordre);
void niveaux(BITMAP* niveau0,BITMAP* niveau_1,BITMAP* niveau_2,BITMAP* page);
void pause(BITMAP* pause, BITMAP* page);

void sauvegarde(BITMAP* sauvegarde, BITMAP* page);

void quitter(BITMAP* quitter, BITMAP* page);
void outils (Bitmaps* bitmaps,BITMAP* rect,BITMAP* page,cases tabcases[23][35]);
Bitmaps* initialisation_bitmaps();

*/
#endif // GRAPH_SIMS_HEADER_H_INCLUDED
