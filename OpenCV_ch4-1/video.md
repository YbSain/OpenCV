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

     
