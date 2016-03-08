#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <thread>
#include <random>
#include <future>
using namespace std;

void cal(int T, std::promise<int> & p) {
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0,1.0);
    int ok = 0;
    for(int i = 0; i < T; i++) {
        double x = distribution(generator);
        double y = distribution(generator);
        if(x*x + y*y <= 1) ok++;
    }
    p.set_value(ok);
}
int Cal(int T) {
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    int ok = 0;
    for(int i = 0; i < T; i++) {
        double x = distribution(generator);
        double y = distribution(generator);
        if(x*x + y*y <= 1) ok++;
    }
    return ok;
}
const int CPU_NUMBER = 4;
int main() {
    std::thread* th[CPU_NUMBER];
    const int T = 1e8;
    auto start_ = std::chrono::system_clock::now();
    std::promise<int> ans[CPU_NUMBER];
    for(int i = 0; i < CPU_NUMBER; i++) {
        th[i] = new std::thread(cal, T / CPU_NUMBER, ref(ans[i])); 
    }
    int totolOK = 0;
    for(int i = 0; i < CPU_NUMBER; i++) {
       auto f = ans[i].get_future(); 
       th[i]->join();
       totolOK += f.get();
    }
    cout << (1.0 * totolOK / T) * 4 << endl;
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end-start_;
    std::cout << "multi thread cost : " << diff.count() << " s\n";

    start_ = std::chrono::system_clock::now();
    cout << (1.0 * Cal(T) / T) * 4 << endl; 
    end = std::chrono::system_clock::now();
    diff = end-start_;
    std::cout << "single thread cost : " << diff.count() << " s\n";

}
