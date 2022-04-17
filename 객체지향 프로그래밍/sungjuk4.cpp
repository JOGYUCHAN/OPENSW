//2019038055 ������ ������������ 3���� ���� ��������� ����ϴ� �Լ��� ���� ���� 
#include <iostream>
#include <cstring>  //�����, ���ڿ� �Է��� ���� �������
using namespace std;
int StdNum = 0;

void PrintMenu(void)//���α׷� ����� �޴�ȭ�� ���
{
    cout << "\n";
    cout << "------- �޴� ------" << endl;
    cout << "1. �л� ���� �Է�" << endl;
    cout << "2. ��ü �л� ���� ����" << endl;
    cout << "3. �л� �̸� �˻�" << endl;
    cout << "4. ���α׷� ����\n" << endl;
    cout << "���ϴ� ����� �Է��ϼ��� : ";
}




struct Subject {//��������
    char SubName[30];
    int Hakjum;
    char Grade[10];
    float GPA;

};


struct Student {//�л�����
    char StdName[30];
    int Hakbun;
    Subject *Sub;
    int SubNum;
    float AveGPA;
};


void CalcGPA(Subject& Sub)// if���� strcmp�� ����Ͽ� ����(���ڿ�)�� ����(�Ǽ�)�� ��ȯ�ϴ� �Լ� 
{

    if (strcmp(Sub.Grade, "A+") == 0) {
        Sub.GPA = (float)(4.5) * (float)Sub.Hakjum; //����*����
    }
    else if (strcmp(Sub.Grade, "A") == 0 || strcmp(Sub.Grade, "A0") == 0) {
        Sub.GPA = (float)(4.0) * (float)Sub.Hakjum; 
    }
    else if (strcmp(Sub.Grade, "B+") == 0) {
        Sub.GPA = (float)(3.5) * (float)Sub.Hakjum;
    }
    else if (strcmp(Sub.Grade, "B") == 0 || strcmp(Sub.Grade, "B0") == 0) {
        Sub.GPA = (float)(3.0) * (float)Sub.Hakjum;
    }
    else if (strcmp(Sub.Grade, "C+") == 0) {
        Sub.GPA = (float)(2.5) * (float)Sub.Hakjum;
    }
    else if (strcmp(Sub.Grade, "C") == 0 || strcmp(Sub.Grade, "C0") == 0) {
        Sub.GPA = (float)(2.0) * (float)Sub.Hakjum;
    }
    else if (strcmp(Sub.Grade, "D+") == 0) {
        Sub.GPA = (float)(1.5) * (float)Sub.Hakjum;
    }
    else if (strcmp(Sub.Grade, "D") == 0 || strcmp(Sub.Grade, "D0") == 0) {
        Sub.GPA = (float)(1.0) * (float)Sub.Hakjum;
    }
    else {
        Sub.GPA = (float)(0.0) * (float)Sub.Hakjum;
    }

}

   float CalcAveGPA(Subject* Sub,const Student& std) //��������� ����ϴ� �Լ� ����� avg�� ���� �������� ���� �� ������� ����
{
    float avg = 0;
    for(int i = 0; i < std.SubNum;i++){
        avg += (Sub + i)->GPA;
    }

   return avg / std.SubNum;
}

inline void InputValue(char *str)// ���ڿ��� ������ cin�� ���� �Է¹޴� �Լ��� inline�Լ��� ���� ���� �̸����� ����
{
    cin >> str;
}

inline void InputValue(int &num)
{
    cin >> num;
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
            InputValue(stu[i].Sub[j].SubName);
            cout.width(10);
            cout << "���� ������ :";
            InputValue(stu[i].Sub[j].Hakjum);
            cout.width(10);
            cout << "������(A+ ~ F) :";
            InputValue(stu[i].Sub[j].Grade);
            cout << "\n";
            CalcGPA(stu[i].Sub[j]);//�л��� ���� �������
        }
    
            stu[i].AveGPA = CalcAveGPA(&(stu[i].Sub[0]),stu[i]);//�л��� ��������� ���

        
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

Student* StdSearch(char *inname, Student *pSt, int StudentNum)// �л��̸�(inname)�� �Է¹޾� strcmp�� ����
                                                               // ����ü�� ����� �л� �̸�  �� ������ �����ϴ� �Լ�
   {   
      for (int i = 0; i < StudentNum; i++)
      {
         if (strcmp(inname, pSt[i].StdName) == 0)
            return &pSt[i];
      }

      cout << "�ش� �л��� �������� �ʽ��ϴ�." << endl;
      return 0;
   }   

int main()//�����Լ�
{
    cout.precision(2);//�Ҽ��� �ι�°�ڸ����� ���
    cout << fixed;

    
    int i = 0; 
    char menu;
    cout << "�л����� �Է��ϼ��� : ";
    cin >> StdNum;
    Student* std;
    std = new Student[StdNum];// Student����ü�� �Է¹��� �л�����ŭ �����Ҵ�

    for (i = 0; i < StdNum; i++) {
        std[i].AveGPA = 0;}   // �л� �������� ������ �߻��Ͽ� ������ �ʱ�ȭ��

    while (true)//while���� ���� '4'�� �Է��ϱ� ������ �ݺ��ǵ�����
    {

        PrintMenu();
        cin >> menu;

        if (menu == '4') {
            cout << "���α׷��� �����մϴ�.";  //while���� ���� '4'�� �Է��ϱ� ������ �ݺ��ǵ�����
            break;
        }
        switch (menu)//��ȣ�Է¿� ���� �ٸ� ���
        {
        case '1':
        {
           
            InputData(std, StdNum);
            break;


        }

        case '2': { //���� ���� ���

            PrintAllData(std, StdNum);
            break;

        }
        case '3': 
         {
            
            char inname[20];
            cout << "�˻� �� �л� �̸� : ";
            cin >> inname;
            Student *find = StdSearch(inname, std, 2);
            if (find != 0)
               PrintOneData(*find);
            
            break;
         }



        }
    }
    delete []std;//�����Ҵ� �� �޸� ����





}







