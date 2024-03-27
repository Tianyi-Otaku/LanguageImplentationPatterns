#pragma once
#include<iostream>
#include<Lexer.h>
class Parser
{
	Token** lookhead;//环形缓冲区
	int n;//缓冲区大小
	Lexer* input;//词法源
	int p;//下一个缓冲区中装填的位值。
	
public:
	Parser(Lexer& input, int n);

	~Parser() {
		delete[] lookhead;
	}
};

