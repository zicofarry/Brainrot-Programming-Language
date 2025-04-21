#ifndef LEXER_H
#define LEXER_H
#include <stdio.h>   // deklarasi library yang akan digunakan
#include <string.h>  // deklarasi library yang akan digunakan
#include <ctype.h>  // deklarasi library yang akan digunakan
#define RED     "\033[1;31m"
#define GREEN   "\033[0;32m"
#define WHITE   "\033[97m"
#define RESET   "\033[0m"
#define typename(x) _Generic((x), \
    int: "int", \
    float: "float", \
    double: "double", \
    char: "char", \
    char*: "char*", \
    default: "unknown")

// typedef untuk menyimpan tipe data dari variabel
typedef struct {
    char name[50]; // nama variabel
    char type[10]; // jenis tipe data
} Variable;

// Token types
typedef enum {
    DATA_TYPE,
    INTEGER_NUM,
    FLOAT_NUM,
    CHAR,
    STRING,
    VARIABLE,
    ASSIGNMENT,
    OPERATOR,
    FUNCTION,
    IDENTIFIER,
    KEYWORD,
    OPEN_COL,
    CLOSE_COL,
    TOKEN_EOP,
    UNKNOWN
} TokenType;

// Struct untuk menyimpan informasi token
typedef struct {
    char lexeme[101];    // isi kata/token
    TokenType type;      // tipe token
    int line;            // baris token
    int column;          // kolom awal token
} TokenInfo;


// DEKLARASI VARIABEL GLOBAL

// menyimpan variabel
extern Variable variables[100];
extern int var_count;

// mesin karakter
extern int idx;                // Index dari karakter terakhir pada kata
extern int wlen;               // Panjang kata (word length)
extern char cc;                // Karakter saat ini (current character)

// mesin kata
extern char cw[51];            // Kata saat ini (current word)
extern char tape[1025];         // Pita Masukan

// mesin baris
extern char lines[200][1025];  // Maks 200 baris, masing-masing maksimal 1024 karakter
extern int line_count;    // Total jumlah baris
extern int curr_line;     // Baris saat ini

// tokenize 
extern int error;

// mesin karakter
int EOP();
void START(char pita[]);
void INC(char pita[]);
void DEC(char pita[]);
void ADV(char pita[]);
char GETCC();
int GETIdx();

// mesin kata
int eop(char pita[]);
void start(char pita[]);
void reset();
void inc(char pita[]);
void dec(char pita[]);
char* getcw();
int getlen();
int countw(char pita[]);
int wordnow(char pita[]);
int cekEOP(char pita[]);
int lastw(char pita[]);
int ctape(char pita[]);
void pisahtape(char pita[], char tmp[51][101]);
int is_single_word(const char *str);

// mesin baris
void pisahbaris(char pita[]);
void startLine();
void nextLine();
void prevLine();
int isLastLine();
char* getLine();

// read and write
void readFromStdin();
void read(char fileName[]);
void write(char fileName[]);


// Tambahkan variabel ke tabel
void addVariable(char* name, char* type);
char* getType(const char* name);


// Fungsi untuk mengenali tipe token dari lexeme
TokenType identifyTokenType(const char *lexeme);
const char* tokenTypeToString(TokenType type);
void tokenizeLine(const char* filename, char* line, int lineNumber);
void printToken(const char* filename, int lineNumber, int startCol, const char* token, TokenType type);

#endif