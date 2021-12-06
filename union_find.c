//
// Created by Yakov Khodorkovski
//
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int find (int *A,  int n ){
    int tmp= n ;
    if ( A[n] < 0 ) {
        return tmp;
    }

    while (A[tmp] >= 0 ){
        tmp = A[tmp];
    }
    if (A[n] != tmp && tmp != n){
        A[n]= tmp;
        A[tmp] --;
    }
    return tmp ;
}





void unionSet ( int *A, int first ,int second ){
    int a = find(A,first);
    int b = find(A,second);
    int tmp ;
    if ( a != b) {
        if ( A[a] < A[b]){
            tmp = A[b];
            A[b]= a;
            if (A[a] != -1) {
                A[a] += tmp;
                A[a]--;
            }
        }
        else {
            tmp = A[a];
            A[a]= b;
            if (A[b] != -1) {
                A[b] += tmp;
                A[b]--;
            }
        }


    }

}


void runAlgo (int *ptr , int *wallsArr, int n , int m ){
    int flag = 1 ,r, x,y,i  ;
    srand(time(NULL));
    int *boolArr , cnt = 0 ;
    boolArr = (int * ) calloc(n * m, sizeof (int ));
    int tmp;
    while (flag) {
        r = rand()%(n*m);
        if (boolArr[r] == 1){
            continue;
        }
        else {
            boolArr[r]= 1;
        }

        if ( wallsArr[r] == 3) {
            x= find (ptr,r);
            tmp = r+1;
            y= find (ptr,tmp);
            if ( x != y){
                wallsArr[r] =1 ;
                unionSet(ptr,r,r+1);
            }
            else {
                wallsArr[r] =4 ;
            }
        }
        if ( wallsArr[r] == 2) {
            x= find (ptr,r);
            tmp = r+1;
            y= find (ptr,tmp);
            if ( x != y){
                wallsArr[r] =0 ;
                unionSet(ptr,r,r+1);
            }
        }
        if ( wallsArr[r] == 1 || wallsArr[r] == 4) {
            x= find (ptr,r);
            tmp = r+m;
            y= find (ptr,tmp);
            if ( x != y){
                if (wallsArr[r] == 4){
                    wallsArr[r] =2 ;
                }
                if (wallsArr[r] == 1){
                    wallsArr[r] =0 ;
                }
                unionSet(ptr,r,r+m);
            }
        }
        cnt = 0;
        for ( i = 0 ; i < n*m ; i ++){
            if (ptr[i] > 0 ){
                cnt++;
            }
        }
        if (cnt == n*m -1){
            flag= 0 ;
        }
    }

    free(boolArr);
    boolArr =NULL;

}



void makeNewWalls (int *wallsArr , int n, int m ){
    int i ;
    for (i = 0 ; i < n*(m-1) ; i++){
        if ( i%n  == n-1){
            wallsArr[i] = 1;
        }
        else {
            wallsArr[i] = 3;
        }
    }
    for (i = n*(m-1) ; i < n*m ; i++){
        if ( i == n*m-1){
            wallsArr[i]= 0;
        }
        else {
            wallsArr[i]= 2;
        }

    }


}

void convertMatrixToPrintable (int *newWalls , int*wallsArr , int n , int m ){
    int i ,j , cnt;
    int k=0;
    for ( i = 0 ; i  < n*2+1 ; i ++){
        cnt =1;

        for ( j = 0 ; j < m*2+1 ; j++){
            if ( i%2 == 1 ){
                if (j == cnt){
                    newWalls[i*n + j ]= wallsArr[k];
                    k++;
                    cnt += 2;
                }

            }
        }
    }



}

void MazePrinter (int *newWalls , int n ,int m ){

    printf("\n");
    int wall , i , cnt  ;
    int cnt2 = 1;
    for ( i = 0 ; i < n*2+1 ; i++){
        if ( i%2 == 0 ){
            printf("+");

        }
        else {
            printf("-");
        }
    }
    printf("\n");

    for ( i = 1 ; i < m*2 ; i ++) {
        cnt = 1;
        for (int j = 0; j < n*2+1; j++) {
            if (i % 2 ==0 ){
                if (j % 2 == 0){
                    printf("+");
                    continue;
                }
                else {
                    if (newWalls [(i-1)*n + j ] == 0 || newWalls [(i-1)*n + j ]== 2 ){
                        printf(" ");
                        continue;
                    }
                    else {
                        printf("-");
                        continue;
                    }
                }
            }
            if ( j == 0 ||  j == n*2){
                if ( i == 1 && j == 0   ){
                    printf(">");
                    continue;
                }
                else if (i ==m*2-1 && j == n*2){
                    printf(">");
                    continue;
                }
                else {
                    printf("|");
                    continue;
                }
            }
            else {

                if ( j % 2 == 0 ){
                    if (newWalls [i*n + j -1 ] < 2  && j != n*2){
                        printf(" ");
                    }
                    else{
                        printf("|");
                    }

                }
                else {
                    printf(" ");
                }

            }



        }
        printf("\n");
    }
    for ( i = 0 ; i < n*2+1 ; i++){
        if ( i%2 == 0 ){
            printf("+");

        }
        else {
            printf("-");
        }
    }

    printf("\n");



}

