///	@file		utilities.h
///	@brief		...
///	@licence	...
///	@designer	Tankle L.
///	@date		First created at < November 17th, 2015 >
///
///	@version	0.1.0
///
///	@programmer	Tankle L.
///	@programmer ...

#ifndef _UTILITIES_H
#define	_UTILITIES_H


#define	SAFE_RELEASE(pObj)			{if(pObj) {(pObj)->Release(); pObj = nullptr;}}
#define	SAFE_DELETE(pObj)			{if(pObj) {delete pObj; pObj = nullptr;}}
#define SAFE_DELETE_ARRAY(pObj)		{if(pObj) {delete[] pObj; pObj = nullptr;}}
#define SAFE_FREE(pObj)				{if(pObj) {free(pObj); pObj = nullptr;}}
#define	SAFE_CLOSEHANDLE(pObj)		{if(pObj && pObj != INVALID_HANDLE_VALUE) {CloseHandle(pObj); pObj = nullptr;}}


_inline PIXELCHANNEL GetPixelAValue(PIXEL pixel)
{
	return LOBYTE((pixel) >> 24);
}

_inline PIXELCHANNEL GetPixelRValue(PIXEL pixel)
{
	return LOBYTE((pixel) >> 16);
}

_inline PIXELCHANNEL GetPixelGValue(PIXEL pixel)
{
	return LOBYTE(((WORD)(pixel)) >> 8);
}

_inline PIXELCHANNEL GetPixelBValue(PIXEL pixel)
{
	return LOBYTE(pixel);
}

_inline	PIXEL PixelRGB(BYTE r, BYTE g, BYTE b)
{
	return (PIXEL)(((BYTE)(b) | ((WORD)((BYTE)(g)) << 8)) | (((DWORD)(BYTE)(r)) << 16) | (((DWORD)(BYTE)(0xff)) << 24));
}

_inline	PIXEL PixelARGB(BYTE a, BYTE r, BYTE g, BYTE b)
{
	return (PIXEL)(((BYTE)(b) | ((WORD)((BYTE)(g)) << 8)) | (((DWORD)(BYTE)(r)) << 16) | (((DWORD)(BYTE)(a)) << 24));
}

_inline float	GetPixelBrightness(PIXEL px)
{
	return (((float)GetPixelRValue(px)) + ((float)GetPixelGValue(px)) + ((float)GetPixelBValue(px))) / 3.0f;
}

_inline float	GetPixelBrightness(BYTE r, BYTE g, BYTE b)
{
	return (((float)r) + ((float)g) + ((float)b)) / 3.0f;
}

_inline float	GetPixelBrightness(cv::Vec3b pixel)
{
	// pixel.val[1]    pixel.val[2]    pixel.val[2]
	//      r               g               b
	return (((float)pixel.val[0]) + ((float)pixel.val[1]) + ((float)pixel.val[2])) / 3.0f;
}

_inline float	GetPixelBrightnessWithAlpha(BYTE a, BYTE r, BYTE g, BYTE b)
{
	return (((float)r) + ((float)g) + ((float)b)) / 3.0f *((float)a) / 255.0f;
}

_inline float	GetPixelBrightnessWithAlpha(cv::Vec4b pixel)
{
	// pixel.val[0]    pixel.val[1]    pixel.val[2]    pixel.val[2]
	//      a               r               g               b
	return (((float)pixel.val[1]) + ((float)pixel.val[2]) + ((float)pixel.val[3])) / 3.0f *((float)pixel.val[0]) / 255.0f;
}

_inline float	GetPixelBrightnessWithAlpha(PIXEL px)
{
	return (((float)GetPixelRValue(px)) + ((float)GetPixelGValue(px)) + ((float)GetPixelBValue(px))) / 3.0f *((float)GetPixelAValue(px)) /255.0f;
}

_inline int IIRadix2XRadix_8bit(int in)
{
	int out = 0;

	out += ((in & 128) >> 7) * 10000000;
	out += ((in & 64) >> 6) *  1000000;
	out += ((in & 32) >> 5) *  100000;
	out += ((in & 16) >> 4) *  10000;
	out += ((in & 8) >> 3) *   1000;
	out += ((in & 4) >> 2) *   100;
	out += ((in & 2) >> 1) *   10;
	out += (in & 1);

	return out;
}

#endif // !_UTILITIES_H
