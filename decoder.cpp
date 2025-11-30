#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
#include "helper.h"

void data_read(string &s, vector<int> &coeffs){
    ifstream f("links.txt");
    if (!f.is_open()){
        cerr<<"Error opening the file!";
        return;
    }
    getline(f,s);

    string temp;
    while(f>>temp){
        coeffs.push_back(stoi(temp));
    }
    f.close();
}

int main(){
    string enc_link;
    vector<int> coeffs;
    try{
        data_read(enc_link,coeffs);

        cout<<"Enter Roll number:";
        string key;cin>>key;

        int key_num = poly_hash(key);
        int final_key = eval_poly(coeffs,key_num);
        //cout<<final_key<<endl;

        string link = enc_dec(enc_link,final_key);
        if(link.substr(0,21)!="https://chat.whatsapp"){
            cout<<"There's still a bug mate"<<endl;
        }else{
            cout<<link<<endl;
        }
    }
    catch(const exception &e){
        cerr<<"Error sir: "<<e.what()<<endl;
    }

    return 0;
}