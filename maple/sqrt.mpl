#######################################################################
# This file is part of the crlibm library, and is distributed under
# the  LGPL.
# To use:
# restart; read "sqrt.mpl";
Digits := 120:

interface(quiet=true):

read "common-procedures.mpl":
read "triple-double.mpl":
mkdir("TEMPSQRT"):

polyDegree := 4:

ERecSqrtmMin := 0.707:
ERecSqrtmMax := 1.4143:

xErrMin := evalf((1/(ERecSqrtmMax^2))):
xErrMax := evalf((1/(ERecSqrtmMin^2))):

printf("Using a %d degree polynomial for computing the iteration seed\n",polyDegree);

polyExact := numapprox[minimax](1/sqrt(x),x=1/2..2,[polyDegree,0],1,'err'):
poly := poly_exact(polyExact):
eps := numapprox[infnorm]((poly*sqrt(x))-1,x=xErrMin..xErrMax):

printf("Relative approximation error eps = 2^(%f)\n",log[2](abs(eps))):

printf("Writing tables...\n");

filename:="TEMPSQRT/sqrt.h":
fd:=fopen(filename, WRITE, TEXT):

fprintf(fd, "\n/* File generated by maple/sqrt.mpl */\n"):

for i from 0 to polyDegree do
	fprintf(fd, "\#define SQRTPOLYC%d %1.50e\n",i,coeff(poly,x,i)):
od:
fprintf(fd, "\#define TWO52 %1.50e\n",evalf(2^(52))):


fclose(fd):

filename:="TEMPSQRT/sqrt.sed":
fd:=fopen(filename, WRITE, TEXT):

fprintf(fd, "s/_epsilonApprox/%1.50e/g\n",eps):
fprintf(fd, "s/_ERecSqrtmMin/%1.50e/g\n",ERecSqrtmMin):
fprintf(fd, "s/_ERecSqrtmMax/%1.50e/g\n",ERecSqrtmMax):


for i from 0 to polyDegree do
   fprintf(fd, "s/_SQRTPOLYC%d/%1.50e/g\n",i,coeff(poly,x,i)):
od:

fclose(fd):

printf("... done\n");