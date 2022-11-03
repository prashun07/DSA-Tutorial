#include<iostream>
using namespace std;
class complex{
    int real;
    int imag;
    public:
    complex(int r=0,int i=0){
        real=r;
        imag=i;
    }
    complex operator+(complex const &obj){
        complex c;
        c.real=real+obj.real;
        c.imag=imag+obj.imag;
        return c;
    }
    void print(){
        printf("%d+i%d\n",real,imag);
    }
};
int main(){
    // cout<<"hello world"<<endl;
    complex c1(2,3),c2(4,5);
    complex c3=c1+c2;
    c3.print();
    return 0;
    
}