#include "Student.h"
#include "Subject.h"
#include <iostream>

void main() {	//subject Ŭ���� �׽�Ʈ
	Subject sub1, sub2, sub3[2], * sub4;
	int i;
	sub1.initialize();
	sub2.initialize("������", 3, "A+");
	for (i = 0; i < 2; i++)
		sub3[i].initialize("��ǻ��", 3, "C");
	sub4 = new Subject[2];
	sub1.inputData(); // ȭ�鿡�� �Է�
	cout << "\n" << "sub1 ����" << "\n";
	sub1.printTitle(); sub1.printData();
	cout << "\n" << "sub2 ����" << "\n";
	sub2.printTitle(); sub2.printData();
	cout << "\n" << "sub3 ����" << "\n";
	sub3[0].printTitle();
	for (i = 0; i < 2; i++) sub3[i].printData();
	for (i = 0; i < 2; i++) (sub4 + i)->inputData();
	cout << "\n" << "sub4 ����" << "\n";
	sub4->printTitle();
	for (i = 0; i < 2; i++) (sub4 + i)->printData();
	delete[] sub4;
}

// void main() {	//student Ŭ���� �׽�Ʈ
// 	Subject sub[2];
// 	sub[0].Initialize("��ǻ��", 3, "C");
// 	sub[1].Initialize("���빫��", 2, "A");
// 	Student st1, st2;
// 	st1.Initialize();
// 	st2.Initialize("ȫ�浿", 2013909845, 2, sub);
// 	st1.InputData();
// 	cout << "\n" << "st1 ����" << "\n";
// 	st1.PrintData();
// 	cout << "\n" << "st2 ����" << "\n";
// 	st2.PrintData();
// 	st1.Remove();
// }

// #include "Subject.h"
// #include "Student.h"
// #include <iostream>
// using namespace std;
// void ShowData(const Student&);
// void main() {
// 	Student st;
// 	// ��ü �Է� �� ��� ����
// 	Subject sub[2];
	
// 	st.Initialize("ȫ�浿", 2013909845, 2, sub);

// 	ShowData(st);
// }
// void ShowData(const Student& s) { //�����Լ�
// 	cout << s.m_name << "�� ������ ������ ��" << s.m_subnum << "����";
	
// 	cout << "������ ������ ���������" << s.m_aveGPA << "�Դϴ�.\n";
// }