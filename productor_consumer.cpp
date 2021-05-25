#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>

using namespace std;

int main() {
    
    queue<int> q;
    mutex m;
    condition_variable cond;

    bool notified = false;
    bool done     = false;

    thread productor([&]() {
        for (int i = 0; i < 10; i++) {
            this_thread::sleep_for(chrono::seconds(1));
            unique_lock<mutex> lock(m);
            cout << "producting... " << i << endl;
            q.push(i);
            notified = true;
            cond.notify_one();
        }
        done = true;
        cond.notify_one();
    });

    thread consumer([&]() {
        while (!done) {
            unique_lock<mutex> lock(m);
            while (!notified) {
                cond.wait(lock);
            }
            while (!q.empty()) {
                cout << "consuming... " << q.front() << endl;
                q.pop();
            }
            notified = false;
        }
    });

    consumer.join();
        productor.join();

    return 0;
}
