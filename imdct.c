int in[16];
int out[12];
int shm[9];
int mul[10];
void imdct()
{
    int out0, out1, out2, out3, out4, out5, in0, in1, in2, in3, in4, tmp;
    in[15] += (in[12] += in[9]) + in[6];
    in[9] += (in[6] += in[3]);
    in[3] += in[0];
    out1 = (in1 = in[0]) - (in2 = in[12]);
    in3 = in1 + (in2 << shm[0]);
    in4 = in[6] * mul[0];
    out0 = in3 + in4;
    out2 = in3 - in4;
    out4 = ((in1 = in[3]) - (in2 = in[15])) * mul[1];
    in3 = in1 + (in2<< shm[1]) ;
    in4 = in[9] * mul[2];
    out5 = (in3 + in4) <<shm[2];
    out3 = (in3 - in4) <<shm[3];
    tmp = out0; out0 += out5; out5 = tmp - out5;
    tmp = out1; out1 += out4; out4 = tmp - out4;
    tmp = out2; out2 += out3; out3 = tmp - out3;
    in1 = out3 * mul[3];
    out[0] *= in1;
    out[1] -= out4 <<shm[4];
    out[2] = out5 <<shm[5];
    out[3] = out5 * mul[4];
    out[4] = out4 * mul[5];
    out[5] = in1  <<shm[6];
    out[6] = out2 * mul[6];
    out[7] = out1 <<shm[7];
    out[8] = out0 * mul[7];
    out[9] = out0 * mul[8];
    out[10] = out1 * mul[9];
    out[11] = out2 <<shm[8];

}
