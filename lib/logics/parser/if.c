#include "parser.h"
#include "../lexer/lexer.h"

// prosedur untuk memparsing token keyword if
void goofy(char* line){
    char output[256] = "";
    char temp[128];

    strcat(output, "if(");
    start(line);
    inc(line);

    while(1){
        char* token = getcw();
        int len = strlen(token);
        int is_last = 0;

        if(token[len - 1] == ':'){
            token[len - 1] = '\0'; // hapus :
            is_last = 1; // tandai bahwa ini token terakhir
        }

        if(getType(token) != NULL && strcmp(getType(token), "string") == 0){ // jika string
            char left[64], op[32], right[64];
            strcpy(left, token);
            inc(line);
            strcpy(op, getcw());
            inc(line);
            strcpy(right, getcw());
        
            if(right[strlen(right) - 1] == ':'){
                right[strlen(right) - 1] = '\0';
                is_last = 1;
            }
        
            parserStrcmp(left, op, right, temp); // panggilnya parser operator yang strcmp
            strcat(output, temp);
        }else{ // jika bukan string
            parserOperator(token, temp); // panggil parseOperator biasa
            strcat(output, temp);
        }
        
        if (is_last) break;
        inc(line);
    }

    strcat(output, "){");
    strcpy(line, output);
}