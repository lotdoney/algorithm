/*2019.8.26�����ֽ��ܼ򵥵��㷨������C��̫��
  ���漰���﷨֪ʶ�뿴part1���ֵĻ������⣬*/
//����һ���������ԵĽṹ�Ķ��壬������˳�������
/*
#include "stdio.h"
#include "windows.h"
#define maxsize 20
int main() 
{
	int A[maxsize];//����һ�����Ա�˳��洢��
	int length = 0;
	
	typedef struct LNode //����һ�����Ա���ʽ�洢�ṹ�ģ������� 
	{
		int data;
		struct LNode *next;//ָ����һ���ڵ��ָ��
	}LNode;
	
	typedef struct  DLNode  //����һ��˫����
	{
		int data;
		struct DLNode *prior; // ǰ��
		struct DLNode *next;  // ���
	}DLNode;

	LNode *L; //����һ���ڵ��ָ��
	L = (LNode *)malloc(sizeof(LNode)); //��̬����ռ�
	system("pause");
	return 0;
}
*/
//�������˳���Ĳ����ɾ��
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
	display(sqList,length);//��ʾ��˳���ĳ���
	int x=0,y = 0, z = 0;
	printf_s("����Ҫ��������ֺ�λ��");
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
			puts("�������Ϸ������²���");
			printf_s("����Ҫ��������ֺ�λ��:\n");
			scanf_s("%d", &y);
			scanf_s("%d", &z);
			k = in_set(sqList, length, z, y);
			display(sqList, length);
		}
	} while (k==0);

	printf_s("����Ҫɾ�������ֵ�λ�ӣ�");
	scanf_s("%d", &x);
	int sign = delete_set(sqList,length,x,s);
	//����ͼ�һ�´�ӡ��������
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
	printf_s("�����˳�����Ϊ��%d\n", b);
	for (int i = 0; i <= b - 1; i++)
	{
		printf_s("%d", a[i]);
		putchar(' ');
	}
	putchar('\n');
}

int in_set(int sqList[], int &length, int q, int e) //�����������
{
	if (q<0||q>length||length==maxsize)
	{
		return 0;
	}

		for (int i=length-1;i>=q;--i)
		{
		
		sqList[i + 1] = sqList[i];//�����һλ����ƶ�
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
//������ ����
#include "stdio.h"
#include "windows.h"

typedef struct LNode //�ڵ㶨��
{
	int data;
	struct LNode *next;

}LNode;

//����ͷ�ڵ�ĵ�������,β�巨,���ַ���һ���Ǽ������룬һ�������鸳ֵ��
//������ʹ�ü�������
void createlistR(LNode *&head)
{
	head = (LNode *)malloc(sizeof(LNode));//��̬����ռ�,��Ūһ��ͷ���
	head->next = NULL;
	LNode *r = head; //ʹ��β�壬ָ��ĩβ�ڵ㣬������ͷ���
	LNode *p=NULL;//�µĽڵ�
	int n;
	scanf_s("%d", &n);
	for (int i =0;i<n;++i)
	{
		p = (LNode *)malloc(sizeof(LNode));
		p->next = NULL;
		scanf_s("%d", &(p->data));
		//����Ͳ��뷨�ķ�ʽһģһ��
		p->next = r->next;
		r->next=p;
		r = p;
		//ͷ�巨������Ҫrָ��ָ��ڵ�
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
//���һ��˳���Ĳ����ɾ��,p�ɲ���Ϊ0-length
int sqlist[max] = { 1,2,3,4,5,6,7,8,9,0,1,22,32 }
int length = 5;
//����һ�����뺯��,length��ʾ���Ȳ���ʾλ��
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
//����һ��ɾ��������ɾ���ض���λ�ã�ɾ��λ��Ϊ0-length-1

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

//����������,ͨ����������

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode;//����һ���ڵ�

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
		p->next = r->next;//���Բ�Ҫ��Ϊ����������ü���
		r->next = p;
		r = p;
		//ͷ�巨������Ҫrָ��ָ��ڵ�
		//p-next=head->next;
		//head->next=p;
	}
}

//��Ŀһ ������������ĸ��n(���ٸ�)��c1,c2,....c26�����뵥�����У����Ҳ����ظ���
typedef struct  LNode
{
	int data;
	struct LNode *next;

}LNode;

void createlist(LNode *&head)
{
	head = (LNode *)malloc(sizeof(LNode));
	head - next = NULL;
	LNode *p, *r;//p���������½ڵ㣬rβ�巨
	r = head;
	int n;
	char ch;
	scanf("%d", &n)
		for (int i = 0; i < n; ++i)
		{
			p = (LNode *)malloc(sizeof(LNode));
			p->next = NULL;
			scanf("%c", &ch);
			//�ж�
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
				//����
				p->data = ch;
				p->next = r->next;
				r->next = p;
				r = p;
			}
		}
}

//����,˳���

for (int i = 0, j = length - 1; i < j; i++, j--)
{
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
	 code 
}

//��������
LNode *t;
while (p->next != q)//p�ǵ�һ���ڵ��ǰһ���ڵ㣬q��
{
	t = p->next;
	p->next = t->next;
	t->next = q->next;
	q->next = t;
}

//��Ŀ ��n���ȵ�����ǰk��Ԫ�������ŵ����
void reserve(int a[], int left, int right, int k)
{
	int temp;
	for (int i = left, j = right; i < k + left && i < j; ++i)//i<j��ֹ�ظ�����
	{

		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	//���ʱ��˳��ǰ�淢���˱仯��������ĿûҪ�����ǾͿ���ǰk�κͺ�k�ν���
}

//��n�������ǰk��Ԫ��˳��ķŵ�������,���øոյķ���
void movetoend(int a[], int n, int k)
{
	reserve(a, 0, k - 1, k);
	reserve(a, 0, n - 1, k);
}
//������ѭ������p��λ��
void leftmove(int a[], int n, int p)
{
	reserve(a, 0, p - 1, p);
	reserve(a, p, n - 1, n - p);
	reserve(a, 0, n - 1, n);
}

//ȡ��ֵ ˳���򵥾Ͳ�д�ˣ�ע��ʹ�ñ��min=�ô��ֵ��max=��С��ֵ������=���е�ֵ
//ȡ��ֵ��������
LNode *p, *q;//q���ڱ��
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

//˫����{llink��data��rlink},�ҵ�dataֵ���Ľڵ�(ֻ��һ��)���ŵ���ǰ��
typedef struct DNode
{
	int data��
		struct DNode *llink;//prior
	sruct DNode *rlink;//next
}DNode;

void maxFisrt(DNode *head)//��д��������������ʱ��
						  //���ǵ��õ���ͷ�ڵ㣬������������*&head���ڴ���������
{
	DNode *p = head->rlink, *q = p;//p���ڱ��
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
	q->llink->rlink = q->rlink;//ɾ������������鷳��������һ��
	if (q - rlink != NULL)
	{
		q->rlink->lleft = q->llink;
	}
	//	DNode *l=q->llink,*r=q->rlink;//�������������
	// l-rlink=r;
	//if(r!=NULL)r=link=l;	
	//���뵽ͷ�ڵ��
	q->rlink = head->rlink;
	q = head->rlink->llink;
	head = q->rlink;
	head->rlink = q;
}

//�鲢����·�鲢��
//˳���鲢������,ֵ��ѧϰ��˼��
void merge(int a[], int m, int b[], int n, int c[])
{
	//��Ҫ��һ�Ƚϣ����ǱȽ϶̵ģ��ȱȽ���ϣ���ǰ��if(m<n)������Ҳ����ʡ����while
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

//����鲢
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
	//����Ҳ���ԣ�����̫�鷳��ע���������ץ��ͷ������
	if (p != NULL) r->next = p;
	if (q != NULL) r->next = q;
}

//����鲢��ı�˳���뷨ʹ��ͷ�巨
p->next = C->next;
C->next = p;
p = p->next;
//ʹ��ͷ�巨�Ѿ��޷�ʹ�����һ�β��룬��Ҫ�ĳ�while
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

//����,��ĳ��Ԫ��Ϊ��־�����Ҳ�һ����������Ŀ
//��һ�֣�2,-1,-9,-3,5,6,-1;˳�����2Ϊ���֣���߱�2С���ұ߱�2��
//ʹ��ʱ�临�ӶȾ����͵ķ�����i������ĵ�һ����j������ĵڶ���
//����j��ͬʱ�жϣ�һ��j���ڵ���ֵС��2����ֵ��i���ڵ�λ�ã�i++
//����i��ֱ��������2������֣�ֹͣ����i��ָ������ֵ��j����
//ֱ��ij��������i>=j��a[i]=temp(2)������
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
//�����ʱ���Ƚϵ�ֵ����temp�����Լ�ָ���ģ�comp,ֻ��Ҫ������
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
//�Ƚϵ�ֵ�����ֵ�����һ��ֵ�����������±�k��Ĭ��k��0-n-1��Χ��
void partition(int a[], int n��int k)
{
	int temp;
	int i = 0, j = n - 1;
	temp = a[i];//�����׸�Ԫ��
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
