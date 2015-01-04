#include "ExpressionUtil.h"
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

		if(data.oper == NONE)//����������
		{
			char tmpStr[10];
			sprintf(tmpStr,"%d",data.num);//���			
			m_str_list_suffix.push_back(tmpStr);

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
						string tmpStr = printOper(stack.stackTop().oper);
						m_str_list_suffix.push_back(tmpStr);
						stack.pop();
					}
					while(OPEN_BRACKET != stack.stackTop().oper);							
					stack.pop();//�˳�������
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
			case BIGGER://�������ջ�������
				{
				//��ջ
				stack.push(data);	
				}
				break;
			case SMALLER://�������ջ�������
				{
				//���ջ������ջ
				string tmpStr = printOper(stack.stackTop().oper);				
				m_str_list_suffix.push_back(tmpStr);
				stack.pop();
				//����ǰ�������ջ
				stack.push(data);
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