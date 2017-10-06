// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#define HAVE_OPENCV_HIGHGUI
#define HAVE_OPENCV_IMGPROC
#define HAVE_OPENCV_OBJDETECT

#include "targetver.h"
#include <stdio.h>
#include <stdexcept>
#include <tchar.h>
#include <thread>
#include <opencv2\opencv.hpp>
#include <opencv2\imgproc\imgproc.hpp>