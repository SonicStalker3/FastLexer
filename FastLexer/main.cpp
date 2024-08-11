#include <iostream>
#include "Lexer.h"

int main()
{
    Lexer lexer = *new Lexer();
    std::vector<Token> tokens = lexer.tokenize("Number x = 5;\n x=10;\n");
    for (const auto& token : tokens)
    {
      std::cout << token.string() << std::endl;
    }
    std::cout << "Hello World!\n";
}