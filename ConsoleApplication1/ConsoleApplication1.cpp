// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include"stdafx.h" 
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using std::string;

int main()
{
	cv::Mat out, in = imread("D:\\10.png", 1);
	if (in.empty()) return -1; 
	Canny(in, out, 50, 200, 3);
	std::vector<cv::Vec4i> lines;
	cv::HoughLinesP(out, lines, 1, CV_PI / 180, 30, 5, 20);
	for (size_t i = 0; i < lines.size(); i++) {
		Vec4i l = lines[i];
		line(in, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(186, 88, 255), 1, CV_AA);
	}
	imshow("out", in);
	waitKey(0);
    return 0;
}

