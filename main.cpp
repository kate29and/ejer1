#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    int A[91];
    for (int f=0; f<=91; f++){
        A[f]=0;
    }
    int i=0;
    srand(time(NULL));


    while (i<=200){

        int na;
        na=65+rand()%(91-65);
        char a=na;
        i++;
        cout<<a<<',';

        A[na]=A[na]+1;

    }

    cout<<endl;

    for (int k=65; k<=90; k++){

        char a=k;
        cout<<"La letra "<<a<<" : "<<A[k]<<endl;
    }
    return 0;
}
