#include "Token.h"

std::ostream& operator<<(std::ostream& cout,Token& token) {
	cout << "[" <<token.typeShow(token.Type)<< "| '" <<token.data<< "' ]";
	return cout;
}

std::string Token::typeShow(TokenType& const types) const{
	std::string s="";
	switch (types) {
	case TokenType::ID: s = "ID"; break;
	case TokenType::NUMBER: s = "NUMBER"; break;
	case TokenType::WS: s = "WS"; break;
	case TokenType::UNKNOW: s = "UNKNOW"; break;
	case TokenType::EoF: s = "EOF"; break;
	}
	return s;
}

Token::Token(std::string data, TokenType Type) {
	this->data = data;
	this->Type = Type;
}