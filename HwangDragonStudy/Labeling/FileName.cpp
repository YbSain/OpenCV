#include <iostream>
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;
int main() {
    Mat src = imread("char_c.png", IMREAD_GRAYSCALE);
    Mat dst = src.clone();
    threshold(src, src, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);
    cvtColor(dst, dst, COLOR_GRAY2BGR);

    Mat labels, stats, centroids;
    int c = connectedComponentsWithStats(src, labels, stats, centroids);
    int* cf = stats.ptr<int>(1);        //������
    int* cs = stats.ptr<int>(2);        //stats�� 1����ü�� 2����ü�� �ּ�

    Rect c1(cf[0] - 1, cf[1] - 1, cf[2] + 3, cf[3] + 3);    //+3�� �ٿ�� �ڽ��� ������ �ֱ� ����
    Rect c2(cs[0] - 1, cs[1] - 1, cs[2] + 3, cs[3] + 3);
    //������ ��ü�� rect�� ���߰� �� ��ü�� ���� ������ ���� ���ؼ� �������̸� ã�ƾ��Ѵ�

    Rect c1r(cf[0] + cf[2] / 2 - 1, cf[1] - 1, cf[2] / 2 + 3, cf[3] + 3);
    // ���� ���� �������� ��ǥ ����� ���� x��ǥ �������� ���� = ���̸� ���� 2�� ���� �߾Ӱ��� �����
    // y��ǥ�� ��ȭ�� ����
    // 3��°ĭ�� 1��° ĭ�� �ٸ��� width�� ���̸� ���ϸ�ż� ���̰��� /2�� ó����
    Rect c1l(cf[0] - 1, cf[2] - 1, cf[2] / 2 + 3, cf[3] + 3);
    //���� �ٸ��� ���ʽ����� x���� ��ġ ��ȭ�� ������ ���̸� ������ ������༭ ���Ѵ�

    Rect c2r(cs[0] + cs[2] / 2 - 1, cs[1] - 1, cs[2] / 2, cs[3]);
    Rect c2l(cs[0] - 1, cs[2] - 1, cs[2] / 2 + 3, cs[3] + 3);
    //���� ��ǥ�� ���� ���� ������ ������ �����ϰ� ����Ҽ��ִ�.

    int c1lc, c1rc, c2lc, c2rc;
    c1lc = connectedComponents(src(c1l), labels);
    //src(c1l) �Է¿����� c1left �κ��� ���̺�� ���̴�
    c1rc = connectedComponents(src(c1r), labels);
    c2lc = connectedComponents(src(c2l), labels);
    c2rc = connectedComponents(src(c2r), labels);
    //�� ���̺� �� 3�� �����ΰ� ?
    if (c1lc == 3) {    
        vector<vector<Point>> left;
        findContours(src(c1), left, RETR_LIST, CHAIN_APPROX_NONE);
        drawContours(dst(c1), left, 0, Scalar(255, 0, 0), 2);
    }
    if (c1rc == 3) {
        vector<vector<Point>> right;
        findContours(src(c1), right, RETR_LIST, CHAIN_APPROX_NONE);
        drawContours(dst(c1), right, 0, Scalar(0, 0, 255), 2);
    }
    if (c2lc == 3) {
        vector<vector<Point>> left;
        findContours(src(c2), left, RETR_LIST, CHAIN_APPROX_NONE);
        drawContours(dst(c2), left, 0, Scalar(255, 0, 0), 2);
    }
    if (c2rc == 3) {
        vector<vector<Point>> right;
        findContours(src(c2), right, RETR_LIST, CHAIN_APPROX_NONE);
        drawContours(dst(c2), right, 0, Scalar(0, 0, 255), 2);
    }
    

    imshow("src", src);
    imshow("dst", dst);

    waitKey();

    return 0;
}