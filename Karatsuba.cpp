#include<bits/stdc++.h>
using namespace std;

int integerSize(int num){
    int c=1;
    while(num>10){
        num = (num - num%10)/10;
        c++;
    }
    return c;
}

int karatsuba(int x,int y){
    if(x<10 || y<10){
        return x*y;
    }
    else{
        int n = integerSize(max(x,y));
        int half = floor(n/2);
        int b = x%int(pow(10,half));
        int a = (x-b)/int(pow(10,half));
        int d = y%int(pow(10,half));
        int c = (y-d)/int(pow(10,half));
        int ac = karatsuba(a,c);
        int bd = karatsuba(b,d);
        int ad_plus_bc = karatsuba(a+b,c+d) - ac - bd;
        return ac*int(pow(10,2*half)) + ad_plus_bc*int(pow(10,half)) + bd;
    }
}

int main(void){
    cout<<karatsuba(11111,-66666);
}
