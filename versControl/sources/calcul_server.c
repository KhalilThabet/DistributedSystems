/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calcul.h"
long convert(long n) {
  long bin = 0;
  long rem, i = 1;

  while (n!=0) {
    rem = n % 2;
    n /= 2;
    bin += rem * i;
    i *= 10;
  }

  return bin;
}
void *
calnull_1_svc(void *argp, struct svc_req *rqstp)
{
	static char * result;

	/*
	 * insert server code here
	 */

	return (void *) &result;
}

long *
puiss_1_svc(Param *argp, struct svc_req *rqstp)
{
	static long  result;

	long i; /* Variable used in loop counter */
    long number = 1;

    for (i = 0; i < argp->b; ++i)
        number *= argp->a;
	result=number;
	printf("(Server Side)  V1: Calculating Power of %ld\n",argp->a);
	return &result;
}

long *
dec2bin_1_svc(long *argp, struct svc_req *rqstp)
{
	static long  result;

	result=convert(*argp);
	printf("(Server Side)  V1: Conversion of %ld to %ld\n",*argp,result);

	return &result;
}

long *
puiss_2_svc(Param *argp, struct svc_req *rqstp)
{
	static long*  result;
	result=puiss_1_svc(argp,rqstp);
	printf("(Server Side)  V2: Power %ld to %ld\n",argp->a,argp->b);

	return result;
}

long *
dec2bin_2_svc(long *argp, struct svc_req *rqstp)
{
	static long * result;

	result=dec2bin_1_svc(argp,rqstp);
	printf("(Server Side)  V2: Converting %ld to binary %ld\n",*argp,*result);

	return result;
}

char *
dec2hex_2_svc(long *argp, struct svc_req *rqstp)
{
	static char*  result;

	sprintf(result, "%p", argp);
	printf("(Server Side)  V2: Converting %ld to Hexadecimal",*argp);

	return result;
}
