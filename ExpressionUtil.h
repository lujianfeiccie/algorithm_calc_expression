#pragma once
#include <vector>
#include "Stack.h"
using namespace std;
class ExpressionUtil
{
public:
	ExpressionUtil(void);
	~ExpressionUtil(void);

	void infixToSuffix();
	void printInfix();
	void printSuffix();

	vector<string> m_str_list_infix;
	vector<string> m_str_list_suffix;
};

