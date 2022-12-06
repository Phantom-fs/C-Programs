//find the address of the elements of the array 
//Coder : Phantom-fs

#include <stdio.h>
#include <unistd.h>

int main()
{
    int arr [100];
    int i = 0, j = 0;
    int SIZE;
    int *p = &arr[0];

    printf("\n************************************************************\n");

    printf("\n\nEnter the number of elements you wish to enter (MAX 100) : ");
    scanf("%d", &SIZE);

    printf("\nEnter the elements of the array : \n\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("Enter the element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\n\nThe elements of the array are : \n\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("Element %d : %d\n", i + 1, *(p+i));
    }

    printf("\n************************************************************\n");

    printf("\nThe Address of the elements of the array is : \n\n");

    for(i = 0; i < SIZE; i++)
    {
        printf("Address of element %d : %p\n", i + 1, (p+i));
    }

    sleep(2);

    printf("\n************************************************************\n");

    return 0;    
}
