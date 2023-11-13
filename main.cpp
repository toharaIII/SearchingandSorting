#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>
#include "searchingAndSorting.h"
using namespace std;

int main(int argc, const char * argv[]) {
    int num=0;
    int size;

    cout<<"enter the size of the randomized array you would like to generate"<<endl;
    cin>>size;

    int values[size];

    srand(time(nullptr));
    for(int i=0; i<size; i++) values[i]=rand();

    cout<<"What function would you like to run? Enter the corresponding number."<<endl;
    cout<<"1. Sequential search"<<endl;
    cout<<"2. Exchange sort"<<endl;
    cout<<"3. Binary search (exchange sort will run prior to)"<<endl;
    cout<<"4. Fibonacci term recursive"<<endl;
    cout<<"5. Fibonacci term iterative"<<endl;
    cout<<"6. Terminate program"<<endl;
    cin>>num;

    while(num!=6){
        menu(values, num, size);
        cout<<"run another program?"<<endl;
        cin>>num;
    }

    return 0;
}
