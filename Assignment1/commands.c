#include<stdlib.h>
#include <stdio.h>
#include "GenerateMap.h"
#include "map.h"
#include "commands.h"

char** getInput(char** maze, char input, int *x, int *y)
{
    int move[2];int i= ' '; int j = 'x';

    if (input == 'w'){   /*if input is 'w' the player will go one step up*/
        move[0] = *x-1; /*determines the coordinates*/
        move[1] = *y;  /*determines the coordinates*/
        if(maze[move[0]][move[1]] == i){  /* stops player from moving into walls/barriers*/
            maze[*x][*y] = ' ';
            *x = move[0];   /*updates the coodrinates*/
            *y = move[1];
            maze[*x][*y] = '^';
        }
        if(maze[move[0]][move[1]] == j){   /*allows the player to reach the object 'x'*/
            maze[*x][*y] = ' ';
            *x = move[0];
            *y = move[1];
            maze[*x][*y] = '^';
        }
    }
    else if (input =='a'){             /*if input is 'a' the player will go one step left*/
        move[0] = *x;    /*determines the coordinates*/
        move[1] = *y -1; /*determines the coordinates*/
        if(maze[move[0]][move[1]] == i){   /* stops player from moving into walls/barriers*/
            maze[*x][*y] = ' ';
            *x = move[0];    /*updates the coodrinates*/
            *y = move[1];
            maze[*x][*y] = '<';
        }
        if(maze[move[0]][move[1]] == j){ /*allows the player to reach the object 'x'*/
            maze[*x][*y] = ' ';
            *x = move[0];
            *y = move[1];
            maze[*x][*y] = '<';
        }
    }
    else if (input == 'd'){    /*if input is 'd' the player will go one step right*/
        move[0] = *x;   /*determines the coordinates*/
        move[1] = *y +1;   /*determines the coordinates*/
        if(maze[move[0]][move[1]] == i){ /* stops player from moving into walls/barriers*/
            maze[*x][*y] = ' ';
            *x= move[0];        /*updates the coodrinates*/
            *y = move[1];
            maze[*x][*y] ='>';
        }
        if(maze[move[0]][move[1]] == j){  /*allows the player to reach the object 'x'*/
            maze[*x][*y] = ' ';
            *x = move[0];
            *y = move[1];
            maze[*x][*y] = '>';
        }
    }
    else if (input == 's'){   /*if input is 's' the player will go one step down*/
        move[0] = *x+1;       /*determines the coordinates*/
        move[1] = *y;         /*determines the coordinates*/
        if(maze[move[0]][move[1]] == i){  /* stops player from moving into walls/barriers*/
            maze[*x][*y] = ' '; 
            *x = move[0];        
            *y = move[1];         /*updates the coodrinates*/
            maze[*x][*y] ='v';
        }
        if(maze[move[0]][move[1]] == j){   /*allows the player to reach the object 'x'*/
            maze[*x][*y] = ' ';
            *x = move[0];
            *y = move[1];
            maze[*x][*y] = 'v';
        }
    }
    else
        printf("Error: Enter 'w'(UP),'a'(LEFT),'s'(DOWN), 'd'(RIGHT)");  /*error message telling the user they have inputed the wrong commands*/
    return maze;
}
