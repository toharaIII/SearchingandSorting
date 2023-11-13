#ifndef searchingAndSorting_h
#define searchingAndSorting_h
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

void fibonacciIterative(int term);
int fibonacciRecursive(int term);
void binarySearch(int values[], int size, int target);
void exchangeSort(int values[], int size);
void seqSearch(int values[], int size, int target);
void menu(int values[], int num, int size);

void fibonacciIterative(int term){
    if(term<=2) cout<<"fibonacci term "<<term<<" is "<<1<<endl;

    int val=1;
    int pastval=1;
    int temp;
    int cnt=2;

    while(cnt!=term){
        temp=val;
        val+=pastval;
        pastval=temp;
        cnt++;
    }

    cout<<"fibonacci term "<<term<<" is "<<val<<endl;
    cout<<cnt-2<<" addition operators to reach fibonacci term "<<term<<endl;
}

int additioncount=0; //global variable for addition count
int callcount=0; //global variable for recurisve call count

int fibonacciRecursive(int term){
    callcount++;
    if(term<=1) return term;
    else{
        additioncount++;
        return fibonacciRecursive(term-1)+fibonacciRecursive(term-2);
    }
}

void binarySearch(int values[], int size, int target){
    int left=0;
    int right=size;
    int cnt=0;
    bool flag=false;

    while(left<=right){
        int mid=left+(right-left)/2;
        cnt++;

        if(values[mid]==target){
            cout<<"value found at "<<mid<<endl;
            cout<<cnt<<" search iterations required"<<endl;
            flag=true;
            break;
        }
        else if(values[mid]<target){
            left=mid+1;
            cnt++;
        } else{
            right=mid-1;
            cnt++;
        }
    }
    if(!flag) cout<<target<<" could not be found"<<endl;
}

void exchangeSort(int values[], int size){
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(values[j]>values[j+1]){
                int temp=values[j];
                values[j]=values[j+1];
                values[j+1]=temp;
            }
        }
    }
}

void seqSearch(int values[], int size, int target){
    int cnt=0;
    int location=INT_MAX;

    for(int i=0; i<size; i++){
        if(values[i]==target){
            location=i;
            cout<<"found at index "<<i<<endl;
            cout<<cnt<<" search iterations required"<<endl;
            break;
        }
        cnt++;
    }
    if(location==INT_MAX) cout<<target<<" could not be found"<<endl;
}

void menu(int values[], int num, int size){
    int target;
    int term;
    int val;
    static int cnt=0;

    while(num<1 || num>6){
        cout<<"option not available, please enter again"<<endl;
        return;
    }

    if(num==1){
        cout<<"what value would you like to search for?"<<endl;
        cin>>target;
        cout<<"searching..."<<endl;
        seqSearch(values, size, target);
        return;
    }

    if(num==2){
        cout<<"array unsorted:"<<endl;
        for(int j=0; j<size; j++) cout<<values[j]<<endl;
        cout<<"sorting..."<<endl;
        exchangeSort(values, size);
        cout<<"array sorted"<<endl;
        for(int j=0; j<size; j++) cout<<values[j]<<endl;
        return;
    }

    if(num==3){
        cout<<"what value would you like to search for?"<<endl;
        cin>>target;
        cout<<"running exchange sort"<<endl;
        exchangeSort(values, size);
        cout<<"searching..."<<endl;
        binarySearch(values, size, target);
        return;
    }

    if(num==4){
        cout<<"what term do you want to reach in the fibonacci sequence?"<<endl;
        cin>>term;
        additioncount=0;
        callcount=0;
        val=fibonacciRecursive(term);
        cout<<"the value at position "<<term<<" in the fibonacci sequence is: "<<val<<endl;
        cout<<additioncount<<" addition operators to reach fibonacci term "<<term<<endl;
        cout<<callcount<<" recursive calls to reach fibonacci term "<<term<<endl;
        return;
    }

    if(num==5){
        cout<<"what term do you want to reach in the fibonacci sequence?"<<endl;
        cin>>term;
        fibonacciIterative(term);
        return;
    }
}

#endif
