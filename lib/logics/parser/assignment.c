#include "parser.h"

// prosedur untuk memparsing assignment
void parseAssignment(char* line){
    start(line);
    char lhs[100], rhs[256] = "";
    strcpy(lhs, getcw());  // ambil variabel kiri
    char* tipeLHS = getType(lhs);

    inc(line); // ke 'is'
    inc(line); // gabungkan semua token setelah 'is' sampai akhir baris ('\0')
    while(!eop(line)){
        if (strlen(rhs) > 0) strcat(rhs, " ");
        strcat(rhs, getcw());
        inc(line);
    }
    if(strlen(rhs) > 0) strcat(rhs, " ");
    strcat(rhs, getcw());

    // validasi setiap token dalam ekspresi
    char temp[256];
    strcpy(temp, rhs);
    char* token = strtok(temp, " +-*/()%%");
    sprintf(line, "%s = %s;", lhs, rhs);
}