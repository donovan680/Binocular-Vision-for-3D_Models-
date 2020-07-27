// OnOCV.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "lab.h"

using namespace std;
using namespace cv;

int _tmain(int argc, _TCHAR* argv[])
{
	Mat		imgL = imread("..\\..\\ImgRes\\aloeL.jpg");
	Mat		imgR = imread("..\\..\\ImgRes\\aloeR.jpg");

	RELATIVEPXGRADIENT_3x3*	pGradientsL = nullptr;
	RELATIVEPXGRADIENT_3x3*	pGradientsR = nullptr;

	int nGradientsL = CalculateRelativePxGradient3x3(pGradientsL, imgL);
	int nGradientsR = CalculateRelativePxGradient3x3(pGradientsR, imgR);


	OutputAsTxt_PxGradient3x3("..\\..\\FireField\\aloeL_01_Gradient3x3.txt", pGradientsL, nGradientsL);
	OutputAsTxt_PxGradient3x3("..\\..\\FireField\\aloeR_01_Gradient3x3.txt", pGradientsR, nGradientsR);

	SAFE_DELETE_ARRAY(pGradientsL);
	SAFE_DELETE_ARRAY(pGradientsR);

	return 0;
}

