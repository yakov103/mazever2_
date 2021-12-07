//
// Created by Yakov Khodorkovski
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "union_find.h"




int main() {
int input;
    printf("please enter n*n size of maze : ");
    scanf("%d", &input );

// ptr will be the pointer for the union_find
    int n = input, m =input, i  ;
    int *ptr ;
    ptr = (int*) malloc (sizeof (int) *n*m);
    if (ptr == NULL){
        printf("error no alocated memory !!");
        return 1;
    }
    memset(ptr, -1, sizeof (int)*n*n);

 // wallsArr is an n*n matrix of all the walls that can be in the maze
    int *wallsArr ;
    wallsArr = (int*)malloc(n*m *sizeof (int));
    memset(wallsArr, 0, n*m*sizeof (int));
    if (wallsArr == NULL){
        printf("error no alocated memory !!");
        return 1;
    }
    //Make the walls
    makeNewWalls(wallsArr, n, m);

    // Make the maze with the algorithm
    runAlgo(ptr,wallsArr,n,m);

    //newWalls are to convert the walls to pritable matrix
    int *newWalls ;
    newWalls = (int *) malloc (sizeof (int) * (n*2+1)* (m*2+1));
    memset(newWalls,-1,sizeof (int) * (n*2+1)* (m*2+1));
    if (newWalls == NULL){
        printf("error no alocated memory !!");
        return 1;
    }
    //Convertor
    convertMatrixToPrintable(newWalls, wallsArr, n, m);

    //Printer
    MazePrinter(newWalls,n,n);

    free(ptr);
    free(wallsArr);
    free(newWalls);

    ptr=NULL;
    wallsArr =NULL;
    newWalls = NULL;
    return 0;
}
