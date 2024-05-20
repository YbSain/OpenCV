# 실습과제 4

![image](https://github.com/YbSain/OpenCV/assets/108385276/f01c6885-46b9-4be5-8260-49ed50f8b45d)

## 문제 풀이

이 문제는 음수는 __0__ , 양수는 __255__ 로 수정하여 저장해 출력하는 __C++__ 프로그램을 작성하는 문제이다.

    vector<vector<int>> a = { {-5, 2, 35}, {-20, 5, 100}, {-75, 5, -25} };
    vector<vector<int>> positive;

문제에서 주어진 3x3행렬을 2차원 행렬 __a__ 로 초기화하고 수정한 뒤 저장할 2차원 행렬인 __positive__ 를 만들어 두었다.

### 양수, 음수 확인 및 positive 객체에 초기화

    for (int i = 0; i < a.size(); i++) {
	    vector<int> tmp;
	    for (int j = 0; j < a[i].size(); j++) {
		    if (a[i][j] < 0) {
			    a[i][j] = 0;
		    }
		    else if (a[i][j] > 0) {
			    a[i][j] = 255;
		    }
		    tmp.push_back(a[i][j]);
	    }
	    positive.push_back(tmp);
    }

__positive__ 는 _vector_ 객체를 입력받아야 한다.   
따라서 위의 반복문에서

	vector<int> tmp

를 하나 만들어 __a[i][j]__ 의 값을 __0__ 과 __255__ 로 바꾼 뒤, __tmp__ 1차원 행렬에 저장한다.   
작업을 완료 한 뒤, 2차원 행렬인 __positive__ 에 1차원 행렬인 __tmp__ 값을 __push_back__ 해서 초기화한다.

### 초기화 한 positive 행렬 출력

    cout << "수정행렬" << endl;
    for (int i = 0; i < positive.size(); i++) {
	    for (int j = 0; j < positive[i].size(); j++) {
		    cout << positive[i][j] << "\t";
	    }
	    cout << endl;
    }

위의 코드로 3x3행렬의 모습처럼 보이도록 출력하였다.

## 결과

![image](https://github.com/YbSain/OpenCV/assets/108385276/bea1ce33-f254-4108-976b-1ac2b4732823)
