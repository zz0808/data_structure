#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex data_mutex;
std::condition_variable data_var;
bool flag = true;
void print_a() {
    
    while (1) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::unique_lock<std::mutex> lck(data_mutex);
        data_var.wait(lck, []{return flag;});
        printf("A");
        flag = false;
        data_var.notify_one();
    }
}

void print_b() {
    
    while (1) {
        std::unique_lock<std::mutex> lck(data_mutex);
        data_var.wait(lck, []{return !flag;});
        printf("B");
        flag = true;
        data_var.notify_one();
    }
}

int main() {
    
    std::thread t1(print_a);
    std::thread t2(print_b);
    
    t1.join();
    t2.join();
    
    return 0;
}
