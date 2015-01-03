#include <stdio.h>
#include <vector>
using namespace std;
#include "Stack.h"

enum ENUM_PRIOR
{
	BIGGER,
	SMALLER
};

//�Ƚ����ȼ�
ENUM_PRIOR priority(ENUM_OPER oper1,ENUM_OPER oper2);
//��ȡ����
int getNum(string str);
//��ȡ�����
ENUM_OPER getOper(string str);
//��������
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

	//�����׺���ʽ
	printf("Mid expression\n");
	for(it = str_list.begin();it!=str_list.end();it++)
	{
		printf("%s",it->c_str());
	}
	printf("\n");

	//�����׺���ʽ
	printf("Back expression\n");
	for(it = str_list.begin();it!=str_list.end();it++)
	{
		dataType data;

		data.num = getNum(*it);
		data.oper = getOper(*it);

		if(data.oper == NONE)//����������
		{
			printf("%d",data.num);//���			
		}//end if(data.oper == NONE)//����������
		else if(!stack.isEmpty())
		{
			switch(data.oper)
			{
				case OPEN_BRACKET://����������
				{
					//��ջ
					stack.push(data);
				}
			    break;
				case CLOSE_BRACKET://����������
				{
					//��ջֱ��������Ϊֹ
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
			if(stack.isEmpty()) continue;//ջ���������һ��ѭ��

			ENUM_PRIOR prio = priority(data.oper,stack.stackTop().oper);
			switch(prio)
			{
			case BIGGER://�������ջ�������
				{
				//��ջ
				stack.push(data);	
				}
				break;
			case SMALLER://�������ջ�������
				{
				//���ջ������ջ
				printOper(stack.stackTop().oper);
				stack.pop();
				}
				break;
			}
			
		}
		else if(stack.isEmpty())//ջ��
		{
			//��ջ
			stack.push(data);
		}
	}
	while(!stack.isEmpty()) //��������������
	{
		printOper(stack.stackTop().oper);
		stack.pop();
	}

	printf("\n");
return 0;
}

ENUM_PRIOR priority(ENUM_OPER oper1,ENUM_OPER oper2)//�Ƚ����ȼ�  
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