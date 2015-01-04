#include "ExpressionUtil.h"
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
string printOper(ENUM_OPER oper);

ExpressionUtil::ExpressionUtil(void)
{
}


ExpressionUtil::~ExpressionUtil(void)
{
}

void ExpressionUtil::infixToSuffix()
{
	CStack stack;
	vector<string>::iterator it;
	m_str_list_suffix.clear();

	for(it = m_str_list_infix.begin();it!=m_str_list_infix.end();it++)
	{
		dataType data;

		data.num = getNum(*it);
		data.oper = getOper(*it);

		if(data.oper == NONE)//遇到操作数
		{
			char tmpStr[10];
			sprintf(tmpStr,"%d",data.num);//输出			
			m_str_list_suffix.push_back(tmpStr);

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
						string tmpStr = printOper(stack.stackTop().oper);
						m_str_list_suffix.push_back(tmpStr);
						stack.pop();
					}
					while(OPEN_BRACKET != stack.stackTop().oper);							
					stack.pop();//退出左括号
				}
				break;
			}//end switch(data.oper)
			if(stack.isEmpty()) continue;			

			ENUM_PRIOR prio = priority(data.oper,stack.stackTop().oper);
			/*printf("\n");
			printf("Data:");
			printOper(data.oper);
			printf("\n");
			printf("StackTop:");
			printOper(stack.stackTop().oper);
			printf("\n");*/
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
				string tmpStr = printOper(stack.stackTop().oper);				
				m_str_list_suffix.push_back(tmpStr);
				stack.pop();
				//将当前运算符入栈
				stack.push(data);
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
		string tmpStr = printOper(stack.stackTop().oper);
		m_str_list_suffix.push_back(tmpStr);
		stack.pop();
	}
}
void ExpressionUtil::printInfix()
{
	vector<string>::iterator it;
	for(it = m_str_list_infix.begin();it!=m_str_list_infix.end();it++)
	{
		printf("%s ",it->c_str());
	}
}
void ExpressionUtil::printSuffix()
{
	vector<string>::iterator it;
	for(it = m_str_list_suffix.begin();it!=m_str_list_suffix.end();it++)
	{
		printf("%s ",it->c_str());
	}
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
	//int num = atoi(str.c_str());
	bool isNum = true;
	int num = -1;
	for(int i=0;i<str.size();i++)
	{
		if(!(str[i]>='0' && str[i]<='9'))
		{
			isNum = false;
			break;
		}
	}
	if(isNum)
	{
		num = atoi(str.c_str());
	}
	return num;
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
string printOper(ENUM_OPER oper)
{
	string str;
	switch(oper)
	{
	case ADD:
		str="+";
		break;
	case MINUS:
		str="-";
		break;
	case MUL:
		str="*";
		break;
	case DIV:
		str="/";
		break;
	case OPEN_BRACKET:
		str="(";
		break;
	case CLOSE_BRACKET:
		str=")";
		break;
	}
	return str;
}