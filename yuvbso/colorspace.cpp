#include "colorspace.h"

void yuv2bgr(unsigned char* src_bgr,int src_cols, int src_rows,float* y,float* u,float* v)
{
    float b;
    float g;
    float r;
    int idx = 0;
    int i = 0;
    for (int h = 0; h<src_rows; h++)
    {
        for (int w = 0; w<src_cols; w++)
        {
            b = ((y[i] + 2.03211 * (u[i] - 128)) + 0.5);
            g = ((y[i] - 0.39465 * (u[i] - 128) - 0.58060 * (v[i] - 128)) + 0.5);
            r = ((y[i] + 1.13983 * (v[i] - 128)) +0.5 );

            if (b > 255) b = 255;
            if (g > 255) g = 255;
            if (r > 255) r = 255;
            if (b < 0) b = 0;
            if (g < 0) g = 0;
            if (r < 0) r = 0;
            src_bgr[idx + 0] =(unsigned char) b;
            src_bgr[idx + 1] =(unsigned char) g;
            src_bgr[idx + 2] =(unsigned char) r;
            i++;
            idx += 3;
         }
     }
}
void bgr2yuv(unsigned char* src_bgr,int src_cols, int src_rows,float* y,float* u,float* v)
{
    unsigned char b;
    unsigned char g;
    unsigned char r;
    int idx = 0;
    int i = 0;
    for (int h = 0; h<src_rows; h++)
    {
        for (int w = 0; w<src_cols; w++)
        {
            b = src_bgr[idx + 0];
            g = src_bgr[idx + 1];
            r = src_bgr[idx + 2];
            y[i] = (float)(0.299 * r + 0.587 * g + 0.114 * b);       //y = yuv[idx + 0];
            u[i] = (float)(-0.169 * r - 0.331 * g + 0.5 * b + 128);  //u = yuv[idx + 1];
            v[i] = (float)(0.5 * r - 0.419 * g - 0.081 * b + 128);   //v = yuv[idx + 2]
            idx += 3;
            i++;
        }
    }
}
