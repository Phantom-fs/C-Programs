//The Cuboid calculator using C
//Coder : Phantom-fs


#include <stdio.h>
#include <math.h>
#include <unistd.h>

int main ()
{
 double length = 0.00, breath = 0.00, height = 0.00, volume = 0.00, surface = 0.0, perimeter = 0.00, lateral = 0.00, diagonal = 0.00, facediagonal = 0.00;

 //double type data declaration of sqrt
 double sqrtdiagonal, sqrtface;

 printf("\n\nCuboid Calculator \n\n");

 //value 
 printf("Enter length, breath and height : ");
 scanf (" %lf%lf%lf", &length, &breath, &height);

 printf("........................................................ \n");
 printf("........................................................ \n");

 printf("LENGTH of cuboid : %.4lf \n", length);
 printf("BREATH of cuboid : %.4lf \n", breath);
 printf("HEIGHT of cuboid : %.4lf \n", height);

 printf("......................................................... \n");
 printf("......................................................... \n");

 sleep(2);
 printf("\n\n");

 //volume calculation
 volume = length * breath * height;

 //surface area calculation
 surface = 2 * length * breath + 2 * breath * height + 2 * length * height;

 //perimeter calculation
 perimeter = 4 * length + 4 * breath + 4 * height;

 //lateral surface area calculation
 lateral = 2 * length * height + 2 * breath * height;

 //space diagonals or just diagonals
 //l*l + b*b +h*h
 sqrtdiagonal = length * length + breath * breath + height * height;
 //sqrt calculator for space diagonal
 diagonal = sqrt(sqrtdiagonal);

 //face diagonals
 //l*l + b*b
 sqrtface = length * length + breath * breath;
 //sqrt calculator for face diagonal
 facediagonal = sqrt (sqrtface);


 //all final value displaying
 printf ("VOLUME of cuboid : %.4lf \n", volume);

 printf("......................................................... \n");

 printf ("PERIMETER of cuboid : %.4lf \n", perimeter);

 printf("......................................................... \n");

 printf ("SURFACE AREA of cuboid : %.4lf \n", surface);

 printf("......................................................... \n");

 printf ("LATERAL SURFACE AREA of cuboid : %.4lf \n", lateral);

 printf("......................................................... \n");

 printf ("LENGTH OF SPACE DIAGONALS of cuboid : %.4lf \n", diagonal);

 printf("......................................................... \n");

 printf ("LENGTH OF FACE DIAGONALS of cuboid : %.4lf \n", facediagonal);

 printf("......................................................... \n");

 sleep(2);
 printf("\n\n");

 return 0;

}
