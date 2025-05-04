#include<iostream>
#include<fstream>

using namespace std;

int main(){
    ifstream file("vehicles.txt");
    if(!file){
        cout<<"File not found"<<endl;
    }
    string line;
    while(getline(file,line)){
        if((!line.empty()) && (!line[0] == '#')){
            cout<<"Line: "<<line<<endl;
        }
    }
    file.close();
}