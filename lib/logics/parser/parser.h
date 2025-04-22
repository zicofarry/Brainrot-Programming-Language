#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../lexer/lexer.h"

// Deklarasi prosedur 
void mainParser(char* line);                                            // untuk memproses string baris menjadi bahasa c (parsing)
void parserOperator(char *token, char* str);                            // untuk memparsing operator
void parserStrcmp(char* left, char* op, char* right, char* result);     // untuk memparsing operator (untuk string)
void parserAuraOperation(char pita[]);                                  // untuk parsing aura (increment/ decrement)
void parseAssignment(char* line);                                       // untuk memparsing assignment
void skibidi(char* line);                                               // untuk memparsing token tipe data int
void skibidiToilet(char* line);                                         // untuk memparsing token tipe data float
void sigma(char* line);                                                 // untuk memparsing token tipe data char
void sigmaBoy(char* line);                                              // untuk memparsing token tipe data string
void gyatt(char* line);                                                 // untuk memparsing token fungsi scanf
void bombaclat(char* line);                                             // untuk memparsing token fungsi printf
void tungtungtung(char* line);                                          // untuk memparsing token keyword for
void lingaguliguli(char* line);                                         // untuk memparsing token keyword while
void goofy(char* line);                                                 // untuk memparsing token keyword if
void sus(char* line);                                                   // untuk memparsing token keyword else if
void ahh(char* line);                                                   // untuk memparsing token keyword else
