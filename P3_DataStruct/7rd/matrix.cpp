//һ����Ȥ�ľ���������
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
class Mat;
Mat factor_value();
Mat term_value();
Mat expression_value();
bool check(const Mat &a, const Mat &b, int flag); //��Χ���

class Mat
{
  public:
	int row, col; //��Ա����
	int *p;
	Mat(int row, int col); //���캯��
	Mat(int row, int col, int *p);
	Mat(const Mat &a);			 //���ƹ��캯��
	~Mat();						 //��������
	Mat operator=(const Mat &a); //���ظ�ֵ�����
	Mat operator+(const Mat &a); //���ؼӷ������
	Mat operator-(const Mat &a); //���ؼ��������
	Mat operator*(const Mat &a); //���س˷������
	Mat operator!();			 //����ת�������
	int *operator[](int n);		 //���������������
};
Mat::Mat(int row, int col) : row(row), col(col)
{
	p = new int[row * col];
	memset(p, 0, row * col);
}
Mat::Mat(int row, int col, int *p) : row(row), col(col), p(p)
{
}
Mat::Mat(const Mat &a)
{
	row = a.row;
	col = a.col;
	p = new int[row * col];
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			*(p + col * i + j) = *(a.p + col * i + j);
}
Mat::~Mat()
{
	delete[] p;
}
bool check(const Mat &a, const Mat &b, int flag = 0)
{
	if (!flag)
		return a.row == b.row && a.col == b.col;
	else
		return a.col == b.row;
}
Mat Mat::operator=(const Mat &a)
{
	int *np = new int[a.row * a.col];
	for (int i = 0; i < a.row; ++i)
		for (int j = 0; j < a.col; ++j)
			*(np + a.col * i + j) = *(a.p + a.col * i + j);
	row = a.row;
	col = a.col;
	int *tmp = p;
	p = np;
	delete[] tmp;
	return *this;
}
Mat Mat::operator+(const Mat &a)
{
	int *np = new int[row * col];
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			*(np + col * i + j) = *(p + col * i + j) + *(a.p + col * i + j);
	return Mat(row, col, np);
}
Mat Mat::operator-(const Mat &a)
{
	int *np = new int[row * col];
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			*(np + col * i + j) = *(p + col * i + j) - *(a.p + col * i + j);
	return Mat(row, col, np);
}
Mat Mat::operator*(const Mat &a)
{
	int *np = new int[row * a.col];
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < a.col; ++j)
		{
			*(np + a.col * i + j) = 0;
			for (int l = 0; l < col; ++l)
				*(np + a.col * i + j) = *(p + col * i + l) * *(a.p + a.col * l + j);
		}
	}
	return Mat(row, a.col, np);
}
Mat Mat::operator!()
{
	int *np = new int[col * row];
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			*(np + row * j + i) = *(p + col * i + j);
	return Mat(col, row, np);
}
int *Mat::operator[](int n)
{
	int *np = p + col * n;
	return np;
}
ostream &operator<<(ostream &out, Mat &a)
{ //�������������
	out << "RANK = " << a.row << " * " << a.col << endl;
	for (int i = 0; i < a.row; ++i)
	{
		for (int j = 0; j < a.col; ++j)
		{
			out << *(a.p + a.col * i + j) << " ";
		}
		out << endl;
	}
	return out;
}
vector<Mat> all;
Mat expression_value()
{
	Mat result = term_value();
	while (1)
	{
		char op;
		op = cin.peek();
		if (op == '+' || op == '-')
		{
			getchar();
			Mat next = term_value();
			if (check(result, next))
			{
				if (op == '+')
					result = result + next;
				else
					result = result - next;
			}
			else
				return Mat(-1, -1);
		}
		else
			break;
	}
	return result;
}
Mat term_value()
{
	Mat result = factor_value();
	while (1)
	{
		char op;
		op = cin.peek();
		if (op == '*')
		{
			getchar();
			Mat next = factor_value();
			if (check(result, next, 1))
				result = result * next;
			else
				return Mat(-1, -1);
		}
		else
			break;
	}
	return result;
}
Mat factor_value()
{
	char op;
	op = cin.peek();
	if (op == '!')
	{
		getchar();
		int n;
		scanf("%d", &n);
		if (n > 0 && n - 1 < all.size())
			return !all[n - 1];
		else
			return Mat(-1, -1);
	}
	else if (op == '(')
	{
		getchar();
		Mat result = expression_value();
		getchar();
		return result;
	}
	else
	{
		int n;
		scanf("%d", &n);
		if (n > 0 && n - 1 < all.size())
			return all[n - 1];
		else
			return Mat(-1, -1);
	}
}
int main(void)
{
	char list[] = ("����˵���\n1.mm - ��������\n2.dm - ɾ������\n3.l(a)m - �鿴(����)����\n4.mc - ��������\n5.q - �˳�����\n");
	printf("%s", list);
	while (1)
	{
		putchar(':');
		char cmd[100];
		cin.getline(cmd, 100);
		while (cmd[0] == '\0')
			cin.getline(cmd, 100);
		if (strcmp(cmd, "mm") == 0)
		{
			int row, col;
			printf("������ң�\nrow = ");
			scanf("%d", &row);
			printf("col = ");
			scanf("%d", &col);
			int *p = new int[row * col];
			printf("������%d*%d������\n", row, col);
			for (int i = 0; i < row; ++i)
				for (int j = 0; j < col; ++j)
					scanf("%d", p + col * i + j);
			all.push_back(Mat(row, col, p));
			printf("�����ɹ���Ϊ����%d\n", all.size());
		}
		else if (strcmp(cmd, "dm") == 0)
		{
			printf("���������Ҫɾ���ĸ�����\n");
			int n;
			scanf("%d", &n);
			if (0 < n && n < all.size() + 1)
			{
				vector<Mat>::iterator i = all.begin();
				all.erase(i + n - 1);
				printf("ɾ���ɹ����˺����о���ǰ��һ��\n");
			}
			else
				printf("���뷶Χ����\n");
		}
		else if (strcmp(cmd, "lm") == 0)
		{
			printf("���������Ҫ�鿴�ĸ�����\n");
			int n;
			scanf("%d", &n);
			if (0 < n && n < all.size() + 1)
				cout << all[n - 1];
			else
				printf("���뷶Χ����\n");
		}
		else if (strcmp(cmd, "lam") == 0)
		{
			if (all.size())
			{
				for (int i = 0; i < all.size(); ++i)
				{
					printf("MATRIX %d\n", i + 1);
					cout << all[i];
				}
			}
			else
				printf("���κξ���Ԫ��\n");
		}
		else if (strcmp(cmd, "mc") == 0)
		{
			printf("���������Ҫ�����ʽ�ӣ�\n");
			Mat result = expression_value();
			if (result.row == -1 && result.col == -1)
				printf("���ʽ����\n");
			else
				cout << result;
		}
		else if (strcmp(cmd, "q") == 0)
		{
			printf("��ӭ�´�ʹ�ã�\n");
			break;
		}
		else
			printf("δ֪����\n");
	}
	return 0;
}
