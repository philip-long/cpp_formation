/*
 * MemoryPool.h
 *
 *  Created on: 17 janv. 2017
 *      Author: joel
 */

#ifndef MEMORYPOOL_H_
#define MEMORYPOOL_H_
#include  <cstring>
#include  <cassert>
#include  <iostream>

class MemoryPool {
	 char *pool;
	 char *used;
	 size_t objectSize;
	 int capacity;

public :
 MemoryPool(size_t objectSize, int capacity) : objectSize(objectSize), capacity(capacity)  {
	 pool = new char[objectSize*capacity];
	 used = new char[capacity];
	 memset(used,0,capacity);
 }

 void * allocate() {
  std::cout << "allocate()" <<std::endl;
  for(int i=0; i<capacity; i++)
	  if(!used[i]){
		  used[i]=1;
		  return pool + (i * objectSize);
}
  return NULL;
}

void release(void * p) {
	 std::cout << "release()" <<std::endl;
	 char * _p = static_cast<char *>(p);
	 assert(_p >= pool && p <= (pool + (objectSize *(capacity-1))));
 	 int index = (_p-pool) / objectSize;
 	 used[index]=0; }
};


#endif /* MEMORYPOOL_H_ */
