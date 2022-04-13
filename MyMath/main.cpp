#include <iostream>
#include <math.h>
using namespace std;

void MatrixMultiplication(double *m1,double *m2,double *m3,int m,int n,int k)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<k;j++)
        {
            double sum = 0.0;
            for(int jj=0;jj<n;jj++)
            {
                sum += *(m1+i*n+jj)*(*(m2+jj*k+j));
            }
            *(m3+i*k+j) = sum;
        }
    }
}
void RotateArbitraryAxis(float* pOut, float* axis, float theta)
{
    float u = axis[0];
    float v = axis[1];
    float w = axis[2];

    pOut[0*4+0] = cosf(theta) + (u * u) * (1 - cosf(theta));
    pOut[0*4+1] = u * v * (1 - cosf(theta)) + w * sinf(theta);
    pOut[0*4+2] = u * w * (1 - cosf(theta)) - v * sinf(theta);
    pOut[0*4+3] = 0;

    pOut[1*4+0] = u * v * (1 - cosf(theta)) - w * sinf(theta);
    pOut[1*4+1] = cosf(theta) + v * v * (1 - cosf(theta));
    pOut[1*4+2] = w * v * (1 - cosf(theta)) + u * sinf(theta);
    pOut[1*4+3] = 0;

    pOut[2*4+0] = u * w * (1 - cosf(theta)) + v * sinf(theta);
    pOut[2*4+1] = v * w * (1 - cosf(theta)) - u * sinf(theta);
    pOut[2*4+2] = cosf(theta) + w * w * (1 - cosf(theta));
    pOut[2*4+3] = 0;

    pOut[3*4+0] = 0;
    pOut[3*4+1] = 0;
    pOut[3*4+2] = 0;
    pOut[3*4+3] = 1;
}

int main(int argc, char* argv[])
{
    int m = 4 , n = 4 , k = 4;
    double *m1,*m2,*m3;
    m1 = new double[m*n];
    m2 = new double[n*k];
    m3 = new double[m*k];

    //[50   50  1]
    *(m1+n*0+0) = 50;
    *(m1+n*0+1) = 50;
    *(m1+n*0+2) = 1;

    //[1    0   0]
    //[0    1   0]
    //[200, 200,1]
    *(m2+k*0+0) = 1;
    *(m2+k*0+1) = 0;
    *(m2+k*0+2) = 0;
    *(m2+k*1+0) = 0;
    *(m2+k*1+1) = 1;
    *(m2+k*1+2) = 0;
    *(m2+k*2+0) = 200;
    *(m2+k*2+1) = 200;
    *(m2+k*2+2) = 1;

    MatrixMultiplication(m1,m2,m3,m,n,k);

    cout<<"["<<*(m3+k*0+0)<<" ";
    cout<<*(m3+k*0+1)<<" ";
    cout<<*(m3+k*0+2)<<"]"<<endl;


    float* pOut = new float[16];
    float* axis = new float[3]{0.0f,1.0f,0.0f};
    RotateArbitraryAxis(pOut,axis,0.1f);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout<<pOut[i*4+j]<<" ";
        }
        cout<<endl;
    }

    delete[] m1;
    delete[] m2;
    delete[] m3;
    return 0;
}
