//
// Created by mi on 8/14/18.
//


#include<stdlib.h>
#include<stdio.h>

#define x 9999
#define max 9999
int data[10][10];
int dist[10];//记录最短路径为多少
int path[10];//记录最短路径

void fpath(int a[][10]);

int froute(int a[][10]);
/*

int main() {
    int i, m;
    int a[10][10] =
            {
                    {x, 4, 2, 3, x, x,  x,  x, x, x},
                    {x, x, x, x, 10, 9, x,  x, x, x},
                    {x, x, x, x, 6,  7, 10, x, x, x},
                    {x, x, x, x, x,  3, 8,  x, x, x},
                    {x, x, x, x, x, x,  x, 4, 8,  x},
                    {x, x, x, x, x, x,  x, 9, 6,  x},
                    {x, x, x, x, x, x,  x, 5, 4,  x},
                    {x, x, x, x, x, x,  x,  x, x, 8},
                    {x, x, x, x, x, x,  x,  x, x, 4},
                    {x, x, x, x, x, x,  x,  x, x, x}
            };
//    for (i = 0; i < 10; i++) {
//        for (int j = 0; j < 10; j++)
//            printf("%d ", a[i][j]);
//        printf("\n");
//    }
    fpath(a);
    printf("最短路径大小为: %d\n", dist[9]);

    m = froute(a);
    for (i = m - 1; i >= 0; i--)
        printf("最短路径经过: %d\n", path[i]);

    return 0;
}*/

void fpath(int a[][10]) {
    int i, j, k;
    dist[0] = 0;
    for (i = 1; i < 10; i++) {
        k = max;
        for (j = 0; j < i; j++) {
            if (a[j][i] != x)
                if ((dist[j] + a[j][i]) < k)
                    k = dist[j] + a[j][i];
        }
        dist[i] =  k;
    }
}


int froute(int a[][10]) {
    int j, b, k = 1, i = 9;
    path[0] = 10;
    while (i > 0) {
        for (j = i - 1; j >= 0; j--) {
            if (a[j][i] != x) {
                b = dist[i] - a[j][i];
                if (b == dist[j]) {
                    path[k++] = j + 1;
                    i = j;
                    break;
                }
            }
        }
    }
    return k;
}
