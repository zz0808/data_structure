#include <iostream>
#include <thread>

// 1. 对一个锁重复加锁
std::mutex m;
void a2();
void a1() {
    m.lock();
    a2();
    m.unlock();
}

void a2() {
    m.lock();
    m.unlock();

}

// 2. 两个数 m1, m2, 线程1持有m1，尝试对m2加锁，线程2持有m2，尝试对m1加锁
std::mutex m1, m2;
void a1() {
    m1.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    m2.lock();
    m1.unlock();
    m2.unlock();
}

void a2() {
    m2.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    m1.lock();
    m1.unlock();
    m2.unlock();
}
int main() {
    
    std::thread t1(a1);
    std::thread t2(a2);
    t1.join();
    t2.join();
    std::cout << "ok" << std::endl;
    return 0;
}
