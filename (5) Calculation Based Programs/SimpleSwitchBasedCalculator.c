//Option based simple calculator with fail safe methods
//Coder : Phantom-fs

#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

int main()
{
    char ch;
    float num1,num2,answer;

    printf("\n**************************************************************\n");

    printf("Enter the operation you want to perform\n");
    printf("a. Add\ts. Subtract\tm. Multiply\td. Divide\tq. Quit : ");

    while ((ch = getchar())!='q')
    {
        ch=tolower(ch);  //convert uppercase to the lowercase character

        if (ch=='\n')
            continue;

        else
        {
            switch(ch)  //switch command for different cases
            {

            //Addition
            case 'a':

                printf("Enter first number: ");

                while (scanf("%f",&num1)==0)
                {
                    printf("Invalid input. Please enter a number, such as 2.5, -1.78E8, or 3: ");   //for invalid input
                    scanf("%*s");
                }


                printf("Enter second number: ");
                while (scanf("%f",&num2)==0)
                {
                    printf("Invalid input. Please enter a number, such as 2.5, -1.78E8, or 3: ");   //for invalid input
                    scanf("%*s");
                }

                answer = num1 + num2;

                printf("%.3f + %.3f = %.3f\n", num1,num2,answer);
                break;


            //Subtraction
            case 's':
                printf("Enter first number: ");
                while (scanf("%f",&num1)==0)
                {
                    printf("Invalid input. Please enter a number, such as 2.5, -1.78E8, or 3: ");   //for invalid input
                    scanf("%*s");
                }
                printf("Enter second number: ");
                while (scanf("%f",&num2)==0)
                {
                    printf("Invalid input. Please enter a number, such as 2.5, -1.78E8, or 3: ");   //for invalid input
                    scanf("%*s");
                }
                answer = num1 - num2;
                printf("%.3f - %.3f = %.3f\n", num1,num2,answer);
                break;


            //Multiplication
            case 'm':
                printf("Enter first number: ");
                while (scanf("%f",&num1)==0)
                {
                    printf("Invalid input. Please enter a number, such as 2.5, -1.78E8, or 3: ");   //for invalid input
                    scanf("%*s");
                }
                printf("\nEnter second number: ");
                while (scanf("%f",&num2)==0)
                {
                    printf("Invalid input. Please enter a number, such as 2.5, -1.78E8, or 3: ");   //for invalid input
                    scanf("%*s");
                }
                answer = num1 * num2;
                printf("%.3f * %.3f = %.3f\n", num1,num2,answer);
                break;


            //Division
            case 'd':
                printf("\nEnter first number: ");
                while (scanf(" %f",&num1)==0)
                {
                    printf("\nInvalid input. Please enter a number, such as 2.5, -1.78E8, or 3: ");   //for invalid input
                    scanf("%*s");
                }
                printf("\nEnter second number: ");
                while (scanf(" %f",&num2)==0)
                {
                    printf("Invalid input. Please enter a number, such as 2.5, -1.78E8, or 3: ");   //for invalid input
                    scanf("%*s");
                }

                answer = num1 / num2;
                printf("\n%.3f / %.3f = %.3f\n", num1,num2,answer);
                break;

            //if value other than a, s, m, d & q is entered by the user
            default:
                printf("\nError, not a valid operation. Please try again!\n");
                break;
            }

            sleep(2);

        }

        printf("\n**************************************************************\n");

        printf("\nEnter the operation you want to perform\n");
        printf("a. Add \ts. Subtract \tm. Multiply \td. Divide \tq. Quit : ");
    }

 printf("\n**************************************************************\n");
 printf("                          Thank You!\n\n");
 return 0;

}

