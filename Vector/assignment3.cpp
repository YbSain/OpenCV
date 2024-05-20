#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(void)
{
	//½Ç½À°úÁ¦3
	vector<vector<int>> a = { {-5, 2, 35}, {-20, 5, 100}, {-75, 5, -25} };
	vector<int> b;
	int max = 0;

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[i].size(); j++) {
			b.push_back(a[i][j]);
			max = b[0];
		}
	}
	for (int i = 1; i < b.size(); i++) {
		if (b[i] > max) {
			max = b[i];
		}
	}
	cout << max;


	return 0;
}
