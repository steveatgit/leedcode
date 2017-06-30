#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
using namespace std;

int getFileSize(const char* file)
{
   size_t size = 0;
   FILE *fp = fopen(file, "rb");
   fseek(fp, 0, SEEK_END);
   size = ftell(fp);
   fclose(fp);
   printf("[C] the file size is %d\n", size);
   return size;
}

int _getFileSize(const char* file)
{
   size_t size = 0;
   ifstream in;
   in.open(file, ofstream::binary);
   size = in.seekg(0, ifstream::end).tellg();
   in.seekg(0, ifstream::beg);
   in.close();
   cout<<"[CPP]the file size is "<<size<<endl;
   return size;
}

int main()
{
   const char* file = "C:\\tools\\clipboard tools code\\TestData\\test.bmp";
   getFileSize(file);
   _getFileSize(file);
   return 0;
}
