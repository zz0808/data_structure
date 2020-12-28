#include <iostream>
#include <thread>
#include <condition_variable>

std::mutex data_mutex;
std::condition_variable data_var;
bool flag = true;

void print_odd() {
    int i = 1;
    while (i <= 100) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::unique_lock<std::mutex> lck(data_mutex);
        data_var.wait(lck, []{return flag;});
        std::cout << i << std::endl;
        i += 2;
        flag = false;
        data_var.notify_one();
    }
}

void print_even() {
    int i = 2;
    while (i <= 100) {
        std::unique_lock<std::mutex> lck(data_mutex);
        data_var.wait(lck, []{return !flag;});
        std::cout << i << std::endl;
        i += 2;
        flag = true;
        data_var.notify_one();
    }
    
}

int main () {
    
    std::thread t1(print_odd);
    std::thread t2(print_even);
    t1.join();
    t2.join();
    
    return 0;
}
