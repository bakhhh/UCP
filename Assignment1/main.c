/*  ==========================================================================
**  Author: Sohailharoon Bakhshi 
**  ID: 20605126
**  Last Updated: 20/9/21
**  ==========================================================================
*/
#include<stdlib.h>
#include <stdio.h>
#include<termios.h>
#include "terminal.h"
#include "GenerateMap.h"
#include "map.h"
#include "commands.h"

/*no command line arguments :(*/

int main()
{
    int row; int* objective; int *user; int col; /*variables to store arrays, inputs etc..*/
    char** maze = 0; char input; 
    objective  = (int*)malloc(sizeof(int)*2); /*malloc used to allocate memory*/
    user = (int*)malloc(sizeof(int)*2);   /*malloc used to allocate memory*/
    maze = createMap(&row, &col, objective, user); /*uses createMap function to create the maze*/
   {    
        disableBuffer();   /*sends input straight to scanf*/
        system("clear");   /*clears the terminal screen*/
        while (user[0] != objective[0] || user[1] != objective[1]){ /*while loop that keeps on running until the user is has reached the objective*/
            displayMaze(maze, row, col, user);  /* prints the maze on to the screen*/
            scanf(" %c", &input);  /*users input*/
            maze = getInput(maze, input, &user[0], &user[1]); /*function that gets users input and allows them to move up down left or right*/
            system("clear");  /*clears the terminal screen*/
        }
        displayMaze(maze, row, col, user);
        printf("YOU WIN!!");
        enableBuffer();  /*buffer re enabled*/
    }
    free(maze);free(objective);free(user); /*freeing all allocated memory*/
    return 0;
}
