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
/*
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

		for (int i=0;i<=n/2;i++)
		{
			int j = n - i - 1;
			int length = n - 2 * i;
			char c='0';
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
		if (n!=1)
		{
			matrix[0][0] = ' ';
			matrix[0][n - 1] = ' ';
			matrix[n - 1][0] = ' ';
			matrix[n - 1][n - 1] = ' ';
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
*/

//例题7 日期 输入年月日 ,计算该天是本年的第几天 这类问题的关键是在于闰年(二月)的问题
/*
#include<iostream>
#include <cstdio>
#include <windows.h>
using namespace std;

int daytab [2][13]= {
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}
};

bool Judge(int year) {
	return(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int  Judgeday(int year) {
	if (Judge(year))
	{
		return 366;
	}
	else  return 365;
}

int main() 
{
	int count;
	scanf_s("%d", &count);
	int year, month, day,num;

	while (count--)
	{
		scanf_s("%d%d%d%d", &year, &month, &day, &num);
		//算出当前日期的总天数
		int row = Judge(year);
		
		for (int i=0;i<month;i++)
		{
			num += daytab[row][i];
		}
		num += day;
		//再反求出年份
		while(num>Judgeday(year))
		{
			num -= Judgeday(year);
			year++;
		}
		//再反求出月份
		month = 0;
		int row_1 = Judge(year);
	
		int i = 0;
		while (num>daytab[row_1][i])
		{
			num -=daytab[row_1][i];
			i++;
			month++;
		}
		

		day = num;

		printf_s("%04d-%02d-%02d\n", year, month, day);
		

	}
	system("pause");
	return 0;

}
*/

//排序  调用sort函数
/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string> //输入string的时候一定使用VS一定要写这个

using namespace std;

struct Student
{
	string name;
	int num;
	int score;
};

bool CompareDes(Student x, Student y) {
	if (x.score == y.score) {
		return x.num < y.num;
	}
	else {
		return x.score > y.score;
	}
}

bool CompareAsc(Student x, Student y) {
	if (x.score == y.score) {
		return x.num > y.num;
	}
	else {
		return x.score > y.score;
	}
}

int main() {
	int n, way;
	while (scanf_s("%d%d",&n,&way)!=EOF){
		Student arr[100];
		
		for (int i=0;i<n;i++)
		{
			cin >> arr[i].name>>arr[i].score  ;
			arr[i].num = i;
		}
		if (way==0)
		{
			sort(arr, arr + n, CompareDes);
		}
		else sort(arr, arr + n, CompareAsc);
		
		for (int i=0;i<n;i++)
		{
			cout << arr[i].name << arr[i].score << endl;
		}
	}
	return 0;
}
*/

//排序 sort函数多种编写方法
/*
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int  arr[10];


bool Compare(int x, int y) {
	
	 if (x%2==1&&y%2==1)
	{
		return x > y;
	}
	else if(x%2==0&&y%2==0)
	{
		return x < y;
	}
	else return x % 2 > x % 2;

}


int main() {

	while (scanf_s("%d", &arr[0]) != EOF)
	{
		for (int i = 1; i < 10; i++) {
			scanf_s("%d", &arr[i]);
		}

		sort(arr, arr + 10, Compare);


	

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << ' ';
	}
	putchar('\n');

	}
	return 0;
}
*/

//排序 线性排序
/*
#include <iostream>
#include <cstdio>
#include <cstring>

const int MAXN = 1000010;
const int RANGE = 500000;

using namespace std;


int arr[MAXN];
int num[MAXN];
int main() {
	int n, m;
	while (scanf_s("%d%d",&n,&m))
	{
		memset(num, 0, sizeof(num));
		memset(arr, 0, sizeof(arr));
		for (int i=0;i<n;i++)
		{
			scanf_s("%d", &arr[i]);
			num[arr[i] + RANGE]++;
		}
		int index = 0;
		for (int i=0;i<MAXN;i++)
		{
			while (num[i]--)
			{
				arr[index++] = i - RANGE;
			}
		}

		for (int i=n-1;i>=m-n;i--)
		{
			if (i=m-n)
			{
				printf_s("%d\n", arr[i]);
			}
			else printf_s("%d ", arr[i]);
		}

		

	}

	return 0;

}
*/

//排序 归并排序
/*
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int arr[100] = {0};
int temp[100] = {0};

int num = 0;
void Combine( int left, int middle, int right) {

	int i = left;
	int j = middle + 1;
	int t = 0;
	while (i<=middle&&j<=right)
	{
		if (arr[i]<=arr[j])
		{
			temp[t++] = arr[i++];
		}
		else
		{
			num += (middle - i + 1);
			temp[t++] = arr[j++];
		}
					
	}

	while (i<=middle)
	{
		temp[t++] = arr[i++];
	}
	while (j<=right)
	{
		temp[t++] = arr[j++];
	}
	t = 0;
	while (left<=right)
	{
		arr[left++] = temp[t++];
	}
	
		
}


void MergeSort(int left,int right) {
	
	if (left<right)
	{
		int middle = (left + (right - left) / 2);//使用之处理方式就不会溢出，两数相加时
		MergeSort( left, middle);
		MergeSort( middle+1, right);
		Combine(left, middle, right);
	}
}

int main() {

	int n;
	while (scanf_s("%d",&n)!=EOF)
	{
	//	memset(arr, 0, sizeof(arr));
	//	memset(temp, 0, sizeof(temp));
		for (int i = 0; i < n;i++) {
			scanf_s("%d", &arr[i]);
		}
		MergeSort(0, n-1);

		for (int i=0;i<n;i++)
		{
			printf_s("%d ", arr[i]);
		}
		printf_s("%d", num);
	}



	return 0;
}
*/

// 查找——lower_bound 大于等于要找数值的第一个位置 ,北邮机试——查找
/*
#include<iostream>
#include<cstdio>
#include<algorithm>


using namespace std;



int main() {
	int n,m;
	int arr[100];
	int target;
	while (scanf_s("%d",&n)!=EOF)
	{
		for (int i=0;i<n;i++)
		{
			scanf_s("%d", &arr[i]);
		}
		
		sort(arr, arr + n);
		scanf_s("%d", &m);
		for (int i=0;i<m;i++)
		{
			scanf_s("%d", &target);
			int flag = lower_bound(arr, arr + n, target) - arr;//lower_bound 返回的是地址，所以需要减去arr的地址，才能得到下班
			if (flag!=n&&arr[flag]==target)
			{
				printf_s("yes\n");
			}
			else printf_s("no\n");
		}
		
		
	}

	return 0;

}
*/