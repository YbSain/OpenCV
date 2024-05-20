#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(void)
{
	//실습과제2
	vector<vector<int>> score;
	int tot, max, avg, count = 0;
	vector<int> avgvec;

	for (int i = 0; i < 3; i++) {
		cout << i + 1 << "번째 학생의 국어, 영어, 수학 성적을 입력: ";
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
	cout << "최우수 학생은 " << count + 1 << "번째 학생이고 평균점수는 " << max << "점이다.";


	return 0;
}
