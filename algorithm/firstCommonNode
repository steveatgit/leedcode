http://blog.csdn.net/nwpulei/article/details/8125938
List *firstCrossNode(List *list1, List *list2)
{
   if(NULL == list1 || NULL == list2) {
      return NULL;
   }
   List *p1 = list1;
   List *p2 = list2;
   int l1 = lenOfList(list1);
   int l2 = lenOfList(list2);
   if(l1<l2) {
      p1 = list2;
      p2 = list1;
      int tmp = l1;
      l1 = l2;
      l2 = tmp;
   }
   while(l1>l2) {
      p1 = p1->next;
      l1--;
   }
   while(p1 && p1!=p2) {
      p1 = p1->next;
      p2 = p2->next;
   }
   return p1;
}

//  如何创建这样的链表不是很清楚，没写main函数
