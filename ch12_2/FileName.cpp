#include <iostream>
using namespace std;
#include "opencv2/opencv.hpp"
using namespace cv;
int main(void)
{
	Mat src = imread("labelex.png", IMREAD_GRAYSCALE);
	if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }
	vector<vector<Point>> contours;
	Mat tmp;
	threshold(src, tmp, 150, 255, THRESH_BINARY_INV);
	findContours(tmp, contours, RETR_LIST, CHAIN_APPROX_NONE);
	Mat dst;
	dst = src.clone();
	for (int i = 0; i < contours.size(); i++) {
		int num = 0;
		for (int j = 0; i < contours[i].size(); j++) {
			num++;
		}
		line(dst, Point(contours[i][0]), Point(contours[i][num]), 30, 2);
		num = 0;
	}

	imshow("src", src);
	imshow("dst", dst);
	waitKey(0);
	return 0;
}