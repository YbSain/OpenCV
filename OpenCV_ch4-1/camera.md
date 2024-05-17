# 카메라 입력처리하기

## 객체 생성
1. 기본 생성자를 이용하여 __VideoCapture__ 객체 생성 후, __VideoCapture::open() 멤버 함수를 이용하여 사용할 카메라 장치를 열어야

        VideoCapture cap;
        cap.open(0);

2. __VideoCapture__ 객체 생성과 동시에 카메라 장치를 열기
 
        VideoCapture cap(0);
   
3. 카메라 장치가 정상적으로 열렸는지는 __VideoCapture::isOpened()__ 멤버 함수를 이용하여 확인해야 함
   
        if(!cap.isOpened()) { cerr << "Camera open failed!" << endl; return -1; }
   
## 프레임 읽기
1. 카메라의 프레임은 연산자 >>를 이용하여 Mat 클래스 객체에 저장.
2. Mat 객체에 저장된 영상은 imshow() 함수를 사용하여 화면에 출력
   
          VideoCapture cap(0);
          if(!cap.isOpened()) { cerr << "Camera open failed!" << endl; return -1; ]
          Mat frame;
          while (true)
          {
              cap >> frame;
     
              imshow("frame", frame);
              waitKey(10);
          }
   
4. 카메라에서 정지 영상 프레임을 제대로 받아 오지 못하는 경우에 예외 처리도 추가하는 것이 좋음.
5. 프로그램 동작 중 사용자가 특정 키를 누를 때 종료할 수 있도록 코드를 추가하는 것이 좋음

         Mat frame;
         while(true)
         {
           cap>>frame;
           if(frame.empty()) break;
      
           imshow("frame", frame);
      
           if(waitKey(10) == 27) break;
         }
     
