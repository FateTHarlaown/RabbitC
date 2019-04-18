%{
#include "token.h"
int cur_line_num = 1;
void lex_error(char* msg, int line);
%}

%option noyywrap

/* Definitions, note: \042 is '"' */
INTEGER             ([0-9]+)
UNTERM_STRING       (\042[^\042\n]*)
STRING              (\042[^\042\n]*\042)
IDENTIFIER          ([_a-zA-Z][_a-zA-Z0-9]*)
OPERATOR            ([+*-/%=,;!<>(){}])
SINGLE_COMMENT1     ("//"[^\n]*)
SINGLE_COMMENT2     ("#"[^\n]*)

%%

[\n]                { cur_line_num++;                       }
[ \t\r\a]+          { /* ignore all spaces */               }
{SINGLE_COMMENT1}   { /* skip for single line comment */    }
{SINGLE_COMMENT2}   { /* skip for single line commnet */    }

{OPERATOR}          { return yytext[0];         }

"<="                { return TokenType::T_Le;              }
">="                { return TokenType::T_Ge;              }
"=="                { return TokenType::T_Eq;              }
"!="                { return TokenType::T_Ne;              }
"&&"                { return TokenType::T_And;             }
"||"                { return TokenType::T_Or;              }
"void"              { return TokenType::T_Void;            }
"int"               { return TokenType::T_Int;             }
"char"              { return TokenType::T_Char;            }
"short"             { return TokenType::T_Short;           }
"long"              { return TokenType::T_Long;            }
"struct"            { return TokenType::T_Struct;          }
"union"             { return TokenType::T_Union;           }
"enum"              { return TokenType::T_Enum;            }
"static"            { return TokenType::T_Static;          }
"extern"            { return TokenType::T_Extern;          }
"const"             { return TokenType::T_Const;           }
"signed"            { return TokenType::T_Signed;          }
"unsigned"          { return TokenType::T_Unsigned;        }
"switch"            { return TokenType::T_Switch;          }
"case"              { return TokenType::T_Case;            }
"default"           { return TokenType::T_Default;         }
"do"                { return TokenType::T_Do;              }
"for"               { return TokenType::T_For;             }
"goto"              { return TokenType::T_Goto;            }
"typedef"           { return TokenType::T_Typedef;         }
"sizeof"            { return TokenType::T_Sizeof;          }
"while"             { return TokenType::T_While;           }
"if"                { return TokenType::T_If;              }
"else"              { return TokenType::T_Else;            }
"return"            { return TokenType::T_Return;          }
"break"             { return TokenType::T_Break;           }
"continue"          { return TokenType::T_Continue;        }
"print"             { return TokenType::T_Print;           }
"readint"           { return TokenType::T_ReadInt;         }
"import"            { return TokenType::T_Import;          }

{INTEGER}           { return TokenType::T_IntConstant;     }
{STRING}            { return TokenType::T_StringConstant;  }
{IDENTIFIER}        { return TokenType::T_Identifier;      }

<<EOF>>             { return 0; }

{UNTERM_STRING}     { lex_error("Unterminated string constant", cur_line_num);  }
.                   { lex_error("Unrecognized character", cur_line_num);        }

%%

void lex_error(char* msg, int line) {
    printf("\nError at line %-3d: %s\n\n", line, msg);
}
