#include <iostream>
using namespace std;

class Singleton {
public:
    static Singleton& get_instance() {
        static Singleton instance;
        cout << "get instance" << endl;
        return instance;
    }
    Singleton(const Singleton& )=delete;
    Singleton& operator=(const Singleton& )=delete;
    
private:
    Singleton() {
        
    }
    ~Singleton() {
        
    }
};


int main() {
    
    Singleton& s = Singleton::get_instance();
    
    return 0;
}
