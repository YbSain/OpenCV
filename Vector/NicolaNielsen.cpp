#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(void)
{
	//�ǽ�����2
	vector<vector<int>> score;
	int tot, max, avg, count = 0;
	vector<int> avgvec;

	for (int i = 0; i < 3; i++) {
		cout << i + 1 << "��° �л��� ����, ����, ���� ������ �Է�: ";
		vector<int> tmp;
		for (int j = 0; j < 3; j++) {
			int a;
			cin >> a;
			tmp.push_back(a);
		}
		score.push_back(tmp);
	}
	for (int i = 0; i < score.size(); i++) {
		tot = 0;
		for (int j = 0; j < score[i].size(); j++) {
			tot += score[i][j];
		}
		avg = tot / 3;
		avgvec.push_back(avg);
	}
	max = avgvec[count];
	for (int i = 1; i < avgvec.size(); i++) {
		if (avgvec[i] >= max)
		{
			max = avgvec[i];
			count = i;
		}
	}
	cout << "�ֿ�� �л��� " << count + 1 << "��° �л��̰� ��������� " << max << "���̴�.";


	return 0;
}
