//
// Created by NorSnow_ZJ on 2019/4/18.
//

#include <FlexLexer.h>
#include <memory>
#include "token.h"

void init_scanner() {
    printf("%-20s%s\n", "TOKEN-TYPE", "TOKEN-VALUE");
    printf("-------------------------------------------------\n");
}

int main() {
    init_scanner();
    auto lexer = std::make_unique<yyFlexLexer>();
    int token;
    while (token = lexer->yylex()) {
        print_token(token);
        puts(lexer->YYText());
    }
    
    return 0;
}