//����һ �����ʵ��ѧ���������ת��
//https://www.nowcoder.com/kaoyan/retest/1005  ��������
/*
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
int main() 
{
	unsigned int n;
	
	while (scanf_s("%d",&n)!=EOF)
	{
		int a = 0;
		vector<int> binary;
		while (n!=0)
		{
			binary.push_back(n % 2);
			n = n / 2;
		}
		for (int i=binary.size()-1;i>=0;--i)
		{
			cout << binary[i];
		}
		putchar('\n');
		//���䣺������ת��Ϊʮ����
		for (int i =0;i<binary.size();i++)
		{
		
				a+=binary[i] * pow(2, i);
		}
		cout << a <<endl;
	}
	//ʹ�����������
	//unsigned int n;
	//int count=0;
	//int saved[40] = { 0 };
	//while (scanf_s("%d",&n)!=EOF)
	//{
	//	count = 0;
	//	while(n!=0)
	//	{
	//			
	//			saved[count] = n % 2;
	//			n = n / 2;
	//			count++;
	//			
	//	
	//	}
	//
	//	for (int i=count-1;i>=0;i--)
	//	{
	//		printf_s("%d", saved[i]);
	//	}
	//
	//}
	//
	return 0;
}
*/

//����2 ����Ϊ30���ڵ��������룬ʮ����ת��Ϊ�����ƣ�����������ת��Ϊʮ���� �廪��ѧ������
/*
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;


string Divide(string str, int x)  //�ַ�������
{
		
	int reminder = 0;//����
	for (unsigned int i=0;i<str.size();++i)
	{
		int current = reminder * 10 + str[i] - '0';
		str[i] = current / x + '0';
		reminder = current % x;
	}
	int pos = 0;
	while (str[pos]=='0')
	{
		pos++;
	}
	return str.substr(pos);

}

string Multiply(string str, int x)  //�ַ����˷�
{
	int carry = 0;//��λ
	for (int i=str.size()-1;i>=0;i--)
	{
		int current = x * (str[i] - '0') + carry;
		str[i] = current % 10 + '0';
		carry = current / 10;
	}
	if (carry==1)
	{
		str = "1" + str;
	}
	return str;
}

string Add(string str, int x)  //�ַ����ӷ�
{
	int carry = x;
	for (int i=str.size()-1;i>=0;i--)
	{
		int current = (str[i] - '0') + carry;
		str[i] = current % 10 + '0';
		carry = current / 10;
	}
	if (carry==1)
	{
		str = str + "1";
	}

	return str;

}

int main() 
{
	string str;
	
	while (cin>>str)
	{
		vector <int> binary;
		while (str.size()!=0)
		{
			int last = str[str.size() - 1] - '0';
			binary.push_back(last % 2);
			str = Divide(str, 2);
		}
		string answer = "0";
		for (int i = 0; i <= binary.size()-1; i++)
		{  //������ת��Ϊʮ���ƣ����Ƕ���������ÿһλ������2����ӦλȨ
			answer = Multiply(answer, 2);
			answer = Add(answer, binary[i]);
			
		}
		cout << answer << endl;

	}

}
*/

//����3 ���Լ�� ��С������

#include<iostream>
#include<cstdio>

using namespace std;

//շת�������ԭ��a��b�����Լ������b��a%b�����Լ��
/*
int GCD(int a, int b)
{
	int r = 0;
	while (b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

//�ݹ��
int GCD(int a, int b) 
{
	if (b == 0) return a;
	else return GCD(b, a%b);
}

int main()
{
	int a, b;
	while (scanf_s("%d%d", &a, &b) != EOF)
	{
		printf_s("%d\n", GCD(a, b));//���Լ��
		printf_s("%d\n", a*b / GCD(a, b));//��С������
	}
	return 0;
}
*/

//����4 ����
