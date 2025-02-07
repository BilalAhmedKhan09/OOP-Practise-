#include<iostream>

using namespace std;

int main(){
    int size;
    cout<<"Enter the size of Array:";
    cin>>size;
    int *array = new int[size];
    for(int i=0;i<n;i++){
        cout<<"Array["<<i+1<<"]:";
        cin>> array[i];
    }
    cout<<endl;
    cout<<"Array:";
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    delete[] array;
}