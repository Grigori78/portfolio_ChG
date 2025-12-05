#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 10


int queue[QUEUE_SIZE];


size_t in=0, out=0, n=0;

void init (void)
{
    in=0;
    out=0;
    n=0;
}
size_t next(size_t number)
{
    return (number+1)%QUEUE_SIZE;
}


void show(void)
{

        size_t current_index=out;
        for(size_t i=0; i<n;i++ )
        {
            printf("%d\t%d\n", i, queue[current_index] );
            current_index=next(current_index);
        }
        if(!n)
        {
            printf(" Queue is empty\n" );
        }

}
//функция записывает число в конец очереди, если в ней есть место,
//и возвращает -1, если очередь переполнена

int push(int a)
{
    if(n!=QUEUE_SIZE)
    {
        n++;
        size_t current_index=in;
        in=next(in);
        return queue[current_index]=a;
    }
    else
    {
        return -1;
    }

}

//Функция забирает первое число в очереди, если там есть числа, и возвращает -1,
//если очередь пуста
int pop(void)
{
    //проверка есть ли в очереди числа
    if(n)
    {
       size_t cur_index=out;
       out=next(out);
       n--;
       return queue[cur_index];
    }
    else
    {
        return -1;
    }
}

int main()
{
    printf("Program is started\n" );
    init();
    printf("-------calling the show() \"queue is empty\"--------\n" );
    show();
    printf("-------calling the pop() \"queue is empty\"--------\n" );
    printf("pop() return:%d\n", pop() );
    printf("-------calling the push(5)--------\n" );
    printf("push(5) return:%d\n", push(5));
    printf("-------calling the show()  \"queue isn`t empty\"--------\n" );
    show();
    printf("-------calling init() and then calling the push(i) (QUEUE_SIZE+1) times--------\n" );
    init();
    for (size_t i=0; i<QUEUE_SIZE+1; i++)
    {
        printf("Call number:%d\tpush(i) return:%d\n", i, push((i+1)*2) );
    }
    printf("-------calling the show()  \"queue isn`t empty\"--------\n" );
    show();
    printf("-------calling the pop() \"queue isn`t empty\"--------\n" );
    printf("pop() return:%d\n", pop() );
    printf("-------calling the show()  \"queue isn`t empty\"--------\n" );
    show();
    printf("-------calling the push(999) and show()--------\n" );
    push(999);
    show();

    return 0;
}
