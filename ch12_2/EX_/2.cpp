﻿#include <iostream>
using namespace std;
#include "opencv2/opencv.hpp"
using namespace cv;
int main(void)
{
	Mat src = imread("contours.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }
	vector<vector<Point>> contours;
	findContours(src, contours, RETR_LIST, CHAIN_APPROX_NONE);
	Mat dst;
	cvtColor(src, dst, COLOR_GRAY2BGR);
	for (int i = 0; i < contours.size(); i++) {
		Scalar c(rand() & 255, rand() & 255, rand() & 255);
		drawContours(dst, contours, i, c, 2);
	}
	imshow("src", src);
	imshow("dst", dst);
	waitKey(0);
	return 0;
}
