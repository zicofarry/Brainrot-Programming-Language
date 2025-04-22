#include "parser.h"
#include "../lexer/lexer.h"

// prosedur untuk melakukan parsing tiap barisnya
void mainParser(char* line){
    start(line);
    if (line[0] == '\0' || strcmp(getcw(), "") == 0) return;
    if(strcmp(getcw(), "skibidi") == 0) skibidi(line);
    else if(strcmp(getcw(), "skibidiToilet") == 0) skibidiToilet(line);
    else if (strcmp(getcw(), "sigma") == 0) sigma(line);
    else if (strcmp(getcw(), "sigmaBoy") == 0) sigmaBoy(line);
    else if (strcmp(getcw(), "gyatt") == 0) gyatt(line);
    else if(strcmp(getcw(), "bombaclat") == 0) bombaclat(line);
    else if(strcmp(getcw(), "tungtungtung") == 0) tungtungtung(line);
    else if(strcmp(getcw(), "lingaguliguli") == 0) lingaguliguli(line);
    else if(strcmp(getcw(), "goofy") == 0) goofy(line);
    else if(strcmp(getcw(), "sus") == 0) sus(line);
    else if(strcmp(getcw(), "ahh") == 0) ahh(line);
    else if (strstr(line, "bruh") != NULL) strcpy(line, "break;");
    else if (strstr(line, "unpause") != NULL) strcpy(line, "continue;");
    else if(strcmp(getcw(), "stahp") == 0) strcpy(line, "}");
    else if (strstr(line, "is") != NULL) parseAssignment(line);
    else if (strstr(line, "aura") != NULL) parserAuraOperation(line);
    else if(strcmp(getcw(), "danYappp") == 0) line[0] = '\0';
    else sprintf(line, "// ERROR: keyword tidak dikenali");
}
