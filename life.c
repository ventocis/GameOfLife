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
			//FIX
			//printf("c  ", &grid[h][w]);

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
	return 1;
}
