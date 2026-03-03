#include <stdio.h>
#include <stdlib.h>
# define Amount 3

size_t towers[Amount][3];

void show_towers()
{
    for (size_t i=0; i<Amount; i++)
    {
        for (size_t j=0; j<3; j++)
        {
            printf("%d\t", towers[i][j]);
        }
        printf("\n");
    }
    printf("-----------------\n");
}
void move (size_t from, size_t to)
{
    if((to>=3)||(from>=3))
    {
        return;
    }

    size_t top_from = 0;
    size_t top_to = 0;

    while((top_from < Amount)&&(towers[top_from][from]==0))
    {
        top_from++;

    }
    while((top_to < Amount)&&(towers[top_to][to]==0))
    {
        top_to++;

    }
    if(top_from==Amount)
        return;

    towers[top_to-1][to]=towers[top_from][from];
    towers[top_from][from]=0;
}

void hanoi (size_t amount, size_t from, size_t to)
{

    //нужно было исправить 1 единственную строчку  (size_t temp_to = 6 - from - to;)->(size_t temp_to = 3 - from - to;)
    size_t temp_to = 3 - from - to;
    if (amount == 1)
    {
        move(from, to);
        show_towers();
    }
    else
    {
        hanoi(amount-1,from,temp_to);
        hanoi(1, from, to);
        hanoi(amount-1, temp_to, to);
    }
}
int main()
{
    for ( size_t i=0; i<Amount; i++)
{
    towers[i][0]=i+1;
    towers[i][1]=0;
    towers[i][2]=0;
}
    show_towers();
    hanoi(Amount, 0, 2);
    return 0;
}
