#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#include <stdlib.h>
#include <string.h>

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20070509

#define YYEMPTY (-1)
#define yyclearin    (yychar = YYEMPTY)
#define yyerrok      (yyerrflag = 0)
#define YYRECOVERING (yyerrflag != 0)

extern int yyparse(void);

static int yygrowstack(void);
#define YYPREFIX "yy"
#line 2 "parser.y"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ast.h"
#include "print_ast.h"
#include "symtab.h"

void yyerror(const char *c);

program* ast;

#line 17 "parser.y"
typedef union{
	char ch;
	char* str;
	int num;
	symbol_node* symbol;
	symbol_ref* ref;
	program* p;
	proc_list* pro_l;
	procedure_node* proc;
	params_list* params_l;
	symbol_list* symbol_l;
	params* param;
	body_node* body;
	var_dec_list* var_dec_l;
	var_decs* var_dec;
	assign* assign_;
	stmt* stmt_;
	stmt_list* stmt_l;
	code_block* block;
	fn_call* call;
	expr_list* expr_l;
	if_node* if_;
	if_else_node* if_else_;
	for_node* for_;
	while_node* while_;
	ret_stmt* ret;
	expr* exp;
	type* type_;
	lit* l;
	lit_integer* lit_i;
	lit_real* lit_real;
	lit_string* lit_s;
	lit_char* lit_c;
	lit_boolean* lit_b;
	lit_null* lit_n;					
	
} YYSTYPE;
#line 74 "y.tab.c"
#define NULL_LITERAL 257
#define KEY_PROCEDURE 258
#define KEY_VAR 259
#define KEY_CHARPTR 260
#define KEY_INTPTR 261
#define KEY_REALPTR 262
#define KEY_STRING 263
#define KEY_INTEGER 264
#define KEY_REAL 265
#define KEY_BOOLEAN 266
#define KEY_CHAR 267
#define KEY_ELSE 268
#define KEY_IF 269
#define KEY_RETURN 270
#define KEY_FOR 271
#define KEY_WHILE 272
#define OP_AND 273
#define OP_EQ 274
#define OP_GE 275
#define OP_LE 276
#define OP_NE 277
#define OP_OR 278
#define STRING_LITERAL 279
#define IDENTIFIER 280
#define KEY_VOID 281
#define CHAR_LITERAL 282
#define COMMA 283
#define COLON 284
#define DOT 285
#define SINGLE_QUOTE 286
#define QUOTE 287
#define SQ_BRA_C 288
#define SQ_BRA_O 289
#define PARAN_C 290
#define PARAN_O 291
#define SEMICOLON 292
#define BRA_C 293
#define BRA_O 294
#define OP_DEREFERENCE 295
#define OP_ADDRESS_OF 296
#define OP_MULTI 297
#define OP_PLUS 298
#define OP_NOT 299
#define OP_MINUS 300
#define OP_LT 301
#define OP_GT 302
#define ASSIGN 303
#define OP_DIV 304
#define OP_ABS 305
#define TRUE_LITERAL 306
#define FALSE_LITERAL 307
#define INTEGER_LITERAL 308
#define HEX_LITERAL 309
#define REAL_LITERAL 310
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    1,    1,    2,    3,    4,    5,    5,    5,    6,
    7,    7,    8,    9,    9,   10,   11,   11,   12,   12,
   12,   12,   12,   12,   13,   13,   13,   13,   13,   14,
   15,   16,   16,   16,   18,   17,   19,   20,   21,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
   23,   23,   23,   23,   23,   23,   23,   24,   24,   25,
   25,   25,   25,   25,   27,   28,   26,   26,   26,   29,
   29,
};
short yylen[] = {                                         2,
    1,    2,    0,    8,    1,    4,    1,    3,    0,    2,
    3,    1,    4,    2,    0,    4,    2,    0,    1,    1,
    1,    1,    1,    1,    4,    4,    5,    3,    3,    4,
    5,    3,    1,    0,    7,    5,    5,    5,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    2,    2,    2,    2,    3,    1,    3,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    4,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,
};
short yydefred[] = {                                      0,
   61,   62,   63,   64,   65,   66,   67,    0,    1,    0,
    0,    2,    5,    0,    0,    0,    0,    0,    0,    0,
    0,   10,    0,    8,    0,    0,    0,   11,    0,    0,
    0,    4,    0,   68,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   19,   24,   20,   21,   22,
   23,   14,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   13,   17,   77,   78,   79,    0,   16,
   74,   75,   76,    0,    0,    0,    0,    0,    0,   80,
   81,   57,   59,    0,   60,   71,   70,   72,   73,    0,
    0,    0,    0,    0,    0,   28,    0,   29,    0,    0,
   69,    0,   54,   55,   52,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    6,   30,    0,    0,   25,   26,   39,   58,
   56,    0,    0,    0,    0,    0,    0,    0,   42,    0,
    0,    0,    0,   43,   37,   38,   27,    0,    0,    0,
    0,    0,   35,   31,   32,
};
short yydgoto[] = {                                       8,
    9,   10,   82,   83,   16,   17,   22,   27,   30,   31,
   44,   45,   46,   47,   96,  148,   48,   49,   50,   51,
   64,  149,   11,   35,   85,   86,   87,   88,   89,
};
short yysindex[] = {                                    430,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  430,
 -249,    0,    0, -255,  430, -258, -243, -249, -254,  430,
 -222,    0,  430,    0, -249, -189, -206,    0,  412,  394,
 -189,    0, -217,    0, -249, -209, -190, -187, -183, -189,
 -249, -201, -196, -161,  394,    0,    0,    0,    0,    0,
    0,    0, -218, -173, -211, -211, -211, -211,  394, -182,
 -211, -211, -211,    0,    0,    0,    0,    0, -166,    0,
    0,    0,    0, -211, -211, -211, -211, -211, -211,    0,
    0,    0,    0,  147,    0,    0,    0,    0,    0,  165,
  183,  201, -164, -211, -160,    0,  217,    0,  249,  260,
    0,  292,    0,    0,    0, -221,  -12, -211, -211, -211,
 -211, -211, -211, -162, -211, -211, -211, -211, -211, -211,
 -162, -162,    0,    0,  303, -211,    0,    0,    0,    0,
    0,  354,  -45, -186, -186,  -45, -223, -133,    0, -221,
 -221, -186, -186,    0,    0,    0,    0, -151,  335, -162,
 -149, -211,    0,    0,    0,
};
short yyrindex[] = {                                    144,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,
    0,    0,    0,    0, -145,    0, -144,    0,    0, -145,
 -278,    0, -252,    0,    0,  390,    0,    0,    0, -121,
  -93,    0,    0,    0,    0,    0,    0,    0, -150,   11,
    0,    0,    0,    0, -259,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -131,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  346,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -117,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -127,    0,    0,    0,    0,
    0,  127,  104,   24,   44,  124, -175,  -60,    0,  -84,
  -51,   64,   84,    0,    0,    0,    0,    0, -126,    0,
    0, -127,    0,    0,    0,
};
short yygindex[] = {                                      0,
   25,    0,   75,  -30,  145,    0,  -19,    0,   -1,    0,
  -32,    0,    0,  -77,  105,   16,    0,    0,    0,    0,
    0,  -53,   18,    0,    0,  116,    0,    0,    0,
};
#define YYTABLESIZE 711
short yytable[] = {                                      43,
    3,   84,   90,   91,   92,   28,    3,   97,   99,  100,
   18,   12,   65,   12,   43,   54,    3,    3,    3,    3,
  102,  103,  104,  105,  106,  107,   93,    3,   43,   52,
   13,   19,   18,   18,   12,   15,  138,   18,   59,   23,
  125,    3,    3,  145,  146,   71,   34,   26,   20,  108,
  109,  110,  111,  112,  132,  133,  134,  135,  136,  137,
   25,  139,  140,  141,  142,  143,  144,   72,   39,   29,
   73,   53,  153,  115,  116,  115,  117,  118,  119,   74,
  120,   55,  120,   75,   76,   14,   32,   77,   78,   66,
   67,   68,   21,   79,   80,   81,   66,   67,   68,   21,
   56,   61,   45,   57,   42,   58,   62,   45,   63,   21,
  115,  116,   45,  117,   45,   60,   45,  120,   70,   42,
   94,  101,    5,    5,    5,    5,    5,    5,  124,   45,
  126,   40,    5,   42,  150,   95,   95,    5,  151,    5,
    5,    5,  154,    3,    9,    7,    5,    5,   18,    5,
    5,    5,    5,    5,    5,   53,   53,   53,   53,   53,
   53,   18,   34,   33,   24,   53,   98,  155,   69,    0,
   53,    0,   53,    0,   53,   15,   15,   15,   15,    0,
   53,    0,   53,   53,   53,    0,   15,   53,   40,   40,
   40,   40,   40,   40,    0,    0,    0,    0,   40,   15,
   15,   15,    0,   40,    0,   40,    0,   40,   36,   36,
   36,   36,    0,   40,    0,   40,   40,   40,    0,   36,
   40,   41,   41,   41,   41,   41,   41,    0,    0,  110,
  111,   41,   36,   36,   36,    0,   41,    0,   41,    0,
   41,    0,    0,    0,    0,    0,   41,    0,   41,   41,
   41,  115,  116,   41,  117,  118,  119,    0,  120,    3,
  108,  109,  110,  111,  112,  113,    0,    0,    0,    3,
    3,    3,    3,    0,    0,    0,    0,    0,    0,   15,
    3,   15,   15,    0,  115,  116,    0,  117,  118,  119,
   15,  120,  131,    0,    3,    3,   48,   48,   48,   48,
   48,   48,    0,   15,   15,   15,   48,    0,    0,    0,
    0,   48,    0,   48,    0,   48,   50,   50,   50,   50,
   50,   50,    0,    0,   48,   48,   50,    0,   48,    0,
    0,   50,    0,   50,    0,   50,   51,   51,   51,   51,
   51,   51,    0,    0,   50,   50,   51,    0,   50,    0,
    0,   51,    0,   51,    0,   51,   49,   49,   49,   49,
   49,   49,    0,    0,   51,   51,   49,    0,   51,    0,
    0,   49,    0,   49,    0,   49,   46,   46,    0,    0,
   46,   46,    0,    0,   49,   49,   46,    0,   49,    0,
    0,   46,    0,   46,    0,   46,   47,   47,    0,   44,
   47,   47,    0,    0,   44,    0,   47,    0,   46,   44,
    0,   47,    0,   47,   44,   47,   44,    0,   44,  108,
  109,  110,  111,  112,  113,    0,    0,    0,   47,    0,
    0,   44,    0,    0,    0,    0,  114,  108,  109,  110,
  111,  112,  113,  115,  116,    0,  117,  118,  119,    0,
  120,    0,    0,    0,  121,  108,  109,  110,  111,  112,
  113,  115,  116,    0,  117,  118,  119,    0,  120,    0,
    0,    0,  122,  108,  109,  110,  111,  112,  113,  115,
  116,    0,  117,  118,  119,    0,  120,    0,  123,  108,
  109,  110,  111,  112,  113,    0,    0,  115,  116,    0,
  117,  118,  119,    0,  120,    0,    0,    0,  127,    0,
    0,    0,    0,  115,  116,    0,  117,  118,  119,    0,
  120,  108,  109,  110,  111,  112,  113,    0,    0,    0,
    0,    0,  108,  109,  110,  111,  112,  113,    0,    0,
  128,    0,    0,    0,    0,  115,  116,    0,  117,  118,
  119,  129,  120,    0,    0,    0,  115,  116,    0,  117,
  118,  119,    0,  120,  108,  109,  110,  111,  112,  113,
    0,    0,    0,    0,    0,  108,  109,  110,  111,  112,
  113,  130,    0,    0,    0,    0,    0,    0,  115,  116,
    0,  117,  118,  119,  147,  120,    0,    0,    0,  115,
  116,    0,  117,  118,  119,    0,  120,  108,  109,  110,
  111,  112,  113,    0,    0,    0,    0,  152,   57,   57,
   57,   57,   57,   57,    0,    0,    0,  109,  110,  111,
  112,  115,  116,    0,  117,  118,  119,   57,  120,    0,
    0,    0,   57,   57,    0,   57,   57,   57,    0,   57,
  115,  116,    0,  117,  118,  119,    0,  120,   15,   15,
   15,   15,   36,    0,   37,   38,    0,    0,    0,   15,
    0,    1,    2,   39,   33,    3,    4,    5,    6,    0,
    0,    0,    0,   15,   15,    0,    0,   40,   41,    1,
    2,    0,    7,    3,    4,    5,    6,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    7,
};
short yycheck[] = {                                      30,
    0,   55,   56,   57,   58,   25,  259,   61,   62,   63,
  270,  290,   45,  292,   45,   35,  269,  270,  271,  272,
   74,   75,   76,   77,   78,   79,   59,  280,   59,   31,
  280,  290,   15,  293,   10,  291,  114,   20,   40,  294,
   94,  294,  295,  121,  122,  257,   29,   23,  292,  273,
  274,  275,  276,  277,  108,  109,  110,  111,  112,  113,
  283,  115,  116,  117,  118,  119,  120,  279,  280,  259,
  282,  289,  150,  297,  298,  297,  300,  301,  302,  291,
  304,  291,  304,  295,  296,   11,  293,  299,  300,  308,
  309,  310,   18,  305,  306,  307,  308,  309,  310,   25,
  291,  303,  278,  291,   30,  289,  303,  283,  270,   35,
  297,  298,  288,  300,  290,   41,  292,  304,  292,   45,
  303,  288,  273,  274,  275,  276,  277,  278,  293,  305,
  291,  294,  283,   59,  268,   61,   62,  288,  290,  290,
  291,  292,  292,    0,  290,  290,  297,  298,  270,  300,
  301,  302,  303,  304,  305,  273,  274,  275,  276,  277,
  278,  293,  290,  290,   20,  283,   62,  152,   53,   -1,
  288,   -1,  290,   -1,  292,  269,  270,  271,  272,   -1,
  298,   -1,  300,  301,  302,   -1,  280,  305,  273,  274,
  275,  276,  277,  278,   -1,   -1,   -1,   -1,  283,  293,
  294,  295,   -1,  288,   -1,  290,   -1,  292,  269,  270,
  271,  272,   -1,  298,   -1,  300,  301,  302,   -1,  280,
  305,  273,  274,  275,  276,  277,  278,   -1,   -1,  275,
  276,  283,  293,  294,  295,   -1,  288,   -1,  290,   -1,
  292,   -1,   -1,   -1,   -1,   -1,  298,   -1,  300,  301,
  302,  297,  298,  305,  300,  301,  302,   -1,  304,  259,
  273,  274,  275,  276,  277,  278,   -1,   -1,   -1,  269,
  270,  271,  272,   -1,   -1,   -1,   -1,   -1,   -1,  269,
  280,  271,  272,   -1,  297,  298,   -1,  300,  301,  302,
  280,  304,  305,   -1,  294,  295,  273,  274,  275,  276,
  277,  278,   -1,  293,  294,  295,  283,   -1,   -1,   -1,
   -1,  288,   -1,  290,   -1,  292,  273,  274,  275,  276,
  277,  278,   -1,   -1,  301,  302,  283,   -1,  305,   -1,
   -1,  288,   -1,  290,   -1,  292,  273,  274,  275,  276,
  277,  278,   -1,   -1,  301,  302,  283,   -1,  305,   -1,
   -1,  288,   -1,  290,   -1,  292,  273,  274,  275,  276,
  277,  278,   -1,   -1,  301,  302,  283,   -1,  305,   -1,
   -1,  288,   -1,  290,   -1,  292,  273,  274,   -1,   -1,
  277,  278,   -1,   -1,  301,  302,  283,   -1,  305,   -1,
   -1,  288,   -1,  290,   -1,  292,  273,  274,   -1,  273,
  277,  278,   -1,   -1,  278,   -1,  283,   -1,  305,  283,
   -1,  288,   -1,  290,  288,  292,  290,   -1,  292,  273,
  274,  275,  276,  277,  278,   -1,   -1,   -1,  305,   -1,
   -1,  305,   -1,   -1,   -1,   -1,  290,  273,  274,  275,
  276,  277,  278,  297,  298,   -1,  300,  301,  302,   -1,
  304,   -1,   -1,   -1,  290,  273,  274,  275,  276,  277,
  278,  297,  298,   -1,  300,  301,  302,   -1,  304,   -1,
   -1,   -1,  290,  273,  274,  275,  276,  277,  278,  297,
  298,   -1,  300,  301,  302,   -1,  304,   -1,  288,  273,
  274,  275,  276,  277,  278,   -1,   -1,  297,  298,   -1,
  300,  301,  302,   -1,  304,   -1,   -1,   -1,  292,   -1,
   -1,   -1,   -1,  297,  298,   -1,  300,  301,  302,   -1,
  304,  273,  274,  275,  276,  277,  278,   -1,   -1,   -1,
   -1,   -1,  273,  274,  275,  276,  277,  278,   -1,   -1,
  292,   -1,   -1,   -1,   -1,  297,  298,   -1,  300,  301,
  302,  292,  304,   -1,   -1,   -1,  297,  298,   -1,  300,
  301,  302,   -1,  304,  273,  274,  275,  276,  277,  278,
   -1,   -1,   -1,   -1,   -1,  273,  274,  275,  276,  277,
  278,  290,   -1,   -1,   -1,   -1,   -1,   -1,  297,  298,
   -1,  300,  301,  302,  292,  304,   -1,   -1,   -1,  297,
  298,   -1,  300,  301,  302,   -1,  304,  273,  274,  275,
  276,  277,  278,   -1,   -1,   -1,   -1,  283,  273,  274,
  275,  276,  277,  278,   -1,   -1,   -1,  274,  275,  276,
  277,  297,  298,   -1,  300,  301,  302,  292,  304,   -1,
   -1,   -1,  297,  298,   -1,  300,  301,  302,   -1,  304,
  297,  298,   -1,  300,  301,  302,   -1,  304,  269,  270,
  271,  272,  269,   -1,  271,  272,   -1,   -1,   -1,  280,
   -1,  260,  261,  280,  263,  264,  265,  266,  267,   -1,
   -1,   -1,   -1,  294,  295,   -1,   -1,  294,  295,  260,
  261,   -1,  281,  264,  265,  266,  267,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  281,
};
#define YYFINAL 8
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 310
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"NULL_LITERAL","KEY_PROCEDURE",
"KEY_VAR","KEY_CHARPTR","KEY_INTPTR","KEY_REALPTR","KEY_STRING","KEY_INTEGER",
"KEY_REAL","KEY_BOOLEAN","KEY_CHAR","KEY_ELSE","KEY_IF","KEY_RETURN","KEY_FOR",
"KEY_WHILE","OP_AND","OP_EQ","OP_GE","OP_LE","OP_NE","OP_OR","STRING_LITERAL",
"IDENTIFIER","KEY_VOID","CHAR_LITERAL","COMMA","COLON","DOT","SINGLE_QUOTE",
"QUOTE","SQ_BRA_C","SQ_BRA_O","PARAN_C","PARAN_O","SEMICOLON","BRA_C","BRA_O",
"OP_DEREFERENCE","OP_ADDRESS_OF","OP_MULTI","OP_PLUS","OP_NOT","OP_MINUS",
"OP_LT","OP_GT","ASSIGN","OP_DIV","OP_ABS","TRUE_LITERAL","FALSE_LITERAL",
"INTEGER_LITERAL","HEX_LITERAL","REAL_LITERAL",
};
char *yyrule[] = {
"$accept : PROGRAM",
"PROGRAM : PROCEDURES",
"PROCEDURES : PROCEDURE PROCEDURES",
"PROCEDURES :",
"PROCEDURE : TYPE IDENT PARAN_O PARAM_L PARAN_C BRA_O BODY BRA_C",
"IDENT : IDENTIFIER",
"IDENTARR : IDENTIFIER SQ_BRA_O EXPR SQ_BRA_C",
"PARAM_L : SPARAMS",
"PARAM_L : SPARAMS SEMICOLON PARAM_L",
"PARAM_L :",
"SPARAMS : TYPE PARAMS",
"PARAMS : IDENT COMMA PARAMS",
"PARAMS : IDENT",
"BODY : PROCEDURES VAR_DECS STMTS RET_STMT",
"VAR_DECS : VAR_DEC VAR_DECS",
"VAR_DECS :",
"VAR_DEC : KEY_VAR ARTYPE PARAMS SEMICOLON",
"STMTS : STMT STMTS",
"STMTS :",
"STMT : ASSIGNMENT",
"STMT : IF_STMT",
"STMT : IF_ELSE_STMT",
"STMT : FOR_STMT",
"STMT : WHILE_STMT",
"STMT : CODE_BLOCK",
"ASSIGNMENT : IDENT ASSIGN EXPR SEMICOLON",
"ASSIGNMENT : IDENTARR ASSIGN EXPR SEMICOLON",
"ASSIGNMENT : OP_DEREFERENCE IDENT ASSIGN EXPR SEMICOLON",
"ASSIGNMENT : IDENT ASSIGN FN_CALL",
"ASSIGNMENT : IDENTARR ASSIGN FN_CALL",
"CODE_BLOCK : BRA_O VAR_DECS STMTS BRA_C",
"FN_CALL : IDENT PARAN_O EXPR_LIST PARAN_C SEMICOLON",
"EXPR_LIST : EXPR COMMA EXPR_LIST",
"EXPR_LIST : EXPR",
"EXPR_LIST :",
"IF_ELSE_STMT : KEY_IF PARAN_O EXPR PARAN_C CODE_BLOCK KEY_ELSE CODE_BLOCK",
"IF_STMT : KEY_IF PARAN_O EXPR PARAN_C CODE_BLOCK",
"FOR_STMT : KEY_FOR PARAN_O EXPR PARAN_C CODE_BLOCK",
"WHILE_STMT : KEY_WHILE PARAN_O EXPR PARAN_C CODE_BLOCK",
"RET_STMT : KEY_RETURN EXPR SEMICOLON",
"EXPR : EXPR OP_PLUS EXPR",
"EXPR : EXPR OP_MINUS EXPR",
"EXPR : EXPR OP_MULTI EXPR",
"EXPR : EXPR OP_DIV EXPR",
"EXPR : EXPR OP_AND EXPR",
"EXPR : EXPR OP_OR EXPR",
"EXPR : EXPR OP_EQ EXPR",
"EXPR : EXPR OP_NE EXPR",
"EXPR : EXPR OP_GE EXPR",
"EXPR : EXPR OP_GT EXPR",
"EXPR : EXPR OP_LE EXPR",
"EXPR : EXPR OP_LT EXPR",
"EXPR : OP_NOT EXPR",
"EXPR : OP_MINUS EXPR",
"EXPR : OP_DEREFERENCE EXPR",
"EXPR : OP_ADDRESS_OF EXPR",
"EXPR : OP_ABS EXPR OP_ABS",
"EXPR : IDENT",
"EXPR : PARAN_O EXPR PARAN_C",
"EXPR : IDENTARR",
"EXPR : LITERAL",
"TYPE : KEY_CHARPTR",
"TYPE : KEY_INTPTR",
"TYPE : KEY_INTEGER",
"TYPE : KEY_REAL",
"TYPE : KEY_BOOLEAN",
"TYPE : KEY_CHAR",
"TYPE : KEY_VOID",
"ARTYPE : TYPE",
"ARTYPE : KEY_STRING SQ_BRA_O LITERAL_NUM SQ_BRA_C",
"LITERAL : LITERAL_STRING",
"LITERAL : LITERAL_NUM",
"LITERAL : LITERAL_CHAR",
"LITERAL : LITERAL_BOOLEAN",
"LITERAL : NULL_LITERAL",
"LITERAL_STRING : STRING_LITERAL",
"LITERAL_CHAR : CHAR_LITERAL",
"LITERAL_NUM : INTEGER_LITERAL",
"LITERAL_NUM : HEX_LITERAL",
"LITERAL_NUM : REAL_LITERAL",
"LITERAL_BOOLEAN : TRUE_LITERAL",
"LITERAL_BOOLEAN : FALSE_LITERAL",
};
#endif
#if YYDEBUG
#include <stdio.h>
#endif

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 500

int      yydebug;
int      yynerrs;
int      yyerrflag;
int      yychar;
short   *yyssp;
YYSTYPE *yyvsp;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static short   *yyss;
static short   *yysslim;
static YYSTYPE *yyvs;
static int      yystacksize;
#line 287 "parser.y"

int currentScope;

#include "lex.yy.c"
#include "ast.c"
#include "print_ast.c"
#include "symtab.c"
#include "semantics.c"
#include "ir.c"

int main(){
	symtable = make_symtable(HASHTABLE_SIZE);
	int i,max;
	currentScope = 0;
	yyparse();

	print_ast(ast);

	checkSemantics(ast);

	print_table(symtable);

	tacGeneration(ast);
}


void yyerror(const char *c){
	fprintf(stderr,"line %d: %s\n",yylineno - 1,c);
	
}





#line 542 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(void)
{
    int newsize, i;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = yyssp - yyss;
    newss = (yyss != 0)
          ? (short *)realloc(yyss, newsize * sizeof(*newss))
          : (short *)malloc(newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    yyss  = newss;
    yyssp = newss + i;
    newvs = (yyvs != 0)
          ? (YYSTYPE *)realloc(yyvs, newsize * sizeof(*newvs))
          : (YYSTYPE *)malloc(newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse(void)
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

#ifdef lint
    goto yyerrlab;
#endif

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yyvsp[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 129 "parser.y"
{printf("Syntax and Parsing: ok \n"); ast = make_program(yyvsp[0].pro_l); }
break;
case 2:
#line 132 "parser.y"
{yyval.pro_l = yyvsp[0].pro_l;yyvsp[0].pro_l->list[yyvsp[0].pro_l->i++] = yyvsp[-1].proc;}
break;
case 3:
#line 133 "parser.y"
{yyval.pro_l = make_proc_list();}
break;
case 4:
#line 139 "parser.y"
{yyval.proc = make_procedure_node(yyvsp[-6].ref,yyvsp[-4].params_l,yyvsp[-7].type_,yyvsp[-1].body);}
break;
case 5:
#line 143 "parser.y"
{yyval.ref = make_symbol_ref(yyvsp[0].str,yylineno,NULL);}
break;
case 6:
#line 146 "parser.y"
{yyval.ref = make_symbol_ref(yyvsp[-3].str,yylineno,yyvsp[-1].exp);}
break;
case 7:
#line 148 "parser.y"
{yyval.params_l = make_params_list();
				   yyval.params_l->list[yyval.params_l->i++] = yyvsp[0].param;}
break;
case 8:
#line 150 "parser.y"
{yyval.params_l = yyvsp[0].params_l;
								  	 yyvsp[0].params_l->list[yyvsp[0].params_l->i++] = yyvsp[-2].param;}
break;
case 9:
#line 152 "parser.y"
{yyval.params_l = make_params_list();}
break;
case 10:
#line 155 "parser.y"
{yyval.param = make_params(yyvsp[-1].type_,yyvsp[0].symbol_l);}
break;
case 11:
#line 158 "parser.y"
{yyval.symbol_l = yyvsp[0].symbol_l;
							  yyvsp[0].symbol_l->list[yyvsp[0].symbol_l->i++] = yyvsp[-2].ref;}
break;
case 12:
#line 160 "parser.y"
{yyval.symbol_l =  make_symbol_list();
	   	 		yyval.symbol_l->list[yyval.symbol_l->i++] = yyvsp[0].ref;}
break;
case 13:
#line 164 "parser.y"
{yyval.body = make_body_node(yyvsp[-3].pro_l,yyvsp[-2].var_dec_l,yyvsp[-1].stmt_l,yyvsp[0].ret);}
break;
case 14:
#line 167 "parser.y"
{yyval.var_dec_l = yyvsp[0].var_dec_l; yyvsp[0].var_dec_l->list[yyvsp[0].var_dec_l->i++] = yyvsp[-1].var_dec;}
break;
case 15:
#line 168 "parser.y"
{yyval.var_dec_l = make_var_dec_list();}
break;
case 16:
#line 171 "parser.y"
{yyval.var_dec = make_var_decs(yyvsp[-2].type_,yyvsp[-1].symbol_l);}
break;
case 17:
#line 175 "parser.y"
{yyval.stmt_l = yyvsp[0].stmt_l;
					yyvsp[0].stmt_l->list[yyvsp[0].stmt_l->i++] = yyvsp[-1].stmt_;}
break;
case 18:
#line 177 "parser.y"
{yyval.stmt_l = make_stmt_list();}
break;
case 19:
#line 180 "parser.y"
{yyval.stmt_ = make_stmt(yyvsp[0].assign_);}
break;
case 20:
#line 181 "parser.y"
{yyval.stmt_ = make_stmt(yyvsp[0].if_);}
break;
case 21:
#line 182 "parser.y"
{yyval.stmt_ = make_stmt(yyvsp[0].if_else_);}
break;
case 22:
#line 183 "parser.y"
{yyval.stmt_ = make_stmt(yyvsp[0].for_);}
break;
case 23:
#line 184 "parser.y"
{yyval.stmt_ = make_stmt(yyvsp[0].while_);}
break;
case 24:
#line 185 "parser.y"
{yyval.stmt_ = make_stmt(yyvsp[0].block);}
break;
case 25:
#line 188 "parser.y"
{yyval.assign_ = make_assign(ASSIGN_,yyvsp[-3].ref,yyvsp[-1].exp);}
break;
case 26:
#line 189 "parser.y"
{yyval.assign_ = make_assign(ASSIGN_,yyvsp[-3].ref,yyvsp[-1].exp);}
break;
case 27:
#line 190 "parser.y"
{yyval.assign_ = make_assign(ASSIGN_DER_,yyvsp[-3].ref,yyvsp[-1].exp);}
break;
case 28:
#line 191 "parser.y"
{yyval.assign_ = make_assign(ASSIGN_,yyvsp[-2].ref,yyvsp[0].call);}
break;
case 29:
#line 192 "parser.y"
{yyval.assign_ = make_assign(ASSIGN_,yyvsp[-2].ref,yyvsp[0].call);}
break;
case 30:
#line 195 "parser.y"
{yyval.block = make_code_block(yyvsp[-2].var_dec_l,yyvsp[-1].stmt_l);}
break;
case 31:
#line 199 "parser.y"
{yyval.call = make_fn_call(yyvsp[-4].ref,yyvsp[-2].expr_l);}
break;
case 32:
#line 202 "parser.y"
{yyval.expr_l = yyvsp[0].expr_l;
	  							  yyvsp[0].expr_l->list[yyvsp[0].expr_l->i++] = yyvsp[-2].exp;}
break;
case 33:
#line 204 "parser.y"
{yyval.expr_l = make_expr_list();
		  		  yyval.expr_l->list[yyval.expr_l->i++] = yyvsp[0].exp; }
break;
case 34:
#line 206 "parser.y"
{yyval.expr_l = make_expr_list();}
break;
case 35:
#line 209 "parser.y"
{yyval.if_else_ = make_if_else_node(yylineno,yyvsp[-4].exp,yyvsp[-2].block,yyvsp[0].block);}
break;
case 36:
#line 212 "parser.y"
{yyval.if_ = make_if_node(yylineno,yyvsp[-2].exp,yyvsp[0].block);}
break;
case 37:
#line 215 "parser.y"
{yyval.for_=make_for_node(yylineno,yyvsp[-2].exp,yyvsp[0].block);}
break;
case 38:
#line 218 "parser.y"
{yyval.while_ = make_while_node(yylineno,yyvsp[-2].exp,yyvsp[0].block);}
break;
case 39:
#line 221 "parser.y"
{yyval.ret = make_ret_stmt(yyvsp[-1].exp);}
break;
case 40:
#line 224 "parser.y"
{yyval.exp = make_expr(make_op(PLUS_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 41:
#line 225 "parser.y"
{yyval.exp = make_expr(make_op(MINUS_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 42:
#line 226 "parser.y"
{yyval.exp = make_expr(make_op(MULTI_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 43:
#line 227 "parser.y"
{yyval.exp = make_expr(make_op(DIV_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 44:
#line 228 "parser.y"
{yyval.exp = make_expr(make_rel(AND_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 45:
#line 229 "parser.y"
{yyval.exp = make_expr(make_rel(OR_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 46:
#line 230 "parser.y"
{yyval.exp = make_expr(make_rel(EQ_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 47:
#line 231 "parser.y"
{yyval.exp = make_expr(make_rel(NE_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 48:
#line 232 "parser.y"
{yyval.exp = make_expr(make_rel(GE_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 49:
#line 233 "parser.y"
{yyval.exp = make_expr(make_rel(GT_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 50:
#line 234 "parser.y"
{yyval.exp = make_expr(make_rel(LE_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 51:
#line 235 "parser.y"
{yyval.exp = make_expr(make_rel(LT_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 52:
#line 236 "parser.y"
{yyval.exp = make_expr(make_rel(NOT_,yylineno,yyvsp[0].exp,NULL));}
break;
case 53:
#line 237 "parser.y"
{yyval.exp = make_expr(make_op(UMINUS_,yylineno,yyvsp[0].exp,NULL));}
break;
case 54:
#line 238 "parser.y"
{yyval.exp = make_expr(make_op(DEREFERENCE_,yylineno,yyvsp[0].exp,NULL));}
break;
case 55:
#line 239 "parser.y"
{yyval.exp = make_expr(make_op(ADDRESS_OF_,yylineno,yyvsp[0].exp,NULL));}
break;
case 56:
#line 240 "parser.y"
{yyval.exp = make_expr(make_op(ABS_,yylineno,yyvsp[-1].exp,NULL)); }
break;
case 57:
#line 241 "parser.y"
{yyval.exp = make_expr(yyvsp[0].ref);}
break;
case 58:
#line 242 "parser.y"
{yyval.exp = yyvsp[-1].exp;}
break;
case 59:
#line 243 "parser.y"
{yyval.exp = make_expr(yyvsp[0].ref);}
break;
case 60:
#line 244 "parser.y"
{yyval.exp = make_expr(yyvsp[0].l);}
break;
case 61:
#line 249 "parser.y"
{ yyval.type_ = make_type(CHARPTR_,0);}
break;
case 62:
#line 250 "parser.y"
{ yyval.type_ = make_type(INTPTR_,0);}
break;
case 63:
#line 251 "parser.y"
{ yyval.type_ = make_type(INTEGER_,0);}
break;
case 64:
#line 252 "parser.y"
{ yyval.type_ = make_type(REAL_,0);}
break;
case 65:
#line 253 "parser.y"
{ yyval.type_ = make_type(BOOLEAN_,0);}
break;
case 66:
#line 254 "parser.y"
{ yyval.type_ = make_type(CHAR_,0);}
break;
case 67:
#line 255 "parser.y"
{ yyval.type_ = NULL;}
break;
case 69:
#line 260 "parser.y"
{ yyval.type_ = make_type(STRING_,yyvsp[-1].lit_i->value);}
break;
case 70:
#line 264 "parser.y"
{ yyval.l = make_lit(yyvsp[0].lit_s);}
break;
case 71:
#line 265 "parser.y"
{ yyval.l = make_lit(yyvsp[0].lit_i);}
break;
case 72:
#line 266 "parser.y"
{ yyval.l = make_lit(yyvsp[0].lit_c);}
break;
case 73:
#line 267 "parser.y"
{ yyval.l = make_lit(yyvsp[0].lit_b);}
break;
case 74:
#line 268 "parser.y"
{ yyval.l = make_lit(make_lit_null());}
break;
case 75:
#line 271 "parser.y"
{ yyval.lit_s = make_lit_string(yyvsp[0].str);}
break;
case 76:
#line 274 "parser.y"
{ yyval.lit_c = make_lit_char(yyvsp[0].ch);}
break;
case 77:
#line 277 "parser.y"
{ yyval.lit_i = make_lit_integer(yyvsp[0].num);}
break;
case 78:
#line 278 "parser.y"
{ yyval.lit_i = make_lit_integer(yyvsp[0].num);}
break;
case 79:
#line 279 "parser.y"
{ yyval.lit_i = make_lit_real(yyvsp[0].num);}
break;
case 80:
#line 282 "parser.y"
{ yyval.lit_b = make_lit_boolean(1);}
break;
case 81:
#line 283 "parser.y"
{ yyval.lit_b = make_lit_boolean(0);}
break;
#line 1050 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    return (1);

yyaccept:
    return (0);
}
