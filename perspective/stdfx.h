#ifndef __STDFX_H__
#define __STDFX_H__

#ifdef _Win32
#ifdef _Debug
#pragma comment(lib, "opencv_core244d.lib")
#pragma comment(lib, "opencv_imgproc244d.lib")
#pragma comment(lib, "opencv_highgui244d.lib")
#else
#pragma comment(lib, "opencv_core244.lib")
#endif
//#else
#endif

#endif /* __STDFX_H__ */