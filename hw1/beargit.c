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

void check_init()
{
    //Check not already initialised
    //Check that .beargit/ doesn't exist
    DIR *dir;
    struct dirent* d;
    char err_msg[] = "Beargit already initialised";
    if((dir = opendir("./.beargit")))
    {
        printf("%s\n", err_msg);
        exit(1);
    }
}

void init(void)
{
    char subdir[] = ".beargit";
    check_init();

    //Create a list of file names
    DIR* dir;
    struct dirent* d;
    if(!(dir = opendir(".")))
    {
        printf("Error opening dir\n");
        exit(1);
    }

    //Error potential only tracks up to 100 files
    char *file_names[100];

    int count = 0;
    while((d = readdir(dir)) != NULL)
    {
        if(d->d_name[0] == '.') continue;
        if(d->d_type == 4) continue;
        file_names[count] = (char*) malloc((strlen(d->d_name) + 1) * sizeof(char));
        strcpy(file_names[count], d->d_name);
        count++;
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

    for(int i = 0; i < count; i++)
    {
        fprintf(fp, "%s\n", file_names[i]);
        i++;
    }
    fclose(fp);


    if(!(fp = fopen(".prev", "w")))
    {
        printf("Error creating .prev\n");
        exit(1);
    }
    fprintf(fp, "0..0");
    fclose(fp);

    printf("Beargit successfully initialised!\n");
    

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
