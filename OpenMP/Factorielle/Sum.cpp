#include <iostream>
#include <omp.h>
#include <iomanip>
#include <chrono>
using namespace std::chrono;
using namespace std;
int main(){
    int N =10000000; //25
    for (int k=0;k<10;k++){
    long long a = 0;
    auto start = high_resolution_clock::now();

    for (int i=1;i<=N;i++){
        a+=i;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "|"
         << duration.count() << " us ";
    // cout<<a<<endl;
    a=0;
    start = high_resolution_clock::now();
    #pragma omp parallel for reduction(+:a)
        for(int idx=1;idx<=N;idx++){
            a+=idx;
        }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "|"
         << duration.count() << " us|" << endl;}
    // cout<<a<<endl;
    return 0;
}
