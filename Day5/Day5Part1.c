#include <stdio.h>
#include <string.h>

int main(){
    /*Open the file*/
    int DATA_SIZE = 514;
    char data[DATA_SIZE];
    int i;
    FILE * fPointer;
    fPointer = fopen("Day5/input.txt", "r");

    /*If there exist no file, return an error*/
    if (fPointer == NULL){
        perror("opening input.txt failed");
        return 1;
    }

    while(fgets(data, DATA_SIZE, fPointer) !=NULL){
        /*Print each line in the file*/
        /*printf("%s", data);*/
    }
    /*Close the file*/
    fclose(fPointer);
    return 0;
}