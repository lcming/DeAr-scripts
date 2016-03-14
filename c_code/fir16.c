
#define TAP 16

int input[TAP];
int coe[TAP];
int output;

void fir16()
{ 
    output = input[0] * coe[0];
    int i;
    for(i = 1; i < TAP; i++)
    {
        output += input[i] * coe[i];
    }
}
