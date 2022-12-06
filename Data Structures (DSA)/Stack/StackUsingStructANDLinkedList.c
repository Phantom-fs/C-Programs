//Menu based program on Stack Using struct (Linked List)
//Push, Pop, Display, Peek, Count
//coder: Phantom-fs


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Stack using linked list
typedef struct stack
{
    int data;
    struct stack *next;
} stack;

//creating a stack pointer top, which will point to stack we will create (currently empty)
stack *top = NULL;

//function to check if stack is empty
int isEmpty ()
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

//fuction to check if stack is full
int isFull ()
{
    stack *temp = (stack *)malloc(sizeof(stack));
    if (temp == NULL)
    {
        return 1;
    }
    return 0;
}

//function to push an element in stack
void push (int data)
{
    //if stack is full
    if (isFull())
    {
        printf("\nStack is full\n");
        return;
    }

    //if stack is not full
    stack *temp = (stack *)malloc(sizeof(stack));
    temp->data = data;
    temp->next = top;
    top = temp;
}

//function to pop an element from stack
void pop ()
{
    int data;

    //if stack is empty
    if (isEmpty())
    {
        printf("\nStack is empty\n");
        return;
    }

    //if stack is not empty
    data = top->data;
    top = top->next;
    printf("\n%d is popped from stack\n", data);
}

//function to display stack
void display ()
{
    stack *temp = top;

    //if stack is empty
    if (isEmpty())
    {
        printf("\nStack is empty\n");
        return;
    }

    //if stack is not empty
    printf("\nStack is: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//peek function
void peek ()
{
    //if stack is empty
    if (isEmpty())
    {
        printf("\nStack is empty\n");
        return;
    }

    //if stack is not empty
    printf("\nTop element is: %d", top->data);
}

//count function
int count ()
{
    int count = 0;
    stack *temp = top;

    //if stack is empty
    if (isEmpty())
    {
        return 0;
    }

    //if stack is not empty
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

int main()
{
    int choice, data;

    while (1)
    {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Peek");
        printf("\n5. Count");
        printf("\n6. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        printf("\n");

        switch (choice)
        {
            case 1:
                printf("\nEnter data: ");
                scanf("%d", &data);
                push(data);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                peek();
                break;

            case 5:
                printf("\nCount is: %d", count());
                break;

            case 6:
                exit(0);

            default:
                printf("\nInvalid choice\n");
        }

        printf("\n");
        sleep(2);
    }

    return 0;
}
