#include "parser.h"

// prosedur untuk memproses token operator comparation, tapi untuk string
void parserStrcmp(char* left, char* op, char* right, char* result) {
    char cmp[16] = "";

    if (strcmp(op, "match") == 0) {
        strcpy(cmp, "==");
    } else if (strcmp(op, "hitdiff") == 0) {
        strcpy(cmp, "!=");
    } else if (strcmp(op, "peak") == 0) {
        strcpy(cmp, ">");
    } else if (strcmp(op, "mid") == 0) {
        strcpy(cmp, "<");
    } else if (strcmp(op, "mogged") == 0) {
        strcpy(cmp, ">=");
    } else if (strcmp(op, "cooked") == 0) {
        strcpy(cmp, "<=");
    } else {
        sprintf(result, "%s %s %s", left, op, right);
        return;
    }

    sprintf(result, "(strcmp(%s, %s) %s 0)", left, right, cmp);
}
