///	@file		Funcs.h
///	@brief		...
///	@licence	...
///	@designer	Tankle L.
///	@date		First created at < November 22th, 2015 >
///
///	@version	0.1.0
///
///	@programmer	Tankle L.
///	@programmer ...


#ifndef _TYPES_H
#define	_TYPES_H

typedef	struct Pixel24
{
	BYTE	r;
	BYTE	g;
	BYTE	b;
} PIXEL24, *PPIXEL24;

typedef	unsigned int	PIXEL, PIXEL32;
typedef PIXEL			*PPIXEL, *PPIXEL32;
typedef BYTE			PIXELCHANNEL, *PPIXELCHANNEL;

typedef enum _ImageFileType
{
	IFT_Unknown = 0,
	IFT_BMP_24,
	IFT_BMP_32,
	IFT_JPEG,
	IFT_PNG
} IMAGEFILETYPE, *PIMAGEFILETYPE;

typedef struct resolution
{
	resolution() : width(0), height(0)
	{}

	resolution(const resolution& reso) :
		width(reso.width), height(reso.height)
	{}

	int		width;
	int		height;
} RESOLUTION, *PRESOLUTION;



typedef unsigned char	RELATIVEPXGRADIENT_3x3;		// Total 8-bits.
typedef unsigned int	RELATIVEPXGRADIENT_5x5;		// Total 32-bits, 8 High-Order-Bits Reserved.



#endif // !_TYPES_H
