#include "lib/logics/lexer/lexer.h"
#include "lib/logics/parser/parser.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <brainrot-file>\n", argv[0]);
        return 1;
    }

    read(argv[1]);

// kalau kamu mau ngoding di cmd, uncomment kode di bawah, dan int main diatas sampe read, jadiin komen atau hapus aja    
// int main(){
//     readFromStdin();

    pisahbaris(tape);
    tape[0] = '\0';
    startLine();
    while (1) {
        // Tokenisasi baris sebelum parsing
        tokenizeLine(argv[1], getLine(), curr_line + 1);
        mainParser(getLine());
        strcat(tape, getLine());
        strcat(tape, "\n");  // kalau tiap baris perlu dipisah newline

        if (isLastLine()) break;

        nextLine();
    }


    if(error == 0){
        printf(GREEN "Interpretation successful!\n" RESET);
        write("bin/brainrot.c");
        system("gcc bin/brainrot.c -o bin\\brainrot && bin\\brainrot");
    }else{
        printf(RED "Interpretation failed!\n" RESET);
    }
    
    return 0;
}
