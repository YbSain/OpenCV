# 실습과제 3

![image](https://github.com/YbSain/OpenCV/assets/108385276/f5780050-5dca-48ce-956a-f3ca2a9d31f0)

## 문제 풀이

위 문제는 3x3인 2차원 행렬의 최댓값을 찾는 것이 목적이다.   

    vector<vector<int>> a = { {-5, 2, 35}, {-20, 5, 100}, {-75, 5, -25} };

일단 시작은 3x3 행렬을 초기화 시켜주었다.   

    vector<int> b;
    int max = 0;

__vector<int> b__ 의 역할은 실습과제 2번과 같은 이유로 대소 비교를 하기 위한 1차원 행렬을 하나 만들어주었다.   
__max__ 는 최댓값을 저장하기 위한 변수로 0으로 초기화 시켜주었다.

### 최댓값 구하기

    for (int i = 0; i < a.size(); i++) {
	    for (int j = 0; j < a[i].size(); j++) {
		    b.push_back(a[i][j]);
		    max = b[0];
	    }
    }

이는 첫번째 반복문인데 __a[i][j]__ 의 값을 __b[i]__ 로 1차원 행렬에 전부 초기화 시키고 첫 번째 값인 __a[0][0]__ 즉 __b[0]__ 을 max에 초기화 시켰다.

    for (int i = 1; i < b.size(); i++) {
    	if (b[i] > max) {
    		max = b[i];
	    }
    }

그러고 위의 반복문을 활용해서 2번째 값부터 __max__ 값과 비교를 해, 최댓값을 찾아 내었다.


## 결과

![image](https://github.com/YbSain/OpenCV/assets/108385276/63d89e30-074b-4866-a404-84ec0b6ebf21)
