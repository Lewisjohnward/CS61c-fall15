
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


    for(int i = 0; i < count; i++)
    {
        fprintf(fp, "%s\n", file_names[i]);
        i++;
    }
