#include "scaleprocess.h"

float fmax(float* arr,int arr_len)
{
    float max = 0;
    for (int i=0; i<arr_len ;i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
float fmin(float* arr,int arr_len)
{
    float min = 255;
    for (int i=0; i<arr_len ;i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}
void sca2max(float* arr,int arr_len,float max,float min,float* new_arr)
{
    for (int i=0; i<arr_len ;i++)
    {
        new_arr[i] = (float)((arr[i] - min)/(max - min)*255.0);
    }
}
