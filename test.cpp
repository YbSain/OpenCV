#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

Mat Save(250, 100, CV_8UC3, Scalar(255, 255, 255));
Mat src(500, 500, CV_8UC3, Scalar(255, 255, 255));

Point pt0ld;
void on_mouse(int event, int x, int y, int flags, void*);

int main(void)
{
	line(src, Point(0, 0), Point(0, src.rows - 1), Scalar(0, 0, 0), 2);
	line(src, Point(0, 0), Point(src.cols - 1, 0), Scalar(0, 0, 0), 2);
	line(src, Point(0, src.rows - 1), Point(src.cols - 1, src.rows - 1), Scalar(0, 0, 0), 2);
	line(src, Point(src.cols - 1, 0), Point(src.cols - 1, src.rows - 1), Scalar(0, 0, 0), 2);
	line(src, Point(500, 0), Point(500, src.rows - 1), Scalar(0, 0, 0), 2);
	line(src, Point(500, 100), Point(src.cols - 1, 100), Scalar(0, 0, 0), 2);
	/*putText(src, "SAVE", Point())*/
	line(src, Point(500, 200), Point(src.cols -1, 200), Scalar(0, 0, 0), 2);
	line(src, Point(500, 300), Point(src.cols - 1, 300), Scalar(0, 0, 0), 2);
	line(src, Point(500, 400), Point(src.cols - 1, 400), Scalar(0, 0, 0), 2);


	namedWindow("src");
	setMouseCallback("src", on_mouse);

	imshow("src", src);
	waitKey();
	return 0;
}

void on_mouse(int event, int x, int y, int flags, void*)
{
	switch (event) {		
	case EVENT_LBUTTONDOWN:
		pt0ld = Point(x, y);
	case EVENT_MOUSEMOVE:
		if (flags & EVENT_FLAG_LBUTTON) {
			line(src, pt0ld, Point(x, y), Scalar(0, 0, 0), 2);
			imshow("src", src);
			pt0ld = Point(x, y);
		}
		break;

	case EVENT_RBUTTONDOWN:
		return;
	}
}
