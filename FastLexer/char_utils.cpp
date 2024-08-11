#include "char_utils.h"
#include <cctype>

namespace character
{
    bool isDigit(char symbol)
    {
        return std::isdigit(symbol);
    }

    bool isAlphabet(char symbol)
    {
        return std::isalpha(static_cast<unsigned char>(symbol));
    }

    bool isSpaceChar(char symbol)
    {
        return symbol == ' ';
    }

    bool isLetterOrDigit(char symbol)
    {
        return isAlphabet(symbol) || isDigit(symbol);
    }
}