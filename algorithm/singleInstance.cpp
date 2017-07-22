class Singleton {
private:
	Singleton(){} // 构造函数声明为私有的，保证只能创建一个实例
	Singleton(const Singleton &); //显示声明拷贝构造函数为私有的，保证不能复制，不用实现
	Singleton &operator= (const Singleton &);
public:
	static Singleton &getInstance()  //静态成员函数，没有对象的时候可以通过类名调用，独立于对象
	{
		static Singleton singleton;  //静态局部变量，程序结束的时候会析构所有的静态变量
		return singleton;
	}
};


若考虑线程安全：
class Lock
{
private:
CCriticalSection m_cs;
public:
Lock(CCriticalSection cs): m_cs(cs)
{
m_cs.Lock();
}
~Lock(){
{
m_cs.~Lock();
}
};
class Singleton
{
private:
Singleton() {}
Singleton(const Singleton &);
Singleton &operator=(const Singleton &);
public:
static Singleton * instance; // 不太明白为什么是public，private不知是否可以
static Singleton* getInstance();
static CCriticalSection cs;
}
Singleton* Singleton::instance = 0;
Singleton* Singleton::getInstance()
{
if(instance == NULL) {
Lock lock(cs);
if(instance == NULL) {  //常常有面试官说这里性能会不好
instance = new Singleton(); // 但是这个实现里没有delete，也会造成内存泄露啊？？
}
}
return instance;
}
