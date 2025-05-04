#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

int main(){
    ifstream file("vehicles.txt");
    if(!file){
        cout<<"File not found"<<endl;
    }
    string line;
    while(getline(file,line)){
        if((!line.empty()) && (!line[0] == '#')){
            stringstream ss(line);
            string type, id, name, year;
            getline(ss,type,',');
            getline(ss,id,',');
            getline(ss,name,',');
            getline(ss,year,',');
            cout<< "Type: " << type <<endl;
            cout<< "ID: " << id <<endl;
            cout<< "Name: " << name <<endl;
            cout<< "Year: " << year <<endl;
        }
    }
}