#include <gtest/gtest.h>
#include <FlexLexer.h>
#include "token.h"

//
// Created by NorSnow_ZJ on 2019/4/18.
//

class Lexer_test : public testing::Test {
protected:
    yyFlexLexer * lexer;
    
    virtual void SetUp() {
        lexer = new yyFlexLexer();
    }
    
    virtual void TearDown() {
        delete lexer;
    }
};

TEST_F(Lexer_test, test) {
    std::istringstream input("import stdio;\n                      \
                              int\n                                \
                              main(int argc, char **argv)\n        \
                              {\n                                  \
                                  printf(\"Hello, World!\\n\");\n  \
                                  return 0;\n                      \
                              }");
                              
    lexer->switch_streams(&input);
    
    EXPECT_EQ(TokenType::T_Import, lexer->yylex());
    EXPECT_EQ("import", std::string(lexer->YYText()));
    
    EXPECT_EQ(TokenType::T_Identifier, lexer->yylex());
    EXPECT_EQ("stdio", std::string(lexer->YYText()));
    
    EXPECT_EQ(';', lexer->yylex());
    
    EXPECT_EQ(TokenType::T_Int, lexer->yylex());
    EXPECT_EQ("int", std::string(lexer->YYText()));
    
    EXPECT_EQ(TokenType::T_Identifier, lexer->yylex());
    EXPECT_EQ("main", std::string(lexer->YYText()));
    
    EXPECT_EQ('(', lexer->yylex());
    
    EXPECT_EQ(TokenType::T_Int, lexer->yylex());
    EXPECT_EQ("int", std::string(lexer->YYText()));
    
    EXPECT_EQ(TokenType::T_Identifier, lexer->yylex());
    EXPECT_EQ("argc", std::string(lexer->YYText()));
    
    EXPECT_EQ(',', lexer->yylex());
    
    EXPECT_EQ(TokenType::T_Char, lexer->yylex());
    EXPECT_EQ("char", std::string(lexer->YYText()));
    
    EXPECT_EQ('*', lexer->yylex());
    EXPECT_EQ('*', lexer->yylex());
    
    EXPECT_EQ(TokenType::T_Identifier, lexer->yylex());
    EXPECT_EQ("argv", std::string(lexer->YYText()));
    
    EXPECT_EQ(')', lexer->yylex());
    
    EXPECT_EQ('{', lexer->yylex());
    
    EXPECT_EQ(TokenType::T_Identifier, lexer->yylex());
    EXPECT_EQ("printf", std::string(lexer->YYText()));
    
    EXPECT_EQ('(', lexer->yylex());
    
    EXPECT_EQ(TokenType::T_StringConstant, lexer->yylex());
    EXPECT_EQ("\"Hello, World!\\n\"", std::string(lexer->YYText()));
    
    EXPECT_EQ(')', lexer->yylex());
    
    EXPECT_EQ(';', lexer->yylex());
    
    EXPECT_EQ(TokenType::T_Return, lexer->yylex());
    EXPECT_EQ("return", std::string(lexer->YYText()));
    
    EXPECT_EQ(TokenType::T_IntConstant, lexer->yylex());
    EXPECT_EQ("0", std::string(lexer->YYText()));
}
