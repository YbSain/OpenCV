#include <iostream>
using namespace std;
#include <opencv2/opencv.hpp>
using namespace cv;
int main(void
)
{
	uchar data[] = {
	0, 0, 1, 1, 0, 0, 0, 0,
	1, 1, 1, 1, 0, 0, 1, 0,
	1, 1, 1, 1, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 1, 0,
	0, 0, 0, 1, 1, 1, 1, 0,
	0, 0, 0, 1, 0, 0, 1, 0,
	0, 0, 1, 1, 1, 1, 1, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	};
	Mat src = Mat(8, 8, CV_8UC1, data)* 255;
	vector<vector<Point>> contours;
	findContours(src, contours, RETR_LIST, CHAIN_APPROX_NONE);

	cout << "외곽선의 갯수:" << contours.size() << endl;
	for (int i = 0; i < contours.size(); i++){
		vector<Point> tmp;
		cout << i << "번째 외곽선의 점의 좌표: ";
		for (int j = 0; j < contours[i].size(); j++) {
			cout << contours[i][j];
		}
		cout << endl;
	}
	return 0;
}