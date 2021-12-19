#ifndef SEMANTICS_H
#define SEMANTICS_H
#include "ast.h"


void printError(int errorType, int ln, int t1, int t2, symbol_ref * symbol);
int checkSemantics(void* ast);
int* get_params_type(params_list* ast);
int get_numer_type(params_list* ast);

#endif