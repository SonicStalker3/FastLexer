#pragma once

#include <vector>
#include "Token.h"

const char space_char = ' ';

class Lexer
{
public:
	std::vector<Token> tokenize(std::string input);
private:
	std::string input;
	int pos;
	char current;
	
	//void Initialize();
	void Iterate();
	void SkipIgnoreSymbols();
	std::string Integer();
	std::string Consume_String(char type);
	Token idOrKeyword();
};

