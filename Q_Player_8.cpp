//------------------------------------------------------------------
//          Practica 5                              
//         Generic Q Player 
//         Prof Oscar Chang
//         October 28, 2020
//
//--------------------------//        GLOBALS   -------------------                    
const int qSize = 9;
const double gamma = 0.8;
const int iterations = 10;

int R[qSize][qSize] =
        {
            {-1, 0, -1, -1, -1, -1, -1,-1,-1},   // 0
			{-1, -1, 0, -1, -1, -1, -1,-1,0},   // 1   acomodamos la matriz para poder realizar un estudio de  mejoramiento de la ruta
			{-1, -1, -1, 0, -1, -1, -1,-1,-1},   // 2 
			{-1, -1, -1, -1, 0, -1, -1,-1,-1},   // 3 
            {-1, -1, -1, -1, -1, 0, -1,-1,0},   // 4 
			{-1, -1, -1, -1, -1, -1, 0,-1,-1},   // 5 
			{-1, -1, -1, -1, -1, -1, -1, 0,-1},  // 6  
			{-1, -1, -1, -1, -1, -1, -1,-1, 100},// 7
            {-1, -1, -1, -1, -1, -1, -1,-1, 100},// 8 
        };
//--
int Q[qSize][qSize];
int currentState;   
int episode;      
char dummy[1];
//--
int files=3;
int columns=3;        
        
int x_plot_node=200;
int y_plot_node=200;
int node_space=100;
int radius=20;
  
//          //            0     1    2    3    4    5    6    7    8
//int node_id[] = { 2, 3, 1, 4, 5, 7, 0, 0, 0 };

          //            0     1    2    3    4    5    6    7    8  
int node_id[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };


int chosen_node;        
        
//-----------------------------------------------
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>
#include <conio.h>   
#include <stdio.h>
#include <iostream.h>
#include <time.h>
#include <windows.h>
#include <iostream>
#include <iomanip>
#include <ctime>#include <iomanip>
#include <ctime>


        
#include "nodes_lib.h"
#include "nodes_move.h"
#include "Q_structures_lib.H" 


//using namespace std;  
//--------------------------------------
void grafico(void)
{
    int    GraphDriver;  /* The Graphics device driver */
    int    GraphMode;    /* The Graphics mode value */
    int    ErrorCode;    /* Reports any graphics errors */
   
    initgraph(&GraphDriver, &GraphMode, "");

    ErrorCode = graphresult();            /* Read result of initialization*/
    if( ErrorCode != grOk )              /* Error occured during init    */
    {
       printf(" Graphics System Error: %s", grapherrormsg( ErrorCode ) );
       exit( 1 );
    }
}
//---------------------------------------
//int master_delay;
//--------------------------------------

void clear_screen(void)
{
    system("cls");
} 
//----------------------------------------
//    LOOP
//----------------------------------------
void loop(void)
{
     Q_learn_server();
     cout << "End training in episode "<< episode << endl; 
                        
     print_Q(); 
     cout << "Ready to play "<<endl; 
     getch();
     Q_player_server();
     getch(); 
}
//----------------------------------------
main()
{
 //int i;  

   cout << "Q_learner_version_1.0  "<<endl<<endl; 
   Sleep(500);
   randomize();
   print_Q();
   print_R(); 
    
   //Sleep(100);               
   //gets(dummy); 
//-- 
    clrscr();                   // limpia la pantalla
    grafico();                  // prepara modo grafico   
    cleardevice();              // limpia la pantalla windows
    
    setcolor(LIGHTGRAY);
    bar(0,0,1400,900);       //    limpia pantalla local
    
    
    setcolor(WHITE);
    settextstyle(3, HORIZ_DIR, 1);
    
    print_R();
    //getch();
    fill_nodes(); 
    plot_links();  
    plot_nodes();
    
    
    //getch();
    
    chosen_node=0;
    
//--    
   loop(); 
  
}

//--------------------------------------------------------