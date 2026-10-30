#include <iostream>
#include <vector>

using namespace std;

int fib(int n){
    if(n <= 1){
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int fibDP(int n, vector<int> &dp){
    if(n <= 1){
        return n;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    return dp[n] = fibDP(n - 1, dp) + fibDP(n - 2, dp);
}

int fibDPTab(int n){
    if(n <= 1){
        return n;
    }
    vector <int> dpTab(n + 1);
    dpTab[0] = 0;
    dpTab[1] = 1;
    
    for(int i = 2; i <= n; i++){
        dpTab[i] = dpTab[i - 1] + dpTab[i - 2];

    }
    return dpTab[n];
}

int main(){
    int n = 6;
    cout<<"n is : "<<n<<endl;
    cout<<endl;

    vector<int> dp(n + 1, -1);

    int fibRec = fib(n);
    cout<<"Fibonacci No. using simple recursion "<<fibRec<<endl;
    cout<<"Time Complexity: O(2^n)"<<endl;
    cout<<"Space Complexity: O(n)"<<endl;
    cout<<endl;

    int fibwithDP = fibDP(n, dp);
    cout<<"Fibonacci No. using DP Memoization "<<fibwithDP<<endl;
    cout<<"Time Complexity using DP Memoization : O(n)"<<endl;
    cout<<"Space Complexity using DP Memoization: O(n)"<<endl;
    cout<<endl;

    int fibTab = fibDPTab(n);
    cout<<"Fibonacci No. with DP Tabulation "<<fibTab<<endl;
    cout<<"Time Complexity with DP Tabuation is O(n)"<<endl;
    cout<<"Space Complexity using DP Tabulation is O(n)"<<endl;
    cout<<endl;

    return 0;
}



/*

                ||||            USING  PYTHON       ||||

def fibonacci_non_recursive(n):
    if n == 0:
        return 0

    a = 0
    b = 1

    for i in range(1, n):
        c = a + b
        a = b
        b = c

    return b


def fibonacci_recursive(n):
    if n <= 1:
        return n

    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2)



n = int(input("Enter the value of n: "))


result1 = fibonacci_non_recursive(n)
print("\nNon-Recursive Method")
print("Fibonacci number:", result1)
print("Time Complexity: O(n)")
print("Space Complexity: O(1)")



result2 = fibonacci_recursive(n)
print("\nRecursive Method")
print("Fibonacci number:", result2)
print("Time Complexity: O(2^n)")
print("Space Complexity: O(n)")




*/