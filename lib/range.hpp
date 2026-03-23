#pragma once

#include <cassert>
#include "types.hpp"

namespace math
{
   class intRange
   {
      public:
         intRange()=delete;
         constexpr intRange(u16 inst) : start(inst), end(inst)
         {
         }
         constexpr intRange(u16 _start, u16 _end) : start(_start), end(_end)
         {
            assert(start<=end);
         }
         constexpr intRange(const std::initializer_list<u16>& _data) : start(std::data(_data)[0]), end(std::data(_data)[1])
         {
            assert(start<=end);
         }
         ~intRange()=default;

         constexpr u16 span()
         {
            return end-start+1;
         }

      public:
         const u16 start, end;
   };
}
