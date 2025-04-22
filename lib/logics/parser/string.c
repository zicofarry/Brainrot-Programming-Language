#include "parser.h"
#include "../lexer/lexer.h"

// prosedur untuk memproses token tipe data string
void sigmaBoy(char* line){
    start(line);
    inc(line);
    char var_name[100];
    strcpy(var_name, getcw());
    char* tipe = "string";
    addVariable(var_name, tipe);

    inc(line);
    if(strcmp(getcw(), "is") == 0){
        inc(line);
        char* value = getcw();
        sprintf(line, "char %s[101]; strcpy(%s, \"%s\");", var_name, var_name, value);
    }else{
        sprintf(line, "char %s[101];", var_name);
    }
}