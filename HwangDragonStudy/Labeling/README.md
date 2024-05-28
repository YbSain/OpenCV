# 실행결과

![image](https://github.com/YbSain/OpenCV/assets/108385276/295e7319-8d22-46ed-a7fa-e4676cf69e22)

## 문제 풀이

![image](https://github.com/YbSain/OpenCV/assets/108385276/9de09804-54d4-4042-9f2f-a4359a716efd)

이 문제는   
1) 이진화   
2) 레이블링   
3) 각 객체의 rect값   
4) rect값의 좌, 우 구분   
5) 구분한 좌, 우 값의 외곽선 개수 비교(뚫린 방향을 찾기 위함)
6) 이 중 좌우에 원하는 색으로 덧칠

이렇게 진행된다

### 레이블링진행을 위한 이진화

레이블링을 진행하기 위해서는 우선 이진화를 해야한다

    threshold(src, src, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);

를 통해 이진화를 먼저 진행시켜줌

### 레이블링

이진화 된 __src__ 영상에 대한 레이블링이다

    Mat labels, stats, centroids;
    int c = connectedComponentsWithStats(src, labels, stats, centroids);
    int* cf = stats.ptr<int>(1);
    int* cs = stats.ptr<int>(2);

위 과정으로 __cf__ 는 __1번 객체__, __cs__ 는 __2번 객체__ 의 주소를 가져와준다

### 바운딩박스

특정구간의 Rect값을 구한 뒤 그 구한 __Rect__ 값의 좌, 우 __Rect__ 를 다시 한번 구한다

    Rect c1(cf[0] - 1, cf[1] - 1, cf[2] + 3, cf[3] + 3);
    Rect c2(cs[0] - 1, cs[1] - 1, cs[2] + 3, cs[3] + 3);
    
    Rect c1r(cf[0] + cf[2] / 2 - 1, cf[1] - 1, cf[2] / 2 + 3, cf[3] + 3);
    Rect c1l(cf[0] - 1, cf[1] - 1, cf[2] / 2 + 3, cf[3] + 3);
    
    Rect c2r(cs[0] + cs[2] / 2 - 1, cs[1] - 1, cs[2] / 2, cs[3]);
    Rect c2l(cs[0] - 1, cs[1] - 1, cs[2] / 2 + 3, cs[3] + 3);

이렇게 __c1__ 은 __1번객체__ 의 __Rect값__ __c2__ 는 __2번객체__ 의 __Rect__ 값이고, __c1r, c1l__ 은 __1번객체__ 의 우측 좌측, __c2r, c2l__ 은 __2번객체__ 의 우측 좌측이다   

_+3을 해주는 이유는 바운딩 박스에 여유를 두기 위함_

### 각 객체의 좌, 우 외곽선 값 구하기 및 결과 도출

각 __Rect__ 객체를 이진화 한 __src__ 영상내부에서의 레이블링을 수행 한 뒤 조건에 부합한 외곽선에 색을 칠함

     int c1lc, c1rc, c2lc, c2rc;
     c1lc = connectedComponents(src(c1l), labels);
     c1rc = connectedComponents(src(c1r), labels);
     c2lc = connectedComponents(src(c2l), labels);
     c2rc = connectedComponents(src(c2r), labels);

     if (c1lc == 3) {    
         vector<vector<Point>> left;
         findContours(src(c1), left, RETR_LIST, CHAIN_APPROX_NONE);
         drawContours(dst(c1), left, 0, Scalar(255, 0, 0), 2);
         cout << "왼쪽으로 열림" << endl;
     }
     if (c1rc == 3) {
         vector<vector<Point>> right;
         findContours(src(c1), right, RETR_LIST, CHAIN_APPROX_NONE);
         drawContours(dst(c1), right, 0, Scalar(0, 0, 255), 2);
         cout << "오른쪽으로 열림" << endl;
     }
     if (c2lc == 3) {
         vector<vector<Point>> left;
         findContours(src(c2), left, RETR_LIST, CHAIN_APPROX_NONE);
         drawContours(dst(c2), left, 0, Scalar(255, 0, 0), 2);
         cout << "왼쪽으로 열림" << endl;
     }
     if (c2rc == 3) {
         vector<vector<Point>> right;
         findContours(src(c2), right, RETR_LIST, CHAIN_APPROX_NONE);
         drawContours(dst(c2), right, 0, Scalar(0, 0, 255), 2);
         cout << "오른쪽으로 열림" << endl;
     }
                        
