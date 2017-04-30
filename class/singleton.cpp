#include <iostream>

class Singleton{
	static Singleton s;
	int i;
	Singleton(int x): i(x) {};
	Singleton(const Singleton &s);
	Singleton &operator=(Singleton &);
public:
	static Singleton &instance() {
		return s;
	}
	int getValue() {
		return i;
	}
	void setValue(int x) {
		i = x;
	}
};
Singleton Singleton::s(44);

int main()
{
	Singleton &s = Singleton::instance();
	std::cout<<s.getValue()<<std::endl;
	Singleton &s1 = Singleton::instance();
	s1.setValue(21);
	std::cout<<s.getValue()<<std::endl;
}
