float gain;

void LPC_analysis()
{
  float E;

  float temp_gain;
  float sum;
  float temp3;

  int m;
  int n;
  int r;


  /* Window the signal */

  for (m = 0; m < N; ++m) {
    signal[m]=window[m]*hamming[m];
  }

  /* Compute the autocorrelation vector */

  for (m = 0; m < P ; ++m) {
    r = N - m;
    sum = 0.0;                  /* R[m] = 0.0 */
    for (n = 0; n < r; ++n) {
      sum += signal[n] * signal[n+m];
    }
    autocorr[m] = sum;
  }

  /* Solve the matrix equation by the Durbin-Levinson method */

  E = autocorr[0];                       /* E=R[0] */

  alpha[1] = autocorr[1]/E;

  for (m = 2; m < P; ++m) {
    E = (1 - alpha[m-1] * alpha[m-1]) * E;

    temp3 = autocorr[m];
    for (n = 1; n < m; ++n) {
      temp3 -= autocorr[m-n] * alpha[n];
    }

    temp3 = temp3 / E;
    for (n = 1; n < m; ++n) {
      temp_vect[n] = alpha[n] - (alpha[m-n] * temp3);
    }

    for (n = 1; n < m; ++n) {
      alpha[n]=temp_vect[n];
    }

    alpha[m] = temp3;
  }

  /* Compute the gain */
  temp_gain = 0.0;
  for (n = 1; n < P; ++n) {
    temp_gain += alpha[n] * autocorr[n];
  }

  gain = autocorr[0]) - temp_gain;

}


