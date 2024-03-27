#pragma once
#include<iostream>
#include<fstream>
#include<regex>
#include"Token.h"
class Lexer
{
	unsigned char* input;
	long n;
	long current;
	void consume();
	void lexerBuffer(unsigned char* input, long n);//缓冲区
	//匹配集
	bool isWS();
	bool isNUMBER();
	bool isID();
	bool isUNKNOW();
	//操作集
	Token NUMBER();
	Token ID();
	Token UNKNOW();

public:
	~Lexer();
	Lexer(std::string data);
	//Lexer(std::fstream file);
	Token nextToken();
	bool isEND();


};

