/*
 * MemoryPool.h
 *
 *  Created on: 17 janv. 2017
 *      Author: joel
 */

#ifndef GENERIC_MEMORYPOOL_H_
#define GENERIC_MEMORYPOOL_H_
#include  <cstring>
#include  <cassert>
#include  <iostream>

// We must define T by typename, an older version was
// template<class T> , if we put the capacity at the template part
// rather than in constructor it is resolved at compilation and not at execution
template<typename T,int capacity=10000>
class GenericMemoryPool {
     char pool[sizeof(T)*capacity];
     char used[capacity];
     //size_t objectSize; now object size can be substitued by the sizeof(T)
     //int capacity; it is no longer an attribute

public :
 GenericMemoryPool() {
     memset(used,0,capacity); //We keep this
 }

 void * allocate() {
  std::cout << "allocate()" <<std::endl;
  for(int i=0; i<capacity; i++)
	  if(!used[i]){
		  used[i]=1;
          return pool + (i * sizeof(T));
}
  return NULL;
}

void release(void * p) {
	 std::cout << "release()" <<std::endl;
	 char * _p = static_cast<char *>(p);
     assert(_p >= pool && p <= (pool + (sizeof(T) *(capacity-1))));
     int index = (_p-pool) / sizeof(T);
 	 used[index]=0; }
};


#endif /* MEMORYPOOL_H_ */
