#include "Stack.h"
#include <stdio.h>

CStack::CStack(void)
{
	top = NULL;            //top=NULL��ʾ��ջΪ��  
}


CStack::~CStack(void)
{
	node *ptr = NULL;  
  
    while(top != NULL)     //ѭ���ͷ�ջ�ڵ�ռ�  
    {  
        ptr = top->next;  
        delete top;  
        top = ptr;  
    }  
}
void CStack::push(dataType var)  
{  
    node *ptr = new node;  
  
    ptr->data = var;        //��ջ����ֵ  
    ptr->next = top;        //��ջ��ָ���ջ��  
  
    top = ptr;              //topָ����ջ��  
}  
  
void CStack::pop()  
{  
    node *ptr = top->next;  //Ԥ����һ�ڵ��ָ��  
    delete top;             //�ͷ�ջ���ռ�  
    top = ptr;              //ջ���仯  
}  
  
dataType CStack::stackTop()  
{  
    return top->data;       //����ջ��Ԫ��,�����ж�ջ�Ƿ��ѿ�  
}  
  
bool CStack::isEmpty()  
{  
    return top == NULL;     //ջ��ΪNULL��ʾջ��  
}  