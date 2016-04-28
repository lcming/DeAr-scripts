#define SIZE 32
int alpha, y;
int x[SIZE];
void axpy()
{
    for(int i = 0; i < SIZE; i++) 
    {
        x[i] *= alpha;
        x[i] += y;
    }
}

