#include <stdio.h>
#include <stdlib.h> 

int main()
{
    /*Read file*/
    FILE * fPointer;
    fPointer = fopen("//mnt//c//users//marti//Documents//Git//input2.txt", "r");

    /*If there exist no file, return an error*/
    if (fPointer == NULL)
    {
        perror("opening input2.txt failed");
        return 1;
    }
    /*Number is used to print the numbers in the file*/
    int number[2251];

    /*Create an character that has the same length as the file*/
    char character[2251];

    /*Initialize the length of the file*/
    int i = 0;

    /*Loop through the file*/
    while(fgets(character, sizeof(character), fPointer) !=NULL){
        /*Convert the character to a number*/
        number[i] = atoi(character);
        /*Increase the length by 1 for each iteration*/
        i++;
    }
    /*Close the file*/
    fclose(fPointer);

    /*Print the file*/
    int j;
    for(j = 0; j<sizeof(character); j++){
        printf("%d \n", number[j]);
    }

    /*Print the number elements in the file*/
    printf("The number of elements in the file is: %d\n", i);

    /*Sorts the file and prints the results*/
    int a = 0;
    int calories = 0; 
    int maximum_calories = 0; 
    while(a < i)
    {
        calories = 0;
        while(a < i && number[a] != 0)
        {
            calories +=number[a];
            a++;
        }
        if (calories > maximum_calories)
        {
            maximum_calories = calories;
        }
        a++;

    }  
    printf("Maximum calories %d \n", maximum_calories);
    return 0;
}