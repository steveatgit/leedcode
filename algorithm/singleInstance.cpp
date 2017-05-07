class Singleton {
private:
	Singleton(){}
	Singleton(const Singleton &);
	Singleton &operator= (const Singleton &);
public:
	static Singleton &getInstance()
	{
		static Singleton singleton;
		return singleton;
	}
};
