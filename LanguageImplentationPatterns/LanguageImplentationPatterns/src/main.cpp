#include<iostream>
#include"Lexer.h"
#include"Token.h"
//std::ostream& operator<< (std::ostream& cout, Token& token);
int main(void) {
	std::string data = "123 kas23 a1 _a [ ] ";
	Lexer lexer(data);
	int num = 0;
	while (!lexer.isEND())
	{
		Token token = lexer.nextToken();
		std::cout << num++ << ":" << token << std::endl;
	}

	return 0;
}