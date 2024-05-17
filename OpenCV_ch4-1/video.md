# VideoCapture 클래스에 대해

    class VideoCapture
    {
    public:
        VideoCapture();
        VideoCapture(const String& filename, int apiPreference = CAP_ANY);
        VideoCapture(int index, int apiPreference = CAP_ANY);
        virtual ~VideoCapture();
 
        virtual bool open(const String& filename, int apiPreference = CAP_ANY);
        virtual bool open(int index, int apiPreference = CAP_ANY);
        virtual bool isOpened() const;
        virtual void release();
        virtual bool grab();
        virtual bool retrieve(OutputArray image, int flag = 0); 
    
        vitual VideoCapture& operator >> (Mat& image);
        virtual bool read(OutputArray image);
        virtual bool set(int propId, double value);
        virtual double get(int propId) const;
        ...
    };

    
## 동영상 객체 생성 - VideoCapture 클래스

    VideoCapture::VideoCapture(const String& filename, int apiPreference = CAP_ANY);
    bool VideoCapture::open(const String& filename, int apiPreference = CAP_ANY);

![image](https://github.com/YbSain/OpenCV/assets/108385276/5ecfa671-c5bf-4323-aa7c-c9aaeaae4d28)

__VideoCapture__ 객체를 생성할 때 동영상 파일 이름을 지정함.
기본생성자로 객체를 생성할때에는  __::open()__ 멤버 함수를 호출해야한다.

__apiPreference__: 동영상 파일을 불러올 때 사용하는 API를 지정할 수 있음. VideoCaptureAPIs 열거형 상수 중 하나를 지정함.   
(CAP_ANY가 기본값이다)

![image](https://github.com/YbSain/OpenCV/assets/108385276/8f7ce646-78f5-4df2-82b8-d3813567cebf)

    bool VideoCapture::isOpened() const;
    
반환값 = 카메라 또는 동영상 파일이 사용 가능하면 *true*, 그렇지 않으면 *false* 반환

객체 생성시 에러체크 
    __if(!cap.isOpened()){ cerr << "Video open failed!" << endl; return -1; }__

## 카메라 객체 생성 - VideoCapture클래스

    VideoCapture::VideoCapture(int index, int apiPreference = CAP_ANY);
    bool VideoCapture::open(int index, int apiPreference = CAP_ANY);

![image](https://github.com/YbSain/OpenCV/assets/108385276/7a523aeb-c87c-4355-b309-86994d60b201)

1. 카메라 장치를 사용하는 경우에도 __VideoCapture__ 생성자 혹은 __VideoCapture::open()__ 멤버 함수를 사용
2. __index__ = camera_id + domain_offset_id   
   1대의 카메라만 연결된 경우 camera_id - > 0   
   2대 이상의 카메라가 연결된 경우 camera_id -> 0, 1, 2, ....   
   domain_offset_id : apiPreference 인자값을 의미   
   apiPreference 인자가 CAP_ANY(0)인 경우 index 값은 camera_id와 같다.   
3. __apiPrefernece__: 동영상 파일을 불러올 때 사용하는 API를 지정할 수 있음. _VideoCaptureAPIs_ 열거형 상수중 하나를 지정함   
   *대부분의 경우 _apiPreference_ 인자를 생략하면 기본 값인 *CAP_ANY*를 지정하며, 이 경우 시스템이 알아서 적절한 방법을 선택해 사용함.

        VideoCapture cap(0);
        VideoCapture cap;
        cap.open(0);
        
        bool VideoCapture::isOpened() const;
   
반환값 = 카메라 또는 동영상 파일이 사용 가능하면 *true*, 그렇지 않으면 *false* 반환

객체 생성시 에러체크 
    __if(!cap.isOpened()){ cerr << "Camera open failed!" << endl; return -1; }__


## VideoCapture 클래스: 프레임읽기

     VideoCapture& VideoCapture::operator >> (Mat& image);
     bool VideoCapture::read(OutputArray image);

![image](https://github.com/YbSain/OpenCV/assets/108385276/6fa92d15-f895-468b-8c84-084f5a4ed2d2)

1. 카메라 또는 동영상 파일로부터 한 프레임을 받아오기 위한 함수
2. 카메라 또는 동영상 파일로부터 다음 프레임을 받아와서 Mat 클래스 형식의 변수 image에 저장함

 
       VideoCapture cap(0);
       Mat frame1, frame2;
       cap >> frame1;     //1st frame
       cap.read(frame2);  //2nd frame

## VideoCapture 클래스 : 속성얻기

        double VideoCapture::get(int propId) const;

![image](https://github.com/YbSain/OpenCV/assets/108385276/4c92ef3d-399f-4924-aae6-b82eeb2dc113)

1. 카메라 장치 또는 동영상 파일로부터 여러 가지 파일/장치 속성값을 받아오기 위한 함수
        VideoCapture cap(0);
        int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
        int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
2. 프레임의 폭과 높이 읽어옴, 리턴값이 실수이므로 반올림(cvRound) 하여 저장

아래는 __get()__ 괄호 안에 넣을 수 있는 **VideoCaptureProperties** 열거형 상수이다.

![image](https://github.com/YbSain/OpenCV/assets/108385276/85ba4063-342f-4f0d-907c-cc5e703434e6)
![image](https://github.com/YbSain/OpenCV/assets/108385276/3e524174-2f9a-40aa-98b2-1c993a49da84)

        bool VideoCapture::set(int propId, double value);

![image](https://github.com/YbSain/OpenCV/assets/108385276/60856c36-c113-4fa7-ab95-88005c3a67dd)

1. 카메라 또는 비디오 파일 재생과 관련된 속성 값을 설정할 때 사용함.
2. 만약 *video.mp4* 파일을 열어서 100번째 프레임으로 이동

        VideoCapture cap("video.mp4");
        cap.set(CAP_PROP_POS_FRAMES, 100);

