# 실행 결과

![스크린샷 2024-05-28 130259](https://github.com/YbSain/OpenCV/assets/108385276/2d9474f7-ccc2-4ebc-911b-9fd5438a8fee)

# 실습과제 3

![image](https://github.com/YbSain/OpenCV/assets/108385276/67245498-f99e-460d-8d9e-41c182d9ff11)

## 문제 풀이

[1)이진화 및 외곽선 구하기](#이진화-및-외곽선구하기)   
[2)외곽선 색 칠하기](#line을-활용해서-그리기)

### 이진화 및 외곽선구하기

위 코드에서는 **src**에 그대로 컬러 이미지를 받아 결과물로 출력하기 때문에 **src**이미지를 컬러로 받았다   
따라서 __dst__ 에 모든 과정을 넣었다

     vector<vector<Point>> contours;
     Mat dst;
     cvtColor(src, dst, COLOR_BGR2GRAY);
     threshold(dst, dst, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);
     findContours(dst, contours, RETR_LIST, CHAIN_APPROX_NONE);

위의 코드로 그레이스케일 변환 - 이진화 - 외곽선 구하기의 과정을 다 담았다

### line을 활용해서 그리기

__drawContours__ 를 사용하지 않고 외곽선에 색을 칠하기 위해서 __line__ 을 사용하기 때문에 점의 좌표를 전부 구해내야한다

     for(int i = 0; i<contours.size(); i++){
         for(int j = 0; j < contours[i].size(); j++){
             line(src, contours[i][j], contours[i][j], Scalar(0, 0, 255), 2);
         }
     }

위의 코드로 __src__ 이미지에 __(0, 0, 255)__ 즉 빨간색으로 __contours[i][j]__ 점마다 **2**의 굵기 만큼 선을 잇는다
