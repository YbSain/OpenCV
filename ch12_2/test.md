#include <iostream>
using namespace std;
#include "opencv2/opencv.hpp"
using namespace cv;
int main(void)
{
	Mat src = imread("char_c.png", IMREAD_GRAYSCALE);
	if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }
	vector<vector<Point>> contours_left;
	vector<vector<Point>> contours_right;
	vector<vector<Point>> contours;
	Mat tmp;
	threshold(src, tmp, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);
	findContours(tmp, contours, RETR_LIST, CHAIN_APPROX_NONE);
	Mat dst;
	dst = src.clone();
	cvtColor(dst, dst, COLOR_GRAY2BGR);
	Rect rectleft(0, 0, tmp.cols / 2, tmp.rows / 2);
	Rect rectright(tmp.cols / 2 -1, tmp.rows / 2 -1, tmp.cols, tmp.rows);
	Mat leftImage = tmp(rectleft);
	Mat rightImage = tmp(rectright);

	Rect rectlefthalf(0, 0, leftImage.cols / 2, leftImage.rows / 2);
	

	findContours(leftImage, contours_left, RETR_LIST, CHAIN_APPROX_NONE);
	findContours(rightImage, contours_right, RETR_LIST, CHAIN_APPROX_NONE);



	
	imshow("src", src);
	imshow("dst", dst);
	waitKey(0);
	return 0;
}
