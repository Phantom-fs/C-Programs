//Menu based program on Stack Using struct and Array built in it
//Push, Pop, Display, Peek, Count
//coder: Phantom-fs

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct stack
{
  int top;
  int size;
  int *arr;
} stack;

//creating a stack pointer
stack* s = NULL;

//create a stack
void createStack (int size)
{
  s = (stack *)malloc(sizeof(stack));
  s->top = -1;
  s->size = size;
  s->arr = (int *)malloc(s->size * sizeof(int));
}

//function to check if stack is empty
int isEmpty ()
{
  if (s->top == -1)
  {
    return 1;
  }

  return 0;
}

//fuction to check if stack is full
int isFull ()
{
  if (s->top == s->size - 1)
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
  s->top++;
  s->arr[s->top] = data;
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
  data = s->arr[s->top];
  s->top--;
  printf("\n%d is popped from stack\n", data);
}

//function to print stack
void display ()
{
  int i;

  if (isEmpty())
  {
    printf("\nStack is empty\n");
    return;
  }

  printf("\nStack is: ");

  for (i = s->top; i >= 0; i--)
  {
    printf("%d ", s->arr[i]);
  }

  printf("\n");
}

//peek function
void peek ()
{
  if (isEmpty())
  {
    printf("\nStack is empty\n");
    return;
  }

  printf("\nTop element is: %d\n", s->arr[s->top]);
}

//count elements
void count ()
{
  printf("\nNumber of elements in stack are: %d\n", s->top + 1);
}

int main()
{
    int choice, data;
    createStack(10);

    while(1)
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

        switch(choice)
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
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                count();
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
