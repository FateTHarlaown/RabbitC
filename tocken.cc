//
// Created by NorSnow_ZJ on 2019/4/17.
//


#include <cstdio>
#include <string>

static std::string token_strs[] = {
    "T_Le",
    "T_Ge",
    "T_Eq",
    "T_Ne",
    "T_And",
    "T_Or",
    "T_IntConstant",
    "T_StringConstant",
    "T_Identifier",
    "T_Void",
    "T_Int",
    "T_Char",
    "T_Short",
    "T_Long",
    "T_Struct",
    "T_Union",
    "T_Enum",
    "T_Static",
    "T_Extern",
    "T_Const",
    "T_Signed",
    "T_Unsigned",
    "T_Switch",
    "T_Case",
    "T_Default",
    "T_Do",
    "T_For",
    "T_Goto",
    "T_Typedef",
    "T_Sizeof",
    "T_While",
    "T_If",
    "T_Else",
    "T_Return",
    "T_Break",
    "T_Continue",
    "T_Print",
    "T_ReadInt",
    "T_Import"
};

void print_token(int token) {
    if (token < 256) {
        printf("%-20c", token);
    } else {
        printf("%-20s", token_strs[token-256].c_str());
    }
}