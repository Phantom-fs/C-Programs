//Menu based program on Stack Using Array
//Push, Pop, Display, Peek, Count
//coder: Phantom-fs


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Stack using array
int stack[100];
int top = -1;

//function to check if stack is empty
int isEmpty ()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

//function to check if stack is full
int isFull ()
{
    if (top == 99)
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
    top++;
    stack[top] = data;
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
    data = stack[top];
    top--;
    printf("\n%d is popped from stack\n", data);
}

//function to display stack
void display ()
{
    int i;
    if (isEmpty())
    {
        printf("\nStack is empty\n");
        return;
    }
    printf("\nStack is: ");
    for (i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }

}

//peek function
void peek ()
{
    if (isEmpty())
    {
        printf("\nStack is empty\n");
        return;
    }

    printf("\nTop element is: %d", stack[top]);
}

//number of elements in stack
int size ()
{
    return top + 1;
}

int main ()
{
    int choice, data;

    while (1)
    {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Peek");
        printf("\n5. Size");
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
                printf("\nSize of stack is: %d", size());
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
