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

	//	for (int h=0; h<x; h++)
	//		for (int w=0; w<y; w++)
	//			grid[h][w] = '0';


	// REMOVE AFTER TESTING
	//	for (int h=0; h<x; h++) {
	//		for (int w=0; w<y; w++){
	//			printf("%c  ", grid[h][w]);
	//		}
	//		printf("\n");
	//	}

	return grid;	
}

/*
 * print_grid attempts to print an x height
 * by y width grid stored at the location
 * provided by grid
 */
void print_grid(int x, int y, char** grid){
	printf("\n");
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


/*
 * mutate takes a grid and mutates that grid
 * according to Conway's rules.  A new grid
 * is returned.
 */
char** mutate(int x, int y, char** grid){
	int neighbors = 0;
	char** newGrid = get_grid(x, y);
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

/* get_neighbors is a helper method that returns
 * the number of live neighbors a cell has.
 */
int get_neighbors(int i, int j, int x, int y, char** grid){
	// Variable to hold the number of alive neighbors.
	int neighbors = 0;

	//go through each possible direction. If it doesn't move at all, don't increment neighbors
	for(int a = -1; a < 2; a++)
		for(int b = -1; b < 2; b++)
			if(!(a == 0 && b == 0))
				if(onBoard(i+a,j+b,x,y) == 1)
					if(grid[i+a][j+b] == 1)
						neighbors++;    		    
	return neighbors;
}

int onBoard(int i, int j, int x, int y){
	if(i >= x || i < 0 || j < 0 || j >= y)
		return 0;
	return 1;
}
