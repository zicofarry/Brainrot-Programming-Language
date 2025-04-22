#include "parser.h"

// prosedur untuk memparsing lexeme aura
void parserAuraOperation(char pita[]){
    start(pita);

    char varname[100];
    strcpy(varname, getcw()); // ambil nama variabel

    inc(pita); // ke token kedua (operator+angka)
    char opAndNum[100];
    strcpy(opAndNum, getcw());

    char op = opAndNum[0]; // '+' atau '-'
    int val = atoi(&opAndNum[1]); // ambil angkanya

    inc(pita); // ke token 'aura'
    if(strcmp(getcw(), "aura") == 0){
        if(op == '+'){
            sprintf(pita, "%s += %d;", varname, val);
        }else if(op == '-'){
            sprintf(pita, "%s -= %d;", varname, val);
        }else{
            sprintf(pita, "// ERROR: operator aura tidak dikenali: %c", op);
        }
    }else{
        sprintf(pita, "// ERROR: harus ada keyword 'aura'!");
    }
}