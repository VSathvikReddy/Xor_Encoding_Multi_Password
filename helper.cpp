#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
#include "debug.h"

int char_value(char ch){
    if(ch>='A'&&ch<='Z'){
        return ch -'A'+1;
    }
    if(ch>='a'&&ch<='z')
        return ch-'a'+1;
    else if(ch>='0'&&ch<='9')
        return ch-'0'+27;
    else
        throw invalid_argument(
        std::string("Unsupported character: '") + ch + "'"
    );
}
int poly_hash(const string &s, int p = 37) {
    int h = 0, power = 1;
    for (char ch:s) {
        int val=char_value(ch);
        h=add(h,mul(val,power));
        power=mul(power,p);
    }
    return h;
}

int eval_poly(vector<int> &coeffs,int value){
    int out=0;
    for(auto it=coeffs.begin();it!=coeffs.end();it++) {
        out=add(mul(out,value),*it);
    }
    return out;
}
vector<int> poly_from_roots(const vector<int>& roots) {
    vector<int> coeffs = {1};

    for(int r:roots){
        vector<int> new_coeffs(coeffs.size()+1,0);

        for(int i=0;i<coeffs.size();i++) {
            new_coeffs[i]=sub(new_coeffs[i],mul(coeffs[i],r));
            new_coeffs[i+1] =add(new_coeffs[i+1],coeffs[i]);
        }coeffs=move(new_coeffs);
    }
    reverse(coeffs.begin(),coeffs.end());
    return coeffs;
}


string enc_dec(string &s,int key){
    string out;
    int n = s.size();
    for(int i=0;i<n;i++){
        int mask = (key>>((i*8)%31))&0xFF;
        out+= static_cast<char>((unsigned char)s[i]^mask);
    }
    return out;
}