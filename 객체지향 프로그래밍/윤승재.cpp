/***************************************************************/
/*             HW#4 : ����ó�����α׷�#3                       */
/*  �ۼ��� : ������                    ��¥ : 2022�� 4�� 7��   */
/*                                                             */
/* ���� ���� :  �ζ��� �Լ��� �̿��Ͽ� ����ó�����α׷��� ���� */
/*              ��ü �л� ��� ����� ���� ���� ��� �߰�      */
/***************************************************************/

#include<iostream>
#include<string.h>
using namespace std;

struct Subject {
   char SubName[30];   //���� �̸�
   int Hakjum;         //���� ����
   char Grade[10];      //���� ���
   float GPA;         //���� ����
};

struct Student {
   char StdName[30];   //�л� �̸�
   int Hakbun;         //�й�
   Subject *Sub;   //����(�����Ҵ� �����Ŵϱ� �����ͷ�)
   int SubNum;         //���� ��
   float AveGPA;      //������ ��� ����
};

//Student std_arr[2];


void CalcGPA(Subject& sub) {      //������ ���� ���
   float Sub_score = 0;   //������ ���� ����

   if (strcmp(sub.Grade, "A+") == 0) Sub_score += 4.5;
   else if (strcmp(sub.Grade, "A") == 0) Sub_score += 4.0;
   else if (strcmp(sub.Grade, "B+") == 0) Sub_score += 3.5;
   else if (strcmp(sub.Grade, "B") == 0) Sub_score += 3.0;
   else if (strcmp(sub.Grade, "C+") == 0) Sub_score += 2.5;
   else if (strcmp(sub.Grade, "C") == 0) Sub_score += 2.0;
   else if (strcmp(sub.Grade, "D+") == 0) Sub_score += 1.5;
   else if (strcmp(sub.Grade, "D") == 0) Sub_score += 1.0;
   else if (strcmp(sub.Grade, "F") == 0) Sub_score += 0.0;

   // �������� ���� 
   sub.GPA = Sub_score * sub.Hakjum;

};

float CalcAvgGPA(Subject* sub) {
   float avg = 0;   //������� ����
   int time = 0;
   for (int i = 0;i < 3;++i) {
      avg += sub[i].GPA;   //avg�� �������� ���ϰ�
      time += sub[i].Hakjum;   //time�� ������ ���ؼ�
   }
   return (avg / time);   //�� �������� ����
};



Student* StdSearch(Student* pSt, int StudentNum) {   //�л� �Ѹ� �˻�
   char Std_name[30];   //�˻��� �̸� ���� �뵵
   cout << "�˻��� �л��� �̸��� �Է� : ";
   cin >> Std_name;
   //if(Std_name)
   for (int i = 0;i < 2;i++) {
      for (int j = 0; j < strlen(Std_name) && pSt[i].StdName[j] == Std_name[j] && strlen(Std_name) == strlen(pSt[i].StdName); j++) {   //j<�Է��� �̸����̸�ŭ �ݺ�, pSt�� ����� �̸��̶� �˻��� �̸�,���� ����
         if (j == strlen(Std_name) - 1) return &pSt[i];   //������ �ش� �л� ����
      }
   }
   return NULL;   //������ NULL ����
};

void PrintOneData(const Student& rSt) {   //�ּ� �޾Ƽ� ���   /�л� �Ѹ� ���
   cout.width(10);
   cout << "�̸� : " << rSt.StdName << "     �й� : " << rSt.Hakbun << "\n";
   cout.width(10);
   cout << "========================================================\n";
   cout.width(10);
   cout << "       �����    ��������    ������    ��������\n";
   for (int i = 0;i < rSt.SubNum;i++) {
      cout.width(10);
      cout << "          " << rSt.Sub[i].SubName << "          " << rSt.Sub[i].Hakjum << "          " << rSt.Sub[i].Grade << "          " << rSt.Sub[i].GPA << "\n";
   }
   cout << "========================================================\n";
   cout << "                                �������      " << "\t" << rSt.AveGPA << "\n\n";
};

void PrintAllData(const Student* pSt, int StudentNum) {//printonedata�� �ּ� �޾ƾ��ϴϱ� �����ͷ�, �л��� ��ŭ �ݺ�.   /�л� ���� ���
   cout.width(10);
   cout << "\n           ��ü �л� ���� ����\n";
   cout << "========================================================\n";

   for (int i = 0;i < StudentNum;i++) {
      PrintOneData(pSt[i]);      //�л� ����ŭ PinrtOneData �ݺ�
   }
};


inline void PrintMenu() {   //�޴� ���
   cout.width(10);
   cout << "===== �޴� =====\n";
   cout.width(10);
   cout << "1. �л� ���� �Է�\n";
   cout.width(10);
   cout << "2. ��ü �л� ���� ����\n";
   cout.width(10);
   cout << "3. �л� �̸� �˻�\n";
   cout.width(10);
   cout << "4. ��ü �л� ��� ����\n";
   cout.width(10);
   cout << "5. �л� ���� ����\n";
   cout.width(10);
   cout << "6. ���α׷� ����\n";
   cout.width(10);
   cout << "\n���ϴ� ����� �Է��ϼ��� : ";
};

inline void Input_Value(char* str) {
   cin >> str;
};

inline void Input_Value(int& i) {
   cin >> i;
};

void InputData(Student* pSt, int StudentNum) {   //pSt : ������ �л����������͸Ű�����, StudentNum : ��ü �л� ��
   for (int i = 0;i < StudentNum;i++)   {
      cout << "*" << i + 1<<" ��° �л� �̸��� �й��� �Է��ϼ���.\n";
      cout << "�̸� : ";
      Input_Value(pSt[i].StdName);
      cout << "�й� : ";
      Input_Value(pSt[i].Hakbun);
      pSt[i].SubNum = 0;
      cout << "������ ���� ���� �Է�";
      Input_Value(pSt[i].SubNum);
      pSt[i].Sub = new Subject[pSt[i].SubNum];
      cout << "*" << "������ ������ �� �������, ��������, �������� �Է��ϼ���.\n";
      for (int j = 0; j < pSt[i].SubNum; j++) {
         cout.width(10);
         cout << "������� : ";
         Input_Value(pSt[i].Sub[j].SubName);   
         cout.width(10);
         cout << "���� ������ : ";
         Input_Value(pSt[i].Sub[j].Hakjum);   
         cout.width(10);
         cout << "������(A+ ~f) : ";
         Input_Value(pSt[i].Sub[j].Grade);   
         cout << "\n";
         CalcGPA(*pSt[i].Sub);
      }
      pSt[i].AveGPA = CalcAvgGPA(pSt[i].Sub);
   }

}

void PrintAllStdList(const Student* pSt, int StudentNum) {   //�̸� �й��� ���
   cout << "�̸�\t\t" << "�й�\n";
   for (int i = 0; i < StudentNum; i++) {
      cout << pSt[i].StdName << "\t\t" << pSt[i].Hakbun << "\n";
   }
   cout << "\n\n";
}

void ModifyStdInfo(Student* pSt) { //�л� ���� ���� 
   Student* ChangeStd; //�ٲ� ���� �����ҰŶ� ������
   ChangeStd = StdSearch(pSt, 2);
   if (ChangeStd != NULL) { // ���� 
      cout << " (" << ChangeStd[0].StdName << ", " << ChangeStd[0].Hakbun << ")�� ������ �����ϼ���" << endl;
      cout << "�̸� : ";
      Input_Value(ChangeStd[0].StdName);
      cout << "�й� : ";
      Input_Value(ChangeStd[0].Hakbun);
   }
}

int main(){
   cout.precision(2);
   cout << fixed;

   int num = 0;
   int StdNum = 0;
   cout << "�л����� �Է��ϼ��� : ";
   cin >> StdNum;
   Student* std;
   std = new Student[StdNum];
   /*for (int i = 0;i < StdNum; i++)
      cout << std+i << "\n";*/

   while (1) {
      PrintMenu();
      cin >> num;
      if (num == 1){
            InputData(std, StdNum);
         }
         //   cout.width(10);
         //   cout << "\n" << "* " << n + 1 << " ��° �л� �̸��� �й��� �Է��ϼ���.\n";
         //   cout.width(10);
         //   cout << "�̸� : ";
         //   Input_Value(std[n].StdName);      //n��° �л� �̸� �Է¹ޱ�
         //   cout.width(10);
         //   cout << "�й� : ";
         //   Input_Value(std[n].Hakbun);      //n��° �л� �й� �Է¹ޱ�
         //   cout << "\n";

         //   cout.width(10);
         //   cout << "* ������ ���� 3���� �� �������, ��������, �������� �Է��ϼ���.\n";
         //   for (int i = 0;i < 3;++i) {      //n���л� ���� 3�� �Է�
         //      cout.width(10);
         //      cout << "������� : ";
         //      Input_Value(std[n].Sub[i].SubName);   //n��°�л� i��° ���� ������� �Է¹ޱ�
         //      cout.width(10);
         //      cout << "���� ������ : ";
         //      Input_Value(std[n].Sub[i].Hakjum);   //n��°�л� i��° ���� ������ �Է¹ޱ�
         //      cout.width(10);
         //      cout << "������(A+ ~f) : ";
         //      Input_Value(std[n].Sub[i].Grade);   //n��°�л� i��° ���� ������ �Է¹ޱ�
         //      cout << "\n";
         //      CalcGPA(std[n].Sub[i]);
         //   }
         //   cout << "\n\n\n";
         //   std[n].AveGPA = CalcAvgGPA(std[n].Sub);
         //}
      else if (num == 2)
         PrintAllData(std, StdNum);
      else if (num == 3) {
         Student* search;   //�˻��� search ����
         search = StdSearch(std, StdNum);
         if (search != NULL) PrintOneData(*search);   //������ ���
         else if (search == NULL) cout << "�˻��� �л��� �����ϴ�.\n";
      }
      else if (num == 4) {
         PrintAllStdList(std, StdNum);
      }
      else if (num == 5) {
         ModifyStdInfo(std);
      }
      else if (num == 6) {
         delete[] std;
         cout << "���α׷��� �����մϴ�.";
         break;
      }
      else {               //�޴� �̼��ý� �޴� �ٽ� ���
         //cout << "\n���ϴ� ����� �Է��ϼ��� : " << "\n";

         if (cin.fail())      //int�� �� �ڷ��� �Է¹޾����� ���ѹݺ����� �ذ�
            cout << "\n���ڸ� �Է����ּ���" << "\n";
         cin.clear(); // ������Ʈ���� �ʱ�ȭ
         cin.ignore(256, '\n'); // ���۸� ����   
      }
   }
   return 0;
}