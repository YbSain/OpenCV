#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(void)
{
	//실습과제1
	vector<vector<int>> a = { {2, 4},{5, -5} };
	vector<vector<int>> b = { {-2, 3}, {0, -5 } };
	vector<vector<int>> sum{ {0,0},{0,0} };
	cout << "두 2차원 배열의 합: " << endl;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[i].size(); j++) {
			sum[i][j] = (a[i][j] + b[i][j]);
			cout << sum[i][j] << "\t";;
		}
		cout << endl;
	}
	return 0;
}
