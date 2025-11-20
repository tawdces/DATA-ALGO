#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, int &aux){
	// You MAY use this function
	if(!n){
        return -1;
    }
    int left=my_recur(n->left,aux);
    int right=my_recur(n->right,aux);
    int dist=left+right+2;
    aux=std::max(aux,dist);
    return std::max(left,right)+1;
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance() {
	// write your code here
	if(!mRoot){
        return -1;
    }
    int mx=0;
    my_recur(mRoot,mx);
    return mx;
}

#endif
