#include "graph_sims_header.h"

int main()
{
    int ordre,type=0;
    initAllegro();
    BITMAP *page,*rect,*it;
    page = create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(page);
    rect = create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(rect);
    BITMAP *map;
    map=load_bitmap("menu/map.bmp",NULL);
    cases tabcases[75][35];

    Bitmaps *bitmaps=initialisation_bitmaps();
    bitmaps->idsommet = 0;
    bitmaps->taille = 0;
    for(int i=0;i<75;i++)
    {
        for(int j=0;j<35;j++)
        {
            tabcases[i][j].type=0;
            tabcases[i][j].id=-1;
            tabcases[i][j].intersection=0;
            tabcases[i][j].passage=0;
            tabcases[i][j].x=j*21;
            tabcases[i][j].y=i*11;
           // printf("tab[%d][%d]=x=%d y=%d  ",j,i,tabcases[i][j].x,tabcases[i][j].y);
        }//printf("\n\n\n");
    }


    BITMAP* route;
    route= load_bitmap("routelosange.bmp",NULL);

    draw_sprite(page,map,0,70);
    for(int i=0;i<64;i++)
    {
        line(page,0,10+20*i,20+40*i,0,makecol(86,122,56));
        line(page ,1024-40*i,0,1024,2+20*i,makecol(86,122,56));
    }

    while (!key[KEY_ESC])
    {

        clear_bitmap(rect);
        blit(page,rect,0,0,0,0,SCREEN_W,SCREEN_H);

        outils(bitmaps,rect,page,tabcases);

        pause(bitmaps->pause,page);
        sauvegarde(bitmaps->sauvegarde,page);
        quitter(bitmaps->quitter,page);
        niveaux(bitmaps->niveau0,bitmaps->niveau_1,bitmaps->niveau_2,page);
       // if(mouse_b&1)MAJ_graph(ordre);
        show_mouse(rect);
        blit(rect,screen,0,0,0,0,SCREEN_W,SCREEN_H);

    }
    destroy_bitmap(rect);
    destroy_bitmap(page);


    return 0;
}
END_OF_MAIN();
