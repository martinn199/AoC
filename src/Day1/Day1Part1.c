#include <stdio.h>
#include <stdlib.h> 

int main()
{
    /*Read file*/
    FILE * fPointer;
    fPointer = fopen("src/Day1/input2.txt", "r");

    /*If there exist no file, return an error*/
    if (fPointer == NULL)
    {
        perror("opening input2.txt failed");
        return 1;
    }
    /*Number is used to store all the elements in the file*/
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

    /*Print the number of elements in the file*/
    printf("The number of elements in the file is: %d\n", i);

    /*Initialize integers, used to find maximum calories*/
    int a = 0;
    int calories = 0; 
    int maximum_calories = 0; 

    /*Loop through the file*/
    while(a < i)
    {
        calories = 0;
        /*Loop trough the elfs*/
        while(a < i && number[a] != 0)
        {
            calories +=number[a];
            a++;
        }
        /*Store maximum calories*/
        if (calories > maximum_calories)
        {
            maximum_calories = calories;
        }
        a++;

    }  
    /*Find maximum calories*/
    printf("Maximum calories is: %d \n", maximum_calories);
    return 0;
}