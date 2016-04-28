int in[8];
int out[8];
int sh[10];
void it()
{
    int tmp0;
    int tmp1;
    int tmp2;
    int tmp3;
    int tmp4;
    int tmp5;
    int tmp6;
    int tmp7;

    int _tmp0;
    int _tmp1;
    int _tmp2;
    int _tmp3;
    int _tmp4;
    int _tmp5;
    int _tmp6;
    int _tmp7;

    tmp0 = in[0] + in[7];
    tmp1 = in[1] + in[6];
    tmp2 = in[2] + in[5];
    tmp3 = in[3] + in[4];
    tmp7 = in[0] - in[7];
    tmp6 = in[1] - in[6];
    tmp5 = in[2] - in[5];
    tmp4 = in[3] - in[4];

    tmp5 = tmp5 - tmp6 * sh[0];
    tmp6 = tmp6 + tmp5 * sh[1];
    tmp5 = tmp5 - tmp6 * sh[2];

    _tmp0 =  tmp0;
    _tmp1 =  tmp1;
    _tmp2 =  tmp2;
    _tmp3 =  tmp3;
    _tmp4 =  tmp4;
    _tmp5 =  tmp5;
    _tmp6 =  tmp6;
    _tmp7 =  tmp7;

    tmp0 = _tmp0 + _tmp3;
    tmp3 = _tmp0 - _tmp3;
    tmp1 = _tmp1 + _tmp2;
    tmp2 = _tmp1 - _tmp2;
    tmp4 = _tmp4 + _tmp5;
    tmp5 = _tmp4 - _tmp5;
    tmp6 = _tmp6 + _tmp7;
    tmp7 = _tmp6 - _tmp7;

    out[0] = tmp0 + tmp1;
    out[1] = out[1]*sh[3] - tmp1;

    out[3] = tmp2 * sh[4] + tmp3;
    out[2] = out[3] + tmp2;
    out[3] = out[2] * sh[5] + out[3];
    
    out[7] = tmp4 * sh[6] + tmp7;
    out[4] = out[7] + tmp2;
    out[7] = out[4] * sh[7] + out[7];
    
    out[6] = tmp5 * sh[8] + tmp6;
    out[5] = out[6] + tmp2;
    out[6] = out[5] * sh[9] + out[6];
}
