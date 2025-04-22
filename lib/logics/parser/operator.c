#include "parser.h"

// prosedur untuk memproses token operator
void parserOperator(char *token, char* str){
    if(strcmp(token, "butAlso") == 0){
        strcpy(str, " && ");
    }else if(strcmp(token, "orNah") == 0){
        strcpy(str, " || ");
    }else if(strcmp(token, "peak") == 0){
        strcpy(str, " > ");
    }else if(strcmp(token, "mid") == 0){
        strcpy(str, " < ");
    }else if(strcmp(token, "mogged") == 0){
        strcpy(str, " >= ");
    }else if(strcmp(token, "cooked") == 0){
        strcpy(str, " <= ");
    }else if(strcmp(token, "match") == 0){
        strcpy(str, " == ");
    }else if(strcmp(token, "hitdiff") == 0){
        strcpy(str, " != ");
    }else{
        strcpy(str, token);
    }
}