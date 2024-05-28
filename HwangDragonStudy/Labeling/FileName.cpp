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
    int* cf = stats.ptr<int>(1);        //포인터
    int* cs = stats.ptr<int>(2);        //stats의 1번객체와 2번객체의 주소

    Rect c1(cf[0] - 1, cf[1] - 1, cf[2] + 3, cf[3] + 3);    //+3은 바운딩 박스에 여유를 주기 위함
    Rect c2(cs[0] - 1, cs[1] - 1, cs[2] + 3, cs[3] + 3);
    //위에는 객체의 rect를 구했고 각 객체의 왼쪽 오른쪽 값을 비교해서 공간차이를 찾아야한다

    Rect c1r(cf[0] + cf[2] / 2 - 1, cf[1] - 1, cf[2] / 2 + 3, cf[3] + 3);
    // 왼쪽 값을 쓰기위해 좌표 계산을 위해 x좌표 시작점과 끝점 = 길이를 더해 2로 나눠 중앙값을 계산함
    // y좌표는 변화가 없음
    // 3번째칸은 1번째 칸과 다르게 width즉 길이를 구하면돼서 길이값의 /2만 처리함
    Rect c1l(cf[0] - 1, cf[2] - 1, cf[2] / 2 + 3, cf[3] + 3);
    //위와 다르게 왼쪽시작은 x값의 위치 변화가 없으니 길이만 반절로 계산해줘서 구한다

    Rect c2r(cs[0] + cs[2] / 2 - 1, cs[1] - 1, cs[2] / 2, cs[3]);
    Rect c2l(cs[0] - 1, cs[2] - 1, cs[2] / 2 + 3, cs[3] + 3);
    //위와 좌표만 차이 나기 때문에 계산식은 동일하게 사용할수있다.

    int c1lc, c1rc, c2lc, c2rc;
    c1lc = connectedComponents(src(c1l), labels);
    //src(c1l) 입력영상의 c1left 부분의 레이블맵 값이다
    c1rc = connectedComponents(src(c1r), labels);
    c2lc = connectedComponents(src(c2l), labels);
    c2rc = connectedComponents(src(c2r), labels);
    //왜 레이블 값 3이 기준인가 ?
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