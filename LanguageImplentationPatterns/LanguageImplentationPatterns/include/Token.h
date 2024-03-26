#pragma once
#include<iostream>
enum class TokenType
{
	EoF = -1,
	ID = 0,
	NUMBER,
	WS,
	UNKNOW
};
class Token
{
	TokenType Type;
	std::string data;
	std::string typeShow(TokenType& const types) const;

public:
	friend std::ostream& operator<< (std::ostream& cout, Token& token);
	Token(std::string data, TokenType Type);
};
std::ostream& operator<<(std::ostream& cout,Token& token);

