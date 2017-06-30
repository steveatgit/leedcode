#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <windows.h>

int main()
{
   typedef unsigned short uint16;
   typedef unsigned int uint32;
   typedef char Bool;
   typedef struct {
      uint16 key;
      Bool down;
   } MKSKeyboardPacket;
   typedef struct _RPC {
      char name[40];
      size_t length;
   } RPC;

   uint32 aaa;
   size_t bbb;
   char ccc;
   int ddd;
   MKSKeyboardPacket *keyPacket = NULL;
   void *buffer = NULL;
   buffer = malloc(48);
   RPC *rpcHeader = (RPC *)buffer;
   strcpy(rpcHeader->name, "PressKey");
   rpcHeader->length = sizeof *keyPacket;
   keyPacket = (MKSKeyboardPacket *)(((char *)buffer) + sizeof *rpcHeader);
   //keyPacket->key = 0x011;
   
   printf("buffer is %s\n", buffer);   // PressKey
   printf("keyPacket is %s\n", keyPacket); 
   printf("%d %d\n", sizeof *keyPacket, sizeof *rpcHeader); //4   44
   printf("%d %d %d %d\n", sizeof aaa, sizeof bbb, sizeof ccc, sizeof ddd); //4 4 1 4
   std::cout << "the buffer is " << buffer << "size of char " << sizeof (buffer)<< std::endl;// []  4
   return 1;
}
