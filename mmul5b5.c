#define WA 5
#define HA 5
#define WB 5
#define HB WA
#define WC WB
#define HC HA
#define SC WC * HC
int c[SC];
int a[WA*HA];
int b[WB*HB];
void mmul()
{
    for(int i = 0; i < HC; i++)
    {
        for(int j = 0; j < WC; j++)
        {
            c[i*WC+j] = 0;
            for(int k = 0; k < WA; k++) 
            {
                c[i*WC+j] += a[WA*i+k] * b[k*WB+j];
            }
        }
    }
}
