
#define NORM 3
#define B 3
/* This function calculates the discrete cosine transform of an image block.
   The result is returned in the same matrix as the original block. */
int block[B][B];
int cos1[B][B];
int cos2[B][B];

void dct()
{
  int i;
  int j;
  int k;
  int sum;
  int mid[B][B];

  /* Multiply the input image block with the cos2 matrix; store the result
     in the temporary matrix "temp2d". */

  for (i = 0; i < B; i++) {
    for (j = 0; j < B; j++) {
      sum = 0;
      for (k = 0; k < B; k++) {
        sum += block[i][k] * cos2[k][j];
      }
      mid[i][j] = sum;
    }
  }


  /* Multiply the cosine matrix by the temporary matrix; store the
     result back in the original matrix.  */

  for (i = 0; i < B; i++) {  /* advances cos1 row */
    for (j = 0; j < B; j++) {  /* no change */
      sum = 0.0;
      for (k = 0; k < B; k++) {  /* advances cos1 col */
        sum += cos1[i][k] * mid[k][j] ;
      }
      /* round the result */
      block[i][j] = sum >> NORM;
    }
  }

}

