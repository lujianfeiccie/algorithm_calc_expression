#include "Stack.h"
#include <stdio.h>

CStack::CStack(void)
{
	top = NULL;            //top=NULL表示链栈为空  
}


CStack::~CStack(void)
{
	node *ptr = NULL;  
  
    while(top != NULL)     //循环释放栈节点空间  
    {  
        ptr = top->next;  
        delete top;  
        top = ptr;  
    }  
}
void CStack::push(dataType var)  
{  
    node *ptr = new node;  
  
    ptr->data = var;        //新栈顶存值  
    ptr->next = top;        //新栈顶指向旧栈顶  
  
    top = ptr;              //top指向新栈顶  
}  
  
void CStack::pop()  
{  
    node *ptr = top->next;  //预存下一节点的指针  
    delete top;             //释放栈顶空间  
    top = ptr;              //栈顶变化  
}  
  
dataType CStack::stackTop()  
{  
    return top->data;       //返回栈顶元素,并不判断栈是否已空  
}  
  
bool CStack::isEmpty()  
{  
    return top == NULL;     //栈顶为NULL表示栈空  
}  