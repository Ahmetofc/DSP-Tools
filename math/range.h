#ifndef DSP_MATH_RANGE_H_
#define DSP_MATH_RANGE_H_

#include <cassert>

#include "types.h"

namespace math
{
   class intRange
   {
      public:
         intRange()=delete;
         constexpr intRange(u16 inst) noexcept : start(inst), end(inst)
         {
         }
         constexpr intRange(u16 _start, u16 _end) noexcept : start(_start), end(_end)
         {
            assert(start<=end);
         }
         constexpr intRange(const std::initializer_list<u16>& _data) noexcept : start(std::data(_data)[0]), end(std::data(_data)[1])
         {
            assert(start<=end);
         }
         ~intRange() noexcept=default;

         constexpr u16 span() noexcept
         {
            return end-start+1;
         }

      public:
         const u16 start, end;
   };
}

#endif
