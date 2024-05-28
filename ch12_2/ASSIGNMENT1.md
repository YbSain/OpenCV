# 결과 이미지

![스크린샷 2024-05-28 112839](https://github.com/YbSain/OpenCV/assets/108385276/749eadcf-ad3c-4aa1-b0e6-4c0411e2a7f8)

# 실습과제1

![image](https://github.com/YbSain/OpenCV/assets/108385276/3527c8fd-78fe-4faf-aefc-6ab694416562)

## 문제 풀이

원본이미지 __src__ 의 외곽선들을 검출해내 그 위를 랜덤의 색깔로 덧칠하는 방식이다
[이미지 이진화](###1-이미지-이진화)
2) 외곽선 검출
3) 랜덤색상으로 덧칠하기

### 이미지 이진화

외곽선을 검출하기 위해서 주어진 영상 __src__ 를 이진화 함
이진화할 시에 도형들이 검정색, 배경이 흰색이라 **_INV**를 붙혀 배경을 제외한 도형에만 외곽선을 검출해냄

    Mat tmp;
    cvtColor(src, tmp, COLOR_BGR2GRAY);
    threshold(tmp, tmp, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);

### 외곽선 검출

외곽선 검출을 위해 __findContours__ 를 사용한다

    findContours(tmp, contours, RETR_LIST, CHAIN_APPROX_NONE);

### 검출결과를 원본영상에 랜덤색상으로 덧칠하기

색상 및 원본영상에 그리기 위해서 dst를 새로 만들어주었다(src는 깨끗한 원본 그대로 출력하기위함)

    Mat dst;
    dst = src.clone();
    for(int i = 0; i < contours.size(); i++) {
      Scalar c(rand() & 255, rand() & 255, rand() & 255);
      drawContours(dst, contours, i, c, 2);
   }

