//
// Created by Yakov Khodorkovski
//

#ifndef MAZEVER2__UNION_FIND_H
#define MAZEVER2__UNION_FIND_H


int find (int *A,  int n );
void unionSet ( int *A, int first ,int second );

void runAlgo (int *ptr , int *wallsArr, int n , int m );

void makeNewWalls (int *wallsArr , int n, int m );
void convertMatrixToPrintable (int *newWalls , int*wallsArr , int n , int m );
void MazePrinter (int *newWalls , int n ,int m );


#endif //MAZEVER2__UNION_FIND_H
