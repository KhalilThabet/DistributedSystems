#include <iostream>
#include <omp.h>
#include <iomanip>
#include <chrono>
using namespace std::chrono;
using namespace std;
int main(){
    int N =25; //25
    long long a = 1;
    auto start = high_resolution_clock::now();

    for (int i=1;i<=N;i++){
        a*=i;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "Time taken to sequential algorithm: "
         << duration.count() << " microseconds" << endl;
    cout<<a<<endl;
    a=1;
    start = high_resolution_clock::now();
    #pragma omp parallel for schedule (guided, 1)
        for(int idx=1;idx<=N;idx++){
            a*=idx;
        }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
 
    cout << "Time taken to parallel algorithm: "
         << duration.count() << " microseconds" << endl;
    cout<<a<<endl;

    return 0;
}
