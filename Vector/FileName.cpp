#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(void)
{
	//vector 클래스 (객체의 입출력)
	//vector<int> score;
	//int a;
	//cout << score.size() << endl; // 0
	//for (int i = 0; i < 4; i++)
	//{
	//	cin >> a;
	//	score.push_back(a);
	//}
	//for (int i = 0; i < score.size(); i++)
	//	cout << score.at(i) << endl;
	// 가능하면 위에 방식으로
	//for (int i = 0; i < score.size(); i++)
	//	cout << score[i] << endl;

	//vector<vector<int>> score;
	//cout << score.size() << endl; //// 0
	//for (int i = 0; i < 3; i++)
	//{
	//	vector<int> tmp;
	//	int a;
	//	for (int j = 0; j < 4; j++)
	//	{
	//		cin >> a;
	//		tmp.push_back(a);
	//	}
	//	score.push_back(tmp);
	//}
	//for (int i = 0; i < score.size(); i++)
	//{
	//	for (int j = 0; j < score[i].size(); j++)	////한 i행 에서의 j가 나 나올떄까지 \t 반복
	//		cout << score[i][j] << '\t';
	//	cout << endl;
	//}
	//// 멤버함수이용
	//for (int i = 0; i < score.size(); i++)
	//{
	//	for (int j = 0; j < score[i].size(); j++)
	//		cout << (score.at(i)).at(j) << '\t';
	//	cout << endl;
	//}

	//예제 1
	/*int num1[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	int num2[3][4] = { {1},{5,6},{9,10,11} };
	int num3[][4] = { {1},{2,3},{4,5,6} };
	int num4[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int num5[3][4] = { 1,2,3,4,5,6 };
	int num6[][4] = { 1,2,3,4,5,6 };
	int i, j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			printf("%5d", num1[i][j]);
		}
		printf("\n");
	}*/

	//예제 2
	/*vector<vector<int>> score;
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
	}*/

	//실습과제1

	//실습과제2
	/*vector<vector<int>> score;
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
	cout << "최우수 학생은 " << count + 1 << "번째 학생이고 평균점수는 " << max << "점이다.";*/
	
	
	return 0;
}

