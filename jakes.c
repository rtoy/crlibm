/*
 * Jake's model for fading channels. See
 * http://web.mst.edu/~xiaoc/Pub/Zheng_Xiao_TCOM.pdf, section II.B.
 */

#include <stdio.h>

extern double getRealTime();
extern void init_model(int nosc, double doppler);
extern void jakes_model(double *c, double* s, double t, double step, int nsamples, int nosc);


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
