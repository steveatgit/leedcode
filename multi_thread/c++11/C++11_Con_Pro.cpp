#include <iostream>
#include<queue>
#include<mutex>
#include<condition_variable>
#include<thread>
using namespace std;

mutex mtx;
condition_variable produce, consume

queue<int> q;
int max_size = 20;

void consumer()
{
while(true) {
this_thread::sleep_for(chrono::milliseconds(1000));
unique_lock<mutex> lck(mtx);
consume.wait(lck, []{return q.size() != 0;});
cout<<"consumer "<<this_thread::get_id()<<": ";
q.pop();
cout<<q.size()<<endl;
produce.notify_all();
}
}
void producer(int id)
{
while(true) {
this_thread::sleep_for(chrono::milliseconds(900));
unique_lock<mutex> lck(mtx);
produce.wait(lck, []{return q.size() != max_size;});
cout<<"-> producer "<<this_thread::get_id()<<": ";
q.push(id);
cout<<q.size()<<endl;
consume.notify_all();
}
}
int main()
{
thread consumers[2], producers[2];
for(int i=0;i<2;i++) {
consumers[i] = thread(consumer);
producers[i] = thread(producer, i+1);
}
for(int i=0;i<2;i++) {
producers[i].join();
consumer[i].join();
}
return 0;
}
