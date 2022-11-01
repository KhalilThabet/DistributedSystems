#include <iostream>
#include <omp.h>
#include <iomanip>
#include <chrono>
#include <stdlib.h>
using namespace std::chrono;
using namespace std;
void init_table(int* table,int length,bool random){
    for (int i=0;i<length;i++){
        if (random){
            table[i]=10000;//rand()%100 +1;
        }
        else {
            table[i]=0;
        }
        
    }
}
void sum(int x,int* A,int* B,int* C){
    for (int i=0;i<x;i++){
        C[i]=A[i]+B[i];
    }
   
}
void diff(int x,int* A,int* B,int* C){
    for (int i=0;i<x;i++){
        C[i]= A[i] - B[i];
    }
}
void mult(int x,int * A,int* B,int * C){
    for (int i=0;i<x;i++){
        C[i]= A[i] * B[i];
    }
}
int main(){
    srand (time(NULL));
    int N = 5;

    int A[N];
    int B[N];
    int C[N];
    int D[N];

    init_table(A,N,true);
    init_table(B,N,true);
    init_table(C,N,false);
    init_table(D,N,false);
    //CASE 1
        // for (int i=0;i<N;i++){

        // }
    // CASE 2
    auto start = high_resolution_clock::now();
    #pragma omp parallel for
        for (int i=0;i<N;i++){
            C[i]=A[i]+B[i];
            D[i]=A[i]-B[i];
        }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<duration.count() << "  us\n";
    //CASE 3
    start = high_resolution_clock::now();
    for (int i=0;i<N;i++){
        
        #pragma omp parallel sections
        {
            #pragma omp section
                sum(N,A,B,C);
            #pragma omp section
                diff(N,A,B,D);
        }
        
        
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout <<duration.count() << "  us\n";
    for (int i=0;i<N;i++){
        cout<<C[i]<<" ";
    }
    cout<<endl;
    for (int i=0;i<N;i++){
        cout<<D[i]<<" ";
    }

    
    return 0;
}
