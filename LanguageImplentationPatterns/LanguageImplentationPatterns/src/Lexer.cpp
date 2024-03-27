#include "Lexer.h"

//基础方法
void Lexer::lexerBuffer(unsigned char* input,long n){
	this->input = new unsigned char[n];
	this->n = n;
	this->current = n?0:-1;
	memcpy(this->input, input, n);
}
Lexer::~Lexer() {
	delete[] input;
}
void Lexer::consume() {
	current++;
	if (current <= 0 || current >= n) current = -1;
}

//公开方法
Lexer::Lexer(std::string data) {
	lexerBuffer((unsigned char*)data.c_str(), data.size());

}
//Lexer::Lexer(std::fstream file) {
	//TODO
//}
Token Lexer::nextToken() {	
	while (isWS()) consume();
	if (isNUMBER()) return NUMBER();
	if (isID()) return ID();
	if (isUNKNOW()) return UNKNOW();

	return Token("EOF", TokenType::EoF);

}

//匹配集
bool Lexer::isWS() {
	if (current == -1) return false;
	switch (input[current]) {
	case ' ':return true;
	case '\t':return true;
	case '\n':return true;
	case '\r':return true;
	default: return false;
	}
}
bool Lexer::isNUMBER() {
	if (current == -1) return false;
	if (input[current] <= '9' && input[current] >= '0')return true;
	return false;
}

bool Lexer::isID() {
	if (current == -1) return false;
	if (input[current] <= 'Z' && input[current] >= 'A')return true;
	if (input[current] <= 'z' && input[current] >= 'a')return true;
	if (input[current] <= '9' && input[current] >= '0')return true;
	if (input[current] == '_') return true;
	return false;
}
bool Lexer::isUNKNOW() {
	if (current == -1) return false;
	return true;
}
//操作集
Token Lexer::NUMBER() {
	std::string num="";
	num += input[current];
	consume();
	while (isNUMBER()) {
		num += input[current];
		consume();
	}
	return Token(num, TokenType::NUMBER);
}
Token Lexer::ID() {
	std::string id = "";
	id += input[current];
	consume();
	while (isID()) {
		id += input[current];
		consume();
	}
	return Token(id, TokenType::ID);
}
Token Lexer::UNKNOW(){
	std::string other = "";
	other += input[current];
	consume();
	return Token(other, TokenType::UNKNOW);
}

bool Lexer::isEND() {
	if (current == -1) return true;
	else return false;

}