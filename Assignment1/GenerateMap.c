#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "GenerateMap.h"

char** createMap(int*row, int*col, int objective[], int user[]) /*function to retreive data from map.c*/
{
    int i; int k; int **data = 0; char **Maze; int amount; int Row; int Col; int x; int y;int object; /*variables declared*/
    getMetadata(&data, &amount, &Row, &Col);
    Maze = (char**)malloc(Row*sizeof(char*)); /* memory allocation for maze*/
    *row = Row; /* pointers used to send to the main fucntion*/
    *col = Col;   
    /*for loops used so that it keeps printing the map*/
    for (i=0; i < Row; ++i)
    {
        Maze[i] = (char*)malloc(Col*sizeof(char)); 
        for(k = 0; k < Col; ++k){
            Maze[i][k] = ' ';   /* area player can travel through*/
        }
    }
    for (i=1; i < (Row-1); ++i)
    {
        Maze[i][0]= '|';        /* barriers*/
        Maze[i][Col -1] = '|'; /* barriers*/
    
    for(k=1; k < (Col-1); ++k)
    {
        int xrow = Row - 1;                        
        Maze[0][k] = '-';     /* barriers*/
        Maze[xrow][k] = '-';   /* barriers*/
        }
    }                                          
    for (i=0; i < amount; ++i)   /*this is to make the initial maze*/
    { 
        x = data[i][0];       /*determines x, y coordinates*/
        y = data[i][1]; 
        object = data[i][2];  /*shows whether its a wall, object or the player */
        if (object == 0){        
            Maze[x][y] = '^';   
            user[1] = y;
            user[0] = x;
        }
        else if (object == 1){ 
            Maze[x][y] = 'x';  /*goal*/
            objective[0] = x;
            objective[1] = y;
        }
        else
            Maze[x][y] = 'o';   /* walls*/
    } 
    for (i=0; i < Row; ++i)
    {
        Maze[0][Col-1] = '#';     /* more barriers*/
        Maze[0][0] = '#';        
        Maze[Row-1][0] = '#';     
        Maze[Row-1][Col-1] = '#';
    } 
    return Maze;
}
/*function to print maze onto the screen*/
void displayMaze(char** maze, int Row, int Col, int user[]){
    int i,k;
       for( i = 0; i < Row; ++i)
        {
            for( k =0; k < Col; ++k)
            {
                printf("%c", maze[i][k]);
            }  
                printf("\n");            
        }
}


    
