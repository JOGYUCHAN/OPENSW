#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

class Subject {

private:
    string m_name; // ����� 
    int m_hakjum; // ����
    string m_grade; // ���
    float m_GPA; // ����

public:
    void initialize(); // ������� �ʱ�ȭ
    void initialize(string, int, string); // ���ڰ����� ������� �ʱ�ȭ
    void inputValue(int &);
    void inputValue(string &);
    void inputData(); // ������� �� �Է� // ���������� InputValue()�̿�
    void printTitle(); 
    void printData(); // ��������� ���� title Text ��� // ������� �� ���
    void calcGPA(); // ���� ���
    string getName();	// m_name ����
	int getHakjum();	// m_hakjum ����
	string getGrade(); 	// m_grade ����
	float getGPA();		// m_GPA ����
};

float convert_grade(string str) {
	if (strcmp(str.c_str(), "A+") == 0) return 4.5;
	else if (strcmp(str.c_str(), "A") == 0) return 4.0;
	else if (strcmp(str.c_str(), "B+") == 0) return 3.5;
	else if (strcmp(str.c_str(), "B") == 0) return 3.0;
	else if (strcmp(str.c_str(), "C+") == 0) return 2.5;
	else if (strcmp(str.c_str(), "C") == 0) return 2.0;
	else if (strcmp(str.c_str(), "D+") == 0) return 1.5;
	else if (strcmp(str.c_str(), "D") == 0) return 1.0;
	else if (strcmp(str.c_str(), "F") == 0) return 0.0;
};

void Subject::calcGPA() {
	m_GPA = m_hakjum * convert_grade(m_grade);
}

void Subject::initialize() {	//�ʱ�ȭ
	m_name = "";		// �����
	m_hakjum = 0;		// ��������
	m_grade = "";		// ������
	m_GPA = 0.0f;		// ��������
}

void Subject::initialize(string sub_name, int hakjum, string grade) {	//�Է¹��������� �ʱ�ȭ
	m_name = sub_name;
	m_hakjum = hakjum;
	m_grade = grade;
	m_GPA = m_hakjum * convert_grade(m_grade); 
}

void Subject::inputValue(int& int_num) {
	cin >> int_num;
	if (cin.fail()) {		//int�� �� �ڷ��� �Է¹޾����� ���ѹݺ����� �ذ�
		cout << "\n���ڸ� �Է����ּ���" << "\n";
		cin.clear(); // ������Ʈ���� �ʱ�ȭ
		cin.ignore(256, '\n'); // ���۸� ����	
		cin >> int_num;
	}
	cin.ignore();
}

void Subject::inputValue(string& str) {
	getline(cin, str);
}

void Subject::inputData() {		// �� �Է�
	cout << "���� : ";
	inputValue(m_name);
	cout << "���� : ";
	inputValue(m_hakjum);
	cout << "��� : ";
	inputValue(m_grade);

	calcGPA();
}

void Subject::printTitle() {
	cout.width(10);
	cout << "====================================================================================\n";
	cout.width(10);
	cout << "�����" << setw(20) << "��������" << setw(20) << "������" << setw(20) << "��������\n";
	cout << "====================================================================================\n";
}

void Subject::printData() {
	cout.width(10);
	cout << m_name << setw(20) << m_hakjum << setw(20) << m_grade << setw(20) << m_GPA<<"\n";
}

string Subject::getName() {		// �����
	return m_name;
}

int Subject::getHakjum() {		// ��������
	return m_hakjum;
}

string Subject::getGrade() {	// ������
	return m_grade;
}

float Subject::getGPA() {		// ��������
	return m_GPA;
}

int main() {
    Subject sub1, sub2, sub3[2], *sub4;
    int i;

    sub1.initialize();
    sub2.initialize("������", 3, "A+");

    for (i = 0; i < 2; i++) {
        sub3[i].initialize("��ǻ��", 3, "C");
        sub4 = new Subject[2];
    }

    sub1.inputData(); // ȭ�鿡�� �Է�
    cout << "\n" << "sub1 ����" << "\n";
    sub1.printTitle();
    sub1.printData();

    cout << "\n" << "sub2 ����" << "\n";
    sub2.printTitle();
    sub2.printData();

    cout << "\n" << "sub3 ����" << "\n";
    sub3[0].printTitle();
    for (i = 0; i < 2; i++) sub3[i].printData();
    for (i = 0; i < 2; i++) (sub4 + i)->inputData();
    cout << "ok";
    cout << "\n" << "sub4 ����" << "\n";
    sub4->printTitle();
    for (i = 0; i < 2; i++) (sub4 + i)->printData();
    delete[] sub4;

return 0;
}