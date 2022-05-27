#include <iostream>
#include <string>
#include <iomanip>
#include "Subject.h"
#include "Student.h"

using namespace std;

void Student::initialize() {
    m_name = "";
    m_sub = 0;
    m_hakbun = 0;
    m_subnum = 0;
    m_aveGPA = 0.0f;
}


void Student::initialize(string stdname, int hakbun, int subnum, Subject* sub) {
    m_name = stdname;
    m_sub = sub;
    m_hakbun = hakbun;
    m_subnum = subnum;
    m_aveGPA = calcAveGPA();
}

void Student::remove() {
    delete[] m_sub;
}

void Student::inputValue(int& int_num) {
    cin >> int_num;
    if (cin.fail()) {		//int�� �� �ڷ��� �Է¹޾����� ���ѹݺ����� �ذ�
        cout << "\n���ڸ� �Է����ּ���" << "\n";
        cin.clear(); // ������Ʈ���� �ʱ�ȭ
        cin.ignore(256, '\n'); // ���۸� ����	
        cin >> int_num;
    }
    cin.ignore();
}

void Student::inputValue(string& str) {
    getline(cin, str);
}

void Student::inputData() {
    int tmp_hakjum = 0;
    float tmp_gpa = 0.0f;

    cout << "�̸� :";
    inputValue(m_name);
    cout << "�й� :";
    inputValue(m_hakbun);
    cout << "���� �� :";
    inputValue(m_subnum);
    m_sub = new Subject[m_subnum];              

    for (int i = 0; i < m_subnum; i++)          
    {
        m_sub[i].inputData();
        tmp_hakjum += m_sub[i].getHakjum();    
        tmp_gpa += m_sub[i].getGPA();
    }

    m_aveGPA = tmp_gpa / (float)tmp_hakjum;
}

void Student::printData() {   
    cout << "\n====================================================================================\n"; 
    cout << "�̸� : " << m_name << setw(20) << "�й� : " << m_hakbun << "\n";  
 
    for (int i = 0; i < m_subnum; i++)
    {
        if (i == 0) //�л� ����� Ÿ��Ʋ �ѹ� ���
            m_sub[i].printTitle();
        m_sub[i].printData();
    }
}

float Student::calcAveGPA() {
    int tmp_hakjum = 0;
    float tmp_gpa = 0.0f;

    for (int i = 0; i < m_subnum; i++)
    {
        tmp_hakjum += m_sub[i].getHakjum();
        tmp_gpa += m_sub[i].getGPA();
    }

    m_aveGPA = tmp_gpa / (float)tmp_hakjum;
    return m_aveGPA;
}; // ��� ���� ���

string Student::getName() {
    return m_name;
}; // m_name ����
int Student::getHakbun() {
    return m_hakbun;
}; // m_hakbun ����
int Student::getSubNum() {
    return m_subnum;
}; // m_subnum ����
float Student::getAveGPA() {
    return m_aveGPA;
}; // m_aveGPA ����

