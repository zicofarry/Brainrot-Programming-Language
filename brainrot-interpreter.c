#include "lib/logics/lexer/lexer.h"
#include "lib/logics/parser/parser.h"

// kalau kamu mau ngoding di cmd, uncomment kode di bawah, dan int main yang arg sampe read, jadiin komen atau hapus aja    
// int main(){
//     readFromStdin();

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <brainrot-file>\n", argv[0]);
        return 1;
    }
    read(argv[1]);

    pisahbaris(tape);
    tape[0] = '\0';
    startLine();
    while (1) {
        // tokenisasi baris sebelum parsing
        tokenizeLine(argv[1], getLine(), curr_line + 1);

        // parsing line yang kita miliki dengan memanggil prosedur mainParser
        mainParser(getLine());

        // setelah parsing dilakukan, simpan hasil parsing an ke dalam string tape
        strcat(tape, getLine());
        strcat(tape, "\n");

        // jika sudah line terakhir, break
        if (isLastLine()) break;

        nextLine();
    }

    if(!error){ // jika tidak ditemukan error
        printf(GREEN "Interpretation successful!\n" RESET); // print success
        write("bin/brainrot.c"); // write tape ke dalam file brainrot.c
        system("gcc bin/brainrot.c -o bin\\brainrot && bin\\brainrot"); // kompilasi file, dan langsung eksekusi
    }else{ // jika ditemukan error
        printf(RED "Interpretation failed!\n" RESET); // print failed
    }
    
    return 0;
}
