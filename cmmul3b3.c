#define WA 3
#define HA 3
#define WB 3
#define HB WA
#define WC WB
#define HC HA
#define SC WC * HC
int ci[SC];
int cr[SC];
int ai[WA*HA];
int ar[WA*HA];
int bi[WB*HB];
int br[WB*HB];
void mmul()
{
    for(int i = 0; i < HC; i++)
    {
        for(int j = 0; j < WC; j++)
        {
            ci[i*WC+j] = cr[i*WC+j] = 0;
            for(int k = 0; k < WA; k++) 
            {
                cr[i*WC+j] += ar[WA*i+k] * br[k*WB+j] - ai[WA*i+k] * bi[k*WB+j];
                ci[i*WC+j] += ar[WA*i+k] * bi[k*WB+j] + ai[WA*i+k] * br[k*WB+j];
            }
        }
    }
}
