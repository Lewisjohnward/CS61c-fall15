
#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

#include "beargit.h"

void print_argv(int argc, char *argv[])
{
    int i = 0;
    do
    {
        printf("%s\n", argv[i]);
        i++;
    } while(i < argc);
}

void check_argc(int argc)
{
    if (argc <= 1)
    {
        fprintf(stderr, "Incorrect number of args usage beargit <command>\n");
        exit(1);
    }
}

void assign_functionality(int argc, char *argv[], int *functionality)
{
    //0 init
    //1 status
    //2 rm
    //3 commit
    //4 log
    if(!strcmp("init", argv[1]))
        *functionality = 0;
    else if(!strcmp("add", argv[1]))
        *functionality = 1;
    else
    {
        printf("Error usage: beargit <command>\n");
        exit(1);
    }
}

int main (int argc, char* argv[])
{
    int functionality;
    //print_argv(argc, argv);

    assign_functionality(argc, argv, &functionality);
    if(functionality != 1) check_argc(argc);
    char filename[] = "mynamejeff.txt";

    if(functionality != 0 && !check_init())
    {
        printf("Init beargit first\n");
        exit(0);
    }

    switch(functionality)
    {
        case 0:
            beargit_init();
        case 1:
            beargit_add(argv[2]);
    }
    return 0;
}
