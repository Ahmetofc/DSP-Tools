#pragma once

#include <vector>
#include <iostream>
#include <cassert>

#include "types.hpp"
#include "complex.hpp"
#include "range.hpp"

namespace math
{
   template <typename T>
   class matrix 
   {
      public: 
         matrix()=default;
         constexpr matrix(u16, u16);
         constexpr matrix(const std::initializer_list<std::initializer_list<T> >&);
         constexpr matrix(const matrix&);
         ~matrix()=default;

         matrix& operator=(const matrix&);

         matrix operator+(const matrix&) const;
         matrix& operator+=(const matrix&);
         matrix operator-(const matrix&) const;
         matrix& operator-=(const matrix&);
         matrix operator*(const matrix&) const;
         matrix& operator*=(const matrix&);
         matrix operator/(const matrix&) const;
         matrix& operator/=(const matrix&);

         matrix getSubMatrix(intRange, intRange) const;

         friend math::matrix<T> operator*(const math::matrix<T>& lhs, math::complex rhs)
         {
            matrix res=lhs;
            for(auto& column : res.data)
               for(T& element : column)
                  element*=rhs;
            return res;
         }
         friend math::matrix<T> operator*(math::complex lhs, const math::matrix<T>& rhs)
         {
            matrix res=rhs;
            for(auto& column : res.data)
               for(T& element : column)
                  element*=lhs;
            return res;
         }
         friend math::matrix<T>& operator*=(math::matrix<T>& lhs, math::complex rhs)
         {
            for(auto& column : lhs.data)
               for(T& element : column)
                  element*=rhs;
            return lhs;
         }
         friend math::matrix<T> operator/(const math::matrix<T>& lhs, math::complex rhs)
         {
            matrix res=lhs;
            for(auto& column : res.data)
               for(T& element : column)
                  element/=rhs;
            return res;
         }
         friend math::matrix<T> operator/(math::complex lhs, const math::matrix<T>& rhs)
         {
            matrix res=rhs;
            for(auto& column : res.data)
               for(T& element : column)
                  element/=lhs;
            return res;
         }
         friend math::matrix<T>& operator/=(math::matrix<T>& lhs, math::complex rhs)
         {
            for(auto& column : lhs.data)
               for(T& element : column)
                  element/=rhs;
            return lhs;
         }
         friend std::ostream& operator<<(std::ostream& output, const math::matrix<T>& input)
         {
            output << "Matrix with dimensions " << input.row << "x" << input.col << std::endl;
            output << "Matrix entries:" << std::endl;
            for(u16 i{}; i<input.row; i++)
            {
               for(u16 j{}; j<input.col; j++)
                  output << input.data.at(j).at(i) << " ";
               output << std::endl;
            }
            return output;
         }

      private:
         u16 row{}, col{};
         std::vector<std::vector<T> > data{};
   };
}

#include "matrix.tpp"
