#include "Parser.h"
Parser::Parser(Lexer& input, int n) {
	this->input = &input;
	lookhead = new Token * [n];
	this->n = n;
	p = 0;
}
