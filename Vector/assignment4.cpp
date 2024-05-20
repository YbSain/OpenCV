#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(void)
{
	//assignment 4
	vector<vector<int>> a = { {-5, 2, 35}, {-20, 5, 100}, {-75, 5, -25} };
	vector<vector<int>> positive;

	for (int i = 0; i < a.size(); i++) {
		vector<int> tmp;
		for (int j = 0; j < a[i].size(); j++) {
			if (a[i][j] < 0) {
				a[i][j] = 0;
			}
			else if (a[i][j] > 0) {
				a[i][j] = 255;
			}
			tmp.push_back(a[i][j]);
		}
		positive.push_back(tmp);
	}
	cout << "수정행렬" << endl;
	for (int i = 0; i < positive.size(); i++) {
		for (int j = 0; j < positive[i].size(); j++) {
			cout << positive[i][j] << "\t";
		}
		cout << endl;
	}
	return 0;
}
