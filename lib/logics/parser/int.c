#include "parser.h"
#include "../lexer/lexer.h"

// prosedur untuk memproses token tipe data int
void skibidi(char* line){
    start(line);
    inc(line);
    char var_name[100];
    strcpy(var_name, getcw());
    char* tipe = "int";
    addVariable(var_name, tipe);
    
    inc(line);
    if(strcmp(getcw(), "is") == 0){ // jika deklarasi mengandung inisialisasi
        inc(line);
        char rhs[256] = "";
        // gabungkan semua token setelah 'is' sampai akhir baris
        while(!eop(line)){
            if (strlen(rhs) > 0) strcat(rhs, " ");
            strcat(rhs, getcw());
            inc(line);
        }
        if(strlen(rhs) > 0) strcat(rhs, " ");
        strcat(rhs, getcw());
        
        // validasi ekspresi aritmatika dalam rhs
        char temp[256];
        strcpy(temp, rhs);
        char* token = strtok(temp, " +-*/()%%");
        sprintf(line, "int %s = %s;", var_name, rhs);
    }else{ // jika hanya deklarasi
        sprintf(line, "int %s;", var_name);
    }
}