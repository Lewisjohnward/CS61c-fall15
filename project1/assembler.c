#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define $zero 0
#define $0 0
#define $at 1
#define $v0 2
#define $v1 3
#define $a0 4
#define $a1 5
#define $a2 6
#define $a3 7
#define $t0 8
#define $t1 9
#define $t2 10
#define $t3 11
#define $t4 12
#define $t5 13
#define $t6 14
#define $t7 15
#define $s0 16
#define $s1 17
#define $s2 18
#define $s3 19
#define $s4 20
#define $s5 21
#define $s6 22
#define $s7 23
#define $t8 24
#define $t9 25
#define $k0 26
#define $k1 27
#define $gp 28
#define $sp 29
#define $fp 30
#define $ra 31

//Only assembles text segment
//Strips comments
//Pseudo instructions are expanded
//Relocation table
//input & pseudo instruction validation
//Output wrote to .int file

char *remove_ws(char *str)
{
    int i = 0;
    int contains_ws = 0;
    char *new_str;
    while(str[i] != '\0')
    {
        if(str[i] == ' ') contains_ws = 1;
        i++;
    }

    if (!contains_ws) return str;

    int j = 0;
    new_str = (char*) malloc(sizeof(char) * i);
    i = 0;
    while(str[i] != '\0')
    {
        if(str[i] != ' ')
        {
            new_str[j] = str[i];
            j++;
        }
        i++;
    }
    new_str[j] = '\0';

    return new_str;
}


char *convert(char *str)
{
    char *conversion;
    if(!strcmp("addiu", str))
    {
        char conv[] = "001000";
        conversion = (char*) malloc(sizeof(char) * (strlen(conv) + 1));
        strcpy(conversion, conv);
    }
    else if (!strcmp("addu", str))
    {
        char conv[] = "100001";
        conversion = (char*) malloc(sizeof(char) * (strlen(conv) + 1));
        strcpy(conversion, conv);
    }
    else if(!strcmp("$t0", str))
    {
        char conv[] = "01000";
        conversion = (char*) malloc(sizeof(char) * (strlen(conv) + 1));
        strcpy(conversion, conv);
    }
    else if(!strcmp("$a0", str))
    {
        char conv[] = "00100";
        conversion = (char*) malloc(sizeof(char) * (strlen(conv) + 1));
        strcpy(conversion, conv);
    }
    else if(!strcmp("0", str))
    {
        char conv[] = "0000000000000000";
        conversion = (char*) malloc(sizeof(char) * (strlen(conv) + 1));
        strcpy(conversion, conv);
    }
    printf("%s", str);
    printf(" - ");
    printf("%s\n", conversion);
    return conversion;
}


void determine_format(int *type, int *fields, char *str)
{
    if(!strcmp("addu", str)) *type = 0;
    else if(!strcmp("or", str)) *type = 0;
    else if(!strcmp("slt", str)) *type = 0;
    else if(!strcmp("sltu", str)) *type = 0;
    else if(!strcmp("jr", str)) *type = 0;
    else if(!strcmp("sll", str)) *type = 0;
    else if(!strcmp("addiu", str)) *type = 1;
    else if(!strcmp("ori", str)) *type = 1;
    else if(!strcmp("lui", str)) *type = 1;
    else if(!strcmp("lb", str)) *type = 1;
    else if(!strcmp("lbu", str)) *type = 1;
    else if(!strcmp("lw", str)) *type = 1;
    else if(!strcmp("sb", str)) *type = 1;
    else if(!strcmp("sw", str)) *type = 1;
    else if(!strcmp("beq", str)) *type = 1;
    else if(!strcmp("bne", str)) *type = 1;
    else if(!strcmp("j", str)) *type = 2;
    else if(!strcmp("jal", str)) *type = 2;
    else printf("ERROR in determine_format\n");

    switch(*type)
    {
        case 0:
            *fields = 6;
            break;
        case 1:
            *fields = 4;
            break;
        case 2:
            *fields = 2;
            break;
    }
}


int main (void)
{
    char c;
    char *token;
    char *str_convert;
    char *instructions_to_convert[10];
    char *instructions[10];
    FILE *src_fd, *tg_fd;
    src_fd = fopen("./simple_instructions.s", "r");
    tg_fd = fopen("./intermediate.int", "w");

    

    //printf("%x\n", hexNum);

    char new_str[] = "addiu $t0, $a0, 0";

    token = strtok(new_str, " ");

    int count = 0;

    int type = 0;
    int format_unknown = 1;
    int opcode_converted = 0;
    int fields_to_convert = 0;

    while(token != NULL)
    {
        char *str;
        token = remove_ws(token);
        //str = (char*) malloc(sizeof(char) * strlen(token));
        //strcpy(str, token);

        instructions_to_convert[count] = token;

        if (format_unknown) 
        {
            determine_format(&type, &fields_to_convert, token);
            format_unknown = 0;
            printf("format: %d\n", type);
        }


        //instructions[count] = convert(token);

        //printf("%s\n", token);
        //printf("%s\n", str_convert);
        token = strtok(NULL, ",");
        count++;
    }

    
    for(int i = 0; i < count; i++)
        printf("%s\n", instructions_to_convert[i]);

    fclose(src_fd);
    fclose(tg_fd);
    return 0;
}
