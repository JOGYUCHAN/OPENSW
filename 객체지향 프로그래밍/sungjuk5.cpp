//2019038055 ������
#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
using namespace std;
int StdNum = 0;

void PrintMenu(void)//���α׷� ����� �޴�ȭ�� ���
{
    cout << "\n";
    cout << "------- �޴� ------" << endl;
    cout << "1. �л� ���� �Է�" << endl;
    cout << "2. ��ü �л� ���� ����" << endl;
    cout << "3. �л� �̸� �˻�" << endl;
    cout << "4. �л� ���� ����" << endl;
    cout << "5. ���α׷� ����\n" << endl;
    cout << "���ϴ� ����� �Է��ϼ��� : ";
}




struct Subject {//��������
    //char SubName[30];
    string SubName;
    int Hakjum;
    //char Grade[10];
    string Grade;
    float GPA;

};


struct Student {//�л�����
    //char StdName[30];
    string StdName;
    int Hakbun;
    Subject *Sub;
    int SubNum;
    float AveGPA;
};



void CalcGPA(Subject& Sub)// �Է¹��� string�� ���Ͽ� �������� ��� strcmp���� ==�����ڷ� ����
{

    if (Sub.Grade == "A+") {
        Sub.GPA = (float)(4.5) * (float)Sub.Hakjum; //����*����
    }
    else if ((Sub.Grade == "A") || (Sub.Grade == "A0")) {
        Sub.GPA = (float)(4.0) * (float)Sub.Hakjum; 
    }
    else if (Sub.Grade == "B+") {
        Sub.GPA = (float)(3.5) * (float)Sub.Hakjum;
    }
    else if ((Sub.Grade == "B") || (Sub.Grade == "B0")) {
        Sub.GPA = (float)(3.0) * (float)Sub.Hakjum;
    }
    else if (Sub.Grade == "C+") {
        Sub.GPA = (float)(2.5) * (float)Sub.Hakjum;
    }
    else if ((Sub.Grade == "C")|| (Sub.Grade == "C0")) {
        Sub.GPA = (float)(2.0) * (float)Sub.Hakjum;
    }
    else if (Sub.Grade == "D+") {
        Sub.GPA = (float)(1.5) * (float)Sub.Hakjum;
    }
    else if ((Sub.Grade == "D")|| (Sub.Grade == "D0")) {
        Sub.GPA = (float)(1.0) * (float)Sub.Hakjum;
    }
    else {
        Sub.GPA = (float)(0.0) * (float)Sub.Hakjum;
    }

}

float CalcAveGPA(Subject* sub, int num) {
	float avg = 0;	//������� ����
	int time = 0;
	for (int i = 0;i < num; ++i) {
		avg += sub[i].GPA;	//avg�� �������� ���ϰ�
		time += sub[i].Hakjum;	//time�� ������ ���ؼ�
	}
	return (avg / time);	//�� �������� ����
};

inline void InputValue(string& str)// ���ڿ��� ������ getline�� ���� �Է¹޴� �Լ��� inline�Լ��� ���� ���� �̸����� ����
{
    
   getline(cin,str);
   
   
}

inline void InputValue(int &num)
{
	cin >> num;
	if (cin.fail()) {		//int�� �� �ڷ��� �Է¹޾����� ���ѹݺ����� �ذ�
		cin.clear(); // ������Ʈ���� �ʱ�ȭ
		cin.ignore(256, '\n'); // ���۸� ����	
		cin >> num;
	}
}	



void InputData(Student *stu, int StudentNum)//�л����� ������� ����� ������ �Է¹޴� �Լ�, Student ����ü�� �л����� ��������
{
    for (int i = 0; i < StudentNum; i++ )// �л�����ŭ �ݺ�
    {
    cout << "\n";
    cout << "*" << i + 1 << " ��° �л� �̸��� �й��� �Է��ϼ���." << endl;
    cout.width(10);
    cout << "�̸� :";
    InputValue(stu[i].StdName);//InputValue�Լ�(���ڿ�)
    cout.width(10);
    cout << "�й� :";
    InputValue(stu[i].Hakbun);//InputValue�Լ�(����)
    cout.width(10);
    cout << "������ �����:";
    InputValue(stu[i].SubNum);
    stu[i].Sub = new Subject[stu[i].SubNum];  //����� �����Ҵ�
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "*" << "������ ������ �� �������, ��������, �������� �Է��ϼ���.\n";
        for (int j = 0; j < stu[i].SubNum; j++)
        {

            cout.width(10);
            cout << "������� :";
            cin.ignore();
            InputValue(stu[i].Sub[j].SubName);
            cout.width(10);
            cout << "���� ������ :";
            InputValue(stu[i].Sub[j].Hakjum);
            cout.width(10);
            cout << "������(A+ ~ F) :";
            cin.ignore();
            InputValue(stu[i].Sub[j].Grade);
            cout << "\n";
            CalcGPA(stu[i].Sub[j]);//�л��� ���� �������
        }
    
            stu[i].AveGPA = CalcAveGPA(stu[i].Sub, stu[i].SubNum);//�л��� ��������� ���

        
    }    
}


void PrintOneData(const Student& std)//����ü �迭�� ���� �Ǿ��ִ� �Լ��� ����� ������ �� �л��� ������ ���                                       //Stduent ����ü�� �迭�� ���� �θ��� �л� ���� 
{
        
        cout << " �̸� : " << std.StdName << "  �й� : " << std.Hakbun << endl;
        cout.width(10); cout << "========================================================" << endl;
        cout.width(10); cout << "�����";
        cout.width(10); cout << "��������";
        cout.width(10); cout << "������";
        cout.width(10); cout << "��������" << endl;
        cout.width(10); cout << "========================================================" << endl;
        for (int j = 0; j < std.SubNum; j++)//�ݺ��� - ����
        {
            cout.width(10); cout << std.Sub[j].SubName;
            cout.width(10); cout << std.Sub[j].Hakjum;
            cout.width(10); cout << std.Sub[j].Grade;
            cout.width(10); cout << std.Sub[j].GPA << endl;
        }
        cout << "========================================================" << endl;
        
        cout.width(50); cout << "������� : " << std.AveGPA << endl;
        cout << "\n" << endl;
    
}

void PrintAllData(const Student*pSt, int StudentNum)//printonedata �Լ��� �ι� ȣ���Ͽ� ��� �л��� ������ ���
   {
      cout << "       ��ü ��������" << endl;
      for(int i = 0; i < StudentNum; i++)
      {
          PrintOneData((pSt[i]));
      }
    
   }

Student* StdSearch(Student* pSt, int StudentNum){
	string Std_name;
	cout << "�˻��� �л��� �̸��� �Է� : ";
	cin.ignore();
	getline(cin, Std_name);
	if (pSt == NULL) {//�л� �Է¾��� �˻�ȣ��� ����
		return NULL;
	}
	for (int i = 0;i < 2;i++) {
		for (int j = 0; j < strlen(Std_name.c_str()) && pSt[i].StdName[j] == Std_name[j] && strlen(Std_name.c_str()) == strlen(pSt[i].StdName.c_str()); j++) {	//j<�Է��� �̸����̸�ŭ �ݺ�, pSt�� ����� �̸��̶� �˻��� �̸�,���� ����
			if (j == strlen(Std_name.c_str()) - 1) return &pSt[i];	//������ �ش� �л� ����
		}
	}
	return NULL;
}	//������ NULL ����// �л��̸�(inname)�� �Է¹޾�


Subject* SubSearch(const Student* pSt) {	// pSt : �л������� ��� Student ������ ����
	string searchSub;
	cout << "�˻� �� ���� �̸� : ";
	getline(cin, searchSub);	// Ư�� ���� �̸��� �Է� ��,
	for (int i = 0; i < pSt[0].SubNum; i++) {
		if (searchSub == pSt[0].Sub[i].SubName) {	// pSt.Sub[i]�� ����Ͽ� �ش� �������� �ִ��� Ž��
			return &pSt[0].Sub[i];					// ���ϰ� : �ش� �л��� Ư�� �������� �ִ� ���� �ּ�
		}
	}
	return NULL;
}


void ModifyStdInfo(Student* pSt, int stuNum) {
	Student* ChangeStd;
	ChangeStd = StdSearch(pSt, stuNum);	//�ٲ� �л� ���� �˻� ������ ����ü
	if (ChangeStd != NULL) {
		string info; //���л������� �Ǵ� ������������ ���ڿ� ����� string
		cout << "����(�л�����/��������) : ";
		InputValue(info); // Type �Է� �Լ� �����ε� �̿��� �Է� �Լ�
		if (info == "�л�����") {
			cout << "*( " << ChangeStd[0].StdName << ", " << ChangeStd[0].Hakbun << " )�� ������ �����ϼ���" << endl;
			cout << "�̸� : ";
			InputValue(ChangeStd[0].StdName);
			cout << "�й� : ";
			InputValue(ChangeStd[0].Hakbun);
		}
		else if (info == "��������") {
			Subject* Subinfo;	//����Ž�� ��� ���� ����ü1
			Subinfo = SubSearch(pSt); // ������ Ž��
			if (Subinfo != NULL) {		//Ž���� ���� ���� ����
				cout << "*( " << Subinfo[0].SubName << ", " << Subinfo[0].Hakjum << ", " << Subinfo[0].Grade << " )�� ������ �����ϼ���" << endl;
				cout << "������� : ";
				InputValue(Subinfo[0].SubName);
				cout << "�������� : ";
				InputValue(Subinfo[0].Hakjum);
				cout << "������ : ";
				InputValue(Subinfo[0].Grade);
				CalcGPA(Subinfo[0]);
				ChangeStd[0].AveGPA = CalcAveGPA(ChangeStd[0].Sub, ChangeStd[0].SubNum);	// ������ ��ް� �������� �ٲ�����Ƿ� ���� �ٽð��
			}
			else cout << "�˻��� ������ �����ϴ�.\n\n";
		}
		else
			cout << "�߸� �Է��Ͽ����ϴ�.\n\n";
	}
	else
		cout << "�˻��� �л��� �����ϴ�.\n\n";
}

int main(){//�����Լ�

    cout.precision(2);//�Ҽ��� �ι�°�ڸ����� ���
    cout << fixed;

    
    int i = 0; 
    char menu;
    cout << "�л����� �Է��ϼ��� : ";
    cin >> StdNum;
    Student* std;
    std = new Student[StdNum];// Student����ü�� �Է¹��� �л�����ŭ �����Ҵ�

    for (i = 0; i < StdNum; i++) {
        std[i].AveGPA = 0;}   // �л� �������� ������ �߻��Ͽ� ������ �ʱ�ȭ��3

    while (true)//while���� ���� '4'�� �Է��ϱ� ������ �ݺ��ǵ�����
    {

        PrintMenu();
        cin >> menu;

        if (menu == '5') {
            cout << "���α׷��� �����մϴ�.";  //while���� ���� '4'�� �Է��ϱ� ������ �ݺ��ǵ�����
            break;
        }
        switch (menu)//��ȣ�Է¿� ���� �ٸ� ���
        {
        case '1':
        {
            cin.ignore();
            InputData(std, StdNum);
            break;


        }

        case '2': { //���� ���� ���

            PrintAllData(std, StdNum);
            break;

        }


        case '3': 
         {
            
			Student* search;	//�˻��� search ����
			search = StdSearch(std, StdNum);
			if (search != NULL) PrintOneData(*search);	//������ ���
			else if (search == NULL) cout << "�˻��� �л��� �����ϴ�.\n";
            
            break;
         }

        case '4':
        {
            ModifyStdInfo(std,StdNum);
        }



        }
    }
    delete []std;//�����Ҵ� �� �޸� ����





}







