----
## yuvscaleup
>This file is enlarge the brightness of the image.
Transfrom the image's bgr space to the yuv-color space, and amplification the colorspace plan-y (brightness) from original to maximum norm.
---
This file contains two directories
yuvbso to build the libary
yuv for the main function

* yuv
  1.CMakeLists.txt
  2.build.sh
  3.main.cpp
  4.perforval.cpp
  5.perforval.h
  6.scaleprocess.h
  7.colorspace.h
  8.libyuv.so
  
* yuvbso
1.CMakeLists.txt
2.build.sh
3.colorspace.cpp
4.colorspace.h
5.scaleprocess.cpp
6.scaleprocess.h
