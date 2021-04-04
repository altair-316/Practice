#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;


void passByRef(int &x){
    --x;
}

int main(){

    int A[10]={0,1,2,3,4,5,6,7,8,9};
    int test=5;
    int *p=A;

    passByRef(test);

    cout<<test<<endl;

    for(int  i=0;i<10;i++)
        cout<<p[i];



    return(0);
}