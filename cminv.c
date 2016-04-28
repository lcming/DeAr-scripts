int dstr[9];
int dsti[9];
int srcr[9];
int srci[9];
int detr[6];
int deti[6];
int detsumr, detsumi, det;
void cminv()
{
    dstr[0] =
        ( srcr[4] * srcr[8] - srci[4] * srci[8] ) - ( srcr[5] * srcr[7] - srci[5] *srci[7] );
    dsti[0] =
        ( srcr[4] * srci[8] + srci[4] * srcr[8] ) - ( srcr[5] * srci[7] + srci[5] *srcr[7] );

    dstr[1] =
        ( srcr[3] * srcr[8] - srci[3] * srci[8] ) - ( srcr[5] * srcr[6] - srci[5] *srci[6] );
    dsti[1] =
        ( srcr[3] * srci[8] + srci[3] * srcr[8] ) - ( srcr[5] * srci[6] + srci[5] *srcr[6] );

    dstr[2] =
        ( srcr[3] * srcr[7] - srci[3] * srci[7] ) - ( srcr[4] * srcr[6] - srci[4] *srci[6] );
    dsti[2] =
        ( srcr[3] * srci[7] + srci[3] * srcr[7] ) - ( srcr[4] * srci[6] + srci[4] *srcr[6] );

    dstr[3] =
        ( srcr[1] * srcr[8] - srci[1] * srci[8] ) - ( srcr[2] * srcr[7] - srci[2] *srci[7] );
    dsti[3] =
        ( srcr[1] * srci[8] + srci[1] * srcr[8] ) - ( srcr[2] * srci[7] + srci[2] *srcr[7] );

    dstr[4] =
        ( srcr[0] * srcr[8] - srci[0] * srci[8] ) - ( srcr[2] * srcr[6] - srci[2] *srci[6] );
    dsti[4] =
        ( srcr[0] * srci[8] + srci[0] * srcr[8] ) - ( srcr[2] * srci[6] + srci[2] *srcr[6] );

    dstr[5] =
        ( srcr[0] * srcr[7] - srci[0] * srci[7] ) - ( srcr[1] * srcr[6] - srci[1] *srci[6] );
    dsti[5] =
        ( srcr[0] * srci[7] + srci[0] * srcr[7] ) - ( srcr[1] * srci[6] + srci[1] *srcr[6] );

    dstr[6] =
        ( srcr[1] * srcr[5] - srci[1] * srci[5] ) - ( srcr[2] * srcr[4] - srci[2] *srci[4] );
    dsti[6] =
        ( srcr[1] * srci[5] + srci[1] * srcr[5] ) - ( srcr[2] * srci[4] + srci[2] *srcr[4] );

    dstr[7] =
        ( srcr[0] * srcr[5] - srci[0] * srci[5] ) - ( srcr[2] * srcr[3] - srci[2] *srci[3] );
    dsti[7] =
        ( srcr[0] * srci[5] + srci[0] * srcr[5] ) - ( srcr[2] * srci[3] + srci[2] *srcr[3] );

    dstr[8] =
        ( srcr[0] * srcr[4] - srci[0] * srci[4] ) - ( srcr[1] * srcr[3] - srci[1] *srci[3] );
    dsti[8] =
        ( srcr[0] * srci[4] + srci[0] * srcr[4] ) - ( srcr[1] * srci[3] + srci[1] *srcr[3] );

    detr[0] = srcr[2] * srcr[4] - srci[2] * srci[4];
    deti[0] = srcr[2] * srci[4] + srci[2] * srcr[4];
    detr[0] = detr[0] * srcr[6] - deti[0] * srci[6];
    deti[0] = deti[0] * srci[6] + deti[0] * srcr[6];

    detr[1] = srcr[5] * srcr[7] - srci[5] * srci[7];
    deti[1] = srcr[5] * srci[7] + srci[5] * srcr[7];
    detr[1] = detr[1] * srcr[0] - deti[1] * srci[0];
    deti[1] = deti[1] * srci[0] + deti[1] * srcr[0];

    detr[2] = srcr[8] * srcr[1] - srci[8] * srci[1];
    deti[2] = srcr[8] * srci[1] + srci[8] * srcr[1];
    detr[2] = detr[2] * srcr[3] - deti[2] * srci[3];
    deti[2] = deti[2] * srci[3] + deti[2] * srcr[3];

    detr[3] = srcr[1] * srcr[4] - srci[1] * srci[4];
    deti[3] = srcr[1] * srci[4] + srci[1] * srcr[4];
    detr[3] = detr[3] * srcr[8] - deti[3] * srci[8];
    deti[3] = deti[3] * srci[8] + deti[3] * srcr[8];

    detr[4] = srcr[1] * srcr[5] - srci[1] * srci[5];
    deti[4] = srcr[1] * srci[5] + srci[1] * srcr[5];
    detr[4] = detr[4] * srcr[6] - deti[4] * srci[6];
    deti[4] = deti[4] * srci[6] + deti[4] * srcr[6];

    detr[5] = srcr[2] * srcr[3] - srci[2] * srci[3];
    deti[5] = srcr[2] * srci[3] + srci[2] * srcr[3];
    detr[5] = detr[5] * srcr[7] - deti[5] * srci[7];
    deti[5] = deti[5] * srci[7] + deti[5] * srcr[7];

    detsumr = detr[0] + detr[1] + detr[2] - detr[3] - detr[4] - detr[5];
    detsumi = deti[0] + deti[1] + deti[2] - deti[3] - deti[4] - deti[5];
    det = detsumr * detsumi;
    dstr[ 0] >>= det;
    dstr[ 1] >>= det;
    dstr[ 2] >>= det;
    dstr[ 3] >>= det;
    dstr[ 4] >>= det;
    dstr[ 5] >>= det;
    dstr[ 6] >>= det;
    dstr[ 7] >>= det;
    dstr[ 8] >>= det;

    dsti[ 0] >>= det;
    dsti[ 1] >>= det;
    dsti[ 2] >>= det;
    dsti[ 3] >>= det;
    dsti[ 4] >>= det;
    dsti[ 5] >>= det;
    dsti[ 6] >>= det;
    dsti[ 7] >>= det;
    dsti[ 8] >>= det;
}
