#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    /*Define variables and constant*/
    int DATA_SIZE = 100;
    char data[DATA_SIZE];
    char first_half[DATA_SIZE];
    char second_half[DATA_SIZE];
    char c_first_half;
    char c_second_half;
    int i;
    int j;
    int a;
    int found_character;
    int priority;
    int total_priorities;
    size_t length;
    size_t half_length;

    /*Open the file*/
    FILE * fPointer;
    fPointer = fopen("//home//martin//AoC//Day3//input.txt", "r");

    /*If there exist no file, return an error*/
    if (fPointer == NULL){
        perror("opening input.txt failed");
        return 1;
    }

    /*Loop though each line/string in the file*/
    while(fgets(data, DATA_SIZE, fPointer) !=NULL){
        /*Reset the priority between each line*/
        priority = 0;

        /*Calculate the length of each line*/
        length = strcspn(data, "\n");

        /*Divide the length by two since there are two compartments*/
        half_length = length/2;

        /*Copy the first half of the string*/
        strncpy(first_half, data, half_length);

        /*End the string at the middle*/
        first_half[half_length] = '\0';

        /*Copy the other half of the string*/
        strcpy(second_half, data + half_length); 

        /*Check for equal item in both compartments and calculate the priority*/
        for(j = 0; j < half_length; j++){
            c_first_half = first_half[j];
            /*Keep track of whether there is a character that is equal in both compartments*/
            found_character = 0;
            for(a = 0; a < half_length; a++){
                c_second_half = second_half[a];
                /*Check whether the characters are equal (lower case)*/
                if(c_first_half == c_second_half && islower(c_first_half) && islower(c_second_half)){
                    priority += c_second_half - 'a' + 1;
                    found_character = 1;
                    break;
                }
                /*Check whether the characters are equal (upper case)*/
                else if(c_first_half == c_second_half && isupper(c_first_half) && isupper(c_second_half)){
                    priority += c_second_half - 'A' + 27;
                    found_character = 1;
                    break;
                }
                /*If the characters are not equal*/
                else{
                    priority += 0;
                }
            }
            /*If there exist a character that is equal in both compartments, then break the loop
            and read next line/string in the file*/
            if(found_character){
                break;
            }
        }
        /*Sum the priorities*/
        total_priorities += priority; 
        i++;
    }
    /*Close the file*/
    fclose(fPointer);

    /*Print the total priorities*/
    printf("Total priorities is: %d\n", total_priorities);
    return 0;
}