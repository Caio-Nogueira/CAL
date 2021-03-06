/*
 * Change.cpp
 */

#include "Change.h"
using namespace std;


vector <int> minCoins(int i, int k, int *coinValues){
    vector <int> result;
    for (int x = i-1; x >= 0; x--){
        int num = k/coinValues[x];
        for (int j = 0; j < num; j++) result.push_back(coinValues[x]);
        k %= coinValues[x];
    }
    return result;
}

string calcChange(int m, int numCoins, int *coinValues)
{
    string result = "";
    vector<int> min = minCoins(numCoins, m, coinValues);
    for (int i = 1; i <= numCoins; i++){
        if (minCoins(i,m,coinValues).size() < min.size() && accumulate(min.begin(), min.end(),0) == m) min = minCoins(i,m,coinValues);
    }
    if (accumulate(min.begin(), min.end(),0) != m) result = "-";
    for (int x: min){
        result += (to_string(x) + ";");
    }
    return result;
}


