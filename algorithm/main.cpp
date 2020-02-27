/*2019.8.26本部分介绍简单的算法，若对C不太熟
  所涉及的语法知识请看part1部分的基础讲解，*/
//任务一：基本线性的结构的定义，包括了顺序表，链表
/*
#include "stdio.h"
#include "windows.h"
#define maxsize 20
int main() 
{
	int A[maxsize];//定义一个线性表，顺序存储的
	int length = 0;
	
	typedef struct LNode //定义一个线性表，链式存储结构的，单链表 
	{
		int data;
		struct LNode *next;//指向下一个节点的指针
	}LNode;
	
	typedef struct  DLNode  //定义一个双链表
	{
		int data;
		struct DLNode *prior; // 前驱
		struct DLNode *next;  // 后继
	}DLNode;

	LNode *L; //定义一个节点的指针
	L = (LNode *)malloc(sizeof(LNode)); //动态分配空间
	system("pause");
	return 0;
}
*/
//任务二：顺序表的插入和删除
/*
#include "stdio.h"
#include "windows.h"
#define  maxsize 15
void display(int a[],int &length);
int in_set(int sqList[], int &length, int q, int e);
int delete_set(int sqList[],int &length,int p ,int &s);
int main()
{
	int sqList[maxsize] = { 1,9,9,8,0,1,0,6,9,10};
	int length = 10;
	int s = 0;
	display(sqList,length);//显示出顺序表的长度
	int x=0,y = 0, z = 0;
	printf_s("输入要插入的数字和位子");
	scanf_s("%d", &y);
	scanf_s("%d", &z);
	int k =in_set(sqList,length,z,y);
	do 
	{
		if (k == 1)
		{
			display(sqList, length);
		}
		else
		{
			puts("操作不合法请重新操作");
			printf_s("输入要插入的数字和位子:\n");
			scanf_s("%d", &y);
			scanf_s("%d", &z);
			k = in_set(sqList, length, z, y);
			display(sqList, length);
		}
	} while (k==0);

	printf_s("输入要删除的数字的位子：");
	scanf_s("%d", &x);
	int sign = delete_set(sqList,length,x,s);
	//这里就简化一下打印出来即可
	if (sign == 1) 
	{
		display(sqList, length);
	}
	system("pause");
	return 0;
}

void display(int a[],int &length)
{
	int b = length;
	printf_s("定义的顺序表长度为：%d\n", b);
	for (int i = 0; i <= b - 1; i++)
	{
		printf_s("%d", a[i]);
		putchar(' ');
	}
	putchar('\n');
}

int in_set(int sqList[], int &length, int q, int e) //掌握这个即可
{
	if (q<0||q>length||length==maxsize)
	{
		return 0;
	}

		for (int i=length-1;i>=q;--i)
		{
		
		sqList[i + 1] = sqList[i];//从最后一位向后移动
		}
		sqList[q] = e;
		length++;
		return 1;
}

int delete_set(int sqList[], int &length, int p, int &s)
{
	if (p<0 || p>length - 1) 
	{
		return 0;
	}
	s = sqList[p];
	for (int i = p; i < length -1; i++)
	{
		sqList[i] = sqList[i + 1];
	}
	length--;
	return 1;
}
*/
/*
//任务三 链表
#include "stdio.h"
#include "windows.h"

typedef struct LNode //节点定义
{
	int data;
	struct LNode *next;

}LNode;

//含有头节点的单链表建表,尾插法,两种方法一种是键盘输入，一种是数组赋值。
//这里先使用键盘输入
void createlistR(LNode *&head)
{
	head = (LNode *)malloc(sizeof(LNode));//动态分配空间,先弄一个头结点
	head->next = NULL;
	LNode *r = head; //使用尾插，指向末尾节点，现在是头结点
	LNode *p=NULL;//新的节点
	int n;
	scanf_s("%d", &n);
	for (int i =0;i<n;++i)
	{
		p = (LNode *)malloc(sizeof(LNode));
		p->next = NULL;
		scanf_s("%d", &(p->data));
		//这里和插入法的方式一模一样
		p->next = r->next;
		r->next=p;
		r = p;
		//头插法，不需要r指针指向节点
		//p-next=head->next;
		//head->next=p;
	}
}

int main() 
{
	struct LNode  *head;
	createlistR(head);
	struct LNode *p = head->next;
	while (p != NULL)
	{	
			printf("%d ", p->data);
			p = p->next;		
	}

	system("pause");
	return 0;

}

#include <stdio.h>
#define N 100
//设计一个顺序表的插入和删除,p可插入为0-length
int sqlist[max] = { 1,2,3,4,5,6,7,8,9,0,1,22,32 }
int length = 5;
//创造一个插入函数,length表示长度不表示位置
int inset(int sqlist[], int &length, int p, int e)
{
	if (p < 0 || p < length || length == max)
	{
		return 0;
	}
	else
	{
		for (int i = length - 1; i >= p; --i)
		{
			sqlist[i + 1] = sqlist[i];
		}
		sqlist[p] = e;
		length++;
		return 1;
	}
}
//创造一个删除函数，删除特定的位置，删除位置为0-length-1

int delete(int sqlist[], int &length, int p, int &e)
{
	if (p<0 || p>length - 1)
	{
		return 0;
	}
	else
	{
		e = sqlist[p];
		for (int i = p; i < length - 1; ++i)
		{
			sqlist[p] = sqlist[p + 1];
		}
		length--;
		return 1;
	}
}

//建立单链表,通过键盘输入

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode;//建立一个节点

void createlistR(LNode *&head)
{
	head = (LNode *)malloc(sizeof(LNode));
	head->next = NULL;
	LNode *r = head;
	LNode *p = NULL;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		p = (LNode *)malloc(sizeof(LNode));
		p->next = NULL;
		scanf("%d", &(p->data));
		p->next = r->next;//可以不要，为了完整性最好加上
		r->next = p;
		r = p;
		//头插法，不需要r指针指向节点
		//p-next=head->next;
		//head->next=p;
	}
}

//题目一 ，键盘输入字母表，n(多少个)，c1,c2,....c26，放入单链表中，并且不能重复。
typedef struct  LNode
{
	int data;
	struct LNode *next;

}LNode;

void createlist(LNode *&head)
{
	head = (LNode *)malloc(sizeof(LNode));
	head - next = NULL;
	LNode *p, *r;//p用于申请新节点，r尾插法
	r = head;
	int n;
	char ch;
	scanf("%d", &n)
		for (int i = 0; i < n; ++i)
		{
			p = (LNode *)malloc(sizeof(LNode));
			p->next = NULL;
			scanf("%c", &ch);
			//判断
			p = head->next;
			while (p != NULL)
			{
				if (c == p > data)
				{
					break;
				}
				else
				{
					p = p->next;
				}
			}
			if (p == NULL)
			{
				//存入
				p->data = ch;
				p->next = r->next;
				r->next = p;
				r = p;
			}
		}
}

//逆置,顺序表

for (int i = 0, j = length - 1; i < j; i++, j--)
{
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
	 code 
}

//逆置链表
LNode *t;
while (p->next != q)//p是第一个节点的前一个节点，q是
{
	t = p->next;
	p->next = t->next;
	t->next = q->next;
	q->next = t;
}

//题目 将n长度的数组前k个元素逆序后放到后端
void reserve(int a[], int left, int right, int k)
{
	int temp;
	for (int i = left, j = right; i < k + left && i < j; ++i)//i<j防止重复交换
	{

		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	//这个时候顺序前面发生了变化，但是题目没要求，我们就看成前k段和后k段交换
}

//将n的数组的前k个元素顺序的放到数组后端,利用刚刚的方法
void movetoend(int a[], int n, int k)
{
	reserve(a, 0, k - 1, k);
	reserve(a, 0, n - 1, k);
}
//将数组循环左移p个位置
void leftmove(int a[], int n, int p)
{
	reserve(a, 0, p - 1, p);
	reserve(a, p, n - 1, n - p);
	reserve(a, 0, n - 1, n);
}

//取最值 顺序表简单就不写了，注意使用标记min=好大的值，max=好小的值，或者=表中的值
//取最值，单链表
LNode *p, *q;//q用于标记
q = p = head->next;
int max = head->next->data;
while (p = !NULL)
{
	if (p->data > max)
	{
		max = p->next;
		q = p;
	}
	p = p->next;
}

//双链表，{llink，data，rlink},找到data值最大的节点(只有一个)并放到最前面
typedef struct DNode
{
	int data；
		struct DNode *llink;//prior
	sruct DNode *rlink;//next
}DNode;

void maxFisrt(DNode *head)//在写链表这样函数的时候，
						  //我们调用的是头节点，不是整个链表，*&head用于创建链表中
{
	DNode *p = head->rlink, *q = p;//p用于标记
	int max = p->data;
	while (p != NULL)
	{
		if (max < p->data)
		{
			max = p - data;
			q = p;
		}
		p = p->rlink;
	}
	q->llink->rlink = q->rlink;//删除，如果你嫌麻烦不妨用下一种
	if (q - rlink != NULL)
	{
		q->rlink->lleft = q->llink;
	}
	//	DNode *l=q->llink,*r=q->rlink;//这样替代更清晰
	// l-rlink=r;
	//if(r!=NULL)r=link=l;	
	//插入到头节点后
	q->rlink = head->rlink;
	q = head->rlink->llink;
	head = q->rlink;
	head->rlink = q;
}

//归并（二路归并）
//顺序表归并，按序,值得学习和思考
void merge(int a[], int m, int b[], int n, int c[])
{
	//需要逐一比较，但是比较短的，先比较完毕，大前提if(m<n)，但是也可以省事用while
	int i = 0, j = 0, k = 0;
	while (i < m&&j < n)
	{
		if (a[i] < b[j])
		{
			c[k++] = a[i++];
		}
		else
		{
			c[k++] = b[j++];
		}
	}
	while (i < m)
	{
		c[k++] = a[i++];
	}
	while (j < n)
	{
		c[k++] = b[j++];
	}
}

//链表归并
void merge(LNode *A, LNode *B, LNode *&C)
{
	LNode *p, *q, *r;
	p = A->next;
	q = B->next;
	C = A;
	C->next = NULL;
	r = C;
	free(B);
	while (p->next = !NULL&&q->next != NULL)
	{
		if (p->data < q->data)
		{
			r->next = p;
			r = r->next;
			p = p->next;
		}
		else
		{
			r - next = q;
			r = r->next;
			q = q->next;
		}
	}
	while (p != NULL)
	{
		r->next = p;
		r = r->next;
		p = p->next;
	}
	while (q != NULL)
	{
		r->next = q;
		r = r->next;
		q = q->next;
	}
	//这样也可以，但是太麻烦，注意链表就是抓到头就行了
	if (p != NULL) r->next = p;
	if (q != NULL) r->next = q;
}

//若想归并后的表顺序想法使用头插法
p->next = C->next;
C->next = p;
p = p->next;
//使用头插法已经无法使后面的一次并入，需要改成while
while (p != NULL)
{
	p->next = C->next;
	C->next = p;
	p = p->next;
}
while (q != NULL)
{
	q->next = C->next;
	C->next = q;
	q = q->next;
}

//划分,以某个元素为标志，左右不一样，三种题目
//第一种：2,-1,-9,-3,5,6,-1;顺序表以2为划分，左边比2小，右边比2大
//使用时间复杂度尽量低的方法，i在数组的第一个，j在数组的第二个
//左移j，同时判断，一旦j所在的数值小于2，赋值到i所在的位置，i++
//右移i，直到遇到比2大的数字，停止，把i所指的数赋值到j上面
//直到ij相遇，或i>=j，a[i]=temp(2)结束。
void partition(int a[], int n)
{
	int temp = a[0];
	int i = 0, j = n - 1;
	while (i < j)
	{
		while (i < j && a[j] >= temp)
		{
			j--;
		}
		if (i < j)
		{
			a[i] = a[j];
			i++;
		}
		while (i < j && a[i] < temp)
		{
			i++;
		}
		if (i < j)
		{
			a[j] = a[i];
			j--;
		}
	}
	a[i] = temp;
}
//假设此时，比较的值不是temp，是自己指定的，comp,只需要改三处
void partition(int a[], int n, int comp)
{
	int temp = a[0];
	int i = 0, j = n - 1;
	while (i < j)
	{
		while (i < j && a[j] >= comp)
		{
			j--;
		}
		if (i < j)
		{
			a[i] = a[j];
			i++;
		}
		while (i < j && a[i] < comp)
		{
			i++;
		}
		if (i < j)
		{
			a[j] = a[i];
			j--;
		}
	}
	a[i] = temp;
}
//比较的值是数字的任意一个值，输入数字下表k，默认k在0-n-1范围呢
void partition(int a[], int n，int k)
{
	int temp;
	int i = 0, j = n - 1;
	temp = a[i];//换到首个元素
	a[i] = a[k];
	a[k] = temp;
	temp = a[i];
	while (i < j)
	{
		while (i < j && a[j] >= temp)
		{
			j--;
		}
		if (i < j)
		{
			a[i] = a[j];
			i++;
		}
		while (i < j && a[i] < temp)
		{
			i++;
		}
		if (i < j)
		{
			a[j] = a[i];
			j--;
		}
	}
	a[i] = temp;
}

*/
