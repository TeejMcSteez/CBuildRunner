#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

char path[100];     


int main(int argc, char * argv[]) {
    //initializing path and filename
    GetCurrentDirectory(100, path); 
    char argInFilename[50];
    char * argument2 = path;
    //commands
    char argument1[] = {"gcc -o testScript "};
    char * testScript = {"\\testScript.exe"};
    char pause[] = "pause";
    char rm[] = "del ";//add remove function by adding "" around path (somehow)

    strcpy(argInFilename, argv[1]);
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
    

    printf("\n\nRunning File...\n\n**************************************************\n\n");

    system(argument2);

    printf("\n\n*******************************************\n\nFile ran, Closing Program...\n");

    //system(pause);

    return 0;
}