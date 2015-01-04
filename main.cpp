#include <stdio.h>
#include <vector>
using namespace std;
#include "ExpressionUtil.h"
int main(int argc,char* args[])
{
	vector<string> str_list;
	string str[] = {"(","12","+","2",")","*","(","(","3","+","4",")","+","5",")"};
	for(int i=0;i<sizeof(str)/sizeof(string);i++)
	{
		str_list.push_back(str[i]);
	}

	ExpressionUtil util;
	util.m_str_list_infix = str_list;
	//输出中缀表达式
	printf("Infix expression\n");
	util.printInfix();
	printf("\n");

	//输出后缀表达式
	printf("Suffix expression\n");
	util.infixToSuffix();
	util.printSuffix();
	printf("\n");
return 0;
}

