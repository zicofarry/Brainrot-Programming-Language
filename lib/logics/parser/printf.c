#include "parser.h"
#include "../lexer/lexer.h"

// prosedur untuk memproses token fungsi printf
void bombaclat(char* line){
    char formatStr[1025] = "";
    char args[1025] = "";
    char temp[1025] = "";
    int isFirstArg = 1;
    int noNewline = 0;

    START(line);
    for(int i = 0; i < 9; i++) ADV(line); // skip "bombaclat"

    // cek apakah ada "- bop" di akhir
    char* bopCheck = strstr(line, "- bop");
    if(bopCheck != NULL){
        noNewline = 1;
        // potong sebelum "- bop"
        bopCheck[-1] = '\0'; // hapus spasi sebelum -
    }

    while(!EOP()){
        while (cc == ' ' && !EOP()) INC(line);

        if(cc == '"'){
            INC(line);
            int i = 0;
            while(cc != '"' && !EOP()){
                temp[i++] = cc;
                INC(line);
            }
            temp[i] = '\0';
            INC(line);

            strcat(formatStr, temp);
        }else if(cc == '+'){
            INC(line);
            continue;
        }else{
            int i = 0;
            while (cc != ' ' && cc != '+' && !EOP()) {
                temp[i++] = cc;
                INC(line);
            }
            temp[i] = '\0';

            char* tipe = getType(temp);
            if(tipe == NULL){
                printf("Error: variabel '%s' belum dideklarasikan!\n", temp);
                return;
            }

            if(strcmp(tipe, "int") == 0) strcat(formatStr, "%d");
            else if(strcmp(tipe, "float") == 0) strcat(formatStr, "%.2f");
            else if(strcmp(tipe, "char") == 0) strcat(formatStr, "%c");
            else if(strcmp(tipe, "string") == 0) strcat(formatStr, "%s");

            if(isFirstArg){
                sprintf(args, "%s", temp);
                isFirstArg = 0;
            }else{
                strcat(args, ", ");
                strcat(args, temp);
            }
        }
    }

    if(strlen(args) > 0){
        if(noNewline) sprintf(line, "printf(\"%s\", %s);", formatStr, args);
        else sprintf(line, "printf(\"%s\\n\", %s);", formatStr, args);
    }else{
        if(noNewline) sprintf(line, "printf(\"%s\");", formatStr);
        else sprintf(line, "printf(\"%s\\n\");", formatStr);
    }
}