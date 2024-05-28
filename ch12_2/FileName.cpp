#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

int main(void)
{
	Mat src = imread("labelex.png");
	if (src.empty()) { cerr << "image load failed" << endl; return -1; }
	vector<vector<Point>> contours;
	Mat dst;
	cvtColor(src, dst, COLOR_BGR2GRAY);
	threshold(dst, dst, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);
	findContours(dst, contours, RETR_LIST, CHAIN_APPROX_NONE);
	
	for (int i = 0; i < contours.size(); i++) {
		for (int j = 0; j < contours[i].size(); j++) {
			line(src, contours[i][j], contours[i][j], Scalar(0, 0, 255), 2);
		}
	}
	imshow("result", src);

	waitKey();
	return 0;
}