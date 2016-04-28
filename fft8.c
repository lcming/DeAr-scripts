


int rout[8];
int iout[8];
int rin[8];
int iin[8];
int rw[4];
int iw[4];


void fft8() {
    int rtmp0, rtmp1, rtmp2, rtmp3, rtmp4, rtmp5, rtmp6, rtmp7;
    int itmp0, itmp1, itmp2, itmp3, itmp4, itmp5, itmp6, itmp7;

    rtmp0 = rin[0] + rin[4]; itmp0 = iin[0] + iin[4];
    rtmp1 = rin[0] - rin[4]; itmp1 = iin[0] - iin[4];
    rtmp2 = rin[2] + rin[6]; itmp2 = iin[2] + iin[6];
    rtmp3 = rin[2] - rin[6]; itmp3 = iin[2] - iin[6];
    rtmp4 = rin[1] + rin[5]; itmp4 = iin[1] + iin[4];
    rtmp5 = rin[1] - rin[5]; itmp5 = iin[1] - iin[4];
    rtmp6 = rin[3] + rin[7]; itmp6 = iin[3] + iin[7];
    rtmp7 = rin[3] - rin[7]; itmp7 = iin[3] - iin[7];

    int _rtmp3 = rtmp3;
    int _itmp3 = itmp3;
    rtmp3 = _rtmp3*rw[1] - _itmp3*iw[1];
    itmp3 = _rtmp3*iw[1] + _itmp3*rw[1];
    
    int _rtmp7 = rtmp7;
    int _itmp7 = itmp7;
    rtmp7 = _rtmp7*rw[1] - _itmp7*iw[1];
    itmp7 = _rtmp7*iw[1] + _itmp7*rw[1];
    
    rout[0] = rtmp0; iout[0] = itmp0;
    rout[1] = rtmp1; iout[1] = itmp1;
    rout[2] = rtmp2; iout[2] = itmp2;
    rout[3] = rtmp3; iout[3] = itmp3;
    rout[4] = rtmp4; iout[4] = itmp4;
    rout[5] = rtmp5; iout[5] = itmp5;
    rout[6] = rtmp6; iout[6] = itmp6;
    rout[7] = rtmp7; iout[7] = itmp7;

    rtmp0 = rout[0] + rout[2]; itmp0 = iout[0] + iout[2];
    rtmp2 = rout[0] - rout[2]; itmp2 = iout[0] - iout[2];
    rtmp1 = rout[1] + rout[3]; itmp1 = iout[1] + iout[3];
    rtmp3 = rout[1] - rout[3]; itmp3 = iout[1] - iout[3];
    rtmp4 = rout[4] + rout[6]; itmp4 = iout[4] + iout[6];
    rtmp6 = rout[4] - rout[6]; itmp6 = iout[4] - iout[6];
    rtmp5 = rout[5] + rout[7]; itmp5 = iout[5] + iout[7];
    rtmp7 = rout[5] - rout[7]; itmp7 = iout[5] - iout[7];

    int _rtmp5 = rtmp5;
    int _itmp5 = itmp5;
    rtmp5 = _rtmp5*rw[1] - _itmp5*iw[1];
    itmp5 = _rtmp5*iw[1] + _itmp5*rw[1];

    int _rtmp6 = rtmp6;
    int _itmp6 = itmp6;
    rtmp6 = _rtmp5*rw[2] - _itmp6*iw[2];
    itmp6 = _rtmp6*iw[2] + _itmp6*rw[2];

    _rtmp7 = rtmp7;
    _itmp7 = itmp7;
    rtmp7 = _rtmp7*rw[3] - _itmp7*iw[3];
    itmp7 = _rtmp7*iw[3] + _itmp7*rw[3];

    rout[0] = rtmp0; iout[0] = itmp0;
    rout[1] = rtmp1; iout[1] = itmp1;
    rout[2] = rtmp2; iout[2] = itmp2;
    rout[3] = rtmp3; iout[3] = itmp3;
    rout[4] = rtmp4; iout[4] = itmp4;
    rout[5] = rtmp5; iout[5] = itmp5;
    rout[6] = rtmp6; iout[6] = itmp6;
    rout[7] = rtmp7; iout[7] = itmp7;

}
