#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(void)
{
	//vector Ŭ���� //(��ü�� �����)
	vector<int> score;
	int a;
	cout << score.size() << endl; // 0
	for (int i = 0; i < 4; i++)
	{
		cin >> a;
		score.push_back(a);
	}
	for (int i = 0; i < score.size(); i++)
		cout << score.at(i) << endl;
	 //�����ϸ� ���� �������
	for (int i = 0; i < score.size(); i++)
		cout << score[i] << endl;

	return 0;
}
