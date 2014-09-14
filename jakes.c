/*
 * Jake's model for fading channels. See
 * http://web.mst.edu/~xiaoc/Pub/Zheng_Xiao_TCOM.pdf, section II.B.
 */

#include <stdio.h>
#include <stdlib.h>
#if !(defined(USE_CRLIBM) || defined(USE_FDLIBM))
#include <math.h>
#endif

extern double getRealTime();

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

double
print_elapsed_time(double end_time, double start_time)
{
    double elapsed = end_time - start_time;

    printf("End time     = %15g sec\n", end_time);
    printf("Start time   = %15g sec\n", start_time);
    printf("Elapsed time = %15g sec\n", elapsed);

    return elapsed;
}

int
main()
{
    int k;
    int nosc = 20;
    double doppler = 100.0;

    double *c;
    double *s;

    double burst_length = 577e-6;
    double bits_per_burst = 156.25;
    double samples_per_bit = 8;
    
    /*
     * Time step here is appropriate for a GSM burst. A GSM burst is
     * 156.25 bits long and each burst lasts 577 us. We take 8 samples
     * per bit.
     */
    double tstep = burst_length / bits_per_burst / samples_per_bit;

    /*
     * How many bursts we want to simulate
     */
    int nbursts = 1000;

    int nsamples = nbursts * bits_per_burst * samples_per_bit;

    double start_time;
    double end_time;

    /*
     * Jake's model with 20 oscillators and a Doppler frequency of 100
     * Hz. That's a fast-moving car.
     */
    init_model(nosc, doppler);

    c = malloc(nsamples * sizeof(*c));
    s = malloc(nsamples * sizeof(*s));

    start_time = getRealTime();
    jakes_model(c, s, 0.0, tstep, nsamples, nosc);
    end_time = getRealTime();

    {
	double elapsed = print_elapsed_time(end_time, start_time);
	long trig_calls = nsamples * (nosc + 1);
	printf("%ld trig calls; %g us/call\n", trig_calls, (elapsed / trig_calls) * 1e6);
    }
   
#ifdef DEBUG
    for (k = 0; k < 100; ++k) {
        printf("%4d: %g\t%g\n", k, c[k], s[k]);
    }
#endif

    return 0;
}
