#include <iostream>
#include <string>
#include "Subject.h"

using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

class Student {
protected:
    string m_name; // �л���
    int m_hakbun; // �й�
    Subject* m_sub; // ������ �����
    int m_subnum; // ������ ���� ��
    float m_aveGPA; // ������ ������� ��� ����

public:
    void initialize(); // ������� �ʱ�ȭ
    void initialize(string stdname, int hakbun, int subnum, Subject* sub); // ���ڰ����� ������� �ʱ�ȭ
    void remove(); // �����޸� ����
    void inputValue(int& int_num);
    void inputValue(string& str);
    void inputData(); // ������� �� �Է�
    void printData(); // ������� �� ���
    float calcAveGPA(); // ��� ���� ���
    string getName(); // m_name ����
    int getHakbun(); // m_hakbun ����
    int getSubNum(); // m_subnum ����
    float getAveGPA(); // m_aveGPA ����
    friend void ShowData(const Student&);
};

#endif