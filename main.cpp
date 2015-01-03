#include <stdio.h>
#include <vector>
using namespace std;
#include "Stack.h"

enum ENUM_PRIOR
{
	BIGGER,
	SMALLER
};

//比较优先级
ENUM_PRIOR priority(ENUM_OPER oper1,ENUM_OPER oper2);
//获取数字
int getNum(string str);
//获取运算符
ENUM_OPER getOper(string str);
//输出运算符
void printOper(ENUM_OPER oper);

int main(int argc,char* args[])
{
	vector<string> str_list;
	str_list.push_back("(");
	str_list.push_back("1");
	str_list.push_back("+");
	str_list.push_back("2");
	str_list.push_back(")");
	str_list.push_back("*");
	str_list.push_back("3");

	CStack stack;
	vector<string>::iterator it;

	//输出中缀表达式
	printf("Mid expression\n");
	for(it = str_list.begin();it!=str_list.end();it++)
	{
		printf("%s",it->c_str());
	}
	printf("\n");

	//输出后缀表达式
	printf("Back expression\n");
	for(it = str_list.begin();it!=str_list.end();it++)
	{
		dataType data;

		data.num = getNum(*it);
		data.oper = getOper(*it);

		if(data.oper == NONE)//遇到操作数
		{
			printf("%d",data.num);//输出			
		}//end if(data.oper == NONE)//遇到操作数
		else if(!stack.isEmpty())
		{
			switch(data.oper)
			{
				case OPEN_BRACKET://遇到左括号
				{
					//进栈
					stack.push(data);
				}
			    break;
				case CLOSE_BRACKET://遇到右括号
				{
					//退栈直到左括号为止
					do
					{
						printOper(stack.stackTop().oper);
						stack.pop();
					}
					while(OPEN_BRACKET != stack.stackTop().oper);							
					stack.pop();
				}
				break;
			}//end switch(data.oper)
			if(stack.isEmpty()) continue;//栈空则继续下一个循环

			ENUM_PRIOR prio = priority(data.oper,stack.stackTop().oper);
			switch(prio)
			{
			case BIGGER://运算符比栈顶级别高
				{
				//进栈
				stack.push(data);	
				}
				break;
			case SMALLER://运算符比栈顶级别低
				{
				//输出栈顶并退栈
				printOper(stack.stackTop().oper);
				stack.pop();
				}
				break;
			}
			
		}
		else if(stack.isEmpty())//栈空
		{
			//进栈
			stack.push(data);
		}
	}
	while(!stack.isEmpty()) //将其余运算符输出
	{
		printOper(stack.stackTop().oper);
		stack.pop();
	}

	printf("\n");
return 0;
}

ENUM_PRIOR priority(ENUM_OPER oper1,ENUM_OPER oper2)//比较优先级  
{  
   ENUM_PRIOR priority_matrix[4][4] =
   {
   // +		 -		 *		 /		
	 {BIGGER,BIGGER,SMALLER,SMALLER},//+
	 {BIGGER,BIGGER,SMALLER,SMALLER}, //- 
	 {BIGGER,BIGGER,BIGGER ,BIGGER},  //*
	 {BIGGER,BIGGER,BIGGER ,BIGGER}   // /
   };    
   //printf("priority oper1=%d,oper2=%d matrix=%d\n",oper1,oper2,priority_matrix[oper1][oper2]);
   return priority_matrix[oper1][oper2];
}  
int getNum(string str)
{
	int num = atoi(str.c_str());
	for(int i=0;i<=9;i++)
	{
		if(i==num) return i;
	}
	return -1;
}

ENUM_OPER getOper(string str)
{
	string oper[]={"+","-","*","/","(",")"}; 
	for(int i=0;i<6;i++)
	{
		if(strcmp(oper[i].c_str(),str.c_str())==0)
		{
			return getOper(i);
		}
	}
	return ENUM_OPER::NONE;
}
void printOper(ENUM_OPER oper)
{
	switch(oper)
	{
	case ADD:
		printf("+");
		break;
	case MINUS:
		printf("-");
		break;
	case MUL:
		printf("*");
		break;
	case DIV:
		printf("/");
		break;
	case OPEN_BRACKET:
		printf("(");
		break;
	case CLOSE_BRACKET:
		printf(")");
		break;
	}
}