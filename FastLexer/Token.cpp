#include "Token.h"

TokenType Token::getType()
{
	return Type;
}

std::string Token::getValue()
{
	return Value;
}

std::string Token::string() const
{
	return std::to_string(static_cast<int>(Type)) + " " + Value;
}

Token::Token(TokenType token, std::string value)
{
	Type = token;
	Value = value;
}