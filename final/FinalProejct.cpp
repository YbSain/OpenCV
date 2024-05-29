#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

Mat src(500, 750, CV_8UC3, Scalar(255, 255, 255));

Point pt0ld;
void on_mouse(int event, int x, int y, int flags, void*);

int main(void)
{
	Mat save, load, clear, run, exit;
	save = src(Rect(500, 0, 250, 100));
	load = src(Rect(500, 100, 250, 100));
	clear = src(Rect(500, 200, 250, 100));
	run = src(Rect(500, 300, 250, 100));
	exit = src(Rect(500, 400, 250, 100));
	const String texts = "Save";
	const String textl = "Load";
	const String textc = "Clear";
	const String textr = "Run";
	const String texte = "Exit";
	int fontFace = FONT_HERSHEY_SIMPLEX;
	double fontScale = 2.0;
	int thickness = 2;

	Size sizeImgS = save.size();
	Size sizeTextS = getTextSize(texts, fontFace, fontScale, thickness, 0);
	Point saveorg((sizeImgS.width - sizeTextS.width) / 2, (sizeImgS.height + sizeTextS.height) / 2);
	
	Size sizeImgL = load.size();
	Size sizeTextL = getTextSize(textl, fontFace, fontScale, thickness, 0);
	Point loadorg((sizeImgL.width - sizeTextL.width) / 2, (sizeImgL.height + sizeTextL.height) / 2);

	Size sizeImgC = clear.size();
	Size sizeTextC = getTextSize(textc, fontFace, fontScale, thickness, 0);
	Point clearorg((sizeImgC.width - sizeTextC.width) / 2, (sizeImgC.height + sizeTextC.height) / 2);

	Size sizeImgR = run.size();
	Size sizeTextR = getTextSize(textr, fontFace, fontScale, thickness, 0);
	Point runorg((sizeImgR.width - sizeTextR.width) / 2, (sizeImgR.height + sizeTextR.height) / 2);

	Size sizeImgE = exit.size();
	Size sizeTextE = getTextSize(texte, fontFace, fontScale, thickness, 0);
	Point exitorg((sizeImgE.width - sizeTextE.width) / 2, (sizeImgE.height + sizeTextE.height) / 2);

	line(src, Point(500, 0), Point(500, src.rows - 1), Scalar(0, 0, 0), 2);
	putText(save, texts, saveorg, fontFace, fontScale, Scalar(0, 0, 0), thickness);

	line(src, Point(500, 100), Point(src.cols - 1, 100), Scalar(0, 0, 0), 2);
	putText(load, textl, loadorg, fontFace, fontScale, Scalar(0, 0, 0), thickness);

	line(src, Point(500, 200), Point(src.cols -1, 200), Scalar(0, 0, 0), 2);
	putText(clear, textc, clearorg, fontFace, fontScale, Scalar(0, 0, 0), thickness);

	line(src, Point(500, 300), Point(src.cols - 1, 300), Scalar(0, 0, 0), 2);
	putText(run, textr, runorg, fontFace, fontScale, Scalar(0, 0, 0), thickness);

	line(src, Point(500, 400), Point(src.cols - 1, 400), Scalar(0, 0, 0), 2);
	putText(exit, texte, exitorg, fontFace, fontScale, Scalar(0, 0, 0), thickness);
	

	line(src, Point(0, 0), Point(0, src.rows - 1), Scalar(0, 0, 0), 2);
	line(src, Point(0, 0), Point(src.cols - 1, 0), Scalar(0, 0, 0), 2);
	line(src, Point(0, src.rows - 1), Point(src.cols - 1, src.rows - 1), Scalar(0, 0, 0), 2);
	line(src, Point(src.cols - 1, 0), Point(src.cols - 1, src.rows - 1), Scalar(0, 0, 0), 2);

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
		if (pt0ld src(Rect(500, 0, 250, 100))
		{

		}
		
	case EVENT_MOUSEMOVE:
		if (flags & EVENT_FLAG_LBUTTON) {
			line(src(Rect(0, 0, 500, 500)), pt0ld, Point(x, y), Scalar(0, 0, 0), 8);
			imshow("src", src);
			pt0ld = Point(x, y);
		}
		break;

	case EVENT_RBUTTONDOWN:
		return;
	}
}
