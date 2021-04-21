class Singleton {

	static Singleton& get_instance() {
		static Singleton instance;
		return instance;
	}

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

private:
	Singleton() {
	}
	~Singleton() {
	}
}

int main() {
	Singleton& s = Singleton::get_instance();
}