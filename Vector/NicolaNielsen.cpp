#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(void)
{
	vector<vector<int>> score;
	cout << score.size() << endl; //// 0
	for (int i = 0; i < 3; i++)
	{
		vector<int> tmp;
		int a;
		for (int j = 0; j < 4; j++)
		{
			cin >> a;
			tmp.push_back(a);
		}
		score.push_back(tmp);
	}
	for (int i = 0; i < score.size(); i++)
	{
		for (int j = 0; j < score[i].size(); j++)	////한 i행 에서의 j가 나 나올떄까지 \t 반복
			cout << score[i][j] << '\t';
		cout << endl;
	}
	// 멤버함수이용
	for (int i = 0; i < score.size(); i++)
	{
		for (int j = 0; j < score[i].size(); j++)
			cout << (score.at(i)).at(j) << '\t';
		cout << endl;
	}

	return 0;
}
