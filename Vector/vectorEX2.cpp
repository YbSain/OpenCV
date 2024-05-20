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
		for (int j = 0; j < score[i].size(); j++)	////ÇÑ iÇà ¿¡¼­ÀÇ j°¡ ³ª ³ª¿Ã‹š±îÁö \t ¹Ýº¹
			cout << score[i][j] << '\t';
		cout << endl;
	}
	// ¸â¹öÇÔ¼öÀÌ¿ë
	for (int i = 0; i < score.size(); i++)
	{
		for (int j = 0; j < score[i].size(); j++)
			cout << (score.at(i)).at(j) << '\t';
		cout << endl;
	}

	return 0;
}
