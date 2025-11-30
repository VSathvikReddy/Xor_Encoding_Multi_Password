#ifndef _HELPER_H_
#define _HELPER_H_

int char_value(char ch);
int poly_hash(const string &s, int p = 37);

int eval_poly(vector<int> &coeffs,int value);
vector<int> poly_from_roots(const vector<int>& roots);


string enc_dec(string &s,int key);

#endif