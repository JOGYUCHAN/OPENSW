//2019038055������
#include <iostream>
#include <string>
#include <vector>//vectorŬ���� ��������� ������� ����
using namespace std;

struct WORD {//���ڿ��� ī��Ʈ ������ �����ϴ� ����ü
	string str;
	int count;
};

vector <WORD*> words;//vector Ŭ������ ����ü�� words�� ����

int FindWords(const string& s) { //FindWords�Լ� - 	���ڿ��� ������ �����ϸ� �󵵼��� ��ȯ�ϰ� �ƴ� �� -1 ��ȯ
	for(int i = 0; i<words.size(); i++){
		if(words[i]->str == s)
			return i;
	}
	return -1;
}

void CountWords(const string& s) {//CountWords�Լ� - FindWords�Լ����� -1��ȯ�� ����ü�� ���ο� �ܾ�� �߰��ϰ� ī��Ʈ�� 1�� ����
								  // �ƴ� �� ī��Ʈ +1
	int index = FindWords(s);

	if(index == -1) {
		WORD *pWord = new WORD;
		pWord->str = s;
		pWord->count = 1;
		words.push_back(pWord);//�� ���Ҹ� ����(ó�� �Էµ� ���ڿ�)
	}

	else {
		words[index]->count++;
	}
}

void PrintWords() {//PrintWords - �ܾ��� ������ �󵵼��� ���
	for(int i=0; i<words.size(); i++)
		cout << words[i]->str << " : " << words[i]->count << endl;
}

void RemoveAll() {//�󵵼��� ��� �� �ܾ ����
	for(int i=0; i<words.size(); i++)
		delete words[i];
}
int main() {
	cout << "���ڿ��Է�, Ctrl+Z ����" << endl;
	string buffer;
	
	while( cin >> buffer)//���ۿ� �Էµ� �� ���� vetor�� �̿��� �󵵼��� ����Ѵ�
		CountWords(buffer);

	PrintWords();
	RemoveAll();

	return 0;
}
