#include "graph_sims_header.h"
void initAllegro()
{
    allegro_init();
    install_mouse();
    install_keyboard();
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL);
    set_color_depth(desktop_color_depth());
    if((set_gfx_mode(GFX_AUTODETECT_WINDOWED,1024,768,0,0))!=0)
    {
        allegro_message("Pb de mode graphique") ;
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    return;
}






pSommet* CreerArete(pSommet* sommet,int s1,int s2,int distance)
{

    if(sommet[s1]->arc==NULL)
    {
        pArc Newarc=(pArc)malloc(sizeof(struct Arc));
        Newarc->num_voisin=s2;
        Newarc->distance=distance;
        Newarc->arc_suivant=NULL;
        sommet[s1]->arc=Newarc;
        return sommet;
    }
    else
    {
        pArc temp=sommet[s1]->arc;
        while( !(temp->arc_suivant==NULL))
        {
            temp=temp->arc_suivant;
        }
        pArc Newarc=(pArc)malloc(sizeof(struct Arc));
        Newarc->num_voisin=s2;
        Newarc->distance=distance;
        Newarc->arc_suivant=NULL;

        if(temp->num_voisin>s2)
        {
            Newarc->arc_suivant=temp->arc_suivant;
            Newarc->num_voisin=temp->num_voisin;
            temp->num_voisin=s2;
            Newarc->distance=distance;
            temp->arc_suivant=Newarc;
            return sommet;
        }

        temp->arc_suivant=Newarc;
        return sommet;
    }
}


Graphe* CreerGraphe(int ordre,int type)// cr�er le graphe
{
    Graphe * Newgraphe=(Graphe*)malloc(sizeof(Graphe));

    Newgraphe->pSommet = (pSommet*)malloc(ordre*sizeof(pSommet));


    for(int i=0; i<ordre; i++)
    {
        Newgraphe->pSommet[i]=(pSommet)malloc(sizeof(struct Sommet));
        Newgraphe->pSommet[i]->num=i;
        Newgraphe->pSommet[i]->arc=NULL;
        switch(type)
        {
            case 0:
                Newgraphe->pSommet[i]->habitation=malloc(sizeof(habitation));
                Newgraphe->pSommet[i]->habitation->taxe=0;
                Newgraphe->pSommet[i]->habitation->demande_eau=1;
                Newgraphe->pSommet[i]->habitation->demande_electricite=1;
                Newgraphe->pSommet[i]->habitation->eau=0;
                Newgraphe->pSommet[i]->habitation->electricite=0;
                Newgraphe->pSommet[i]->habitation->habitants=0;
                Newgraphe->pSommet[i]->habitation->regression=0;
                Newgraphe->pSommet[i]->habitation->temps=0;
                Newgraphe->pSommet[i]->ClefEnMain=NULL;
                Newgraphe->pSommet[i]->marque=0;
                Newgraphe->pSommet[i]->type=type;
                break;
            case 1:
                Newgraphe->pSommet[i]->habitation=malloc(sizeof(habitation));
                Newgraphe->pSommet[i]->habitation->taxe=0;
                Newgraphe->pSommet[i]->habitation->demande_eau=1;
                Newgraphe->pSommet[i]->habitation->demande_electricite=1;
                Newgraphe->pSommet[i]->habitation->eau=0;
                Newgraphe->pSommet[i]->habitation->electricite=0;
                Newgraphe->pSommet[i]->habitation->habitants=0;
                Newgraphe->pSommet[i]->habitation->regression=100;
                Newgraphe->pSommet[i]->habitation->temps=0;
                Newgraphe->pSommet[i]->ClefEnMain=NULL;
                Newgraphe->pSommet[i]->marque=0;
                Newgraphe->pSommet[i]->type=type;
                break;
            case 2:
                Newgraphe->pSommet[i]->habitation=malloc(sizeof(habitation));
                Newgraphe->pSommet[i]->habitation->taxe=100;
                Newgraphe->pSommet[i]->habitation->demande_eau=10;
                Newgraphe->pSommet[i]->habitation->demande_electricite=10;
                Newgraphe->pSommet[i]->habitation->eau=0;
                Newgraphe->pSommet[i]->habitation->electricite=0;
                Newgraphe->pSommet[i]->habitation->habitants=10;
                Newgraphe->pSommet[i]->habitation->regression=100;
                Newgraphe->pSommet[i]->habitation->temps=0;
                Newgraphe->pSommet[i]->ClefEnMain=NULL;
                Newgraphe->pSommet[i]->marque=0;
                Newgraphe->pSommet[i]->type=type;
                break;
            case 3:
                Newgraphe->pSommet[i]->habitation=malloc(sizeof(habitation));
                Newgraphe->pSommet[i]->habitation->taxe=500;
                Newgraphe->pSommet[i]->habitation->demande_eau=50;
                Newgraphe->pSommet[i]->habitation->demande_electricite=50;
                Newgraphe->pSommet[i]->habitation->eau=0;
                Newgraphe->pSommet[i]->habitation->electricite=0;
                Newgraphe->pSommet[i]->habitation->habitants=50;
                Newgraphe->pSommet[i]->habitation->regression=100;
                Newgraphe->pSommet[i]->habitation->temps=0;
                Newgraphe->pSommet[i]->ClefEnMain=NULL;
                Newgraphe->pSommet[i]->marque=0;
                Newgraphe->pSommet[i]->type=type;
                break;
            case 4:
                Newgraphe->pSommet[i]->habitation=malloc(sizeof(habitation));
                Newgraphe->pSommet[i]->habitation->taxe=1000;
                Newgraphe->pSommet[i]->habitation->demande_eau=100;
                Newgraphe->pSommet[i]->habitation->demande_electricite=100;
                Newgraphe->pSommet[i]->habitation->eau=0;
                Newgraphe->pSommet[i]->habitation->electricite=0;
                Newgraphe->pSommet[i]->habitation->habitants=100;
                Newgraphe->pSommet[i]->habitation->regression=100;
                Newgraphe->pSommet[i]->habitation->temps=0;
                Newgraphe->pSommet[i]->ClefEnMain=NULL;
                Newgraphe->pSommet[i]->marque=0;
                Newgraphe->pSommet[i]->type=type;
                break;
            case 5:
                Newgraphe->pSommet[i]->habitation=malloc(sizeof(habitation));
                Newgraphe->pSommet[i]->habitation->taxe=10000;
                Newgraphe->pSommet[i]->habitation->demande_eau=1000;
                Newgraphe->pSommet[i]->habitation->demande_electricite=1000;
                Newgraphe->pSommet[i]->habitation->eau=0;
                Newgraphe->pSommet[i]->habitation->electricite=0;
                Newgraphe->pSommet[i]->habitation->habitants=1000;
                Newgraphe->pSommet[i]->habitation->regression=100;
                Newgraphe->pSommet[i]->habitation->temps=0;
                Newgraphe->pSommet[i]->ClefEnMain=NULL;
                Newgraphe->pSommet[i]->marque=0;
                Newgraphe->pSommet[i]->type=type;
                break;
            case 6:
                Newgraphe->pSommet[i]->habitation=malloc(sizeof(ClefEnMain));
                Newgraphe->pSommet[i]->ClefEnMain->approvisionnement=0;
                Newgraphe->pSommet[i]->ClefEnMain->capa=1000;
                Newgraphe->pSommet[i]->ClefEnMain->temps=0;
                Newgraphe->pSommet[i]->habitation=NULL;
                Newgraphe->pSommet[i]->marque=0;
                Newgraphe->pSommet[i]->type=type;
                break;
            case 7:
                Newgraphe->pSommet[i]->habitation=malloc(sizeof(ClefEnMain));
                Newgraphe->pSommet[i]->ClefEnMain->approvisionnement=0;
                Newgraphe->pSommet[i]->ClefEnMain->capa=1000;
                Newgraphe->pSommet[i]->ClefEnMain->temps=0;
                Newgraphe->pSommet[i]->habitation=NULL;
                Newgraphe->pSommet[i]->marque=0;
                Newgraphe->pSommet[i]->type=type;
                break;
        }

    }
    return Newgraphe;
}

/* La construction du r�seau peut se faire � partir d'un fichier dont le nom est pass� en param�tre
Le fichier contient : ordre, taille,orientation (0 ou 1)et liste des arcs */

Graphe * lire_graphe(int type)
{
    Graphe* graphe;
    FILE * ifs = fopen("graphe.txt","r");

    int taille=0, orientation, ordre, s1=0, s2=0,p=0;
    int distance=0;
    if (!ifs)
    {
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }

    fscanf(ifs,"%d",&ordre);

    int *Lsommets=(int*)malloc(ordre*sizeof(int));

    for(int i=0; i<ordre; i++)
    {
        fscanf(ifs,"%d",&Lsommets[i]);
    }
    graphe=CreerGraphe(ordre,type); // cr�er le graphe d'ordre sommets

    fscanf(ifs,"%d",&taille);

    graphe->ordre=ordre;
    graphe->taille=taille;

    // crer les ar�tes du graphe

    // CA CRASH PRCQ GRAPHE->pSOMMET PAS INITIALISé UNE FOIS DS CREER ARRETE PK ?
    for (int i=0; i<taille; ++i)
    {
       // fscanf(ifs,"%d%d%d",&s1,&s2,&p);
        graphe->pSommet=CreerArete(graphe->pSommet, s1, s2,p);

        if(!orientation)
            graphe->pSommet=CreerArete(graphe->pSommet, s2, s1,p);
    }


    return graphe;
}

void MAJ_graph(int ordre,int taille, int S_et_P[3])
{
    int* tmp;
    int cpt=0;
    FILE* f;
            f=fopen("graphe.txt","r");
            fscanf(f,"%d",&ordre);
            fclose(f);
            //printf("ordre: %d\n");
            ordre ++;
            tmp = malloc(ordre*sizeof(int));

            f=fopen("graphe.txt","r");
            for(int i = 0;i<ordre*3 ;i++){
                fscanf(f,"%d",&tmp[i]);
               // printf("%d",tmp[i]);
            }//printf("\n");
            fclose(f);

            f=fopen("graphe.txt","w");
            fprintf(f,"%d\n",ordre);
            for(int k = 1;k<ordre*3 +1 ;k++){
                fprintf(f,"%d ",tmp[k]);
                cpt++;
                if(cpt==3){
                    fprintf(f,"\n");
                    cpt=0;
                }
            }
            fclose(f);

            return;
}

int trouver_distance(cases tabcases[75][35],int xc,int yc )
{

    int dist=1,cpt_taille=0,u=0,v=0;
    int tmp=0;
    int cmpt=1;
    printf("yc:%d   xc:%d\n",yc,xc);
    if(tabcases[yc][xc].type==2)
    {
        if (yc % 2 == 0) {
            printf("on commence sur une case pair\n");
            tmp=0;
            cmpt=1;
            if(tabcases[yc+1][xc].type==1){
                u= yc +1;
                v=xc;
                tabcases[u][v].passage=1;
            }
            printf("uc:%d   vc:%d\n",u,v);
            printf("type case bas droite: %d \n",tabcases[u+1][v+1].type);
            printf("tmp:%d \n",tmp);
            while(true){
                if(tabcases[u-1][v+1].type==3 && tmp%2==0){
                    break;
                }
                if(tabcases[u-1][v].type==3 && tmp%2==0){
                    break;
                }
                if(tabcases[u+1][v+1].type==3 && tmp%2==0){
                    break;
                }
                if(tabcases[u+1][v].type==3 && tmp%2==0){
                    break;
                }
                if(tabcases[u-1][v-1].type==3 && tmp%2!=0){
                    break;
                }
                if(tabcases[u-1][v].type==3 && tmp%2!=0){
                    break;
                }
                if(tabcases[u+1][v-1].type==3 && tmp%2!=0){
                    break;
                }
                if(tabcases[u+1][v].type==3 && tmp%2!=0){
                    break;
                }
                cmpt++;
                printf("uc:%d   vc:%d\n",u,v);
                if(tmp%2==0){printf("type case bas droite: %d \n",tabcases[u+1][v+1].type);
                    if(tabcases[u-1][v+1].type==1 &&  tabcases[u-1][v+1].passage==0){
                        u=u-1;
                        v=v+1;
                        tabcases[u][v].passage=1;
                        printf("haut droite pair \n");
                    }
                    else if(tabcases[u-1][v].type==1 &&  tabcases[u-1][v].passage==0){
                        printf("passage: %d \n",tabcases[u][v].passage);
                        u=u-1;
                        v=v;
                        tabcases[u][v].passage=1;
                        printf("haut gauche pair\n");
                    }
                    else if(tabcases[u+1][v+1].type==1 &&  tabcases[u+1][v+1].passage==0){
                        u=u+1;
                        v=v+1;
                        tabcases[u][v].passage=1;
                        printf("bas droite pair\n");
                    }
                    else if(tabcases[u+1][v].type==1 &&  tabcases[u+1][v].passage==0){
                        u=u+1;
                        v=v;
                        tabcases[u][v].passage=1;
                        printf("bas gauche pair\n");
                    }

                }
                if(tmp%2!=0){printf("type case bas droite: %d \n",tabcases[u+1][v].type);

                    if(tabcases[u-1][v].type==1  &&  tabcases[u-1][v].passage==0){
                        u=u-1;
                        v=v;
                        tabcases[u][v].passage=1;
                        printf("haut droite impair\n");
                    }
                    else if(tabcases[u+1][v-1].type==1 &&  tabcases[u+1][v-1].passage==0){
                        u=u+1;
                        v=v-1;
                        tabcases[u][v].passage=1;
                        printf("bas gauche impair\n");
                    }
                    else if(tabcases[u+1][v].type==1 &&  tabcases[u+1][v].passage==0){
                        u=u+1;
                        v=v;
                        tabcases[u][v].passage=1;
                        printf("bas droite impair\n");
                    }
                    else if(tabcases[u-1][v-1].type==1 &&  tabcases[u-1][v-1].passage==0){
                        u=u-1;
                        v=v-1;
                        tabcases[u][v].passage=1;
                        printf("haut gauche impair\n");
                    }
                }
                printf("uca:%d  vca:%d\n",u,v);
                tmp++;
                printf("tmp:%d \n\n\n\n\n",tmp);
            }
            printf("chemin:%d",cmpt);
        }
        else//case impair
        {
            printf("on commence sur une case impair\n");
            tmp=1;
            cmpt=0;
            if(tabcases[yc+1][xc+1].type==1){
                u= yc +1;
                v=xc+1;
                tabcases[u][v].passage=1;
            }
            printf("uc:%d   vc:%d\n",u,v);
            printf("type case bas droite: %d \n",tabcases[u+1][v].type);
            printf("tmp:%d \n",tmp);
            while(true){
                if(tabcases[u-1][v+1].type==3 && tmp%2!=0){
                    break;
                }
                if(tabcases[u-1][v].type==3 && tmp%2!=0){
                    break;
                }
                if(tabcases[u+1][v+1].type==3 && tmp%2!=0){
                    break;
                }
                if(tabcases[u+1][v].type==3 && tmp%2!=0){
                    break;
                }
                if(tabcases[u-1][v-1].type==3 && tmp%2==0){
                    break;
                }
                if(tabcases[u-1][v].type==3 && tmp%2==0){
                    break;
                }
                if(tabcases[u+1][v-1].type==3 && tmp%2==0){
                    break;
                }
                if(tabcases[u+1][v].type==3 && tmp%2==0){
                    break;
                }
                cmpt++;
                printf("uc:%d   vc:%d\n",u,v);
                if(tmp%2==0){printf("type case bas droite: %d \n",tabcases[u+1][v+1].type);
                    if(tabcases[u-1][v+1].type==1 &&  tabcases[u-1][v+1].passage==0){
                        u=u-1;
                        v=v+1;
                        tabcases[u][v].passage=1;
                        printf("haut droite pair \n");
                    }
                    else if(tabcases[u-1][v].type==1 &&  tabcases[u-1][v].passage==0){
                        printf("passage: %d \n",tabcases[u][v].passage);
                        u=u-1;
                        v=v;
                        tabcases[u][v].passage=1;
                        printf("haut gauche pair\n");
                    }
                    else if(tabcases[u+1][v+1].type==1 &&  tabcases[u+1][v+1].passage==0){
                        u=u+1;
                        v=v+1;
                        tabcases[u][v].passage=1;
                        printf("bas droite pair\n");
                    }
                    else if(tabcases[u+1][v].type==1 &&  tabcases[u+1][v].passage==0){
                        u=u+1;
                        v=v;
                        tabcases[u][v].passage=1;
                        printf("bas gauche pair\n");
                    }

                }
                if(tmp%2!=0){printf("type case bas droite: %d \n",tabcases[u+1][v].type);

                    if(tabcases[u-1][v].type==1  &&  tabcases[u-1][v].passage==0){
                        u=u-1;
                        v=v;
                        tabcases[u][v].passage=1;
                        printf("haut droite impair\n");
                    }
                    else if(tabcases[u+1][v-1].type==1 &&  tabcases[u+1][v-1].passage==0){
                        u=u+1;
                        v=v-1;
                        tabcases[u][v].passage=1;
                        printf("bas gauche impair\n");
                    }
                    else if(tabcases[u+1][v].type==1 &&  tabcases[u+1][v].passage==0){
                        u=u+1;
                        v=v;
                        tabcases[u][v].passage=1;
                        printf("bas droite impair\n");
                    }
                    else if(tabcases[u-1][v-1].type==1 &&  tabcases[u-1][v-1].passage==0){
                        u=u-1;
                        v=v-1;
                        tabcases[u][v].passage=1;
                        printf("haut gauche impair\n");
                    }
                }
                printf("uca:%d  vca:%d\n",u,v);
                tmp++;
                printf("tmp:%d \n\n\n\n\n",tmp);
            }
            if(u%2!=0){
                cmpt++;
            }
            printf("chemin:%d",cmpt);
        }


        }

    }



Bitmaps* initialisation_bitmaps(){



/////////////////////////////////////////////////////////////////////////////

    Bitmaps *Bitmaps = malloc(sizeof(Bitmaps));

    Bitmaps->outils = malloc(sizeof(Bitmaps->outils));

//////////////////////////////////////////////////////////////////////////

    // CREATION DU BUFFER D'AFFICHAGE à la taille de l'écran

    Bitmaps->page=create_bitmap(SCREEN_W,SCREEN_H);

    Bitmaps->bufferDeDetection=create_bitmap(SCREEN_W,SCREEN_H);

    //////////////

    //chargez image sims city
    Bitmaps->route=load_bitmap("menu/route.bmp",NULL);
    Bitmaps->outils=load_bitmap("menu/outils.bmp",NULL);
    Bitmaps->chateauD=load_bitmap("menu/chateauD.bmp",NULL);
    Bitmaps->centraleD=load_bitmap("menu/centraleD.bmp",NULL);
    Bitmaps->chateau=load_bitmap("menu/chateau.bmp",NULL);
    Bitmaps->centrale=load_bitmap("menu/centrale.bmp",NULL);
    Bitmaps->terrain=load_bitmap("menu/terrainvague1.bmp",NULL);
    Bitmaps->pause=load_bitmap("menu/pause.bmp",NULL);
    Bitmaps->sauvegarde=load_bitmap("menu/sauvegarde.bmp",NULL);
    Bitmaps->quitter=load_bitmap("menu/quitter.bmp",NULL);
    Bitmaps->niveau_1=load_bitmap("menu/niveau_1.bmp",NULL);
    Bitmaps->niveau_2=load_bitmap("menu/niveau_2.bmp",NULL);
    Bitmaps->niveau0=load_bitmap("menu/niveau0.bmp",NULL);
    Bitmaps->croixrouge=load_bitmap("menu/croixrouge.bmp",NULL);
    Bitmaps->constr = create_bitmap(40,20);
    clear_bitmap( Bitmaps->constr);

    if (!Bitmaps->pause)
    {
        allegro_message("simscity.bmp non trouve");
        exit(EXIT_FAILURE);
    }

    return Bitmaps;
}
void place_bat(Bitmaps* bitmaps,BITMAP* rect, BITMAP* page,cases tabcases[23][35],int x ,int y,int xc,int yc)
{
    clear_bitmap(bitmaps->page);
    Sleep(50);
    while(true){
        if(mouse_b&1&& mouse_x>20){

            x=mouse_x/40;
            y=mouse_y/20;
            if(mouse_x<(x+1)*40-20)
            {
                if(x!=0)x=x*40-20;
                if(y!=0)y=y*20-10;
            }
            else
            {
                x=x*40;
                y=y*20;
            }
            yc=y/10;
            xc=x/40;
            if(tabcases[yc][xc].type==0)
            {
                draw_sprite(page,bitmaps->route,x,y );
                tabcases[yc][xc].type=1;
                tabcases[yc][xc].x=x;
                tabcases[yc][xc].y=y;

                for(int k=0;k<75;k++){
                    for(int l=0;l<35;l++){
                        printf("%d ",tabcases[k][l].type);

                    }printf("\n");
                    if(k%2==0)printf(" ");
                }printf("\n\n");
            }

        }
        if(mouse_b&2){
            break;
        }

        blit(page,rect,0,0,0,0,SCREEN_W,SCREEN_H);show_mouse(rect);
        draw_sprite(rect,bitmaps->route,mouse_x-20,mouse_y-20 );

        blit(rect,screen,0,0,0,0,SCREEN_W,SCREEN_H);

    }
}
int outils (Bitmaps* bitmaps,BITMAP* rect, BITMAP* page,cases tabcases[23][35]){
    int verif_y=0,yc=0,xc=0,type=0,ordre;
    draw_sprite(rect,bitmaps->outils,965,0);
    int x,y;
    if (mouse_b & 1){

            if ((mouse_x >= 965) && ( mouse_x <=1019 )&&(mouse_y >= 0) && (mouse_y <= 50)){

                rectfill(bitmaps->page, 256, 192, 768, 576, makecol(200,255,255));
                draw_sprite(bitmaps->page,bitmaps->outils,260,195);
                textprintf_ex(bitmaps->page, font, 450,220, makecol(110, 140, 160),-1, "BOITE A OUTILS");
                line(bitmaps->page,256,250,768,250,makecol(110,140,160));
                draw_sprite(bitmaps->page,bitmaps->route,260,270);
                textprintf_ex(bitmaps->page, font, 360,270, makecol(110, 140, 160),-1,"Route : 10 ECE-flouz par unite de grille ");
                stretch_sprite(bitmaps->page,bitmaps->terrain,260,325,60,30);
                textprintf_ex(bitmaps->page, font, 360,345, makecol(110, 140, 160),-1,"Terrain vague : 1000 ECE-flouz ");
                draw_sprite(bitmaps->page,bitmaps->chateauD,260,400);
                textprintf_ex(bitmaps->page, font, 360,420, makecol(110, 140, 160),-1,"Chateau d'eau : 100 000 ECE-flouz ");
                draw_sprite(bitmaps->page,bitmaps->centraleD,260,475);
                draw_sprite(bitmaps->page,bitmaps->croixrouge,700,195);
                rectfill(bitmaps->bufferDeDetection,700,195,750,245,makecol(255, 0, 0));
                textprintf_ex(bitmaps->page, font, 360,495, makecol(110, 140, 160),-1,"Centrale : 100 000 ECE-flouz ");
                rectfill(bitmaps->bufferDeDetection,256,252,320,300,makecol(255, 255, 0));
                rectfill(bitmaps->bufferDeDetection,256,320,320,370,makecol(200, 200, 0));
                rectfill(bitmaps->bufferDeDetection,256,400,320,450,makecol(100, 0, 0));
                rectfill(bitmaps->bufferDeDetection,256,470,320,520,makecol(30, 0, 30));

            }
        if(getpixel(bitmaps->bufferDeDetection,mouse_x,mouse_y)== makecol(255, 0, 0)&&mouse_b&1){

           clear_bitmap(bitmaps->page);

           }
        if(getpixel(bitmaps->bufferDeDetection,mouse_x,mouse_y)== makecol(255, 255, 0)&&mouse_b&1){//pose la route
            clear_bitmap(bitmaps->page);
            Sleep(50);
            while(true){
                if(mouse_b&1&& mouse_x>20){

                    x=mouse_x/40;
                    y=mouse_y/20;
                    if(mouse_x<(x+1)*40-20)
                    {
                        if(x!=0)x=x*40-20;
                        if(y!=0)y=y*20-10;
                    }
                    else
                    {
                        x=x*40;
                        y=y*20;
                    }
                    yc=y/10;
                    xc=x/40;
                    if(tabcases[yc][xc].type==0)
                    {
                        draw_sprite(page,bitmaps->route,x,y );
                        tabcases[yc][xc].type=1;
                        tabcases[yc][xc].x=x;
                        tabcases[yc][xc].y=y;

                        for(int k=0;k<75;k++){
                            for(int l=0;l<35;l++){
                                printf("%d ",tabcases[k][l].type);

                            }printf("\n");
                            if(k%2==0)printf(" ");
                        }printf("\n\n");
                    }

                }
                if(mouse_b&2){
                    break;
                }

                blit(page,rect,0,0,0,0,SCREEN_W,SCREEN_H);show_mouse(rect);
                draw_sprite(rect,bitmaps->route,mouse_x-20,mouse_y-20 );

                blit(rect,screen,0,0,0,0,SCREEN_W,SCREEN_H);

            }

        }
        if(getpixel(bitmaps->bufferDeDetection,mouse_x,mouse_y)== makecol(200, 200, 0)&&mouse_b&1){//pose le terrain vague
            clear_bitmap(bitmaps->page);
            Sleep(100);
            type=1;
            while(true){
                if(mouse_b&1&& mouse_x>20)
                {

                    x=mouse_x/40;
                    y=mouse_y/20;
                    if(mouse_x<(x+1)*40-20)
                    {
                        if(x!=0)x=x*40-20;
                        if(y!=0)y=y*20-10;
                    }
                    else
                    {
                        x=x*40;
                        y=y*20;
                    }
                    yc=y/10;
                    xc=x/40;
                    if(tabcases[yc][xc].type!=0||tabcases[yc -2][xc +1].type!=0||tabcases[yc -2][xc -1].type!=0||tabcases[yc -2][xc ].type != 0||tabcases[yc-1][xc ].type != 0||tabcases[yc -3][xc ].type != 0||tabcases[yc -4][xc ].type != 0 )continue;
                    draw_sprite(page,bitmaps->terrain,x-40,y -40   );
                    if(yc%2==0){

                        tabcases[yc-1][xc -1].type = 2;
                        tabcases[yc -3][xc -1].type = 2;

                    }
                    else{

                        tabcases[yc-1][xc +1].type = 2;
                        tabcases[yc -3][xc +1].type = 2;

                    }
                    tabcases[yc -2][xc +1].type = 2;
                    tabcases[yc -2][xc -1].type = 2;
                    tabcases[yc -2][xc ].type = 2;
                    tabcases[yc-1][xc ].type = 2;
                    tabcases[yc][xc].x=x;
                    tabcases[yc][xc].y=y;
                    tabcases[yc][xc].type = 2;
                    tabcases[yc -3][xc ].type = 2;
                    tabcases[yc -4][xc ].type = 2;
                    break;
                }
                if(mouse_b&2){
                    break;
                }

                blit(page,rect,0,0,0,0,SCREEN_W,SCREEN_H);show_mouse(rect);
                draw_sprite(rect,bitmaps->terrain,mouse_x-63,mouse_y-60 );
                show_mouse(rect);
                blit(rect,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                Sleep(50);
            }
            trouver_distance(tabcases,xc,yc);

        }

        if(getpixel(bitmaps->bufferDeDetection,mouse_x,mouse_y)== makecol(100, 0, 0)&&mouse_b&1){// pose le chateau d'eau
            clear_bitmap(bitmaps->page);
            Sleep(100);
            type=7;
            while(true){
                if(mouse_b&1&& mouse_x>20)
                {


                    x=mouse_x/40;
                    y=mouse_y/20;
                    if(mouse_x<(x+1)*40-20)
                    {
                        if(x!=0)x=x*40-20;
                        if(y!=0)y=y*20-10;
                    }
                    else
                    {
                        x=x*40;
                        y=y*20;
                    }
                    yc=y/10;
                    xc=x/40;
                    if(tabcases[yc -5][xc -3].type !=0||tabcases[yc -2][xc +1].type!=0||tabcases[yc -3][xc -2].type !=0||tabcases[yc -1][xc +1].type!=0||tabcases[yc -3][xc +2].type !=0|| tabcases[yc ][xc ].type != 0||tabcases[yc -2][xc ].type != 0 || tabcases[yc -4][xc ].type != 0|| tabcases[yc -6][xc ].type != 0||tabcases[yc -8][xc -1].type != 0 ||tabcases[yc -2][xc -1].type != 0 || tabcases[yc -2][xc +1].type != 0|| tabcases[yc -4][xc -2].type != 0||tabcases[yc -4][xc -1].type != 0)continue;
                    draw_sprite(page,bitmaps->chateau,x-100,y -80  );
                    if(yc%2==0){


                        tabcases[yc -5][xc -3].type = 3;
                        tabcases[yc -3][xc -2].type = 3;
                        tabcases[yc -1][xc].type = 3;
                        tabcases[yc -7][xc -2].type = 3;
                        tabcases[yc -1][xc -1].type = 3;
                    }
                    else{

                        tabcases[yc -1][xc +1].type = 3;
                        tabcases[yc -3][xc +2].type = 3;
                        tabcases[yc -5][xc +1].type = 3;
                        tabcases[yc -7][xc ].type = 3;
                        tabcases[yc -1][xc].type = 3;


                    }
                    tabcases[yc ][xc ].type = 3;
                    tabcases[yc -2][xc ].type = 3;
                    tabcases[yc -4][xc ].type = 3;
                    tabcases[yc -6][xc ].type = 3;
                    tabcases[yc -8][xc -1].type = 3;
                    tabcases[yc -2][xc -1].type = 3;
                    tabcases[yc -2][xc +1].type = 3;
                    tabcases[yc -4][xc -2].type = 3;
                    tabcases[yc -4][xc -1].type = 3;
                    tabcases[yc -4][xc +1].type = 3;
                    tabcases[yc -6][xc -2].type = 3;
                    tabcases[yc -6][xc -1].type = 3;
                    tabcases[yc -3][xc -1].type = 3;
                    tabcases[yc -3][xc ].type = 3;
                    tabcases[yc -3][xc +1].type = 3;
                    tabcases[yc -5][xc ].type = 3;
                    tabcases[yc -5][xc -1].type = 3;
                    tabcases[yc -5][xc -2].type = 3;
                    tabcases[yc -7][xc -1].type = 3;
                }
                if(mouse_b&2){
                    break;
                }

                blit(page,rect,0,0,0,0,SCREEN_W,SCREEN_H);show_mouse(rect);
                draw_sprite(rect,bitmaps->chateau,mouse_x-63,mouse_y-60 );
                show_mouse(rect);
                blit(rect,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                Sleep(50);
            }


        }
        if(getpixel(bitmaps->bufferDeDetection,mouse_x,mouse_y)== makecol(30, 0, 30)&&mouse_b&1){//pose la centrale
            type=6;
            clear_bitmap(bitmaps->page);
            Sleep(100);
            while(true){
                if(mouse_b&1&& mouse_x>20)
                {

                    x=mouse_x/40;
                    y=mouse_y/20;
                    if(mouse_x<(x+1)*40-20)
                    {
                        if(x!=0)x=x*40-20;
                        if(y!=0)y=y*20-10;
                    }
                    else
                    {
                        x=x*40;
                        y=y*20;
                    }
                    yc=y/10;
                    xc=x/40;
                    if(tabcases[yc -5][xc -3].type !=0||tabcases[yc -2][xc +1].type!=0||tabcases[yc -3][xc -2].type !=0||tabcases[yc -1][xc +1].type!=0||tabcases[yc -3][xc +2].type !=0|| tabcases[yc ][xc ].type != 0||tabcases[yc -2][xc ].type != 0 || tabcases[yc -4][xc ].type != 0|| tabcases[yc -6][xc ].type != 0||tabcases[yc -8][xc -1].type != 0 ||tabcases[yc -2][xc -1].type != 0 || tabcases[yc -2][xc +1].type != 0|| tabcases[yc -4][xc -2].type != 0||tabcases[yc -4][xc -1].type != 0)continue;
                    draw_sprite(page,bitmaps->centrale,x-100,y -80   );
                    if(yc%2==0){


                        tabcases[yc -5][xc -3].type = 4;
                        tabcases[yc -3][xc -2].type =4 ;
                        tabcases[yc -1][xc].type = 4;
                        tabcases[yc -7][xc -2].type = 4;
                        tabcases[yc -1][xc -1].type = 4;
                    }
                    else{

                        tabcases[yc -1][xc +1].type = 4;
                        tabcases[yc -4][xc +2].type = 4;
                        tabcases[yc -5][xc +1].type = 4;
                        tabcases[yc -7][xc ].type = 4;
                        tabcases[yc -1][xc].type = 4;


                    }
                    tabcases[yc ][xc ].type = 4;
                    tabcases[yc -2][xc ].type = 4;
                    tabcases[yc -4][xc ].type = 4;
                    tabcases[yc -6][xc ].type = 4;
                    tabcases[yc -8][xc -1].type = 4;
                    tabcases[yc -2][xc -1].type = 4;
                    tabcases[yc -2][xc +1].type = 4;
                    tabcases[yc -4][xc -2].type = 4;
                    tabcases[yc -4][xc -1].type = 4;
                    tabcases[yc -4][xc +1].type = 4;
                    tabcases[yc -6][xc -2].type = 4;
                    tabcases[yc -6][xc -1].type = 4;
                    tabcases[yc -3][xc -1].type = 4;
                    tabcases[yc -3][xc ].type = 4;
                    tabcases[yc -3][xc +1].type = 4;
                    tabcases[yc -5][xc ].type = 4;
                    tabcases[yc -5][xc -1].type = 4;
                    tabcases[yc -5][xc -2].type = 4;
                    tabcases[yc -7][xc -1].type = 4;
                }
                if(mouse_b&2){
                    break;
                }

                blit(page,rect,0,0,0,0,SCREEN_W,SCREEN_H);show_mouse(rect);
                draw_sprite(rect,bitmaps->centrale,mouse_x-63,mouse_y-60 );
                show_mouse(rect);
                blit(rect,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                Sleep(50);
            }

        }

        }

    if(getpixel(bitmaps->page,256,192)== makecol(200,255,255))blit(bitmaps->page,rect,256, 192, 256, 192,512, 350);

return type;
}

/*
void trouver_distance(cases tabcases[23][35])
{

}*/

void pause(BITMAP* pause, BITMAP* page){
    draw_sprite(page,pause,965,300);

}

void sauvegarde(BITMAP* sauvegarde, BITMAP* page){
    draw_sprite(page,sauvegarde,965,375);

}

void quitter(BITMAP* quitter, BITMAP* page){
    draw_sprite(page,quitter,965,450);

}


void niveaux(BITMAP* niveau0,BITMAP* niveau_1,BITMAP* niveau_2,BITMAP* page){

    draw_sprite(page,niveau0,965,75);
    draw_sprite(page,niveau_1,965,150);
    draw_sprite(page,niveau_2,965,225);


    /*rectfill(page, 970, 75, 1020,125, makecol(0,100,0));
    //rectfill(page, 970,150,1020,200,makecol(0,0,255));
    rectfill(page, 970,225,1020,275,makecol(255,255,0));
    //while(!((mouse_b & 1)&&((mouse_x >= 970) && ( mouse_x <=1024 )&&(mouse_y >= 450) && (mouse_y <= 500)))){
    textprintf_ex(page, font, 972,80, makecol(90, 50,15),-1,"Niveau:");
    textprintf_ex(page, font, 992,100, makecol(90, 50,15),-1,"0");
    //textprintf_ex(page, font, 972,155, makecol(50, 100,255),-1,"Niveau:");
    //textprintf_ex(page, font, 992,175, makecol(50, 100,15),-1,"-1");
    textprintf_ex(page, font, 972,230, makecol(50, 100,255),-1,"Niveau:");
    textprintf_ex(page, font, 992,250, makecol(50, 100,15),-1,"-2");*/

}
