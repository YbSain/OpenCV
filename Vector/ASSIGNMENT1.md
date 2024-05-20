# 실습과제 1

![image](https://github.com/YbSain/OpenCV/assets/108385276/874077c8-6917-448f-a7ac-48d032d269cc)

## 문제 풀이

2x2 짜리인 2차원 배열 2개의 합을 구하는 문제이다.   

    vector<vector<int>> a = { {2, 4}, {5, -5} };
    vector<vector<int>> b = { {-2, 3}, {0, -5 } };

2차원 배열 2개의 값을 __a__ 와 __b__ 에 초기화 시켰다.

    vector<vector<int>> sum{ {0, 0},{0, 0} };

두 값의 합계를 구해야 하니 0으로 초기화 돼있는 2차원 배열 __sum__ 을 만들어 두었음.

    for (int i = 0; i < a.size(); i++) {
	    for (int j = 0; j < a[i].size(); j++) {
		    sum[i][j] = (a[i][j] + b[i][j]);
	    }
    }

__a__ 와 __b__ 두 개의 2차원 행렬은 같은 size를 받아서 __a.size(), a[i].size()__ 를 공통적으로 사용해서   
a[i][j] 와 b[i][j]의 합을 sum[i][j]에 초기화 시켰음. ~~이는 i < 3 으로 통일해도 될 것 같다.~~
	 
	 cout << "두 2차원배열의 합: " << endl;
	 for (int i = 0; i < sum.size(); i++) {
		 for (int j = 0; j < sum[i].size(); j++) {
		 cout << sum[i][j] <<"\t";;
		 }
	 cout << endl;
	 }

~~위의 방법을 사용해서 배열 합의 결과를 출력했다.~~

코드를 작성하다가 더 짧게 사용할 방법이 떠올라서 수정했다.

    cout << "두 2차원배열의 합: " << endl;
    for (int i = 0; i < a.size(); i++) {
	    for (int j = 0; j < a[i].size(); j++) {
		    sum[i][j] = (a[i][j] + b[i][j]);
		    cout << sum[i][j] << "\t";
	    }
	    cout << endl;
    }

합계의 출력은 __sum[i][j]__ 가 나올 때 마다 그 값을 출력하고 __j__ 값 마다 __\t__ 으로 칸을 띄우고   
[i]값이 바뀔 때 마다 __endl__ 로 줄을 넘겨 2차원 행렬의 모습을 띄게 출력했다.

## 결과

![image](https://github.com/YbSain/OpenCV/assets/108385276/8b365474-6774-4510-b000-bcb4eb18ce09)
