
#include <iostream>
#include <stack>
int main()
{
	setlocale(LC_ALL, "ru");
	std::stack <char> mas;
	std::string str;
	std::cout << "Введите строку - ";
	std::cin >> str;
	bool error = 0;
	if (str[0] == '(' || str[0] == '[' || str[0] == '{')
		mas.push(str[0]);
	else {
		std::cout << "строка не существует";
	}
	for (size_t i = 1; i < str.length(); i++)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
			mas.push(str[i]);
		}
		else if ((str[i] == ')' && mas.top() == '(') || (str[i] == ']' && mas.top() == '[') || (str[i] == '}' && mas.top() == '{')) {
			mas.pop();
		}
		else {
			std::cout << "строка не существует" << "\n";
			error = 1;
			break;
		}
	}
	if (!error)
		std::cout << "строка существует" << "\n";

	//()[({}())]
}
