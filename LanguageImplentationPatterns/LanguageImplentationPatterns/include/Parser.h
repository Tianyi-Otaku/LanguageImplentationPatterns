#pragma once
#include<iostream>
#include<Lexer.h>
class Parser
{
	Token** lookhead;//���λ�����
	int n;//��������С
	Lexer* input;//�ʷ�Դ
	int p;//��һ����������װ���λֵ��
	
public:
	Parser(Lexer& input, int n);

	~Parser() {
		delete[] lookhead;
	}
};

