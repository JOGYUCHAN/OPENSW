#include <iostream>
using namespace std;
//2019038055������
template < typename T>
//���ø� T����


void Sort(T* arr, int size)//���ø�T�� ���ڷ� ����Ͽ� ȣ��Ǵ� ������ �ڷ����� ���� �ٸ� ������Ÿ�Կ�� ���
{
	for (int i = 0; i < size - 1; i++)// ���������� ���� �迭�� ����
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main()
{
	char menu;
	while (true)
	{
		cout << "1. ���� ����\n";
		cout << "2. �Ǽ� ����\n";
		cout << "3. ����\n";
		cout << "�޴� ����: ";
		cin >> menu;
		//3�� ������� ����
		if (menu == '3')
			break;
		switch (menu)
		{
		case '1':
		{//������ �޴� ���
			int arr[5];
			cout << "5���� ������ �Է��ϼ���: ";
			for (int i = 0; i < 5; i++)
				cin >> arr[i];
			Sort(arr, 5);//int�� ���� arr�� ����� ȣ���Ͽ� T = int�� ������ ����
			cout << "���� ��� : ";
			for (int i = 0; i < 5; i++) 
				cout << arr[i] << " ";
			cout << "\n";
			break;
		}
		case '2':
		{//�Ǽ��� �޴� ���
			double arr[5];
			cout << "5���� �Ǽ��� �Է��ϼ���: ";
			for (int i = 0; i < 5; i++)
				cin >> arr[i];
			Sort(arr, 5);//double�� ���� arr�� ����� ȣ���Ͽ� T = int�� ������ ����
			cout << "���� ��� : ";
			for (int i = 0; i < 5; i++)
				cout << arr[i] << " ";
			cout << "\n";
			break;
		}
		break;
		default:
		cout << "�߸� �Է��ϼ̽��ϴ�.\n";
		continue;
		}
	}
	return 0;
}