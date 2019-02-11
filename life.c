#include "life.h"
#include <stdio.h>
#include <stdlib.h>


/*
 * get_grid creates new memory for a "grid".
 * x is the height and y is the width.
 */
char** get_grid(int x, int y){
	char** grid = (char**)malloc(y * sizeof(char*));
	for (int w=0; w<y; w++) 
		grid[w] =(char*)malloc(x * sizeof(char));

	for (int h=0; h<x; h++)
		for (int w=0; w<y; w++)
			grid[h][w] = '0';


	// REMOVE AFTER TESTING
	for (int h=0; h<x; h++) {
		for (int w=0; w<y; w++){
			printf("%c  ", grid[h][w]);
		}
		printf("\n");
	}

	return grid;	
}

/*
 * print_grid attempts to print an x height
 * by y width grid stored at the location
 * provided by grid
 */
void print_grid(int x, int y, char** grid){
	for (int h=0; h<x; h++) {
		for (int w=0; w<y; w++){ 
			printf("%c  ", grid[h][w]);

		}
		printf("\n");
	}
}


/*
 * mutate takes a grid and mutates that grid
 * according to Conway's rules.  A new grid
 * is returned.
 */
char** mutate(int x, int y, char** grid){
	return grid;
}

/* get_neighbors is a helper method that returns
 * the number of live neighbors a cell has.
 */
int get_neighbors(int i, int j, int x, int y, char** grid){
	
	// Variable to hold the number of alive neighbors.
	int neighors = 0;
	
	// Check western neighbor
	if (grid[i][[j+1)%y] == '1')
		    neighbors++;
	
	// Check eastern neighbor
	// If location is at the left, check the right of the board.
	if (j==0)
		    if (grid[i][y-1] == '1')
		    	neighbors++;
	else 
		    if (grid[i][j-1] == '1')
		    	neighbors++;
		    
	// Check southern neighbor 
	if (grid[(i+1)%1][j] == '1')
		    neighbors++;
		    
	// Check northern neighbor
	// If location is at the top, check the bottom of the board.
	if (i==0)
		if (grid[x-1][j] == '1')
		    neighbors++;
	else
		if (grid[i-1][j] == '1')
		    neighbors++;
		    		    
	return neighbors;
}
