#include "stdafx.h"
using cv::Mat;
using cv::VideoCapture;
using cv::CascadeClassifier;
using std::vector;
using cv::Rect;

const std::string FACE_CASCADE_PATH = "D:\\OpencvSDK\\build\\etc\\haarcascades\\haarcascade_frontalface_default.xml";
const std::string EYE_CASCADE_PATH = "D:\\OpencvSDK\\build\\etc\\haarcascades\\haarcascade_eye.xml";

CascadeClassifier faceCC, eyeCC;
VideoCapture CameraInit()
{
	VideoCapture *cap = new VideoCapture(0);
	if (!cap->isOpened()) throw std::runtime_error("����ͷ��ʧ��");
	else
	{
		cap->set(cv::CAP_PROP_FPS, 30);
		cap->set(cv::CAP_PROP_FRAME_WIDTH, 800);
		cap->set(cv::CAP_PROP_FRAME_HEIGHT, 600);
	}
	return *cap;
}
Mat FaceEyeDetection(const Mat frame,vector<Rect> &face,vector<Rect> &eye)
{
	faceCC.detectMultiScale(frame, face);
	eyeCC.detectMultiScale(frame, eye);
	Mat *temp = new Mat();
	frame.copyTo(*temp);
	for (auto r : face)
		cv::rectangle(*temp, r, cv::Scalar(255));
	for (auto r : eye)
		cv::rectangle(*temp, r, cv::Scalar(0));
	return *temp;
}
int main()
{
	VideoCapture camera = CameraInit(); //��ʼ������������ͷ

	Mat rawFrame, grayFrame;
	vector<Rect> faceVector, eyeVector;
	cv::namedWindow("ʵʱ��Ƶ");
	cv::namedWindow("ץȡ��������");
	faceCC.load(FACE_CASCADE_PATH);
	eyeCC.load(EYE_CASCADE_PATH);
	while (true)
	{
		camera >> rawFrame;
		cv::cvtColor(rawFrame, grayFrame, cv::COLOR_RGB2GRAY);
		cv::imshow("ʵʱ��Ƶ", grayFrame);
		cv::imshow("ץȡ��������", FaceEyeDetection(grayFrame, faceVector, eyeVector));
		if (-1 != cv::waitKey(1)) break;
	}
}