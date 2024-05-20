# 실습과제 2번

![image](https://github.com/YbSain/OpenCV/assets/108385276/a317414c-1c3f-4ea1-a5c8-122bcd12cb49)

## 문제 풀이
__vector__ 로 2x2 배열을 입력받아 3명의 학생의 3과목 성적을 받아야 하는 문제이다.

    vector<vector<int>> score

위의 score로 학생 인원에 맞춘 과목의 성적을 받기 위해 2x2 배열을 만들었다.

    for (int i = 0; i < 3; i++) {
	   cout << i + 1 << "번째 학생의 국어, 영어, 수학 성적을 입력: ";
	   vector<int> tmp;
	   for (int j = 0; j < 3; j++) {
 		   int a; 
		   cin >> a;
		   tmp.push_back(a);
	   }
	   score.push_back(tmp);
    }

위의 코드로 i 즉 학생 인원 수 3명 만큼 j(과목 수)의 성적을 입력 받았다.    
__push_back__ 을 사용 할 경우 입력받은 값대로 __vector__ 내부에 값이 저장된다.

입력받는 값은 __int__ 값인데, __score__ 는 __vector__ 객체를 가져야 하기 때문에

    vector<int> tmp

를 만들어서 int값을 받는 1차원 행렬을 활용해서 __score__ 의 2차원 행렬에 값을 넣었다.

## 평균값 구하기

    for (int i = 0; i < score.size(); i++) {
       tot = 0;
	     for (int j = 0; j < score[i].size(); j++) {
	 	tot += score[i][j];
	     }
	  	  avg = tot / 3;
	  	  avgvec.push_back(avg);
	}

위 코드를 활용해서 __vector score__ 객체 속 i(학생)당 j(성적)의 평균 값을 구했다.

## 최댓값 찾기

위에서 __avgvec__ vector객체를 만든 이유이다.   
3개의 값을 하나하나 대소 비교 하기에는 너무 난잡해지기 때문에 1차원 행렬에 집어 넣었다.

    max = avgvec[count];

코드의 윗부분에 __int count = 0__ 으로 초기화 한 것을 알 수 있는데   
이를 __max__ 값에 첫 번째 학생의 과목 평균값을 초기화 시키고 그 뒤의 학생들의 평균 값을 비교하기 위해서이다.

    for (int i = 1; i < avgvec.size(); i++) {
	    if (avgvec[i] >= max)
	    {
	 	   max = avgvec[i];
	 	   count = i;
	    }
    }

위의 코드를 보면 __i = 1__ 를 사용해서 2번째 학생부터 평균값을 알아보기위해 반복문을 썼다.   
if를 통하여 max값과 비교를 해 그 중 큰 값이 나온 __avgvec[i]__ 를 최댓값을 뜻하는 변수인 __max__ 에 대입하고 조건에 충족하는 i(학생)을 count에 초기화시킨다.

    cout << "최우수 학생은 " << count + 1 << "번째 학생이고 평균점수는 " << max << "점이다.";

모든 작업을 완료 한 뒤 마지막으로 __count+1__ (학생 값은 0부터 시작했기 때문에 +1을 해줬다.) 과 __max__ 값을 출력했다.
