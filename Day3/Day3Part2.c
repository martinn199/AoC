#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    /*Define variables and constant*/
    int DATA_SIZE = 300;
    int DATA_LEN = 100;
    char data[DATA_SIZE];
    char elf1[DATA_SIZE][DATA_LEN];
    char elf2[DATA_SIZE][DATA_LEN];
    char elf3[DATA_SIZE][DATA_LEN];
    char c_elf1[DATA_LEN];
    char c_elf2[DATA_LEN];
    char c_elf3[DATA_LEN];
    int count = 0;
    int i = 0;
    int j = 0;
    int a = 0;
    int k1 = 0;
    int k2 = 0;
    int k3 = 0;
    int str = 0;
    int priority;
    int total_priorities = 0;

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
        /*Store every third line in an array of strings*/
        count = count + 1;
        if(count == 1){
            strcpy(elf1[i], data);
            i++;
        }
        else if(count == 2){
            strcpy(elf2[j], data);
            j++;
        }
        else if(count == 3){
            strcpy(elf3[a], data);
            a++;
            count = 0;
        }
    }
    /*Close the file*/
    fclose(fPointer);

    /*Loop through each string in the array of string*/
    for(str = 0; str < DATA_LEN; str++){
        /*Reset the priority in each iteration*/
        priority = 0;
        /*Copy the current string in the string of array*/
        strcpy(c_elf1, elf1[str]);
        strcpy(c_elf2, elf2[str]);
        strcpy(c_elf3, elf3[str]);

        /*Loop through each character in the string*/
        for(k1 = 0; c_elf1[k1] != '\0'; k1++){
            for(k2 = 0; c_elf2[k2] != '\0'; k2++){
                for(k3 = 0; c_elf3[k3] != '\0'; k3++){
                    /*Check if the character is equal in the three strings (lower case)*/
                    if(c_elf1[k1] == c_elf2[k2] && c_elf1[k1] == c_elf3[k3] && c_elf2[k2] == c_elf3[k3] && islower(c_elf1[k1])){
                        priority += c_elf1[k1] - 'a' + 1;
                        break;
                    }
                    /*Check if the character is equal in the three strings (upper case)*/
                    else if(c_elf1[k1] == c_elf2[k2] && c_elf1[k1] == c_elf3[k3] && c_elf2[k2] == c_elf3[k3] && isupper(c_elf1[k1])){
                        priority += c_elf1[k1] - 'A' + 27;
                        break;
                    }
                }
                if(priority != 0){
                    break;
                }
            }
            if(priority != 0){
                break;
            }
        }
        /*Calculate the total priorities*/
        total_priorities += priority;
    }
    printf("Total priority is: %d\n", total_priorities);
    return 0;
}