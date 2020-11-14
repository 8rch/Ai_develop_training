//===========================================================================
//  DEFINICION DE ESTRUCTURAS Q 
//========================================================================
struct  mesagge_pass
	  {
           int  s;  
	       int  receiver;
	       int  sender;  
	       int  amount;
      } message_1;
//----------------------------------------------------------------------------------------------------
  struct  peer_to_peer
	  {
           int  status;  // 0=free,   1=sending  3= acknowlodge
           int  receiver;
	       int  sender;
           int  pass;
	       int  amount;
      } peer_mess;
//----------------------------------------------------------------------------------------------------     
void print_Q(void)
{
 int i,j;
    
    printf("This is the Q Matrix:\n \n");
    for(i = 0; i < qSize ; i++)
        {
        for(j = 0; j < qSize; j++)
            {
            cout << setw(5) << Q[i][j];   
			if(j < qSize - 1)cout << "  ";  // separador de de columnas 
		} // j
        cout << "\n";
	} // i
    cout << "\n";
}
//------------------------
void print_R(void)
{
 int i,j;
    
    printf("This is the R Matrix:\n \n");
    for(i = 0; i < qSize; i++)
        {
        for(j = 0; j <= (qSize - 1); j++)
            {
            cout << setw(5) << R[i][j];   
			if(j < qSize - 1)cout << "  ";  // separador de de columnas 
		} // j
        cout << "\n";
	} // i
    cout << "\n";
}
//---------------------------------------------------------
void Q_learn_server(void) 
{
 int i,j;     
 int temp, explore_state, max;
 int initial_state;
 float femp;
    
 episode=1;
    
 do
  {
    initial_state=random(qSize); 
    
    do
       { 
          do
            {
             explore_state=random(qSize);   //  se escioge el estado inicial
             temp=R[initial_state][explore_state];   
            } while(temp==-1);               // estado fijo, buscamos columna diferente de -1 
//-------------------
             clear_nodes();
             chosen_node=explore_state;   
             node.color[node_id[chosen_node]]=14;
             plot_nodes(); 
             delay(50);            
//--------------------            
            system("cls");     
            cout << "initial state = "<< initial_state <<endl; 
            cout << "state to be explored = "<< explore_state << endl;  
             
            max=Q[explore_state][0];
            for(i=1;i<qSize;i++)
            {
            if(Q[explore_state][i]>max) max = Q[explore_state][i];                  // buscamos el valor mas alto de valores Q  
            }
            cout << "The max found Q is = "<< max << endl;  
            femp=max;                                                    //  para convertir a float
            Q[initial_state][explore_state]= R[initial_state][explore_state]+ gamma*femp;  

            
            initial_state=explore_state; 
            cout << "next nitial state = "<< explore_state << endl; 
            cout << "episode = "<< episode << endl<< endl;  
            print_Q();
            //gets(dummy); 
            if(initial_state==8)break;  // end of episode
    } while(1);
    episode++;    
    //gets(dummy); 
 } while(episode<40);  //  aqui controlamos cuantos episodios queremos ejecutar para entrenar

     for(i=0;i<6;i++)
     for(j=0;j<6;j++)  Q[i][j] = Q[i][j]/10;   // reduce el tamaño de entradas en Q
} 
//-------------------------------------------------------------
void Q_player_server(void) 
{
 int i,j,k;     
 int max;
 int initial_state, next_state;
 int step_count;
 int route[100];   //  guarda la ruta seguida por en agente
 
    
 loop:
    
    step_count=0;
    for(i=0;i<10;i++) route[i]=9;   // un estado no existente
    initial_state=random(6); 
             clear_nodes();
             chosen_node=initial_state;   
             node.color[node_id[chosen_node]]=14;
             plot_nodes(); 
             delay(200);   
    
    route[0]=initial_state;
    do
       { 
          
            system("cls");     
            cout << "search begins at = "<< initial_state <<endl; 
            
            max=Q[initial_state][0];  // valor en columna 0 del esta inicial
           
           
           for(i=1;i<qSize;i++)
            {
             if(Q[initial_state][i]>max)
                   {
                       max = Q[initial_state][i];      // buscamos el valor mas alto de valores Q
                       j=i;                            //j apunta a la columna del valor maximo
                   } 
            }
           
            //     ??        hallar valores en columnas diferentes de 0 y convertir a estadistica de decisiones
            //     ??
            //next_state=random(6);
            
            next_state= j;
             clear_nodes();
             chosen_node=j;   
             node.color[node_id[chosen_node]]=14;
             plot_nodes(); 
             delay(200);   
           
            step_count++;  
            route[step_count]=next_state;
           
            for(i=0;i<step_count+1;i++) {cout << route[i]<< "  ";}
            cout<<endl;
            
            cout << "The max found Q guide is = "<< max <<" in column "<< next_state <<endl;  
            cout << "second max is at column "<< k <<endl;
            initial_state=next_state;
            cout << "the next state is = "<< initial_state <<endl;  
            print_Q();
            
            //getch();         
            //gets(dummy);
            
      if(next_state==8)break;  // end of search
    } while(1);
    
    cout << "rute traced = ";  
    
    for(i=0;i<step_count+1;i++) {cout << route[i]<< "  ";}
    getch();
    //gets(dummy); 
    goto loop;
} 
//-------------------------------------------------------------
