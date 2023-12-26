#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    /*Define variables and constant*/
    int DATA_SIZE = 1000;
    char data[DATA_SIZE];
    int number1;
    int number2;
    int number3;
    int number4;
    int total_assignments = 0;

    /*Open the file*/
    FILE * fPointer;
    fPointer = fopen("src/Day4//input.txt", "r");

    /*If there exist no file, return an error*/
    if (fPointer == NULL){
        perror("opening input.txt failed");
        return 1;
    }
    /*Loop through each line in the file*/
    while(fgets(data, DATA_SIZE, fPointer) !=NULL){
        
        /*Store the numbers in each line*/
        if(sscanf(data, "%d-%d,%d-%d", &number1, &number2, &number3, &number4) == 4){
            /*Print the numbers*/
            printf("Number 1: %d, Number 2: %d, Number 3: %d, Number 4: %d\n", number1, number2, number3, number4);
        }
        /*Check if there is a pair that contains the other pair*/
        if(number2 >= number3 && number4 >= number1){
            /*Sum these pairs*/
            total_assignments = total_assignments + 1;;
        }
        /*Do not include a pair that not contains the other pair at all*/
        else{
            total_assignments = total_assignments;
        }
    }
    /*Close the file*/
    /*Print the total assignments*/
    printf("Total assignments are: %d\n", total_assignments);
    fclose(fPointer);
    return 0;
}