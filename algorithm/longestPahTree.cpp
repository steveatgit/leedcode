http://blog.csdn.net/shw372029857/article/details/48663633
在二叉树中，找到距离最远的两个节点的距离


int longestPath(BTreeNode *root)
{
   int left_len, right_len, max_len;
   longestPathCore(root, left_len, right_len, max_len);
   return max_len;
}
int longestPathCore(BTreeNode *root, int &left_len, int &right_len, int max_len)
{
   if(root == NULL) {
      left_len = 0;
      right_len = 0;
      max_len = 0;
      return;
   }
   int left_len1, right_len1, left_len2, right_len2;
   longestPathCore(root->left, left_len1, right_len1, max_len);
   longestpathCore(root->right, left_len2, right_len2, max_len);
   left_len = 1+max(left_len1, right_len1);
   right_len = 1+max(left_len2, right_len2);
   max_len = max(left_len+right_len-1, max_len);
}
