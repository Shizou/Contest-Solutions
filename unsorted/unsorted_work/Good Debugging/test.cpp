 while(lo < hi){
       // propagate the parent
       if(lazy[n]!=0){
         if(lo!=hi){
            lazy[2*n+1]+=lazy[n];
            lazy[2*n+2]+=lazy[n];
         }
         if(lazy[n]%2!=0)
            tree[n] = (hi-lo+1)-tree[n];
            lazy[n] = 0;
       }
       // propogate the children
       if(lo != (lo+hi)/2 && lazy[2*n+1]!=0){
         if(lo!=hi){
            lazy[4*n+3]+=lazy[2*n+1];
            lazy[4*n+4]+=lazy[2*n+1];
          }
          if(lazy[2*n+1]%2!=0)
            tree[2*n+1] = (hi-lo+1)-tree[2*n+1];
          lazy[2*n+1] = 0;
        }
        if((lo+hi)/2+1 != hi && lazy[2*n+2]!=0){
         if(lo!=hi){
            lazy[4*n+5]+=lazy[2*n+2];
            lazy[4*n+6]+=lazy[2*n+2];
          }
          if(lazy[2*n+2]%2!=0)
            tree[2*n+2] = (hi-lo+1)-tree[2*n+2];
          lazy[2*n+2] = 0;
        }
        // traverse appropiate branch
        printf("%d %d -> %d\n",lo,hi,tree[2*n+1]+tot);
        if(tree[2*n+1]+tot >= L){
           if(lo == (lo+hi)/2){
              if(tree[2*n+1]+tot == L)
                 n = 2*n+1,hi = (lo+hi)/2;
              else
                 n = 2*n+2,lo = (lo+hi)/2+1;
           }else{
            n = 2*n+1, hi = (lo+hi)/2;
          }
        }
        else if(tree[2*n+1]+tot > L){
           tot += tree[2*n+1];
           lo = (lo+hi)/2+1;
           n = 2*n+2;
        }
        break;
    }
    return lo;