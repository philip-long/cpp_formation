#ifndef SPECIFIC_ALLOCATOR
#define SPECIFIC_ALLOCATOR

#include <memory>
#include "GenericMemoryPool.h"
#include <iostream>


template<typename _Tp>
   class SpecificAllocator{
   public:
      typedef size_t     size_type;
      typedef std::ptrdiff_t  difference_type;
      typedef _Tp*       pointer;
      typedef const _Tp* const_pointer;
      typedef _Tp&       reference;
      typedef const _Tp& const_reference;
      typedef _Tp        value_type;

    typedef GenericMemoryPool<_Tp, 100000> poolType;

     static poolType& getPool() {
             static poolType pool;
             return pool;
         }

     template<typename _Tp1>
       struct rebind
       { typedef SpecificAllocator<_Tp1> other; };


     // NB: __n is permitted to be 0.  The C++ standard says nothing
     // about what the return value is when __n == 0.
     pointer
     allocate(size_type __n, const void* = 0)
     {
         std::cout << "SpecificAllocator::allocate" << std::endl;
         return static_cast<_Tp*>(getPool().allocate());
     }

     // __p is not permitted to be a null pointer.
     void
     deallocate(pointer __p, size_type)
     {
         std::cout << "SpecificAllocator::deallocate" << std::endl;
         getPool().release(__p); }


     void
     destroy(pointer __p) { __p->~_Tp(); }
   };




#endif // SPECIFIC_ALLOCATOR
