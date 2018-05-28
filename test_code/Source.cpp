#include <opencv2\highgui.hpp>

int main()
{
	cv::Mat img = cv::imread("test.jpg");
	cv::namedWindow("test.jpg", cv::WINDOW_AUTOSIZE);
	cv::imshow("test.jpg", img);
	cv::waitKey(0);
	return 0;
}