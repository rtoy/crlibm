#include <stdlib.h>
#if !(defined(USE_CRLIBM) || defined(USE_FDLIBM))
#include <math.h>
#endif

#ifdef USE_CRLIBM
#include "crlibm.h"
#define sin(x) sin_rn(x)
#define cos(x) cos_rn(x)
#endif

#ifdef USE_FDLIBM
#include "fdlibm.h"
#endif

#ifndef M_SQRT2
#define	M_SQRT2 (1.4142135623730951e0)
#define	M_PI	(3.141592653589793e0)
extern double sqrt(double);
#endif

/* Number of oscillators */
double *cos_beta;
double *sin_beta;
double *freq;

void
init_model(int nosc, double doppler_freq)
{
    int k;
    int N = 4 * nosc + 2;

    cos_beta = malloc((nosc + 1) * sizeof(*cos_beta));
    sin_beta = malloc((nosc + 1) * sizeof(*sin_beta));
    freq = malloc((nosc + 1) * sizeof(*freq));

    cos_beta[0] = M_SQRT2 * cos(M_PI / 4);
    sin_beta[0] = M_SQRT2 * sin(M_PI / 4);
    freq[0] = 2 * M_PI * doppler_freq;
    
    for (k = 1; k <= nosc; ++k) {
        double beta = M_PI * k / nosc;
        
        cos_beta[k] = 2 * cos(beta);
        sin_beta[k] = 2 * sin(beta);
        freq[k] = 2 * M_PI * doppler_freq * cos(2 * M_PI * k / N);
    }

#if 0
    for (k = 0; k <= nosc; ++k) {
        printf("%4d: %g\t%g\t%g\n", k, cos_beta[k], sin_beta[k], freq[k]);
    }
#endif
}

void
jakes_model(double *c, double* s, double t, double tstep, int nsamples, int nosc)
{
    int k;
    double N = 4 * nosc + 2;

    for (k = 0; k < nsamples; ++k) {
        int n;
        double sum_c = 0;
        double sum_s = 0;

        for (n = 0; n <= nosc; ++n) {
            double ct = cos(freq[n] * t);
        
            sum_c += cos_beta[n] * ct;
            sum_s += sin_beta[n] * ct;
        }
        c[k] = 2 / sqrt(N) * sum_c;
        s[k] = 2 / sqrt(N) * sum_s;

        t += tstep;
    }
}

