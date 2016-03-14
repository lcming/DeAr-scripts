#define TAP 16

int inputr[TAP];
int inputi[TAP];
int coer[TAP];
int coei[TAP];
int outputr;
int outputi;

void cfir16()
{ 
    outputr = inputr[0] * coer[0] - inputi[0] * coei[0];
    outputi = inputr[0] * coei[0] + inputi[0] * coer[0];
    int i;
    for(i = 1; i < TAP; i++)
    {
        outputr += inputr[i] * coer[i] - inputi[i] * coei[i];
        outputi += inputr[i] * coei[i] + inputi[i] * coer[i];
    }
}
