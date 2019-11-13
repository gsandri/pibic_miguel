#include "dtw.h"

double dtw(double *v1, double *v2, int N1, int N2)
{
    double *error = new double[N1*N2];
    double *custo = new double[N1*N2];
    int i, j;

    for(i=0; i<N1; i++)
    {
        for(j=0; j<N2; j++)
        {
            double dif = v1[i]-v2[j];
            error[i+j*N1] = dif*dif;
        }
    }

    custo[0] = error[0];

    for(j=1; j<N2; j++)
    {
        custo[j*N1] = custo[(j-1)*N1] + error[j*N1];
    }
    for(i=1; i<N1; i++)
    {
        custo[i] = custo[i-1] + error[i];
    }

    for(i=1; i<N1; i++)
    {
        for(j=1; j<N2; j++)
        {
            double menor = custo[i-1+j*N1];

            if( menor > custo[i-1+(j-1)*N1] )
                menor = custo[i-1+(j-1)*N1];
            if( menor > custo[i+(j-1)*N1] )
                menor = custo[i+(j-1)*N1];

            custo[i+j*N1] = menor + error[i+j*N1];
        }
    }

    double distanciaDTW = custo[N1*N2-1];

    delete [] error;
    delete [] custo;

    return distanciaDTW;
}
