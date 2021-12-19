#ifndef IR_H
#define IR_H



int global_var_num = 0;
int global_line_num = 0;

//returns a new variable number as a string. I.E: "t5"
char* freshVar();

char* freshLabel();

//returns the generated TAC code
ir_vars* tacGeneration(void* ast);

#endif


