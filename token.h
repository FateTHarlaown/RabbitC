//
// Created by NorSnow_ZJ on 2019/4/17.
//

#ifndef RABBITC_TOKEN_H
#define RABBITC_TOKEN_H

void print_token(int token);
// the tokens in ascii use it's true value
enum TokenType {
    T_Le = 256,
    T_Ge,
    T_Eq,
    T_Ne,
    T_And,
    T_Or,
    T_IntConstant,
    T_StringConstant,
    T_Identifier,
    T_Void,
    T_Int,
    T_Char,
    T_Short,
    T_Long,
    T_Struct,
    T_Union,
    T_Enum,
    T_Static,
    T_Extern,
    T_Const,
    T_Signed,
    T_Unsigned,
    T_Switch,
    T_Case,
    T_Default,
    T_Do,
    T_For,
    T_Goto,
    T_Typedef,
    T_Sizeof,
    T_While,
    T_If,
    T_Else,
    T_Return,
    T_Break,
    T_Continue,
    T_Print,
    T_ReadInt,
    T_Import,
};

#endif //RABBITC_TOKEN_H
