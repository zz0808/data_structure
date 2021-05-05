#include <iostream>
#include <pthread.h>

class Rdlock
{
public:
	Rdlock() {
		pthread_mutex_init(&rlock, nullptr);
		pthread_mutex_init(&wlock, nullptr);
		read_count = 0;
	}

	~Rdlock() { 
	}
	Rdlock(const Rdlock&) = delete;
	Rdlock& operator=(const Rdlock&) = delete;

	void read_lock() {
		pthread_mutex_lock(&rlock);
		if (++read_count == 1) {
			pthread_mutex_lock(&wlock);
		}
		pthread_mutex_unlock(&rlock);
	}

	void read_unlock() {
		pthread_mutex_lock(&rlock);
		if (--read_count == 0) {
			pthread_mutex_unlock(&wlock);
		}
		pthread_mutex_unlock(&rlock);
	}

	void write_lock() {
		pthread_mutex_lock(&wlock);
	}

	void write_unlock() {
		pthread_mutex_unlock(&wlock);
	}

private:
	pthread_mutex_t rlock;
	pthread_mutex_t wlock;	
	int read_count;
};