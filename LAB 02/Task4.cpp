#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cout<<"Enter the number of string you want to input:"<<endl;
    cin>>n;
    string *str = new string[n];
    for(int i=0;i<n;i++){
        cout<<"Enter string "<<i+1<<":";
        cin>>str[i];
    }
    cout<<"Unsorted string"<<endl;
    display(str,n);
    sort(str,str+n);
    cout<<"Sorted string"<<endl;
    for(int i=0;i<n;i++){
        cout<<str[i]<<endl;
    }
    delete[] str;
}
