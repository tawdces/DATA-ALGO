void replace(const T& x, list<T>& y) {
  //write your code here
  for(iterator it=begin();it!=end();){
        if(*it==x){
            it=erase(it);
            for(iterator yIt=y.begin();yIt!=y.end();yIt++) {
                it=insert(it,*yIt);
                it++;
            }
        } 
        else{
            it++;
        }
    }
}
