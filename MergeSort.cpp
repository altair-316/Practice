#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;


class MergeSort{

public:
    void divide(int *A, int start,int stop){

        if(start >= stop)
            return;

        int mid = start + (stop-start)/2;

        divide(A,start,mid);
        divide(A,mid+1,stop);
        merge(A,start,stop,mid); 

    }

    void merge(int *A,int start,int stop,int mid){

        int i = start, j = mid+1, k = 0, temp[stop-start+1];

        while( i <= mid && j <= stop){

            if( A[i] <= A[j] ){
                temp[k] = A[i];
                ++i;
            }
            else{
                temp[k] = A[j];
                ++j;
            }
            ++k;
            
        }

        while(i<=mid){
            temp[k] = A[i];
            ++i;
            ++k;
        }
        while(j<=stop){
            temp[k] = A[j];
            ++j;
            ++k;
        }

        i=0;
        for(k=start;k<=stop;k++,i++)
            A[k]=temp[i];


    }


};


int main(){

    int n = 10;
    //cout << "Array Size";
    //cin >> n;

    int array[10]={2,4,62,8,0,11,3,45,76,9};

    //for(int i=0;i<n;i++)
    //    cin >> array[i];

    MergeSort inArray;

    inArray.divide(array,0,n-1);

    for(auto i:array)
        cout<<i<<" ";
    cout<<endl;


    return(0);
}