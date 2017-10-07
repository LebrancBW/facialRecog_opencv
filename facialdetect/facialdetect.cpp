#include "stdafx.h"
using cv::Mat;
using cv::imread;
using cv::namedWindow;
using cv::imshow;
using cv::waitKey;
using cv::VideoCapture;
using std::vector;
using std::runtime_error;
using std::string;
bool isLoop = true;
string FACE_CASCADE_FILE = "D:\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalface_default.xml";

void FaceDetection_fun(cv::CascadeClassifier cc,Mat &raw)
{
	vector<cv::Rect> result;
	Mat temp;
	cv::cvtColor(raw, temp, cv::COLOR_RGB2GRAY);
	cc.detectMultiScale(temp, result);
	for (auto r : result)
		cv::rectangle(raw, r, cv::Scalar(0, 255, 255));
}

int main()
{
	VideoCapture cap(0);
	if (!cap.isOpened()) throw runtime_error("invaid camera");
	
	else
	{
		cap.set(cv::CAP_PROP_FPS, 30);
		cap.set(cv::CAP_PROP_FRAME_WIDTH, 400);
		cap.set(cv::CAP_PROP_FRAME_HEIGHT, 320);
		Mat frame;
		namedWindow("ʵʱ��Ƶ");

		cv::CascadeClassifier face_detection;
		face_detection.load(FACE_CASCADE_FILE);

		while (isLoop)
		{
			cap>>frame;
			FaceDetection_fun(face_detection,frame);
			imshow("ʵʱ��Ƶ", frame);
			waitKey(1);
		}
		return 0;
	}
}

