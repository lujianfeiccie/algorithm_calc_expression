#pragma once

enum ENUM_OPER
{
	ADD = 0,
	MINUS,
	MUL,
	DIV,
	OPEN_BRACKET,
	CLOSE_BRACKET,
	NONE
};

ENUM_OPER getOper(int i);

typedef struct dataType{
	int num;
	ENUM_OPER oper;
} dataType;  
  
struct node                   //��ջ�ڵ�  
{  
    dataType data;            //������  
    node *next;               //ָ����  
}; 

class CStack
{
public:
	CStack(void);
	~CStack(void);
  void push(dataType var); //ѹջ  
  void pop();              //��ջ.��ջ֮ǰ�����ж�ջ�Ƿ��ѿ�.��Ҫͨ��isEmpty()�ж�  
  dataType stackTop();     //ȡջ��Ԫ��,ջ���ޱ仯.����ǰ�ж�ջ�Ƿ�Ϊ��  
  bool isEmpty();          //�п�.�շ���true,��֮����false  
    //bool isFull();         //����.��ջ�Ƕ�̬�����ڴ�ռ��,��������  
private:  
    node *top;               //ջ��ָ��.top=NULL��ʾΪ��ջ  
};

