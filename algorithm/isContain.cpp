#include <stdio.h>
#include <iostream>


//强大的和谐系统  
int isContain(char *parent, char *sub) 
{
    //创建一个哈希表，并初始化  
    const int tableSize = 256;
    int hashTable[tableSize];
    int len,i;
    for(i = 0; i < tableSize; i++)
        hashTable[i] = 0;
    len = strlen(parent);
    for(i = 0; i < len; i++) {
        hashTable[parent[i]] = 1;
    }

    len = strlen(sub);
    for(i = 0; i < len; i++)
    {
        if(hashTable[sub[i]] == 0)
            return 0;         //匹配失败  
    }
    return 1;    //匹配成功  
}

int main()
{
   char dst[20] = "123";
   char parent[20] = "1slafa2ljao3";
   if (isContain(parent, dst)) {
      printf("ok\n");
   }  else {
      printf("fail\n");
   }
}

