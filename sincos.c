#if !(defined(USE_CRLIBM) || defined(USE_FDLIBM))
#include <math.h>
#endif

#ifdef USE_CRLIBM
#include "crlibm.h"
#endif

#ifdef USE_FDLIBM
#include "fdlibm.h"
#endif

double test_sin(double x)
{
#if defined(USE_CRLIBM)
    return sin_rn(x);
#elif defined(USE_FDLIBM)
    return sin(x);
#else
    return sin(x);
#endif
}

double test_cos(double x)
{
#if defined(USE_CRLIBM)
    return cos_rn(x);
#elif defined(USE_FDLIBM)
    return cos(x);
#else
    return cos(x);
#endif
}
