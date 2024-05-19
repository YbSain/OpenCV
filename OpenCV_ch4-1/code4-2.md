# 코드 4-2 : 영상반전
1. while반복문 안에서 카메라로부터 프레임을 받아 왔다면 이후 각 프레임에 다양한 정지영상 처리 기법을 적용할 수 있음
2. 카메라의 매 프레임에 대하여 영상의 반전을 수행하고, 그 결과를 화면에 같이 출력할 수 있음
3. 카메라 및 동영상 처리는 결국 각 프레임에 대한 정지 영상 처리와 같은 구조임

   
![image](https://github.com/YbSain/OpenCV/assets/108385276/e529d0ad-0ad8-407b-bf41-70b4aeafb71c)

      inversed = ~frame; //비트별 not연산을 해서 프레임마다 영상을 반전시킴