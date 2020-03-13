/*
 * Partioning.cpp
 */

#include "Partitioning.h"


int s_recursive(int n,int k)
{
    if (k == 1 || k == n) return 1;
   return s_recursive(n-1,k-1) + k*s_recursive(n-1, k);
}

int s_dynamic(int n,int k)
{
	//return 1;
	int result = 2;
	/*for (unsigned i = 2; i < n; i++){
	    result += ;
	}*/
	return -1;

}


int b_recursive(int n)
{
    int result = 0;
    for (int i = 1; i <= n; i++){
        result += s_recursive(n, i);
    }
    return result;
}

int b_dynamic(int n)
{
    return 0;
}
