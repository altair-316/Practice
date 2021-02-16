#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

int main(){

    int A[10]={0,1,2,3,4,5,6,7,8,9};
    int *p=A;

    for(int  i=0;i<10;i++)
        cout<<p[i];



    return(0);
}