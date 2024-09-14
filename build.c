//testing on how to use git
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

char path[100] = {"\""};     

int main(int argc, char * argv[]) {
    //initializing path and filename
    GetCurrentDirectory(100, path);
    

    char argInFilename[50];
    char * argument2 = path;
    //commands
    char argument1[] = {"gcc -o test "};
    char * testScript = {"\\test.exe"};
    char pause[] = "pause";
    //first quotation mark added on initialization & last added and the end of mains
    char rm[] = {"\"del "};
    char * noRun = {"-n"};
    char * help = {"-h"};
    char argument3[4];

    strcpy(argInFilename, argv[1]);
    //checks if user asked for help
    if (strcmp(help, argv[1]) == 0) {
        printf("\nTeej's C executable builder\nSimply type build _filename_ to build, execute, and remove executable for testing\nUse -n to just compiled script");
        return 0;
    }
    //if chose no run cpy argument  
    if (argc ==  3) {
        strcpy(argument3, argv[2]);
    }
    //make sure the argument has a filename if it is not -h or > 3
    if (argc < 2) {
        printf("\nERROR! No filename given . . .\nClosing Builder . . .");
        return 0;
    }
    //if > 4 to many arguments for use
    if (argc > 3) {
        printf("\nERROR! To many arguments . . .\nClosing Builder . . .");
        return 0;
    } 

    strcat(path, testScript);
    strcat(argument1, argInFilename);

    printf("Running Build Script\n\n");

    if (system(argument1) == 0) {
        //continues normally
    } else {
        printf("\nError Occured! Oopsie, Check your code 4 bugs\n");
        return 0;
    }
    printf("Compiled successfully!\n");

   if (argc == 3) {
        if (strcmp(noRun, argv[2]) == 0) {
            printf("Selected No Run . . . Cleaning up builder . . .");
            return 0;
        } 
        if (strcmp(noRun, argv[2]) != 0) {
            printf("Error Occured! Invalid Input . . . Cleaning up builder . . .");
            return 0;
        }
   }

    printf("\n\nRunning File. . .\n\n**************************************************\n\n");

    if (system(argument2) == 0) {
        //continues normally
    } else {
        printf("\nError Occured! Oopsie, Check your code 4 bugs\n");
        return 0;
    }

    printf("\n\n*******************************************\n\nFile ran, Closing Program. . .\n");

    system(pause);
    //adds quotation marks around path to use windows del command
    strcat(path, "\"");
    strcat(rm, path);
    //removes testScript
    system(rm);
    printf("\nDeleting file and cleaning up builder. . .");

    return 0;
}
