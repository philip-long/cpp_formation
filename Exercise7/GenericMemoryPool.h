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

//      MemoryPool<Operation, 1000> myOperationPool;

template<typename T, int capacity = 10000>
class GenericMemoryPool {
	 char pool[capacity*sizeof(T)];
	 char used[capacity];
public :
	GenericMemoryPool() {
		memset(used,0,capacity);
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
