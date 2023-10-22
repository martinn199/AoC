#include <stdio.h>
#include <stdlib.h> 

/*This is Day 1 part 2. The code is the same as for Day 1 Part 1 except the code that
starts on line 45*/
int main()
{
    /*Read file*/
    FILE * fPointer;
    fPointer = fopen("//home//martin//AoC//Day1//input2.txt", "r");

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

    /*Initialize integers, used to find maximum calories. In Day 1 Part 2 I use maximum_calories1,
    maximum_calories2 and maximum_calories3 to store the three Elves that have the most calories*/
    int a = 0;
    int calories = 0; 
    int maximum_calories1 = 0; 
    int maximum_calories2 = 0;
    int maximum_calories3 = 0;

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
        /*Store the maximum calories and rank the calories*/
        if (calories > maximum_calories1){
            maximum_calories3 = maximum_calories2;
            maximum_calories2 = maximum_calories1;
            maximum_calories1 = calories;
        }
        else if(calories > maximum_calories2){
            maximum_calories3 = maximum_calories2;
            maximum_calories2 = calories;
        }
        else if(calories > maximum_calories3){
            maximum_calories3 = calories;
        }
        a++;

    }  
    /*Find the total calories of the three Elves that have the most calories*/
    printf("Maximum calories is: %d \n", maximum_calories1 + maximum_calories2 + maximum_calories3);
    return 0;
}