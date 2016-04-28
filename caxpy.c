#define SIZE 32
int alphar, alphay, yr, yi;
int xr[SIZE];
int xi[SIZE];
int _xr[SIZE];
int _xi[SIZE];
void axpy()
{
    for(int i = 0; i < SIZE; i++) 
    {
        xr[i] = alphar * _xr[i] - alphay * _xi[i] + yr;
        xi[i] = alphar * _xi[i] + alphay * _xr[i] + yi;
    }
}

