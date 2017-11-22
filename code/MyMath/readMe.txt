#include <iostream>
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

int main(int argc, char* argv[])
{
    int m = 1 , n = 3 , k = 3;
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

    delete[] m1;
    delete[] m2;
    delete[] m3;
    return 0;
}
