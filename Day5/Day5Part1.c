#include <stdio.h>
#include <string.h>

int main(){
    /*Open the file*/
    FILE * fPointer;
    fPointer = fopen("//home//martin//AoC//Day5//input.txt", "r");

    /*If there exist no file, return an error*/
    if (fPointer == NULL){
        perror("opening input.txt failed");
        return 1;
    }
    /*Close the file*/
    fclose(fPointer);
    return 0;
}