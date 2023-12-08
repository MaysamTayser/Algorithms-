#include <iostream>
#include <chrono>
#include <vector>
#include <functional>
using namespace std;
template<typename F, typename T>
double time_exec(F func, T start, T end){
    auto start_time = std::chrono::high_resolution_clock::now();
    for(auto i = start; i != end; ++i) {
        func(*i);
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    return static_cast<double>(duration.count()) / 1'000'000;
}
long long factorial(long long n) {
    if(n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}
int main()
{
      unsigned long long int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    cout  <<factorial(n)<<endl;
     std::vector<int> data = {1, 2, 3, 4, 5};

    auto time_taken = time_exec([](int i) {
        std::cout   << std::endl;
    }, data.begin(), data.end());

    std::cout << "Execution time: " << time_taken << " seconds" << std::endl;
  return 0 ;
}
