#include<iostream>

using namespace std;

void inputArray(int **matrix1,int n,int **matrix2,int m){
    cout<<"Input matrix 1"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
                cout<<"matrix1["<<i+1<<"]["<<j+1<<"]:";
                cin>>matrix1[i][j];
        }
    }
    cout<<"Input matrix 2"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
                cout<<"matrix 2["<<i+1<<"]["<<j+1<<"]:";
                cin>>matrix2[i][j];
        }
    }
}
void displayArray(int **matrix,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void add(int **matrix1,int **matrix2,int n,int m){
    cout<<"Addition of two matrices"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix1[i][j]+matrix2[i][j]<<" ";
        }
        cout<<endl;
    }
}

void subtract(int **matrix1,int **matrix2,int n,int m){
    cout<<"Subtraction of two matrices"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix1[i][j]-matrix2[i][j]<<" ";
        }
        cout<<endl;
    }
}
void deallocate(int **arr,int n){
    for(int i=0;i<n;i++){
        delete[] arr[i];
    }
    delete[] arr;
}


int main(){
    int rows,col;
    cout<<"Enter number of rows"<<endl;
    cin>>rows;
    cout<<"Enter number of column"<<endl;
    cin>>col;
    int **matrix1=new int*[rows];
    int **matrix2=new int*[rows];
    for(int i=0;i<rows;i++){
        matrix1[i]=new int[col];
        matrix2[i]=new int[col];
    }
    inputArray(arr1,rows,arr2,col);
    cout<<"matrix 1"<<endl;
    displayArray(arr1,rows,col);
    cout<<"matrix 2"<<endl;
    displayArray(arr2,rows,col);
    addition(arr1,arr2,rows,col);
    subtraction(arr1,arr2,rows,col);
    deallocate(arr1,rows);
    deallocate(arr2,rows);
}