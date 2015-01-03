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
  
struct node                   //链栈节点  
{  
    dataType data;            //数据域  
    node *next;               //指针域  
}; 

class CStack
{
public:
	CStack(void);
	~CStack(void);
  void push(dataType var); //压栈  
  void pop();              //出栈.出栈之前并不判断栈是否已空.需要通过isEmpty()判断  
  dataType stackTop();     //取栈顶元素,栈顶无变化.不提前判断栈是否为空  
  bool isEmpty();          //判空.空返回true,反之返回false  
    //bool isFull();         //判满.链栈是动态分配内存空间的,无需判满  
private:  
    node *top;               //栈顶指针.top=NULL表示为空栈  
};

