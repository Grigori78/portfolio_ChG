#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int value;
    struct Item *next;
};
void init (struct Item **in, struct Item **out)
{
    struct Item *temp_add;
    while(*in)
    {
        temp_add=(**in).next;
        free(in);
        *in=temp_add;
    }
    (*out)=(*in);
}
int push(struct Item **in, struct Item **out, int a)
{
    if(*out==NULL)
    {

        *in=(struct Item*)malloc(sizeof(struct Item));
        (**in).next=*out;
        (*out)=(*in);
        return (**in).value=a;
    }
    else
    {
        struct Item *temp_item=(struct Item*)malloc(sizeof(struct Item));
        (*temp_item).next=(**in).next;
        (**in).next=temp_item;
        (*in)=temp_item;
        return (**in).value=a;
    }
}

void show (const struct Item *out)
{
    if(out==NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    while(out)
    {
        printf("Current number:%d\n", (*out).value);
        out=(*out).next;
    }
}
int pop(struct Item **out)
{
    if(*out==NULL)
    {
        return -1;
    }
    else
    {
     struct Item temp_add=(**out);
     free(*out);
     (*out)=temp_add.next;
     return temp_add.value;
    }
}
int main()
{
    struct Item *tail=NULL;
    struct Item *head=NULL;
    init(&head, &tail);
    printf("-----------init() and show() \"queue is empty\"----------\n");
    show(tail);

    printf("-------------pop()\"queue is empty\"----------\n");
    printf("pop return:%d\n", pop(&tail));

    printf("-------------push(6)----------\n");
    printf("push(6) return:%d\n", push(&head, &tail, 6));

    printf("-----------show() \"queue isn't empty\"----------\n");
    show(tail);

    printf("-------------push(i) 6 times and show()----------\n");
    for (size_t i=0; i<6; i++)
    {
         push(&head, &tail, 3*i+10);
    }
    show(tail);

    printf("-------------pop() and show()\"queue isn't empty\"----------\n");
    printf("pop return:%d\n\n", pop(&tail));
    show(tail);

     printf("-------------push(99) and show()----------\n");
    printf("push(99) return:%d\n\n", push(&head, &tail, 99));
    show(tail);

    printf("-------------pop() and show() 8 times----------\n");
    for (size_t i=0; i<8; i++)
    {
         printf("======%d========\n", i+1);
         printf("pop return:%d\n\n", pop(&tail));
         show(tail);
          printf("\n\n");
    }

    return 0;
}
