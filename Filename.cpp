#include <iostream>
using namespace std;
#include "opencv2/opencv.hpp"
using namespace cv;
void setLabel(Mat& img, const vector<Point>& pts, const String& label)
{
	Rect rc = boundingRect(pts);
	rectangle(img, rc, Scalar(0, 0, 255), 2);
	putText(img, label, rc.tl(), FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 255));
}
void setLabel2(Mat& img, const vector<Point>& pts, const String& label)
{
	RotatedRect rot  = minAreaRect(pts);
	Point2f rectPoints[4];
	rot.points(rectPoints);

	Rect boundrec = boundingRect(pts);

	for (int i = 0; i < 4; i++) {
		line(img, rectPoints[i], rectPoints[(i + 1) % 4], Scalar(0, 255, 0), 2);
	}
}

int main(void)
{
	Mat img = imread("beta.png", IMREAD_COLOR);
	if (img.empty()) { cerr << "Image load failed!" << endl; return -1; }
	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	Mat bin;
	threshold(gray, bin, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);
	Mat dst;
	cvtColor(bin, dst, COLOR_GRAY2BGR);
	vector<vector<Point>> contours;
	findContours(bin, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);
	for (vector<Point> pts : contours) { // 하나의 외곽선 추출
		if (contourArea(pts) < 400) continue;
		vector<Point> approx;
		approxPolyDP(pts, approx, arcLength(pts, true) * 0.02, true);
		// 외곽선 근사화
		int vtc = (int)approx.size(); // 근사화된 점의 갯수

		if (vtc > 4) 
		{
			setLabel2(dst, pts, " ");
			
			setLabel(dst, pts, " "); 
		}
	}
	imshow("img", dst);
	waitKey(0);
	return 0;
}