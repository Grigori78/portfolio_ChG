#include <stdio.h>
#include <stdlib.h>
#define M 5
#define N 6


void top(int (*massive)[M],int*n, int m, int *cur_i, int*cur_j, int *a)
{
    for(size_t i = 0; i < m; i++)
    {
        massive[*cur_i][(*cur_j)++] = (*a)++;
    }
    (*cur_j)--;
    (*cur_i)++;
    (*n)--;

}

void right(int (*massive)[M], int n, int*m, int *cur_i, int*cur_j, int *a)
{

    for(size_t i = 0; i < n; i++)
    {
        massive[(*cur_i)++][(*cur_j)] = (*a)++;
    }
    (*cur_j)--;
    (*cur_i)--;
    (*m)--;

}

void bottom(int (*massive)[M],int*n, int m, int *cur_i, int*cur_j, int *a)
{


    for(size_t i = 0; i < m; i++)
    {
        massive[*cur_i][(*cur_j)--] = (*a)++;
    }
    (*cur_j)++;
    (*cur_i)--;
    (*n)--;

}

void left(int (*massive)[M], int n, int*m, int *cur_i, int*cur_j, int *a)
{

   for(size_t i = 0; i < n; i++)
    {
        massive[(*cur_i)--][(*cur_j)] = (*a)++;
    }
    (*cur_j)++;
    (*cur_i)++;
    (*m)--;

}

void show (int(*massive)[M], int n, int m)
{
    for (size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < m; j++)
        {
            printf("%d\t", massive[i][j]);
        }
        printf("\n");
    }
}

void fill(int (*massive)[M], int n, int m)
{
   int temp_n=n, temp=m, a=0;
    int temp_i=0, temp_j=0;

     while(temp_n > 0 && temp > 0)
    {
        top(massive, &temp_n, temp, &temp_i, &temp_j, &a);
        if(temp_n <= 0) break;

        right(massive, temp_n, &temp, &temp_i, &temp_j, &a);
        if(temp <= 0) break;

        bottom(massive, &temp_n, temp, &temp_i, &temp_j, &a);
        if(temp_n <= 0) break;

        left(massive, temp_n, &temp, &temp_i, &temp_j, &a);
    }
printf("test\n");
}

int main()
{
    int spiral_nm[N][M] ;

    fill(spiral_nm, N, M);
    show(spiral_nm, N, M);
    printf("\n");



    return 0;
}
