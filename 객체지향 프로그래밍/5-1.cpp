#include <iostream>
#include <cstring>//strcmp�� ����ϱ� ������ ���ش�.
using namespace std;
//2019038055 ������

//����� ó������� ���ϴ� 4���� �Լ� Getmin�Լ��� �Ű����� Ÿ���� �ٸ��� ������ �ߺ����
//Getmin1 ������ �ּڰ�
int GetMin(int a, int b) {
	if (a > b) return b;
	else return a;
}

//Getmin2 �Ǽ��� �ּڰ�
double GetMin(double a, double b) {
	if (a > b) return b;
	else return a;
}

//Getmin3 ���ڿ� ��(strcmp���)
char *GetMin( char* a, char* b) {
	int min = strcmp(a, b);
	if (min > 0) return b;
	else return a;
}

//Getmin4 �迭�� �ּڰ�
int GetMin(int a[], int size) {
	int min = a[0];
	for (int i = 1; i < size; i++)
		if (min > a[i]) min = a[i];
	return min;
}


//main�Լ� - 4���� ��� ��� Getmin �Լ��� ȣ�������� �Ű������� Ÿ���� �ٸ��� ȣ���Ͽ� �ٸ� �Լ��� ����Ѵ�
int main() {
	int a, b;//����
	cout << "�ΰ��� ������ �Է��ϼ��� :";
	cin >> a >> b;
	cout << "�ּҰ��� "<< GetMin(a, b) <<"�Դϴ�.\n";
	double c, d;//�Ǽ�
	cout << "�ΰ��� �Ǽ��� �Է��ϼ��� :";
	cin >> c >> d;
	cout << "�ּҰ��� " << GetMin(c, d) <<"�Դϴ�.\n";
	char s1[20], s2[20];//���ڿ�
	cout << "�ΰ��� ���ڿ��� �Է��ϼ��� :";
	cin >> s1 >> s2;
	cout << "�ּҰ��� " << GetMin(s1, s2) <<"�Դϴ�.\n";
	int arr[] = { 2,19,34,387,1,45,78,45,11,29 };//�迭
	cout << "�迭�� ���� : ";
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << "\n�ּҰ��� "<< GetMin(arr, 10) <<"�Դϴ�.\n";
	return 0;
}