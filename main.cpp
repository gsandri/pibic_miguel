#include "dtw.h"
#include <stdio.h>

int main()
{
    double v1[] = {0,2,3,0,4};
    double v2[] = {0,3,4,1};

    printf("DTW v1->v2 = %lf\n", dtw(v1, v2, 5, 4));
    printf("DTW v2->v1 = %lf\n", dtw(v2, v1, 4, 5));
}
