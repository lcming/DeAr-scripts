


int out[16];
int in[16];
int w[8];


void rfft16() {
    int tmp0;
    int tmp1;
    int tmp2;
    int tmp3;
    int tmp4;
    int tmp5;
    int tmp6;
    int tmp7;
    int tmp8;
    int tmp9;
    int tmp10;
    int tmp11;
    int tmp12;
    int tmp13;
    int tmp14;
    int tmp15;

    tmp0 = in[0] + in[8];
    tmp1 = in[0] - in[8];
    tmp2 = in[4] + in[12];
    tmp3 = in[4] ;
    tmp4 = in[2] + in[10];
    tmp5 = in[2] ;
    tmp6 = in[6] + in[14];
    tmp7 = in[6] ;
    tmp8 = in[1] + in[5];
    tmp9 = in[1] ;
    tmp10 = in[5] + in[3];
    tmp11 = in[5] ;
    tmp12 = in[3] + in[7];
    tmp13 = in[3] ;
    tmp14 = in[7] + in[15];
    tmp15 = in[7] ;

    int _tmp0  = tmp0 ;
    int _tmp1  = tmp1 ;
    int _tmp2  = tmp2 ;
    int _tmp3  = tmp3 ;
    int _tmp4  = tmp4 ;
    int _tmp5  = tmp5 ;
    int _tmp6  = tmp6 ;
    int _tmp7  = tmp7 ;
    int _tmp8  = tmp8 ;
    int _tmp9  = tmp9 ;
    int _tmp10 = tmp10;
    int _tmp11 = tmp11;
    int _tmp12 = tmp12;
    int _tmp13 = tmp13;
    int _tmp14 = tmp14;
    int _tmp15 = tmp15;

    tmp0 = _tmp0 + _tmp2; 
    tmp2 = _tmp0 ; 
    tmp1 = _tmp1 + _tmp3; 
    tmp3 = _tmp1 ; 
    tmp4 = _tmp4 + _tmp6; 
    tmp6 = _tmp4 ; 
    tmp5 = _tmp5 + _tmp7; 
    tmp7 = _tmp5 ; 
    tmp8 = _tmp8 + _tmp10; 
    tmp10 = _tmp8 ; 
    tmp9 = _tmp9 + _tmp11; 
    tmp11 = _tmp9 ; 
    tmp12 = _tmp12 + _tmp14; 
    tmp14 = _tmp12 ; 
    tmp13 = _tmp13 + _tmp15; 
    tmp15 = _tmp13 ; 

    _tmp0  = tmp0 ;
    _tmp1  = tmp1 ;
    _tmp2  = tmp2 ;
    _tmp3  = tmp3 ;     
    _tmp4  = tmp4 ;
    _tmp5  = tmp5 * w[2];
    _tmp6  = tmp6 ;
    _tmp7  = tmp7 * w[6];
    _tmp8  = tmp8 ;
    _tmp9  = tmp9 ;
    _tmp10 = tmp10;
    _tmp11 = tmp11;
    _tmp12 = tmp12;
    _tmp13 = tmp13 * w[2];
    _tmp14 = tmp14 * w[6];
    _tmp15 = tmp15;

    tmp0 = _tmp0 + _tmp4; 
    tmp4 = _tmp0 ; 
    tmp1 = _tmp1 + _tmp5; 
    tmp5 = _tmp1 ; 
    tmp2 = _tmp2 + _tmp6; 
    tmp6 = _tmp2 ; 
    tmp3 = _tmp3 + _tmp7; 
    tmp7 = _tmp3 ; 
    tmp8 = _tmp8 + _tmp12; 
    tmp12 = _tmp8 ; 
    tmp9 = _tmp9 + _tmp13; 
    tmp13 = _tmp9 ; 
    tmp10 = _tmp10 + _tmp14; 
    tmp14 = _tmp10 ; 
    tmp11 = _tmp11 + _tmp15; 
    tmp15 = _tmp11 ; 

    out[0 ]= tmp0 ;
    out[8 ]= tmp1 ;
    out[1 ]= tmp2 ;
    out[9 ]= tmp3 ;     
    out[2 ]= tmp4 ;
    out[10]= tmp5 ;
    out[3 ]= tmp6 ;
    out[11]= tmp7 ;
    out[4 ]= tmp8 ;
    out[12]= tmp9 * w[1];
    out[5 ]= tmp10 * w[2];
    out[13]= tmp11 * w[3];
    out[6 ]= tmp12;
    out[14]= tmp13 * w[5];
    out[7 ]= tmp14 * w[6];
    out[15]= tmp15 * w[7];

}
