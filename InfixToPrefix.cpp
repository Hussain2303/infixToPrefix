#include"myStack.h"
#include<string>
bool isOperand(char ch)
{
	return((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}
bool isOperator(char ch)
{
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
int getPrecedence(char op)
{
	if (op == '*' || op == '/') return 2;
	if (op == '+' || op == '-') return 1;
	return 0;
}
string manualReverse(const string& str)
{
	string reversedStr;
	for (int i = str.size() - 1; i >= 0; i--) {
		reversedStr += str[i];
	}
	return reversedStr;
}
string infixToPrefix(const string& infixExp) {
	myStack<char> stack(100);
	string prefixExp;

	string revInfix = manualReverse(infixExp);

	for (char& ch : revInfix) {
		if (ch == '(')
			ch = ')';
		else if (ch == ')')
			ch = '(';
	}

	for (char ch : revInfix) {
		if (isOperand(ch)) {
			prefixExp += ch;
		}
		else if (ch == '(') {
			stack.push(ch);
		}
		else if (ch == ')') {
			while (!stack.isEmpty() && stack.top() != '(') {
				prefixExp += stack.pop();
			}
			stack.pop();
		}
		else if (isOperator(ch)) {
			while (!stack.isEmpty() && getPrecedence(stack.top()) >= getPrecedence(ch)) {
				prefixExp += stack.pop();
			}
			stack.push(ch);
		}
	}

	while (!stack.isEmpty()) {
		prefixExp += stack.pop();
	}

	prefixExp = manualReverse(prefixExp);

	return prefixExp;
}
bool bracketCheck(const string& expression)
{
	myStack<char> temp(expression.length());

	for (char ch : expression)
	{
		if (ch == '(' || ch == '{' || ch == '[')
		{
			temp.push(ch);
		}
		else if (ch == ')' || ch == '}' || ch == ']')
		{
			if (temp.isEmpty())
			{
				return false;
			}
			char checker = temp.pop();
			if (checker == '(' && ch == ')' || checker == '{' && ch == '}' || checker == '[' && ch == ']')
			{
				continue;
			}
			else {
				return false;
			}
		}
	}
	if (temp.isEmpty())
		return true;
	else {
		return false;
	}

}
void postFix(const string& expression)
{
	myStack<char> temp(expression.length());
	for (char ch : expression)
	{
		if (ch == '(' || ch == '{' || ch == '[')
		{
			temp.push(ch);
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			temp.push(ch);
		}
		else if (ch == ')' || ch == '}' || ch == ']')
		{
			cout << temp.pop();
			temp.pop();
		}
		else {
			cout << ch;
		}
	}
}
int main()
{
	string infixexpression;
	cout << "Enter the Expression" << endl;
	getline(cin, infixexpression);
	string prefixExpression = infixToPrefix(infixexpression);
	cout << "Prefix expression: " << prefixExpression << endl;
	
	return 0;
}
