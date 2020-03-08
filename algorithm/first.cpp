//例题一 北京邮电大学机试题进制转化
//https://www.nowcoder.com/kaoyan/retest/1005  二进制数
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
		//补充：二进制转化为十进制
		for (int i =0;i<binary.size();i++)
		{
		
				a+=binary[i] * pow(2, i);
		}
		cout << a <<endl;
	}
	//使用数组的做法
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

//例题2 长度为30以内的数字输入，十进制转化为二进制，再逆序排序转化为十进制 清华大学机试题
/*
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;


string Divide(string str, int x)  //字符串除法
{
		
	int reminder = 0;//余数
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

string Multiply(string str, int x)  //字符串乘法
{
	int carry = 0;//进位
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

string Add(string str, int x)  //字符串加法
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
		{  //二进制转化为十进制，就是二进制数的每一位都乘以2的相应位权
			answer = Multiply(answer, 2);
			answer = Add(answer, binary[i]);
			
		}
		cout << answer << endl;

	}

}
*/

//例题3 最大公约数 最小公倍数

#include<iostream>
#include<cstdio>

using namespace std;

//辗转相除法，原理：a和b的最大公约数等于b和a%b的最大公约数
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

//递归的
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
		printf_s("%d\n", GCD(a, b));//最大公约数
		printf_s("%d\n", a*b / GCD(a, b));//最小公倍数
	}
	return 0;
}
*/

//例题4 质数 ,输入一个数，输出1到这个数之间所有的质数
//方法一，质数判断之后在用for循环遍历出1-n之间的质数
/*
#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

bool Judge(int x)
{
	int count = 0;
	int bound = sqrt(x);
	if (x < 2) return false;
	else if (x==2) return true;
	else
	{
		if (x % 2 == 0) return false;
		else
		{
			for (int i = 3; i <=bound; i += 2)
			{
				if (x%i == 0)
				{
					count++;
				}
			}
			if (count == 0) return true;
			else return false;
		}
	}
}

int main()
{
	int n;
	while (scanf_s("%d", &n) != EOF)
	{
		for (int i = 2; i < n; i++)
		{
			int a = Judge(i);
			if (a == 1 && i%10==1) printf_s("%d\n", i);
		}

	}

}
*/
//方法二 质数筛选法
/*
#include<iostream>
#include<cstdio>
#include<cmath>
#include <vector>
#define  maxn 10001
using namespace std;

vector<int> prime;

bool signal[maxn];

int  Initial() 
{
	for (int i=0;i<maxn;i++)
	{
		signal[i] = true;
	}

	signal[0] = false;
	signal[1] = false;

	for (int i=2;i<maxn;i++)
	{
		if (signal==0)
		{
			continue;
		}
		else
		{	
		prime.push_back(i);
		for (int j=i*i;j<maxn;j+=i)
		{
			signal[i] = false;
		}
		}
	}
	return 0;
}

int main()
{
	Initial();
	int n;
	
	while (scanf_s("%d",&n)!=EOF) 
	{
		int count = 0;
		for (int i=2;i<prime.size()&&prime[i]<n;i++)
		{
			if (prime[i]%10==1)
			{
				printf_s("%d ", prime[i]);
				count++;
			}
		}
		if (count==0)
		{
			printf_s("%d", -1);
		}
	}
	return 0;
}
*/

//例题5  矩阵相乘  举个例子 2*3的与3*2的相乘
/*
#include<iostream>
#include<cstdio>
//#include <windows.h>
using namespace std;

int answer[2][2] = { 0 };

void  Multiply(int x[2][3], int y[3][2]) 
{
	
	for (int i=0;i<2;i++)
	{
		
		for (int j=0;j<2;j++)
		{
			
			for (int k=0;k<3;k++)
			{
				answer[i][j] += x[i][k] * y[k][j];
			}
		}
	}

}

void Print(int  x[2][2])
{
	for (int i=0;i<2;i++)
	{
		for (int j=0;j<2;j++)
		{
			printf_s("%d ", x[i][j]);
		}
		putchar('\n');
	}
}

int main() 
{
	int  x[2][3] = { 0 };
	int  y[3][2] = { 0 };

	for (int i=0;i<2;i++)
	{
		for (int j =0;j<3;j++)
		{
			scanf_s("%d", &x[i][j]);
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			scanf_s("%d", &y[i][j]);
		}
	}
	Multiply(x, y);
	Print(answer);
	//system("pause");
	return 0;
}
*/
//拓展 快速幂下的矩阵相乘
/*
#include <iostream>
#include <cstdio>

using namespace  std;

void Multiply(int resul[10][10],int a[10][10],int n) 
{
	int c[10][10];//用来暂时保存结果
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) c[i][j] = 0;
	}
	
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++)
		{

			for (int k = 0; k < n; k++)
			{
				c[i][j] += resul[i][k] * a[k][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) resul[i][j] = c[i][j];
	}

}



	


void Print(int  x[10][10],int c)
{
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf_s("%d ", x[i][j]);
		}
		putchar('\n');
	}
}

int main() 
{
	//单位矩阵
	
	int reslut[10][10] = { 0 };
	int n, k;
	int init[10][10] = { 0 };
	
	while (scanf_s("%d%d",&n,&k)!=EOF)
	{
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				scanf_s("%d", &init[i][j]);
				//reslut[i][j] = init[i][j];
			}
		}

		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				if (i==j){
					reslut[i][j] = 1;
				}
			}
		}

		while (k!=0)
		{
			if (k%2==1)
			{
				Multiply(reslut, init,n);
			}
			k /= 2;
			Multiply(init, init, n);
		}

			
		Print(reslut,n);
		

	}

	return 0;
}
*/

//例题6 叠框问题 地址杭电oj 题号2074

#include<iostream>
#include<cstdio>
#include<windows.h>
using namespace std;

char matrix[80][80];


int main() 
{
	int n;
	char  a, b;
	while (scanf_s("%d%c%c",&n,&a,&b)!=EOF)
	{

		for (int i=0;i<n/2;i++)
		{
			int j = n - i - 1;
			int length = n - 2 * i;
			char c;
			if ((n/2-i)%2==0)
			{
				c = a;
			}
			else c = b;
			for (int k=0;k<length;k++)
			{
				matrix[i][i + k] = c;
				matrix[i + k][i] = c;
				matrix[j][j -k] = c;
				matrix[j - k][j] = c;
			}
		}

		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				printf_s("%c", matrix[i][j]);
			}
			putchar('\n');
		}
	}

	
	return 0;
}
