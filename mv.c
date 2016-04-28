#define W 8
#define H 8
#define S W*H
int c[H];
int a[S];
int b[W];
void mvmul()
{
    for(int i = 0; i < H; i++)
    {
        c[i] = 0;
        for(int j = 0; j < W; j++) 
        {
            c[i] += a[j+W*i] * b[j];
        }
    }
}
