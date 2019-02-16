//*********************************************************************
// Filename: life.c
//
// Students: Sam Ventocilla and Randy Nguyen
// ********************************************************************

#include "life.h"
#include <stdio.h>
#include <stdlib.h>


/**********************************************************************
 * get_grid creates new memory for a "grid".
 * 
 * @param x height of grid
 * @param y width of grid
 * @return grid starting memory address for a "grid" 
 *********************************************************************/
char** get_grid(int x, int y){

	// Allocate memory for outer array.
	char** grid = (char**)malloc(y * sizeof(char*));

	// Allocate memory for inner arrays.
	for (int w=0; w<y; w++) 
		grid[w] =(char*)malloc(x * sizeof(char));

	return grid;	
}

/**********************************************************************
 * print_grid attempts to print an x height
 * by y width grid stored at the location
 * provided by grid
 *
 * @param x height of grid
 * @param y width of grid
 * @param grid memory address for "grid"
 *********************************************************************/
void print_grid(int x, int y, char** grid){

	printf("\n");

	// Check each location in grid and prrint the value.
	for (int h=0; h<x; h++) {
		for (int w=0; w<y; w++){ 
			if(grid[h][w] == 0)
				printf("0  ");
			else if(grid[h][w] == 1)
				printf("1  ");
			else
				printf("-1  ");
		}
		printf("\n");
	}
}


/**********************************************************************
 * mutate takes a grid and mutates that grid
 * according to Conway's rules.  A new grid
 * is returned.
 *
 * @param x height of grid
 * @param y width of grid
 * @param grid memory address of "grid"
 * @return newGrid memory address to the mutated grid
 *********************************************************************/
char** mutate(int x, int y, char** grid){

	// Number of live neighbors
	int neighbors = 0;

	// Allocate memory for a new "grid"
	char** newGrid = get_grid(x, y);

	// Count the number of live neighbors at every grid location
	// Update newGrid based on Conway's rules
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			neighbors = get_neighbors(i, j, x, y, grid);
			if(grid[i][j] == 1){
				if(neighbors < 2)
					newGrid[i][j] = 0;
				else if(neighbors > 3)
					newGrid[i][j] = 0;
				else
					newGrid[i][j] = 1;
			}
			else if(grid[i][j] == 0){
				if(neighbors == 3){
					newGrid[i][j] = 1;
				}
			}		
		}
	}

	
	for(int i = 0; i < x; i++)
		for(int j = 0; j < y; j++)
			if(newGrid[i][j] != 1)
				newGrid[i][j] = 0;
	return newGrid;
}

/**********************************************************************
 * get_neighbors is a helper function that returns
 * the number of live neighbors a cell has.
 *
 * @param i the selected height
 * @param j the selected width
 * @param x height of grid
 * @param y width of grid
 * @param grid memory address to "grid"
 *
 * @return neighbors number of live neighbors
 **********************************************************************/
int get_neighbors(int i, int j, int x, int y, char** grid){
	// Variable to hold the number of alive neighbors.
	int neighbors = 0;

	// Go through each possible direction. 
	// If it doesn't move at all, don't increment neighbors
	for(int a = -1; a < 2; a++)
		for(int b = -1; b < 2; b++)
			if(!(a == 0 && b == 0))
				if(onBoard(i+a,j+b,x,y) == 1)
					if(grid[i+a][j+b] == 1)
						neighbors++;    		    
	return neighbors;
}

/**********************************************************************
 * onBoard is a helper function to check if a location is valid
 *
 * @param i the selected height
 * @param j the selected width
 * @param x height of grid
 * @param y width of grid
 *
 * @return 0 not on board : 1 on board
 **********************************************************************/
int onBoard(int i, int j, int x, int y){
	if(i >= x || i < 0 || j < 0 || j >= y)
		return 0;
	return 1;
}
