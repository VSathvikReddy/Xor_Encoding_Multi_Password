#define MOD 1000000007

long long mul(long long a,long long b){
    long long product = a*b;
    return ((a%MOD)*(b%MOD))%MOD;
}

long long add(int a, int b){
    return (a%MOD+b%MOD)%MOD;
}

int sub(int a, int b) {
    return (a%MOD-b%MOD+MOD)%MOD;
}