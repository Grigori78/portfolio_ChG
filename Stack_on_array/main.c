#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10


int stack[STACK_SIZE];


size_t index_of_last_element=0;

void init (void)
{
    index_of_last_element=0;
}
void show(void)
{


        for(size_t i=0; i<index_of_last_element;i++ )
        {
            printf("%d\t%d\n", i, stack[i] );
        }
        if(!index_of_last_element)
        {
            printf(" Stack is empty\n" );
        }

}
int push(int a)
{
    if(index_of_last_element<STACK_SIZE)
    {

        return stack[index_of_last_element++]=a;
    }
    else
    {
        return -1;
    }

}
int pop(void)
{
    //проверка есть ли в очереди числа
    if(index_of_last_element)
    {
       return stack[--index_of_last_element];
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
    printf("-------calling the show() \"stack is empty\"--------\n" );
    show();
    printf("-------calling the pop() \"stack is empty\"--------\n" );
    printf("pop() return:%d\n", pop() );
    printf("-------calling the push(5)--------\n" );
    printf("push(5) return:%d\n", push(5));
    printf("-------calling the show()  \"stack isn`t empty\"--------\n" );
    show();
    printf("-------calling init() and then calling the push(i) (STACK_SIZE+1) times--------\n" );
    init();
    printf("STACK_SIZE:%d\n", STACK_SIZE);
    for (size_t i=0; i<STACK_SIZE+1; i++)
    {
        printf("Call number:%d\tpush(i) return:%d\n", i, push(i*2+1) );
    }
    printf("-------calling the show()  \"stack isn`t empty\"--------\n" );
    show();
    printf("-------calling the pop() \"stack isn`t empty\"--------\n" );
    printf("pop() return:%d\n", pop() );
    printf("-------calling the show()  \"stack isn`t empty\"--------\n" );
    show();
    printf("-------calling the push(999) and show()--------\n" );
    push(999);
    show();

    return 0;
}
