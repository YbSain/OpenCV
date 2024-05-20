#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(void)
{
	//vector 클래스 //(객체의 입출력)
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
	 //가능하면 위에 방식으로
	for (int i = 0; i < score.size(); i++)
		cout << score[i] << endl;

	return 0;
}
