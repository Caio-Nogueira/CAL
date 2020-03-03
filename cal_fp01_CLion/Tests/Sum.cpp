/*
 * Sum.cpp
 */

#include "Sum.h"
#include <chrono>
using namespace std;

int findIndex(vector <int> vect, int element){
    for (size_t i = 0; i < vect.size(); i++){
        if (vect.at(i) == element) return i;
    }
    return -1;
}


string calcSum(int* sequence, int size)
{
    string result = "";
     int sums[size];
    for (int m = 1; m <= size; m++){
        int min = INT_MAX, min_index ;
        for (int idx = 0; idx <= size-m; idx++){
            if (m == 1){
                sums[idx] = sequence[idx];
            }
            else{
                sums[idx] += sequence[idx+m-1];
            }
            if (sums[idx] < min) {
                min_index = idx;
                min = sums[idx];
            }
        }
        result += (to_string(sums[min_index]) + "," + to_string(min_index) + ";");
    }
    return result;

}
