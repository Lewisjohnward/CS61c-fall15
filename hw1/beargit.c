#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <error.h>
#include <sys/stat.h>
#include <sys/types.h>


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
    if (argc != 2)
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
    *functionality = 0;
}

void init(void)
{
    char subdir[] = ".beargit";
    char* err_msg = "Beargit already initialised";
    //Check not already initialised
    //Check that .beargit/ doesn't exist
    DIR *dir;
    FILE *fp;
    struct dirent* d;
    dir = opendir(".");
    while((d = readdir(dir)))
    {
        int cmp = strcmp(d->d_name, subdir);
        if(!cmp)
            error(1, 0, "%s", err_msg);
    }
    closedir(dir);
    mkdir(".beargit", 0777);
    chdir("./.beargit");
    //.index contains a list of all currently tracked files, one per line, no diplicates
    //.prev contains the ID of the last commit, or 0.0 i there is no commit yet
    //Each .beargit/ID directory contains a copy of each tracked file (as well as the .index) at the time of the commit, a .msg file that contains the commit message(one line) and a .prev file that contains the commit _D of the previous commit.
    fopen("test", "w");
    fp = fopen(".index", "w");
    fopen(".prev", "w");
}


int main (int argc, char *argv[])
{
    int functionality;
    //check_argc(argc);
    //print_argv(argc, argv);
    assign_functionality(argc, argv, &functionality);
    switch(functionality)
    {
        case 0:
            init();
    }
    return 0;
}
