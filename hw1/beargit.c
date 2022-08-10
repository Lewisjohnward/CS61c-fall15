#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <error.h>
#include <sys/stat.h>
#include <sys/types.h>

int check_init()
{
    //Check not already initialised
    //Check that .beargit/ doesn't exist
    DIR *dir;
    struct dirent* d;
    if((dir = opendir("./.beargit")))
    {
        return 1;
    } else
        return 0;

}

void init(void)
{
    char subdir[] = ".beargit";
    char err_msg[] = "Beargit already initialised";

    if(check_init())
    {
        printf("%s\n", err_msg);
        exit(0);
    }

    mkdir(".beargit", 0777);
    chdir("./.beargit");
    
    FILE *fp;
    //.index contains a list of all currently tracked files, one per line, no diplicates
    //.prev contains the ID of the last commit, or 0.0 i there is no commit yet
    //Each .beargit/ID directory contains a copy of each tracked file (as well as the .index) at the time of the commit, a .msg file that contains the commit message(one line) and a .prev file that contains the commit _D of the previous commit.
    if(!(fp = fopen(".index", "w")))
    {
        printf("Error creating .index\n");
        exit(1);
    }
    fclose(fp);


    if(!(fp = fopen(".prev", "w")))
    {
        printf("Error creating .prev\n");
        exit(1);
    }
    fprintf(fp, "0000000000000000000000000000000000000000");
    fclose(fp);

    printf("Beargit successfully initialised!\n");
    exit(0);
}

int beargit_init(void)
{
    init();
}

int beargit_add(const char* filename)
{
    FILE *fp;
    //beargit add <filename>
    //to start trackign a file
    printf("BEARGIT ADD\n");
    printf("To add: %s\n", filename);

    //Check file exists
    struct stat buffer;
    if((stat(filename, &buffer)) == -1)
    {
        printf("Unable to locate %s\n", filename);
        exit(1);
    }



    if((fp = fopen("./.beargit/.index", "r+")) == 0)
    {
        printf("Error opening index\n");
        exit(1);
    }
    fprintf(fp, "%s\n", filename);

}

int beargit_rm(const char* filename)
{
    printf("placeholder\n");
}

int beargit_commit(const char* message)
{
    printf("placeholder\n");
}

int beargit_status()
{
    printf("placeholder\n");
}

int beargit_log()
{
    printf("placeholder\n");
}
