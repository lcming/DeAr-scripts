
#define NORM 2

int goutput[32];
int tmp[32];

int sin8[8];
int cos8[8];

int sin16[16];
int cos16[16];

int C_P_S_2PI_16;// = cos8[1] + sin8[1];
int C_M_S_2PI_16;// = cos8[1] - sin8[1];
int C_P_S_6PI_16;// = cos8[3] + sin8[3];
int C_M_S_6PI_16;// = cos8[3] - sin8[3];
int SIN_2PI_16;// = sin8[1];
int SIN_4PI_16;// = sin8[2];
int SIN_6PI_16;// = sin8[3];

__attribute__((always_inline))void fft8(int* array) {
  int temp, out0, out1, out2, out3, out4, out5, out6, out7, out8;
  int out9,out10,out11,out12,out13,out14,out15;

  out0=array[0]+array[8]; /* array[0 through 7] is the data that we */
  out1=array[1]+array[9]; /* take the 8 point real FFT of. */
  out2=array[2]+array[10];
  out3=array[3]+array[11];
  out4=array[4]+array[12];
  out5=array[5]+array[13];
  out6=array[6]+array[14];
  out7=array[7]+array[15];



  out8=array[0]-array[8];   /* inputs 8,9,10,11 are */
  out9=array[1]-array[9];   /* the Real part of the */
  out10=array[2]-array[10]; /* 4 point Complex FFT inputs.*/
  out11=array[3]-array[11]; 
  out12=array[12]-array[4]; /* outputs 12,13,14,15 are */
  out13=array[13]-array[5]; /* the Imaginary pars of  */
  out14=array[14]-array[6]; /* the 4 point Complex FFT inputs.*/
  out15=array[15]-array[7];

  /*First we do the "twiddle factor" multiplies for the 4 point CFFT */
  /*Note that we use the following handy trick for doing a complex */
  /*multiply:  (e+jf)=(a+jb)*(c+jd) */
  /*   e=(a-b)*d + a*(c-d)   and    f=(a-b)*d + b*(c+d)  */

  /* C_M_S_2PI/16=cos(2pi/16)-sin(2pi/16) when replaced by macroexpansion */
  /* C_P_S_2PI/16=cos(2pi/16)+sin(2pi/16) when replaced by macroexpansion */
  /* (SIN_2PI_16)=sin(2pi/16) when replaced by macroexpansion */
  temp=(out13-out9)*(SIN_2PI_16); 
  out9=out9*(C_P_S_2PI_16)+temp; 
  out13=out13*(C_M_S_2PI_16)+temp;

  // fix norm
  out9 >>= NORM;
  out13 >>= NORM;
  
  out14*=(SIN_4PI_16);
  out10*=(SIN_4PI_16);
  out14=out14-out10;
  out10=out14+(out10<<1);

  // fix norm
  out14 >>= NORM;
  out10 >>= NORM;
  
  temp=(out15-out11)*(SIN_6PI_16);
  out11=out11*(C_P_S_6PI_16)+temp;
  out15=out15*(C_M_S_6PI_16)+temp;

  // fix norm
  out11 >>= NORM;
  out15 >>= NORM;

  /* The following are the first set of two point butterfiles */
  /* for the 4 point CFFT */

  out8+=out10;
  out10=out8-(out10<<1);

  out12+=out14;
  out14=out12-(out14<<1);

  out9+=out11;
  out11=out9-(out11<<1);

  out13+=out15;
  out15=out13-(out15<<1);

  /*The followin are the final set of two point butterflies */
  array[1]=out8+out9;
  array[7]=out8-out9;

  array[9]=out12+out13;
  array[15]=out13-out12;
  
  array[5]=out10+out15;        /* implicit multiplies by */
  array[13]=out14-out11;        /* a twiddle factor of -j */                            
  array[3]=out10-out15;  /* implicit multiplies by */
  array[11]=-out14-out11;  /* a twiddle factor of -j */

  
  /* What follows is the 8-point FFT of points array[0-7] */
  /* This 8-point FFT is basically a Decimation in Frequency FFT */
  /* where we take advantage of the fact that the initial data is real*/

  /* First set of 2-point butterflies */
    
  out0=out0+out4;
  out4=out0-(out4<<1);
  out1=out1+out5;
  out5=out1-(out5<<1);
  out2+=out6;
  out6=out2-(out6<<1);
  out3+=out7;
  out7=out3-(out7<<1);

  /* Computations to find X[0], X[4], X[6] */
  
  array[0]=out0+out2;
  array[4]=out0-out2;
  out1+=out3;
  array[12]=(out3<<1)-out1;

  array[0]+=out1;  /* Real Part of X[0] */
  array[8]=array[0]-(out1<<1); /*Real Part of X[4] */
  /* out2 = Real Part of X[6] */
  /* out3 = Imag Part of X[6] */
  
  /* Computations to find X[5], X[7] */

  out5*=SIN_4PI_16;
  out7*=SIN_4PI_16;
  out5=out5-out7;
  out7=out5+(out7<<1);

  // fix norm
  out5 >>= NORM;
  out7 >>= NORM;

  array[14]=out6-out7; /* Imag Part of X[5] */
  array[2]=out5+out4; /* Real Part of X[7] */
  array[6]=out4-out5; /*Real Part of X[5] */
  array[10]=-out7-out6; /* Imag Part of X[7] */


}
//__attribute__((always_inline))
void fft16() {
    int tar, tai, lar, lai, re, im;

    // top butterfly
    for(int i = 0; i < 8; i++)
    {
        tar = goutput[i] + goutput[i+16];
        tai = goutput[i+8] + goutput[i+24];
        goutput[i] = tar;
        goutput[i+8] = tai;
    }
    fft8(goutput);

    // lower bufferfly multiplied by twiddle factor, complex mult
    for(int i = 0; i < 8; i++)
    {
        lar = goutput[i] - goutput[i+16];
        lai = goutput[i+8] - goutput[i+24];
        goutput[i+16] = lar;
        goutput[i+24] = lai;
    }
    for(int i = 1; i < 8; i++)
    {
        int idx = i + 16;
        re = goutput[idx] * cos16[i] - goutput[idx+8] * sin16[i];
        im = goutput[idx] * sin16[i] + goutput[idx+8] * cos16[i];
        goutput[idx] = re >> NORM;
        goutput[idx+8] = im >> NORM;
    }
    fft8(goutput+16);


}

