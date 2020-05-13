#ifndef __COLORSPACE_H__
#define __COLORSPACE_H__

void bgr2yuv(unsigned char* src_bgr,int src_cols, int src_rows,float* y,float* u,float* v);

void yuv2bgr(unsigned char* src_bgr,int src_cols, int src_rows,float* y,float* u,float* v);

#endif
