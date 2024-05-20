#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(void)
{
	//Q 2
	vector<vector<int>> score;
	int tot;
	double avg;

	cout << "네 과목의 점수 입력 : ";
	for (int i = 0; i < 3; i++) {
		vector<int> tmp;
		int a;
		for (int j = 0; j < 4; j++) {
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
		avg = tot / 4.0;
		cout << "총점:" << tot << "\t" << "평균:" << avg << endl;
	}



	return 0;
}
