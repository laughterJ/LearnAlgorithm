#include<iostream>
#include<vector>
using namespace std;

//迭代实现Fibonacci数列
void Fibonacci(int n){
    vector<int> fib;
    fib.push_back(1);
    cout<<fib[0]<<" ";
    fib.push_back(1);
    cout<<fib[1]<<" ";
    for(int i=2;i<n;i++){
        fib.push_back(fib[i-2]+fib[i-1]);
        cout<<fib[i]<<" ";
    }
    cout<<endl;
}

//递归实现Fibonacci数列
int Fib(int n){
    if(n==0||n==1)
        return 1;
    else
        return Fib(n-1)+Fib(n-2);
}

//递归求阶乘
int Factorial(int n){
    if(n==1)
        return 1;
    else
        return n*Factorial(n-1);
}

//递归实现反向输出字符串
void PrintStr(){
    char c;
    cin>>c;
    if(c!='#'){
        PrintStr();
        cout<<c;
    }
}

int main()
{
    int n = 20;
    Fibonacci(n);
    for(int i=0;i<n;i++)
        cout<<Fib(i)<<" ";
    cout<<endl;
    cout<<Factorial(5)<<endl;
    PrintStr();

    getchar();
    getchar();
    return 0;
}