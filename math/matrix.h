#ifndef DSP_MATH_MATRIX_H_
#define DSP_MATH_MATRIX_H_

#include <cassert>
#include <exception>
#include <iostream>
#include <vector>

#include "complex.h"
#include "range.h"
#include "types.h"

namespace math
{
   template <typename T>
   class matrix 
   {
      public: 
         constexpr matrix() noexcept=default;
         constexpr matrix(u16, u16) noexcept;
         constexpr matrix(const std::initializer_list<std::initializer_list<T>>&);
         constexpr matrix(const std::vector<std::vector<T>>&);
         constexpr matrix(const matrix&) noexcept;
         ~matrix() noexcept=default;

         matrix& operator=(const matrix&) noexcept;

         matrix operator+(const matrix&) const;
         matrix& operator+=(const matrix&);
         matrix operator-(const matrix&) const;
         matrix& operator-=(const matrix&);
         matrix operator*(const matrix&) const;
         matrix& operator*=(const matrix&);
         matrix operator/(const matrix&) const;
         matrix& operator/=(const matrix&);

         bool operator==(const matrix&) const noexcept;

         constexpr u16 rowNumber() const noexcept;
         constexpr u16 columnNumber() const noexcept;
         constexpr std::vector<std::vector<T>> getData() const noexcept;

         matrix getSubMatrix(intRange, intRange) const;
         //matrix& subMatrixConstruct(matrix&, matrix&, matrix&, matrix&);

         friend math::matrix<T> operator*(const math::matrix<T>& lhs, math::complex rhs) noexcept
         {
            matrix res=lhs;
            for(auto& column : res.data)
               for(T& element : column)
                  element*=rhs;
            return res;
         }
         friend math::matrix<T> operator*(math::complex lhs, const math::matrix<T>& rhs) noexcept
         {
            matrix res=rhs;
            for(auto& column : res.data)
               for(T& element : column)
                  element*=lhs;
            return res;
         }
         friend math::matrix<T>& operator*=(math::matrix<T>& lhs, math::complex rhs) noexcept
         {
            for(auto& column : lhs.data)
               for(T& element : column)
                  element*=rhs;
            return lhs;
         }
         friend math::matrix<T> operator/(const math::matrix<T>& lhs, math::complex rhs)
         {
            if(rhs==complex{})
               throw std::domain_error("Division by zero.\n");
            matrix res=lhs;
            for(auto& column : res.data)
               for(T& element : column)
                  element/=rhs;
            return res;
         }
         friend math::matrix<T>& operator/=(math::matrix<T>& lhs, math::complex rhs)
         {
            if(rhs==complex{})
               throw std::domain_error("Division by zero.\n");
            for(auto& column : lhs.data)
               for(T& element : column)
                  element/=rhs;
            return lhs;
         }
         friend std::ostream& operator<<(std::ostream& output, const math::matrix<T>& input) noexcept
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
         std::vector<std::vector<T>> data{};
   };
}

#include "math/matrix-inl.h"

#endif
