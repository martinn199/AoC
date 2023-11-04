#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

/*Define constants*/
#define MAX_SIZE_DIR 100000
#define TOT_NUMBER_DIR 1000
#define MAX_DATA_SIZE 1050
#define FREE_UP_SIZE 40000000

/*Define global variables*/
static int sum_dir_size = 0;
static int sizes_dir[TOT_NUMBER_DIR] = {0};
static int dir = 0;

/*Define local variables*/
int sum_small_dir = 0;
int i = 0;
int size_dir = 0;
int delete_size;
int k;
int smallest_dir_delete;
char line[MAX_DATA_SIZE];
bool delete_found;

/*Recursive function that loops through the file system*/
void FileSystem(FILE *fPointer) {
    int j = dir;
    dir++;

    /*Loop through each line in the data file and check what the character is*/
    while (fgets(line, sizeof(line), fPointer) != NULL){
        if (line[0] == '$'){
            if (line[2] == 'c'){
                if (line[5] == '.'){
                    return;
                } 
                else if(line[5] == '/'){
                    continue;
                }
                else{
                    /*If the caracter is: "cd x", run the function again*/
                    FileSystem(fPointer);

                    /*Set the outermost directory to the sum of all directories size*/
                    if(feof(fPointer)){
                        sizes_dir[0] = sum_dir_size;
                    }
                    /*Update the size of each directory*/
                    else{
                        sizes_dir[j] += sizes_dir[j + 1];
                    }
                }
            }
        }
        /*If the line is a number, store it and add it to the size of the directory and to the sum of all directories size*/
        else if (isdigit(line[0])){
            sscanf(line, "%d", &size_dir);
            sum_dir_size += size_dir;
            sizes_dir[j] += size_dir;
        }
        /*If the line is: "dir x", continue to the next line*/
        else{
            continue;
        }
    }
}

int main() {

    /*Open the file*/
    FILE *fPointer;
    fPointer = fopen("Day7/input.txt", "r");

    /*If there exist no file, return an error*/
    if (fPointer == NULL) {
        perror("opening input.txt failed");
        return 1;
    }

    /*Run the function*/
    FileSystem(fPointer);

    /*Close the file*/
    fclose(fPointer);

    /*Find the sum of directories that have a total size of at most 100000*/
    while(i < TOT_NUMBER_DIR){
        if(sizes_dir[i] <= MAX_SIZE_DIR){
            sum_small_dir += sizes_dir[i];
        }
        i++;
    }

    /* ******************** Part 2 ******************** */
    /*The size that needs to be deleted is*/
    delete_size = sum_dir_size - FREE_UP_SIZE;

    /*In the beginning we have not found the directory to delete*/
    delete_found = false;

    /*Loop through the file system, but not the outermost directory, and find the smallest directory that can be deleted*/
    for(k = 1; k < TOT_NUMBER_DIR; k++){
        if(sizes_dir[k] >= delete_size){
            if(!delete_found || sizes_dir[k] < smallest_dir_delete){
                smallest_dir_delete = sizes_dir[k];
                delete_found = true;
            }
        }
    }
    
    /*Print the result*/
    printf("The total size of the directory that should be deleted is: %d\n", smallest_dir_delete);
    
    return 0;
}
