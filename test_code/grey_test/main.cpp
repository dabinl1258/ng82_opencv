
#include <opencv2\highgui.hpp>


int main(int argc, char  ** argv)
{
	using namespace cv;
	Mat img = imread("test.jpg");
	Mat result(Size(img.cols, img.rows), CV_8U);


	namedWindow("test.jpg origin");
	imshow("test.jpg origin", img);



	for (int x = 0; x < img.rows; x++)
	{
		for (int y = 0; y < img.cols; y++) {
			Vec3b vec = img.at<Vec3b>(x, y);
			result.at<uchar>(x, y) = (vec.val[0] + vec.val[1] + vec.val[2]) / 3;

		}
	}
	namedWindow("covert grey");
	imshow("covert grey", result);
	for (int x = 0; x <img.rows; x++)
	{
		for (int y = 0; y < img.cols; y++) {
			Vec3b vec = img.at<Vec3b>(x, y);
			result.at<uchar>(x, y) = (vec.val[0] + vec.val[1] + vec.val[2]) / 3  > 128 ? 255 : 0;
		}
	}
	namedWindow("covert bin");
	imshow("covert bin", result);


	waitKey(0);
	return 0;
}