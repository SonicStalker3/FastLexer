#include "Lexer.h"
#include "char_utils.h"
#include <stdexcept>
#include <iostream>
#include "ignore_symbols.h"

std::vector<Token> Lexer::tokenize(std::string input)
{
    this->input = input;
    this->pos = 0;
    this->current = input[0];

    std::vector<Token> tokens;
   
    while (current != NULL)
    {
        if (ignore_list::haveIgnoreList(current))
            SkipIgnoreSymbols();
        else
        {
            switch (current)
            {
                std::cout << "Initialized switch" << std::endl;
            case '+':
                tokens.push_back(Token(TokenType::PLUS, "+"));
                break;
            case '-':
                tokens.push_back(Token(TokenType::MINUS, "-"));
                break;
            case '*':
                tokens.push_back(Token(TokenType::MULTIPLE, "*"));
                break;
            case '/':
                tokens.push_back(Token(TokenType::DIVIDE, "/"));
                break;
            case '=':
                tokens.push_back(Token(TokenType::ASSIGN, "="));
                break;
            case '(':
                tokens.push_back(Token(TokenType::LEFT_PAREN, "="));
                break;
            case ')':
                tokens.push_back(Token(TokenType::RIGHT_PAREN, "="));
                break;
            //case ':':
            //    tokens.push_back(Token(TokenType::ASSIGN, "="));
            //    break;
            case ';':
                tokens.push_back(Token(TokenType::SEMICOLON, "\0"));
                break;
            default:
                if (character::isDigit(current))
                    tokens.push_back(Token(TokenType::NUMBER_LITERAL, Integer()));
                else if (current == '"' || current == '\'')
                    tokens.push_back(Token(TokenType::STRING_LITERAL, Consume_String(current)));
                else if (character::isAlphabet(current))
                    tokens.push_back(idOrKeyword());
                else
                    throw new std::logic_error("Ошибка компиляции. \n Нераспознанный токен: " + current);
                break;
            }
            Iterate();
        }
    }
    tokens.push_back(Token(TokenType::EOF, "\0"));

    return tokens;
}

//void Lexer::Initialize()
//{
//
//}

void Lexer::Iterate()
{
    pos++;
    if (pos >= input.length())
        current = '\0';
    else
        current = input[pos];
}

void Lexer::SkipIgnoreSymbols()
{
    while (current != '\0' && ignore_list::haveIgnoreList(current))
    {
        Iterate();
    }
}

std::string Lexer::Integer()
{
    std::string result;
    while (current !='\0' && character::isDigit(current))
    {
        result += current;
        Iterate();
    }
    return result;
}

std::string Lexer::Consume_String(char type)
{
    std::string result;
    Iterate();
    while (current != '\0' && current != type)
    {
        result += current;
        Iterate();
    }
    return result;
} 

Token Lexer::idOrKeyword()
{
    std::string result;
    while (current != '\0' && character::isLetterOrDigit(current))
    {
        result += current;
        Iterate();
    }
    if (result == "PRINT")
        return Token(TokenType::PRINT, result);
    else if (result == "Number")
        return Token(TokenType::NUMBER, result);
    else if (result == "String")
        return Token(TokenType::STRING, result);
    else
        return Token(TokenType::ID, result);
}