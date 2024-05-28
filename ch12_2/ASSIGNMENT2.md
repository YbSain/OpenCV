# 결과 이미지 

![스크린샷 2024-05-28 121644](https://github.com/YbSain/OpenCV/assets/108385276/4de2239e-b09a-41c7-af83-ca13f588ee6a)

# 실습과제 2

![image](https://github.com/YbSain/OpenCV/assets/108385276/06e1569c-f6a9-43db-bd8d-5f52dc18ac81)

Mat객체에 저장된 영상의 모든 외곽선을 찾고 갯수와 좌표를 출력하는 문제

## 문제 풀이

이 문제는 외곽선을 검출하고 출력하는 과정이 전부다   

[1. 외곽선 검출](#외곽선-검출)   
[2. 검출한 외곽선 출력](#출력)

### 외곽선 검출

외곽선을 검출해내기 위해선 __vector<vector<Point>>__ 와 __findContours__ 가 필요하다

   vector<vector<Point>> contours;
   findContours(src, contours, RETR_LIST, CHAIN_APPROX_NONE);

으로 __src__ 의 외곽선을 구함

### 출력

**i** 좌표의 크기 = 외곽선의 갯수   
따라서 아래 방식을 사용하면된다

  	cout << "외곽선의 갯수:" << contours.size() << endl;
	  for (int i = 0; i < contours.size(); i++){
		 cout << i << "번째 외곽선의 점의 좌표: ";
		 for (int j = 0; j < contours[i].size(); j++) {
			 cout << contours[i][j];
		 }
		 cout << endl;
	  }

__contours.size()__ 로 갯수를 먼저 출력한 뒤   
__i__ 즉 갯수 중 앞에서 검출되는 순서부터 출력함   
__contours[i][j]__ 로 좌표값을 쭉 출력해냄   
__for j__ 문이 끝나고 endl;을 해줌으로써 줄간격을 맞췄다

