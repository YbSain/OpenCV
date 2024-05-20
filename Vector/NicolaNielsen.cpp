#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(void)
{
	//¿¹Á¦ 1
	int num1[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	int num2[3][4] = { {1},{5,6},{9,10,11} };
	int num3[][4] = { {1},{2,3},{4,5,6} };
	int num4[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int num5[3][4] = { 1,2,3,4,5,6 };
	int num6[][4] = { 1,2,3,4,5,6 };
	int i, j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			printf("%5d", num1[i][j]);
		}
		printf("\n");
	}

	return 0;
}
