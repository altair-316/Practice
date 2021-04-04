#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Heap
{

public:
    void maxHeap(int *arr, int n)
    {

        for (int i = n / 2; i > 0; i--)
            maxHeapify(&arr[0], n, i);
    }

    void minHeap(int *arr, int n)
    {
        for (int i = n / 2; i > 0; i--)
            minHeapify(&arr[0], n, i);
    }

    void minHeapify(int *arr,int n,int i){

        int l=2*i, r=2*i+1,index=0,temp=0;

        if(l<=n && arr[l]<arr[i])
            index=l;
        else
            index=i;
        if(r<=n &&arr[r]<arr[index])
            index=r;
        if(index!=i){
            temp=arr[index];
            arr[index]=arr[i];
            arr[i]=temp;
            minHeapify(&arr[0],n,index);
        }


    }

    void maxHeapify(int *arr, int n, int i)
    {

        int left = 2 * i, right = 2 * i + 1, temp = 0,index=0;

        if (left <= n && arr[left] > arr[i])
        {
            index=left;
        }
        else
            index=i;

        if (right <= n && arr[right] > arr[index])
        {
            index=right;
        }
        if(index!=i){
            temp=arr[index];
            arr[index]=arr[i];
            arr[i]=temp;
            maxHeapify(&arr[0],n,index);
        }

    }

    int removeMax(int *arr,int &n){

        int temp=arr[1];
        arr[1]=arr[n];
        --n;
        maxHeapify(arr,n,1);
        return(temp);
    }

    int removeMin(int *arr,int &n){

        int temp=arr[1];
        arr[1]=arr[n];
        --n;
        minHeapify(arr,n,1);
        return(temp);
    }

};

int main()
{

    int A[16] = {0, 12, 54, 66, 78, 2, 5, 98, 33, 64, 83, 22, 1, 7, 102, 55};
    int n = ( sizeof(A) / sizeof(A[0]) )-1;

    cout << "\n"
         << n << "\n";

    for (int i=1;i<=n;i++)
        cout<<i<<"\t";
    cout<<endl;
    for (int i=1;i<=n;i++)
        cout<<A[i]<<"\t";
    cout<<endl<<endl<<endl;

    Heap createHeap;

    //MAX-heap
    createHeap.maxHeap(A, n);
    for (int i=1;i<=n;i++)
        cout << A[i] << "\t";
    cout << endl;

    //remove-MAX
    cout<<"Removed MAX = "<<createHeap.removeMax(A,n)<<endl;
    cout<<"New Heap = \n";
    for (int i=1;i<=n;i++)
        cout << A[i] << "\t";
    cout << endl;

/*
    //MIN-heap
    createHeap.minHeap(A, n);
    for (int i=1;i<=n;i++)
        cout << i << "\t";
    cout << endl;
*/

    return (0);
}