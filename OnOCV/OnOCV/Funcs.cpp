///	@file		Funcs.h
///	@brief		...
///	@licence	...
///	@designer	Tankle L.
///	@date		First created at < November 17th, 2015 >
///
///	@version	0.1.0
///
///	@programmer	Tankle L.
///	@programmer ...

#include "stdafx.h"

#include "lab.h"

using namespace cv;
using namespace std;

int	CalculateRelativePxGradient3x3(RELATIVEPXGRADIENT_3x3*& pGradients, const cv::Mat& imgMat)
{
	int width = imgMat.cols;
	int height = imgMat.rows;

	pGradients = new RELATIVEPXGRADIENT_3x3[(width - 2)*(height - 2)];

	Vec3b const*	pPxT = nullptr;			// Top
	Vec3b const*	pPxM = nullptr;			// Middle
	Vec3b const*	pPxB = nullptr;			// Bottom
	register unsigned char	regValue = 0;
	for (int y = 1; y < height - 1; ++y)
	{
		pPxT = imgMat.ptr<Vec3b>(y + 1);
		pPxM = imgMat.ptr<Vec3b>(y);
		pPxB = imgMat.ptr<Vec3b>(y - 1);
		for (int x = 1; x < width - 1; ++x)
		{
			pGradients[x-1 + (width - 2)*(y-1)] = 0;

			{
				// Gradient 0.
				if (GetPixelBrightness(pPxM[x - 1]) > GetPixelBrightness(pPxM[x]))
					regValue = 1;
				else
					regValue = 0;
				pGradients[x - 1 + (width - 2)*(y - 1)] |= regValue << 0;

				// Gradient 1.
				if (GetPixelBrightness(pPxT[x - 1]) > GetPixelBrightness(pPxM[x]))
					regValue = 1;
				else
					regValue = 0;
				pGradients[x - 1 + (width - 2)*(y - 1)] |= regValue << 1;

				// Gradient 2.
				if (GetPixelBrightness(pPxT[x]) > GetPixelBrightness(pPxM[x]))
					regValue = 1;
				else
					regValue = 0;
				pGradients[x - 1 + (width - 2)*(y - 1)] |= regValue << 2;

				// Gradient 3.
				if (GetPixelBrightness(pPxT[x + 1]) > GetPixelBrightness(pPxM[x]))
					regValue = 1;
				else
					regValue = 0;
				pGradients[x - 1 + (width - 2)*(y - 1)] |= regValue << 3;

				// Gradient 4.
				if (GetPixelBrightness(pPxM[x + 1]) > GetPixelBrightness(pPxM[x]))
					regValue = 1;
				else
					regValue = 0;
				pGradients[x - 1 + (width - 2)*(y - 1)] |= regValue << 4;

				// Gradient 5.
				if (GetPixelBrightness(pPxB[x + 1]) > GetPixelBrightness(pPxM[x]))
					regValue = 1;
				else
					regValue = 0;
				pGradients[x - 1 + (width - 2)*(y - 1)] |= regValue << 5;

				// Gradient 7.
				if (GetPixelBrightness(pPxB[x]) > GetPixelBrightness(pPxM[x]))
					regValue = 1;
				else
					regValue = 0;
				pGradients[x - 1 + (width - 2)*(y - 1)] |= regValue << 6;

				// Gradient 8.
				if (GetPixelBrightness(pPxB[x - 1]) > GetPixelBrightness(pPxM[x]))
					regValue = 1;
				else
					regValue = 0;
				pGradients[x - 1 + (width - 2)*(y - 1)] |= regValue << 7;
			}


		}
	}
	return (width - 2)*(height - 2);
}


int		OutputAsTxt_PxGradient3x3(const std::string& fileName, RELATIVEPXGRADIENT_3x3* const pGradients, const int& count)
{
	ofstream	file(fileName);

	if (!file.is_open())
	{
		return -1;		// Cannot open file.
	}

	file << "Gradient[N]\tX-RadixValue\tII-RadixValue" << endl;

	for (int i = 0; i < count; ++i)
	{
		file << i << "\t" << (int)pGradients[i] << "\t" << IIRadix2XRadix_8bit(pGradients[i]) << endl;
	}

	return count;
}
