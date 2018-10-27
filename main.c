#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main()
{
    int lower_bound;
    int upper_bound;
    int array_length;
    int counter_length;

    printf("Enter the lowerbound integer: ");
    scanf("%d", &lower_bound);
    
    printf("\nEnter the upperbound integer: ");
    scanf("%d", &upper_bound);

    printf("\nHow many numbers would you like to generate? ");
    scanf("%d", &array_length);
    array_length--;

    counter_length = upper_bound - lower_bound + 1;

    int number_array[array_length];  /* This is the array that will hold all of the 30 random numbers */
    int counting_array[counter_length];  /* This array will be used to count the frequency of each number in number_array */
    int i;

    /* Sets each spot's value in counting_array to 0 */

    for(i = 0; i < counter_length; i++)
    {
        counting_array[i] = 0;
    }
    
    srand(time(0));

    printf("Here is a sequence of %d random numbers between %d and %d:\n  ", array_length + 1, lower_bound, upper_bound);

    /* This for loop fills the number_array with random integers */   

    for(i = 0; i < array_length + 1; i++)
    {
        number_array[i] = rand() % (upper_bound + 1 - lower_bound) + lower_bound;
        printf("%d ", number_array[i]);
    }

    printf("\n\nPrinting them backwards, that's:\n  ");
    
    /* This for loop prints the array backwards */

    for(i = array_length; i > -1; i--)
        printf("%d ", number_array[i]);

    printf("\n\n");

    /* This loop counts how many of each number there are in the array */

    for(i = 0; i < array_length + 1; i++)
        counting_array[number_array[i]]++;
    
    for(i = 0; i < counter_length + 1; i++)
    {
        switch(counting_array[i])
        {
            case 0: printf("There were no %d's\n", i);
                break;
            case 1: printf("There was only 1 %d\n", i);
                break;
            default: printf("There were %d %d's\n", counting_array[i], i);
        }
    }
}
