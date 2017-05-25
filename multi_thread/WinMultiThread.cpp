http://www.cnblogs.com/codingmengmeng/p/5913068.html

#include<iostream>
#include<windows.h>
using namespace std;

HANDLE mutex = NULL;
DWORD WINAPI consumer(LPVOID lparam)
{
   for(int i=0;i<5;i++) {
      WaitForSingleObject(mutex, INFINITE);
      cout<<"consumer:"<<i<<endl;
      Sleep(1000);
      ReleaseMutex(mutex);
   }
   return 0;
}

int main()
{
   HANDLE hThread = CreateThread(NULL, 0, consumer, NULL, 0, NULL);
   mutex = CreateMutex(NULL, FALSE, "screen");
   CloseHandle(hThread);
   for(int i=0;i<5;i++) {
      WaitForSingleObject(mutex, INFINITE);
      cout<<"main:"<<i<<endl;
      Sleep(1000);
      ReleaseMutex(mutex);
   }
   return 0;
}
