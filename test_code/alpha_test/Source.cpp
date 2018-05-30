// 비쥬얼 스튜디오 인자 넣는 법 http://maytrees.tistory.com/112

#include <opencv2\highgui.hpp>
#include <iostream>
#include <string.h>


int main(int argc , char  ** argv)
{
	using namespace std;
	using namespace cv;

	char result_name[255];
	
	if (argc < 2)
	{
		printf("need argument ");
		exit(0);
	}
	float alpha = stof(argv[1]);
	sprintf_s(result_name, "result alpha : %s", argv[1]);
	Mat img = imread("test.jpg");
	Mat img2 = imread("test2.jpg");
	Mat img_result = imread("test2.jpg");
	namedWindow("test.jpg", WINDOW_AUTOSIZE);
	namedWindow("test2.jpg", WINDOW_AUTOSIZE);
	namedWindow(result_name, WINDOW_AUTOSIZE);
	
	for (int x = 0; x < img.cols; x++)
	{
		for (int y = 0; y < img.rows; y++)
		{

			img_result.at<Vec3b>(x, y) = (1 - alpha) * img.at<Vec3b>(x, y) +  alpha * img2.at<Vec3b>(x,y);
		}
	}
	imshow("test.jpg", img); 
	imshow("test2.jpg", img2);
	imshow(result_name, img_result);
	
	waitKey(0);
	

	
	return 0;
}