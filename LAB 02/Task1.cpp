#include<iostream>

using namespace std;

struct Book{
    string title;
    string author;
    int year;
};

void SearchByYear(Book *library, int size){
    int year;
    cout<<"Enter the publishing year"<<endl;
    cin>>year;
    for(int i=0;i<size;i++){
        if(year < library[i].year){
            cout<<library[i].title<<endl;
            cout<<library[i].author<<endl;
            cout<<library[i].year<<endl;
        }
    }
}

int main(){
    int size;
    cout<<"Please enter the number of Books"<<endl;
    cin>>size;
    Book *library = new Book[size];
    for(int i=0;i<size;i++){
        cout<<"Enter the title of Book "<<i+1<<endl;
        cin>>library[i].title;
        cout<<"Enter name of the author"<<endl;
        cin>>library[i].author;
        cout<<"Enter the year of publishing"<<endl;
        cin>>library[i].year; 
    }
    SearchByYear(library,size);
    delete[] library;
}