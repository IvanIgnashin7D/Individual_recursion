#include <iostream>
#include <iomanip>


bool plus_minus(char* str);
bool mantis(char* str, int c);
bool exponent(char* str, int c, int c_first);


int main() {
	char test1[] = "+9.321E412";
	char test2[] = ".";
	char test3[] = ".565656";
	char test4[] = "--.E6767";
	char test5[] = "-.E1";
	char test6[] = "+565";


	plus_minus(test1) ? std::cout << test1 << std::setw(25 - strlen(test1)) << "- True\n" : std::cout << test1 << std::setw(26 - strlen(test1)) << "- False\n";
	plus_minus(test2) ? std::cout << test2 << std::setw(25 - strlen(test2)) << "- True\n" : std::cout << test2 << std::setw(26 - strlen(test2)) << "- False\n";
	plus_minus(test3) ? std::cout << test3 << std::setw(25 - strlen(test3)) << "- True\n" : std::cout << test3 << std::setw(26 - strlen(test3)) << "- False\n";
	plus_minus(test4) ? std::cout << test4 << std::setw(25 - strlen(test4)) << "- True\n" : std::cout << test4 << std::setw(26 - strlen(test4)) << "- False\n";
	plus_minus(test5) ? std::cout << test5 << std::setw(25 - strlen(test5)) << "- True\n" : std::cout << test5 << std::setw(26 - strlen(test5)) << "- False\n";
	plus_minus(test6) ? std::cout << test6 << std::setw(25 - strlen(test6)) << "- True\n" : std::cout << test6 << std::setw(26 - strlen(test6)) << "- False\n";
}


bool plus_minus(char* str) {
	if (isdigit(str[0]))
		return mantis(str, 0);

	if ((str[0] == '.' || str[0] == '+' || str[0] == '-') && isdigit(str[1]))
		return mantis(str, 1);

	if ((str[0] == '+' || str[0] == '-') && str[1] == '.')
		return mantis(str, 2);
	return false;
}


bool mantis(char* str, int c){
	if (str[c] == 'E') {
		c++;
		return exponent(str, c, c);
	}

	if (('0' <= str[c]) && (str[c] <= '9')) {
		c++;
		return mantis(str, c);
	}
	return false;
}


bool exponent(char* str, int c, int c_first) {
	if (str[c] == '\0' && c != c_first)
		return true;

	if ((str[c] == '+' || str[c] == '-') && c == c_first) {
		c++;
		return exponent(str, c, c_first);
	}

	if (isdigit(str[c])) {
		c++;
		return exponent(str, c, c_first);
	}
	
	return false;
}
