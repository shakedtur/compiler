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
	lit_string* lit_s;
	lit_char* lit_c;
	lit_boolean* lit_b;
	lit_null* lit_n;					
	
} YYSTYPE;
#line 73 "y.tab.c"
#define NULL_LITERAL 257
#define KEY_PROCEDURE 258
#define KEY_VAR 259
#define KEY_CHARPTR 260
#define KEY_INTPTR 261
#define KEY_STRING 262
#define KEY_INTEGER 263
#define KEY_BOOLEAN 264
#define KEY_CHAR 265
#define KEY_ELSE 266
#define KEY_IF 267
#define KEY_RETURN 268
#define KEY_FOR 269
#define KEY_WHILE 270
#define OP_AND 271
#define OP_EQ 272
#define OP_GE 273
#define OP_LE 274
#define OP_NE 275
#define OP_OR 276
#define STRING_LITERAL 277
#define IDENTIFIER 278
#define CHAR_LITERAL 279
#define COMMA 280
#define COLON 281
#define DOT 282
#define SINGLE_QUOTE 283
#define QUOTE 284
#define SQ_BRA_C 285
#define SQ_BRA_O 286
#define PARAN_C 287
#define PARAN_O 288
#define SEMICOLON 289
#define BRA_C 290
#define BRA_O 291
#define OP_DEREFERENCE 292
#define OP_ADDRESS_OF 293
#define OP_MULTI 294
#define OP_PLUS 295
#define OP_NOT 296
#define OP_MINUS 297
#define OP_LT 298
#define OP_GT 299
#define ASSIGN 300
#define OP_DIV 301
#define OP_ABS 302
#define TRUE_LITERAL 303
#define FALSE_LITERAL 304
#define INTEGER_LITERAL 305
#define HEX_LITERAL 306
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    1,    1,    2,    3,    4,    5,    5,    5,    6,
    7,    7,    8,    9,    9,   10,   11,   11,   12,   12,
   12,   12,   12,   12,   13,   13,   13,   13,   13,   14,
   15,   16,   16,   16,   18,   17,   19,   20,   21,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
   23,   23,   23,   23,   23,   24,   24,   25,   25,   25,
   25,   25,   27,   28,   26,   26,   29,   29,
};
short yylen[] = {                                         2,
    1,    2,    0,   10,    1,    4,    1,    3,    0,    3,
    3,    1,    4,    2,    0,    5,    2,    0,    1,    1,
    1,    1,    1,    1,    4,    4,    5,    3,    3,    4,
    5,    3,    1,    0,    7,    5,    5,    5,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    2,    2,    2,    2,    3,    1,    3,    1,    1,
    1,    1,    1,    1,    1,    1,    4,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,
};
short yydefred[] = {                                      0,
    0,    0,    1,    0,    5,    0,    2,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   11,    0,    8,   61,
   62,   63,   64,   65,   10,    0,    0,    0,    0,    0,
    0,    0,    4,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   19,   24,   20,   21,   22,   23,
   14,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   13,   17,    0,   66,    0,   72,   73,   74,    0,
    0,    0,    0,    0,    0,   77,   78,   75,   76,   57,
   59,    0,   60,   69,   68,   70,   71,    0,    0,    0,
    0,    0,    0,   28,    0,   29,    0,    0,    0,   16,
    0,   54,   55,   52,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    6,   30,    0,    0,   25,   26,   39,    0,   58,
   56,    0,    0,    0,    0,    0,    0,    0,   42,    0,
    0,    0,    0,   43,   37,   38,   27,    0,    0,   67,
    0,    0,    0,   35,   31,   32,
};
short yydgoto[] = {                                       2,
    3,    4,   80,   81,   10,   11,   12,   29,   31,   32,
   43,   44,   45,   46,   94,  148,   47,   48,   49,   50,
   62,  149,   25,   66,   83,   84,   85,   86,   87,
};
short yysindex[] = {                                   -246,
 -241,    0,    0, -246,    0, -273,    0, -241, -237, -239,
 -238, -228, -241, -206, -241, -176,    0, -176,    0,    0,
    0,    0,    0,    0,    0, -218, -246, -177, -198, -241,
  378, -177,    0, -188, -191, -175, -173, -174, -177, -241,
 -189, -184, -151,  378,    0,    0,    0,    0,    0,    0,
    0,  -10, -202, -202, -202, -202,  378, -182, -202, -202,
 -202,    0,    0, -162,    0, -169,    0,    0,    0, -202,
 -202, -202, -202, -202, -202,    0,    0,    0,    0,    0,
    0,  127,    0,    0,    0,    0,    0,  144,  161,  178,
 -165, -202, -161,    0,  193,    0,  224,  235, -225,    0,
  266,    0,    0,    0, -263,  -36, -202, -202, -202, -202,
 -202, -202, -148, -202, -202, -202, -202, -202, -202, -148,
 -148,    0,    0,  283, -202,    0,    0,    0, -159,    0,
    0,  -52,  343, -223, -223,  343,  356, -136,    0, -263,
 -263, -223, -223,    0,    0,    0,    0, -143,  314,    0,
 -148, -144, -202,    0,    0,    0,
};
short yyrindex[] = {                                    147,
    0,    0,    0,    1,    0,    0,    0, -139, -132,    0,
 -137,    0,    0,    0, -139,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -242,  301,    0,    0,
 -206, -111,    0,    0,    0,    0,    0, -166,  211,    0,
    0,    0,    0, -257,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -138,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  325,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -134,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -133,    0,    0,    0,    0,    0,
    0,  108,   83,    2,   23,  102,   44,  -79,    0, -102,
  -70,   43,   63,    0,    0,    0,    0,    0, -127,    0,
    0,    0, -133,    0,    0,    0,
};
short yygindex[] = {                                      0,
    3,    0,   39,  -15,  151,    0,    5,    0,    7,    0,
  -12,    0,    0, -107,  115,    9,    0,    0,    0,    0,
    0,  -51,  -18,    0,    0,   77,    0,    0,    0,
};
#define YYTABLESIZE 670
short yytable[] = {                                      26,
    3,   82,   88,   89,   90,  138,    7,   95,   97,   98,
   18,    1,  145,  146,    8,   42,    3,   17,  101,  102,
  103,  104,  105,  106,    3,    3,    3,    3,   42,   28,
  114,   63,   18,   65,   34,    3,    5,  119,   51,    6,
  124,   42,   13,  154,   91,   57,    9,   14,    3,    3,
   15,    9,   16,    9,   67,  132,  133,  134,  135,  136,
  137,   18,  139,  140,  141,  142,  143,  144,    9,   41,
  114,  115,   27,  116,   68,   38,   69,  119,   58,   78,
   79,   30,   41,   20,   21,   70,   22,   23,   24,   71,
   72,   33,   52,   73,   74,   41,   53,   93,   93,   75,
   76,   77,   78,   79,    5,    5,    5,    5,    5,    5,
   59,   56,   54,    5,   55,   60,   61,   92,    5,  100,
    5,    5,    5,   99,  123,  150,  125,    5,    5,  151,
    5,    5,    5,    5,    5,    5,   53,   53,   53,   53,
   53,   53,   39,  152,  155,   53,    3,    9,   12,    7,
   53,   18,   53,   34,   53,   15,   15,   15,   15,   33,
   53,  156,   53,   53,   53,   19,   15,   53,   40,   40,
   40,   40,   40,   40,   96,  129,    0,   40,   15,   15,
   15,    0,   40,    0,   40,    0,   40,   36,   36,   36,
   36,    0,   40,    0,   40,   40,   40,    0,   36,   40,
   41,   41,   41,   41,   41,   41,    0,    0,    0,   41,
   36,   36,   36,    0,   41,    0,   41,    0,   41,  108,
  109,  110,  111,    0,   41,    0,   41,   41,   41,    0,
    0,   41,    0,    0,  107,  108,  109,  110,  111,  112,
    0,  114,  115,    0,  116,  117,  118,    0,  119,   20,
   21,   64,   22,   23,   24,    0,    0,  114,  115,    3,
  116,  117,  118,    0,  119,  131,    0,    3,    3,    3,
    3,    0,   48,   48,   48,   48,   48,   48,    3,    0,
    0,   48,    0,    0,    0,    0,   48,    0,   48,    0,
   48,    3,    3,   50,   50,   50,   50,   50,   50,   48,
   48,    0,   50,   48,    0,    0,    0,   50,    0,   50,
    0,   50,    0,   51,   51,   51,   51,   51,   51,   45,
   50,   50,   51,   45,   50,    0,    0,   51,   45,   51,
   45,   51,   45,   49,   49,   49,   49,   49,   49,    0,
   51,   51,   49,    0,   51,   45,    0,   49,    0,   49,
    0,   49,    0,   46,   46,    0,    0,   46,   46,    0,
   49,   49,   46,    0,   49,    0,    0,   46,    0,   46,
    0,   46,   47,   47,    0,    0,   47,   47,   44,    0,
    0,   47,    0,   44,   46,    0,   47,   44,   47,    0,
   47,    0,   44,    0,   44,    0,   44,  107,  108,  109,
  110,  111,  112,   47,    0,    0,    0,    0,    0,   44,
    0,    0,    0,  113,  107,  108,  109,  110,  111,  112,
  114,  115,    0,  116,  117,  118,    0,  119,    0,    0,
  120,  107,  108,  109,  110,  111,  112,  114,  115,    0,
  116,  117,  118,    0,  119,    0,    0,  121,  107,  108,
  109,  110,  111,  112,  114,  115,    0,  116,  117,  118,
    0,  119,  122,  107,  108,  109,  110,  111,  112,    0,
    0,  114,  115,    0,  116,  117,  118,   15,  119,   15,
   15,  126,    0,    0,    0,    0,  114,  115,   15,  116,
  117,  118,    0,  119,  107,  108,  109,  110,  111,  112,
   15,   15,   15,    0,    0,  107,  108,  109,  110,  111,
  112,    0,  127,    0,    0,    0,    0,  114,  115,    0,
  116,  117,  118,  128,  119,    0,    0,    0,  114,  115,
    0,  116,  117,  118,    0,  119,  107,  108,  109,  110,
  111,  112,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  130,  107,  108,  109,  110,  111,  112,  114,
  115,    0,  116,  117,  118,    0,  119,   15,   15,   15,
   15,  147,    0,    0,    0,    0,  114,  115,   15,  116,
  117,  118,    0,  119,  107,  108,  109,  110,  111,  112,
    0,   15,   15,  153,    0,   57,   57,   57,   57,   57,
   57,    0,    0,    0,    0,    0,    0,  114,  115,    0,
  116,  117,  118,   57,  119,  109,  110,    0,   57,   57,
    0,   57,   57,   57,    0,   57,  107,  108,  109,  110,
  111,    0,    0,    0,    0,    0,  114,  115,    0,  116,
  117,  118,    0,  119,   35,    0,   36,   37,    0,  114,
  115,    0,  116,  117,  118,   38,  119,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   39,   40,
};
short yycheck[] = {                                      18,
    0,   53,   54,   55,   56,  113,    4,   59,   60,   61,
  268,  258,  120,  121,  288,   31,  259,   13,   70,   71,
   72,   73,   74,   75,  267,  268,  269,  270,   44,   27,
  294,   44,  290,   52,   30,  278,  278,  301,   32,    1,
   92,   57,  280,  151,   57,   39,    8,  287,  291,  292,
  289,   13,  281,   15,  257,  107,  108,  109,  110,  111,
  112,  268,  114,  115,  116,  117,  118,  119,   30,   31,
  294,  295,  291,  297,  277,  278,  279,  301,   40,  305,
  306,  259,   44,  260,  261,  288,  263,  264,  265,  292,
  293,  290,  281,  296,  297,   57,  288,   59,   60,  302,
  303,  304,  305,  306,  271,  272,  273,  274,  275,  276,
  300,  286,  288,  280,  288,  300,  268,  300,  285,  289,
  287,  288,  289,  286,  290,  285,  288,  294,  295,  266,
  297,  298,  299,  300,  301,  302,  271,  272,  273,  274,
  275,  276,  291,  287,  289,  280,    0,  287,  281,  287,
  285,  290,  287,  287,  289,  267,  268,  269,  270,  287,
  295,  153,  297,  298,  299,   15,  278,  302,  271,  272,
  273,  274,  275,  276,   60,   99,   -1,  280,  290,  291,
  292,   -1,  285,   -1,  287,   -1,  289,  267,  268,  269,
  270,   -1,  295,   -1,  297,  298,  299,   -1,  278,  302,
  271,  272,  273,  274,  275,  276,   -1,   -1,   -1,  280,
  290,  291,  292,   -1,  285,   -1,  287,   -1,  289,  272,
  273,  274,  275,   -1,  295,   -1,  297,  298,  299,   -1,
   -1,  302,   -1,   -1,  271,  272,  273,  274,  275,  276,
   -1,  294,  295,   -1,  297,  298,  299,   -1,  301,  260,
  261,  262,  263,  264,  265,   -1,   -1,  294,  295,  259,
  297,  298,  299,   -1,  301,  302,   -1,  267,  268,  269,
  270,   -1,  271,  272,  273,  274,  275,  276,  278,   -1,
   -1,  280,   -1,   -1,   -1,   -1,  285,   -1,  287,   -1,
  289,  291,  292,  271,  272,  273,  274,  275,  276,  298,
  299,   -1,  280,  302,   -1,   -1,   -1,  285,   -1,  287,
   -1,  289,   -1,  271,  272,  273,  274,  275,  276,  276,
  298,  299,  280,  280,  302,   -1,   -1,  285,  285,  287,
  287,  289,  289,  271,  272,  273,  274,  275,  276,   -1,
  298,  299,  280,   -1,  302,  302,   -1,  285,   -1,  287,
   -1,  289,   -1,  271,  272,   -1,   -1,  275,  276,   -1,
  298,  299,  280,   -1,  302,   -1,   -1,  285,   -1,  287,
   -1,  289,  271,  272,   -1,   -1,  275,  276,  271,   -1,
   -1,  280,   -1,  276,  302,   -1,  285,  280,  287,   -1,
  289,   -1,  285,   -1,  287,   -1,  289,  271,  272,  273,
  274,  275,  276,  302,   -1,   -1,   -1,   -1,   -1,  302,
   -1,   -1,   -1,  287,  271,  272,  273,  274,  275,  276,
  294,  295,   -1,  297,  298,  299,   -1,  301,   -1,   -1,
  287,  271,  272,  273,  274,  275,  276,  294,  295,   -1,
  297,  298,  299,   -1,  301,   -1,   -1,  287,  271,  272,
  273,  274,  275,  276,  294,  295,   -1,  297,  298,  299,
   -1,  301,  285,  271,  272,  273,  274,  275,  276,   -1,
   -1,  294,  295,   -1,  297,  298,  299,  267,  301,  269,
  270,  289,   -1,   -1,   -1,   -1,  294,  295,  278,  297,
  298,  299,   -1,  301,  271,  272,  273,  274,  275,  276,
  290,  291,  292,   -1,   -1,  271,  272,  273,  274,  275,
  276,   -1,  289,   -1,   -1,   -1,   -1,  294,  295,   -1,
  297,  298,  299,  289,  301,   -1,   -1,   -1,  294,  295,
   -1,  297,  298,  299,   -1,  301,  271,  272,  273,  274,
  275,  276,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  287,  271,  272,  273,  274,  275,  276,  294,
  295,   -1,  297,  298,  299,   -1,  301,  267,  268,  269,
  270,  289,   -1,   -1,   -1,   -1,  294,  295,  278,  297,
  298,  299,   -1,  301,  271,  272,  273,  274,  275,  276,
   -1,  291,  292,  280,   -1,  271,  272,  273,  274,  275,
  276,   -1,   -1,   -1,   -1,   -1,   -1,  294,  295,   -1,
  297,  298,  299,  289,  301,  273,  274,   -1,  294,  295,
   -1,  297,  298,  299,   -1,  301,  271,  272,  273,  274,
  275,   -1,   -1,   -1,   -1,   -1,  294,  295,   -1,  297,
  298,  299,   -1,  301,  267,   -1,  269,  270,   -1,  294,
  295,   -1,  297,  298,  299,  278,  301,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  291,  292,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 306
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"NULL_LITERAL","KEY_PROCEDURE",
"KEY_VAR","KEY_CHARPTR","KEY_INTPTR","KEY_STRING","KEY_INTEGER","KEY_BOOLEAN",
"KEY_CHAR","KEY_ELSE","KEY_IF","KEY_RETURN","KEY_FOR","KEY_WHILE","OP_AND",
"OP_EQ","OP_GE","OP_LE","OP_NE","OP_OR","STRING_LITERAL","IDENTIFIER",
"CHAR_LITERAL","COMMA","COLON","DOT","SINGLE_QUOTE","QUOTE","SQ_BRA_C",
"SQ_BRA_O","PARAN_C","PARAN_O","SEMICOLON","BRA_C","BRA_O","OP_DEREFERENCE",
"OP_ADDRESS_OF","OP_MULTI","OP_PLUS","OP_NOT","OP_MINUS","OP_LT","OP_GT",
"ASSIGN","OP_DIV","OP_ABS","TRUE_LITERAL","FALSE_LITERAL","INTEGER_LITERAL",
"HEX_LITERAL",
};
char *yyrule[] = {
"$accept : PROGRAM",
"PROGRAM : PROCEDURES",
"PROCEDURES : PROCEDURE PROCEDURES",
"PROCEDURES :",
"PROCEDURE : KEY_PROCEDURE IDENT PARAN_O PARAM_L PARAN_C KEY_RETURN TYPE BRA_O BODY BRA_C",
"IDENT : IDENTIFIER",
"IDENTARR : IDENTIFIER SQ_BRA_O EXPR SQ_BRA_C",
"PARAM_L : SPARAMS",
"PARAM_L : SPARAMS SEMICOLON PARAM_L",
"PARAM_L :",
"SPARAMS : PARAMS COLON TYPE",
"PARAMS : IDENT COMMA PARAMS",
"PARAMS : IDENT",
"BODY : PROCEDURES VAR_DECS STMTS RET_STMT",
"VAR_DECS : VAR_DEC VAR_DECS",
"VAR_DECS :",
"VAR_DEC : KEY_VAR PARAMS COLON ARTYPE SEMICOLON",
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
"TYPE : KEY_BOOLEAN",
"TYPE : KEY_CHAR",
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
#line 278 "parser.y"

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

	//print_ast(ast);

	checkSemantics(ast);

	//print_table(symtable);

	tacGeneration(ast);
}


void yyerror(const char *c){
	fprintf(stderr,"line %d: %s\n",yylineno - 1,c);
	
}





#line 522 "y.tab.c"
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
#line 127 "parser.y"
{printf("Syntax and Parsing: ok \n"); ast = make_program(yyvsp[0].pro_l); }
break;
case 2:
#line 130 "parser.y"
{yyval.pro_l = yyvsp[0].pro_l;yyvsp[0].pro_l->list[yyvsp[0].pro_l->i++] = yyvsp[-1].proc;}
break;
case 3:
#line 131 "parser.y"
{yyval.pro_l = make_proc_list();}
break;
case 4:
#line 134 "parser.y"
{yyval.proc = make_procedure_node(yyvsp[-8].ref,yyvsp[-6].params_l,yyvsp[-3].type_,yyvsp[-1].body);}
break;
case 5:
#line 138 "parser.y"
{yyval.ref = make_symbol_ref(yyvsp[0].str,yylineno,NULL);}
break;
case 6:
#line 141 "parser.y"
{yyval.ref = make_symbol_ref(yyvsp[-3].str,yylineno,yyvsp[-1].exp);}
break;
case 7:
#line 143 "parser.y"
{yyval.params_l = make_params_list();
				   yyval.params_l->list[yyval.params_l->i++] = yyvsp[0].param;}
break;
case 8:
#line 145 "parser.y"
{yyval.params_l = yyvsp[0].params_l;
								  	 yyvsp[0].params_l->list[yyvsp[0].params_l->i++] = yyvsp[-2].param;}
break;
case 9:
#line 147 "parser.y"
{yyval.params_l = make_params_list();}
break;
case 10:
#line 150 "parser.y"
{yyval.param = make_params(yyvsp[0].type_,yyvsp[-2].symbol_l);}
break;
case 11:
#line 153 "parser.y"
{yyval.symbol_l = yyvsp[0].symbol_l;
							  yyvsp[0].symbol_l->list[yyvsp[0].symbol_l->i++] = yyvsp[-2].ref;}
break;
case 12:
#line 155 "parser.y"
{yyval.symbol_l =  make_symbol_list();
	   	 		yyval.symbol_l->list[yyval.symbol_l->i++] = yyvsp[0].ref;}
break;
case 13:
#line 159 "parser.y"
{yyval.body = make_body_node(yyvsp[-3].pro_l,yyvsp[-2].var_dec_l,yyvsp[-1].stmt_l,yyvsp[0].ret);}
break;
case 14:
#line 162 "parser.y"
{yyval.var_dec_l = yyvsp[0].var_dec_l; yyvsp[0].var_dec_l->list[yyvsp[0].var_dec_l->i++] = yyvsp[-1].var_dec;}
break;
case 15:
#line 163 "parser.y"
{yyval.var_dec_l = make_var_dec_list();}
break;
case 16:
#line 166 "parser.y"
{yyval.var_dec = make_var_decs(yyvsp[-1].type_,yyvsp[-3].symbol_l);}
break;
case 17:
#line 170 "parser.y"
{yyval.stmt_l = yyvsp[0].stmt_l;
					yyvsp[0].stmt_l->list[yyvsp[0].stmt_l->i++] = yyvsp[-1].stmt_;}
break;
case 18:
#line 172 "parser.y"
{yyval.stmt_l = make_stmt_list();}
break;
case 19:
#line 175 "parser.y"
{yyval.stmt_ = make_stmt(yyvsp[0].assign_);}
break;
case 20:
#line 176 "parser.y"
{yyval.stmt_ = make_stmt(yyvsp[0].if_);}
break;
case 21:
#line 177 "parser.y"
{yyval.stmt_ = make_stmt(yyvsp[0].if_else_);}
break;
case 22:
#line 178 "parser.y"
{yyval.stmt_ = make_stmt(yyvsp[0].for_);}
break;
case 23:
#line 179 "parser.y"
{yyval.stmt_ = make_stmt(yyvsp[0].while_);}
break;
case 24:
#line 180 "parser.y"
{yyval.stmt_ = make_stmt(yyvsp[0].block);}
break;
case 25:
#line 183 "parser.y"
{yyval.assign_ = make_assign(ASSIGN_,yyvsp[-3].ref,yyvsp[-1].exp);}
break;
case 26:
#line 184 "parser.y"
{yyval.assign_ = make_assign(ASSIGN_,yyvsp[-3].ref,yyvsp[-1].exp);}
break;
case 27:
#line 185 "parser.y"
{yyval.assign_ = make_assign(ASSIGN_DER_,yyvsp[-3].ref,yyvsp[-1].exp);}
break;
case 28:
#line 186 "parser.y"
{yyval.assign_ = make_assign(ASSIGN_,yyvsp[-2].ref,yyvsp[0].call);}
break;
case 29:
#line 187 "parser.y"
{yyval.assign_ = make_assign(ASSIGN_,yyvsp[-2].ref,yyvsp[0].call);}
break;
case 30:
#line 190 "parser.y"
{yyval.block = make_code_block(yyvsp[-2].var_dec_l,yyvsp[-1].stmt_l);}
break;
case 31:
#line 194 "parser.y"
{yyval.call = make_fn_call(yyvsp[-4].ref,yyvsp[-2].expr_l);}
break;
case 32:
#line 197 "parser.y"
{yyval.expr_l = yyvsp[0].expr_l;
	  							  yyvsp[0].expr_l->list[yyvsp[0].expr_l->i++] = yyvsp[-2].exp;}
break;
case 33:
#line 199 "parser.y"
{yyval.expr_l = make_expr_list();
		  		  yyval.expr_l->list[yyval.expr_l->i++] = yyvsp[0].exp; }
break;
case 34:
#line 201 "parser.y"
{yyval.expr_l = make_expr_list();}
break;
case 35:
#line 204 "parser.y"
{yyval.if_else_ = make_if_else_node(yylineno,yyvsp[-4].exp,yyvsp[-2].block,yyvsp[0].block);}
break;
case 36:
#line 207 "parser.y"
{yyval.if_ = make_if_node(yylineno,yyvsp[-2].exp,yyvsp[0].block);}
break;
case 37:
#line 210 "parser.y"
{yyval.for_=make_for_node(yylineno,yyvsp[-2].exp,yyvsp[0].block);}
break;
case 38:
#line 213 "parser.y"
{yyval.while_ = make_while_node(yylineno,yyvsp[-2].exp,yyvsp[0].block);}
break;
case 39:
#line 216 "parser.y"
{yyval.ret = make_ret_stmt(yyvsp[-1].exp);}
break;
case 40:
#line 219 "parser.y"
{yyval.exp = make_expr(make_op(PLUS_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 41:
#line 220 "parser.y"
{yyval.exp = make_expr(make_op(MINUS_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 42:
#line 221 "parser.y"
{yyval.exp = make_expr(make_op(MULTI_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 43:
#line 222 "parser.y"
{yyval.exp = make_expr(make_op(DIV_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 44:
#line 223 "parser.y"
{yyval.exp = make_expr(make_rel(AND_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 45:
#line 224 "parser.y"
{yyval.exp = make_expr(make_rel(OR_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 46:
#line 225 "parser.y"
{yyval.exp = make_expr(make_rel(EQ_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 47:
#line 226 "parser.y"
{yyval.exp = make_expr(make_rel(NE_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 48:
#line 227 "parser.y"
{yyval.exp = make_expr(make_rel(GE_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 49:
#line 228 "parser.y"
{yyval.exp = make_expr(make_rel(GT_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 50:
#line 229 "parser.y"
{yyval.exp = make_expr(make_rel(LE_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 51:
#line 230 "parser.y"
{yyval.exp = make_expr(make_rel(LT_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 52:
#line 231 "parser.y"
{yyval.exp = make_expr(make_rel(NOT_,yylineno,yyvsp[0].exp,NULL));}
break;
case 53:
#line 232 "parser.y"
{yyval.exp = make_expr(make_op(UMINUS_,yylineno,yyvsp[0].exp,NULL));}
break;
case 54:
#line 233 "parser.y"
{yyval.exp = make_expr(make_op(DEREFERENCE_,yylineno,yyvsp[0].exp,NULL));}
break;
case 55:
#line 234 "parser.y"
{yyval.exp = make_expr(make_op(ADDRESS_OF_,yylineno,yyvsp[0].exp,NULL));}
break;
case 56:
#line 235 "parser.y"
{yyval.exp = make_expr(make_op(ABS_,yylineno,yyvsp[-1].exp,NULL)); }
break;
case 57:
#line 236 "parser.y"
{yyval.exp = make_expr(yyvsp[0].ref);}
break;
case 58:
#line 237 "parser.y"
{yyval.exp = yyvsp[-1].exp;}
break;
case 59:
#line 238 "parser.y"
{yyval.exp = make_expr(yyvsp[0].ref);}
break;
case 60:
#line 239 "parser.y"
{yyval.exp = make_expr(yyvsp[0].l);}
break;
case 61:
#line 244 "parser.y"
{ yyval.type_ = make_type(CHARPTR_,0);}
break;
case 62:
#line 245 "parser.y"
{ yyval.type_ = make_type(INTPTR_,0);}
break;
case 63:
#line 246 "parser.y"
{ yyval.type_ = make_type(INTEGER_,0);}
break;
case 64:
#line 247 "parser.y"
{ yyval.type_ = make_type(BOOLEAN_,0);}
break;
case 65:
#line 248 "parser.y"
{ yyval.type_ = make_type(CHAR_,0);}
break;
case 67:
#line 252 "parser.y"
{ yyval.type_ = make_type(STRING_,yyvsp[-1].lit_i->value);}
break;
case 68:
#line 256 "parser.y"
{ yyval.l = make_lit(yyvsp[0].lit_s);}
break;
case 69:
#line 257 "parser.y"
{ yyval.l = make_lit(yyvsp[0].lit_i);}
break;
case 70:
#line 258 "parser.y"
{ yyval.l = make_lit(yyvsp[0].lit_c);}
break;
case 71:
#line 259 "parser.y"
{ yyval.l = make_lit(yyvsp[0].lit_b);}
break;
case 72:
#line 260 "parser.y"
{ yyval.l = make_lit(make_lit_null());}
break;
case 73:
#line 263 "parser.y"
{ yyval.lit_s = make_lit_string(yyvsp[0].str);}
break;
case 74:
#line 266 "parser.y"
{ yyval.lit_c = make_lit_char(yyvsp[0].ch);}
break;
case 75:
#line 269 "parser.y"
{ yyval.lit_i = make_lit_integer(yyvsp[0].num);}
break;
case 76:
#line 270 "parser.y"
{ yyval.lit_i = make_lit_integer(yyvsp[0].num);}
break;
case 77:
#line 273 "parser.y"
{ yyval.lit_b = make_lit_boolean(1);}
break;
case 78:
#line 274 "parser.y"
{ yyval.lit_b = make_lit_boolean(0);}
break;
#line 1018 "y.tab.c"
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
