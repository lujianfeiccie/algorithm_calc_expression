#include <stdio.h>
#include <vector>
using namespace std;
#include "Stack.h"

enum ENUM_PRIOR
{
	BIGGER,
	SMALLER
};


ENUM_PRIOR priority(ENUM_OPER oper1,ENUM_OPER oper2)//比较优先级  
{  
   ENUM_PRIOR priority_matrix[4][4] =
   {
   // +		 -		 *		 /		
	 {BIGGER,BIGGER,SMALLER,SMALLER },//+
	 {BIGGER,BIGGER,SMALLER,SMALLER}, //- 
	 {BIGGER,BIGGER,BIGGER ,BIGGER},  //*
	 {BIGGER,BIGGER,BIGGER ,BIGGER}   // /
   }; 
   return priority_matrix[oper1][oper2];
}  

int getNum(string str)
{
	return -1;
}
ENUM_OPER getOper(string str)
{
	return ENUM_OPER::NONE;
}
int main(int argc,char* args[])
{
	vector<string> str_list;
	str_list.push_back("1");
	str_list.push_back("+");
	str_list.push_back("2");
	str_list.push_back("x");
	str_list.push_back("3");

	CStack stack;
	vector<string>::iterator it;
	for(it = str_list.begin();it!=str_list.end();it++)
	{
		dataType data;

		data.num = getNum(*it);
		data.oper = getOper(*it);

		stack.push(data);
	}
return 0;
}
