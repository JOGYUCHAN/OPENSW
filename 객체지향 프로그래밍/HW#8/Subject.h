#include <string>

#ifndef SUBJECT_H
#define SUBJECT_H

using namespace std;

class Subject {
protected:
	string m_name;	// �����
	int m_hakjum;	// ����
	string m_grade;	// ��� 
	float m_GPA;	// ����

public:
	void initialize();						// ������� �ʱ�ȭ
	void initialize(string sub_name, int hakjum, string grade);	// �Է¹��������� ������� �ʱ�ȭ
	void inputValue(int& int_num);
	void inputValue(string& str);
	void inputData();						// ������� �� �Է�
	void printTitle();		// Ÿ��Ʋ ���
	void printData();		// �� ���
	void calcGPA();			// ���� ���
	string getName();	// m_name ����
	int getHakjum();	// m_hakjum ����
	string getGrade(); 	// m_grade ����
	float getGPA();		// m_GPA ����
};

#endif
