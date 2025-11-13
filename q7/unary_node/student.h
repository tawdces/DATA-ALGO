#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* ptr) const {
  //you may write additional code here
  if (ptr == nullptr) return 0;
  
  bool isUnary = (ptr->left == nullptr && ptr->right != nullptr) ||
                 (ptr->left != nullptr && ptr->right == nullptr);
  
  return (isUnary ? 1 : 0) + process(ptr->left) + process(ptr->right);
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::count_unary() const {
  //write your code here
  return process(mRoot);
}

#endif
