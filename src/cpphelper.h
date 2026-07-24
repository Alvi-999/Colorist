#include <stdio.h>

float min(float &a, float &b)
{
    if(a<b) return a;

    return b;
}

float max(float &a, float &b)
{
    if(a>b) return a;

    return b;
}