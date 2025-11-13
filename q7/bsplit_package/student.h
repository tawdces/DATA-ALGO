#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
  //your code here
  CP::map_bst<KeyT,MappedT,CompareT> result;
  auto split_rec = [&](auto self, node* cur, KeyT val) -> std::pair<node*, node*> {
    if (!cur) return {NULL, NULL};

    if (mLess(cur->data.first, val)) {
      auto p = self(self, cur->right, val);
      cur->right = p.first;
      if (cur->right) cur->right->parent = cur;
      if (p.second) p.second->parent = NULL;
      return {cur, p.second};
    } else {
      auto p = self(self, cur->left, val);
      cur->left = p.second;
      if (cur->left) cur->left->parent = cur;
      if (p.first) p.first->parent = NULL;
      return {p.first, cur};
    }
  };
  auto [L, R] = split_rec(split_rec, mRoot, val);
  mRoot = L;
  if (mRoot) mRoot->parent = NULL;
  result.mRoot = R;
  if (result.mRoot) result.mRoot->parent = NULL;
  return result;
}

#endif
