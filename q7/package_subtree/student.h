#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "map_bst.h"

template <typename KeyT,typename MappedT, typename CompareT >
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* n) {
  //write your code here
  if (n == nullptr) return 0;
  return 1 + process(n->left) + process(n->right);
}

template <typename KeyT,typename MappedT, typename CompareT >
std::pair<KeyT,MappedT> CP::map_bst<KeyT,MappedT,CompareT>::subtree(map_bst<KeyT,MappedT,CompareT> &left, map_bst<KeyT,MappedT,CompareT> &right) {
  //write your code here
  if (mRoot == nullptr) {
    return std::pair<KeyT,MappedT>();
  }
  
  std::pair<KeyT, MappedT> rootData = mRoot->data;
  
  left.clear();
  right.clear();
  
  if (mRoot->left != nullptr) {
    left.mRoot = mRoot->left;
    left.mRoot->parent = nullptr;
    left.mSize = process(left.mRoot);
  }
  
  if (mRoot->right != nullptr) {
    right.mRoot = mRoot->right;
    right.mRoot->parent = nullptr;
    right.mSize = process(right.mRoot);
  }
  
  mRoot->left = nullptr;
  mRoot->right = nullptr;
  
  mSize = 1;
  
  return rootData;
}

#endif