#include "stdfx.h"
#include <iostream>
#include <math.h>
#include "main.h"

int main(int argc, char *argv[]) {
	if(argc < 4) {
		throw std::exception("Exception: args must be 4.");
	}
	
	char* ends;

	cv::Mat src = cv::imread(argv[1]);
	cv::Mat* dst = perspect(&src, 90.0 - std::strtod(argv[3], &ends));
	cv::imshow("dst", *dst);
	cv::waitKey();
	return 1;
}

cv::Mat* perspect(cv::Mat* src, double angle) {
	if(angle < 0 || angle >= 90) {
		throw std::out_of_range("angle must be in range 0 to 90.");
	}

	double dstRows = abs(src -> rows / tan(angle));
	//cv::Mat* dst = new cv::Mat(dstRows, src->cols, CV_32F);
	cv::Mat* dst = new cv::Mat(*src);
	
	cv::Point2f srcPoint[4], dstPoint[4];
	srcPoint[0] = cv::Point2f(0, 0);
	srcPoint[1] = cv::Point2f(src -> cols, 0.0);
	srcPoint[2] = cv::Point2f(src -> cols, src -> rows);
	srcPoint[3] = cv::Point2f(0.0, src -> rows);

	dstPoint[0] = cv::Point2f(0, 0);
	dstPoint[1] = cv::Point2f(src -> cols, 0.0);
	dstPoint[2] = cv::Point2f(src -> cols - 100, src->rows);
	dstPoint[3] = cv::Point2f(100, src->rows);

	const cv::Mat matrix = cv::getPerspectiveTransform(srcPoint, dstPoint);		
	cv::warpPerspective(*src, *dst, matrix, cv::Size(dst->cols, dst->rows));
	return dst;
}