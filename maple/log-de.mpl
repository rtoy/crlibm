#######################################################################
# To use:
# restart; read "log.mpl";
Digits := 100:

interface(quiet=true):

read "common-procedures.mpl":
read "double-extended.mpl":
mkdir("TEMPLOG"):


ln2h,ln2l := hiloExt(log(2)):

L := 6: # As in Markstein's book

MAXINDEX    := round(2^L * (sqrt(2)-1)):

# The following loop defining wi could be replaced by a search for accurate table.
for i from 0 to MAXINDEX-1 do
    wi[i] := nearest(1 + i*2^(-L)): # double-precision, not extended !
od:
for i from MAXINDEX to 2^L do
    # y has been divided by two
    wi[i] := nearest((1 + i*2^(-L))/2): # double-precision, not extended !
od:



for i from 0 to 2^L do
    (invwih[i], invwil[i]) := hiloExt(1/wi[i]):
    (logwih[i], logwil[i]) := hiloExt(log(wi[i])):
od:

zmax:=2^(-L-1):


PolyDegreeAccurate:=15:

printf("Computing the polynomial for accurate phase (this may take some time...)\n"):
pe:= x  * numapprox[minimax](  log(1+x)/x,  x=-zmax..zmax,  [PolyDegreeAccurate-1,0], 1 ,  'delta_approx'):
log2(delta_approx):
# 123 bits


MaxDegreeDDE:=9:  # 8 gives 120 bits, 9 gives 122

polyAccurate := polyExact2Ext(pe, MaxDegreeDDE):
#delta_approx := numapprox[infnorm](polyAccurate-log(1+x), x=-zmax..zmax):
epsilon_approx := numapprox[infnorm]( 1-polyAccurate/log(1+x), x=-zmax..zmax):
printf("   approximation error for the accurate phase is 2^(%2f)\n", log2(epsilon_approx) ) :


PolyDegreeQuick:=8:

if(1+1=3) then
# Here we tried to use the polynomial from the accurate phase for the
# quick one.  This loses 7 bits of precision compared to a clean minimax, meaning
# one degree more. Better do two polynomials. To investigate some day,
# there must be a polynomial that does both.

#truncated to PolyDegreeQuick and to DE. We use the fact that series(p)=p
polyQuick := convert(series(polyExact2Ext(polyAccurate, 0), x=0, PolyDegreeQuick+1), polynom):
#delta_approx := numapprox[infnorm](polyAccurate-log(1+x), x=-zmax..zmax):
epsilon_approx := numapprox[infnorm]( 1-polyQuick/log(1+x), x=-zmax..zmax):
printf("   approximation error for the quick phase is 2^(%2f)\n", log2(epsilon_approx) ) ;
fi:


polyQuick:= polyExact2Ext(x  * numapprox[minimax](  log(1+x)/x,  x=-zmax..zmax,  [PolyDegreeQuick-1,0], 1 ,  'delta_approx'), 0):
epsilon_approx := numapprox[infnorm]( 1-polyQuick/log(1+x), x=-zmax..zmax):
printf("   approximation error for the quick phase is 2^(%2f)\n", log2(epsilon_approx) ) :











filename:="TEMPLOG/log-de.h":
fd:=fopen(filename, WRITE, TEXT):

fprintf(fd, "\n/*File generated by maple/log-de.mpl*/\n\n"):

  fprintf(fd, "#if defined(CRLIBM_TYPECPU_X86) || defined(CRLIBM_TYPECPU_AMD64)\n\n"):
  fprintf(fd, "  /* Coefficients are read directly from the array thanks to the following macros */ \n"):
  for i from PolyDegreeQuick to 1 by -1 do
    fprintf(fd, "#define c%d  c[%d]\n", i, PolyDegreeQuick-i):
  od:
  for i from PolyDegreeAccurate to 1 by -1 do
    fprintf(fd, "#define c%dh  ch[%d]\n", i, PolyDegreeAccurate-i):
  od:
  for i from MaxDegreeDDE-1 to 1 by -1 do
    fprintf(fd, "#define c%dl  cl[%d]\n", i, MaxDegreeDDE-1-i):
  od:
  fprintf(fd, "#define PREFETCH_POLY_ACCURATE \n"):
  fprintf(fd, "\n#else /* not(defined(CRLIBM_TYPECPU_X86) || defined(CRLIBM_TYPECPU_AMD64)),\n   assuming Itanium, otherwise we shouldn't be there */ \n\n"):
  fprintf(fd, "#define PREFETCH_POLY_QUICK "):
  for i from PolyDegreeQuick to 1 by -1 do
    fprintf(fd, "c%d=c[%d]; ", i, PolyDegreeQuick-i):
  od:
  fprintf(fd, "\n#define PREFETCH_POLY_ACCURATE "):
  for i from PolyDegreeAccurate to 1 by -1 do
    fprintf(fd, "c%dh=ch[%d]; ", i, PolyDegreeAccurate-i):
    if i mod 4 =0 then  fprintf(fd, "\\\n        "): fi:
  od:
  fprintf(fd, "\\\n        "):
  for i from MaxDegreeDDE-1 to 1 by -1 do
    fprintf(fd, "c%dl=cl[%d]; ", i, MaxDegreeDDE-1-i):
  od:

  fprintf(fd, "\n#endif /* defined(CRLIBM_TYPECPU_X86) || defined(CRLIBM_TYPECPU_AMD64) */ \n\n"):


  # Various constants
  fprintf(fd, "#define L        %d\n", L):
  fprintf(fd, "#define MAXINDEX %d\n", MAXINDEX):
  fprintf(fd, "static const long double ln2h  = %1.50eL ;\n", ln2h):
  fprintf(fd, "static const long double ln2l  = %1.50eL ;\n", ln2l):
  fprintf(fd, "static const long double two64 = %1.50eL ;\n", evalf(2^64)):


  # The polynomials
  #  polynomial for quick phase
   fprintf(fd, "static const long double c[%d] =  {\n",PolyDegreeQuick):
   for i from PolyDegreeQuick to 1 by -1 do
     fprintf(fd, "   /* c%d  = */ %1.50eL, \n", i, coeff(polyQuick,x,i)):
   od:
  fprintf(fd, "}; \n \n"):

  #  polynomial for accurate phase
  fprintf(fd, "static const long double ch[%d] =  {\n",PolyDegreeAccurate):
   for i from PolyDegreeAccurate to 1 by -1 do
     (ch, cl) := hiloExt(coeff(polyAccurate,x,i)):
     fprintf(fd, "   /* ch%d  = */ %1.50eL, \n", i, ch):
   od:
  fprintf(fd, "}; \n \n"):

  fprintf(fd, "static const long double cl[%d] =  {\n", MaxDegreeDDE):
  for i from MaxDegreeDDE-1 to 1 by -1 do
     (ch, cl) := hiloExt(coeff(polyAccurate,x,i)):
     fprintf(fd, "   /* cl%d  = */ %1.50eL, \n", i, cl):
   od:
  fprintf(fd, "}; \n \n"):



  # The tables

  fprintf(fd, "typedef struct tablestruct_tag {double wi; long double invwih; long double logwih; long double invwil; long double logwil; } tablestruct ;  \n"):
  fprintf(fd, "static const tablestruct argredtable[%d] = {\n", 2^L+1):
  for i from 0 to 2^L do
      fprintf(fd, "  { %1.40e, /* wi[%d] */ \n", wi[i], i):
      fprintf(fd, "    %1.50eL, /* invwih[%d] */ \n", invwih[i], i):
      fprintf(fd, "    %1.50eL, /* logwih[%d] */ \n", logwih[i], i):
      fprintf(fd, "    %1.50eL, /* invwil[%d] */ \n", invwil[i], i):
      fprintf(fd, "    %1.50eL, /* logwil[%d] */ \n", logwil[i], i):
      fprintf(fd, "  } \n"):
      if(i<2^L) then  fprintf(fd, ", \n"): fi
  od:
fprintf(fd, "}; \n \n"):


fclose(fd):




