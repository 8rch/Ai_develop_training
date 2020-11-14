//-----------------------------------------
//         RUTINA PLOT AGENTS 
//-----------------------------------------
void fill_nodes(void)              ////       PLOT NODES
{
int i,j,sx,sy,x,y,color,scale; 

 x=x_plot_node;
 y=y_plot_node;   
 int count=0;   
   
   for(j=0;j<files;j++)  // 
     { 
      sx = x+j*node_space;               
      for(i=0;i<columns;i++)
         {    
            sy = y+i*node_space;
            node.x[count]=sx;
            node.y[count]=sy;
            color=RED;
            node.color[count]=RED; 
            count++;
         }
     } 
}
//------------------------------------------------------
void clear_nodes(void)              ////       PLOT NODES
{
int i;    

   for(i=0;i<files*columns;i++) node.color[i]=RED; 
}
//---------------------------------------------------------------------------
void plot_links(void)              ////       PLOT NODES
{
 int x,y,sx,sy;
    for(int n_one=0;n_one<qSize;n_one++){
        for(int n_two=0;n_two<qSize;n_two++){
             if((R[n_one][n_two])==100 || (R[n_one][n_two])==0 ){
                x = node.x[node_id[n_one]];
                y = node.y[node_id[n_one]];
                sx = node.x[node_id[n_two]];
                sy = node.y[node_id[n_two]];
   
                setcolor(WHITE);     
                setlinestyle(0,0,5);        
                line(x,y,sx,sy);
                
                 }
             }}
    
}
//----------------------------------------------------------------------------
void plot_nodes(void)              ////       PLOT NODES
{
int i,j,sx,sy,x,y,color,scale; 
int count=0;    


      for(i=0;i<files*columns;i++)
         {  
            sx=node.x[count]; 
            sy=node.y[count]; 
            color=node.color[count]; 
            ///if(count==0) color=LIGHTGRAY;   //  nodos no existentes
            ///if(count==6) color=LIGHTGRAY; 
            //if(count==7) color=GREEN;       // NODO DE LLEGADA 
            ///if(count==8) color=LIGHTGRAY;   
                
            setcolor(color); 
            
            setfillstyle(SOLID_FILL,color); 
            circle(sx,sy,radius);
            floodfill (sx,sy,color );
            count++;
         }
     
}
//--------------------------------------------------------------------------------------
void create_nodes(void)
{

      
}
//--------------------------------------------------------------------



