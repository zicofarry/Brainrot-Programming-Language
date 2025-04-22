#include "parser.h"
#include "../lexer/lexer.h"

// prosedur untuk memparsing tipe data char
void sigma(char* line){
    start(line);
    inc(line);
    char var_name[100];
    strcpy(var_name, getcw());
    char* tipe = "char";
    addVariable(var_name, tipe);

    inc(line);
    if (strcmp(getcw(), "is") == 0) {
        inc(line);
        char* value = getcw();
        sprintf(line, "char %s = '%s';", var_name, value);
    } else {
        sprintf(line, "char %s;", var_name);
    }
}