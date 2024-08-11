#pragma once
#include <string>
#undef EOF

enum TokenType
{
	PLUS,
	MINUS,
	MULTIPLE,
	DIVIDE,

	NUMBER_LITERAL,
	STRING_LITERAL,

	NUMBER,
	STRING,

	LEFT_PAREN,
	RIGHT_PAREN,

	ASSIGN,
	SEMICOLON,

	LET,
	ID,
	PRINT,
	EOF,
};

//enum Keywords
//{
//	PLUS,
//	MINUS,
//	MULTIPLE,
//	DIVIDE,
//
//	NUMBER_LITERAL,
//	STRING_LITERAL,
//
//	LEFT_PAREN,
//	RIGHT_PAREN,
//
//	ASSIGN,
//	SEMICOLON,
//
//	LET,
//	ID,
//	PRINT,
//	EOF,
//};


class Token
{
public:
	Token(TokenType token, std::string value);

	TokenType getType();
	std::string getValue();

	std::string string() const;

private:
    TokenType Type;
	std::string Value;
};
