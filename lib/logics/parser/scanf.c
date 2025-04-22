#include "parser.h"
#include "../lexer/lexer.h"

// prosedur untuk memproses token fungsi scanf
void gyatt(char* line){
    char formatStr[1025] = "";
    char args[1025] = "";
    char temp[1025] = "";
    int isFirstArg = 1;

    START(line);
    for(int i = 0; i < 5; i++) ADV(line); // skip "gyatt"

    while(!EOP()){
        while(cc == ' ' && !EOP()) INC(line);

        if(cc == '+'){
            INC(line); // skip '+'
            continue;
        }

        int i = 0;
        while(cc != ' ' && cc != '+' && !EOP()){
            temp[i++] = cc;
            INC(line);
        }
        temp[i] = '\0';

        char* tipe = getType(temp);
        if(tipe == NULL){
            printf("Error: variabel '%s' belum dideklarasikan!\n", temp);
            return;
        }

        // tambahkan spasi sebelum format jika bukan yang pertama
        if(!isFirstArg) strcat(formatStr, " ");
        if(strcmp(tipe, "int") == 0) strcat(formatStr, "%d");
        else if(strcmp(tipe, "float") == 0) strcat(formatStr, "%f");
        else if(strcmp(tipe, "char") == 0) strcat(formatStr, " %c");
        else if(strcmp(tipe, "string") == 0) strcat(formatStr, "%s");

        if(isFirstArg){
            if(strcmp(tipe, "string") == 0)
                sprintf(args, "%s", temp);
            else
                sprintf(args, "&%s", temp);
            isFirstArg = 0;
        }else{
            strcat(args, ", ");
            if(strcmp(tipe, "string") == 0)
                strcat(args, temp);
            else{
                strcat(args, "&");
                strcat(args, temp);
            }
        }
    }

    if(strlen(args) > 0){
        sprintf(line, "scanf(\"%s\", %s);", formatStr, args);
    }else{
        printf("Error: tidak ada variabel untuk diproses oleh gyatt!\n");
    }
}