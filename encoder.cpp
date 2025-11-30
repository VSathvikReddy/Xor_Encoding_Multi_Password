#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
#include "helper.h"
#include "debug.h"

void data_read(string &link,vector<int> &roll_numbers,int &key){
    ifstream f("links.txt");
    if (!f.is_open()){
        cerr<<"Error opening the file!";
        return;
    }
    getline(f,link);

    string temp;
    while(f>>temp){
        if(temp=="1"){ 
            cerr<<"Might have already encrypted"<<endl;
            exit(1);
        }
        roll_numbers.push_back(poly_hash(temp));
    }
    key = roll_numbers.back();
    roll_numbers.pop_back();

    f.close();
}

void data_write(string &enc_link,vector<int> &coeffs){
    ofstream f("links.txt");
    f<<enc_link<<endl;
    for(int x:coeffs){
        f<<x<<endl;
    }
}

int main(){
    string link;
    vector<int> hashed_roll_numbers;
    int key;
    data_read(link,hashed_roll_numbers,key);

    vector<int> coeffs = poly_from_roots(hashed_roll_numbers);
    coeffs[coeffs.size()-1] = add(coeffs[coeffs.size()-1],key);

    string enc_link = enc_dec(link,key);
    data_write(enc_link,coeffs);

    return 0;

}