// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once
#pragma warning(disable:4819)

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO:  在此处引用程序需要的其他头文件

#include <iostream>
#include <fstream>

#include <Windows.h>

#include <opencv2/opencv.hpp>
#ifdef _DEBUG

#pragma comment(lib, "opencv_ts300d.lib")
#pragma comment(lib, "opencv_world300d.lib")
#pragma comment(lib, "opencv_core300d.lib")

#else	// Release

#pragma comment(lib, "opencv_ts300.lib")
#pragma comment(lib, "opencv_world300.lib")
#pragma comment(lib, "opencv_core300.lib")

#endif // _DEBUG