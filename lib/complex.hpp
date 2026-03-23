#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>

#include "types.hpp"
#include "macros.hpp"

namespace math
{
   class complex
   {
      public:
         complex()=default;
         complex(double);
         complex(double, double);
         complex(const complex&);
         ~complex()=default;

         complex& operator=(const complex&);

         complex operator+(const complex&) const;
         complex& operator+=(const complex&);
         complex operator-(const complex&) const;
         complex& operator-=(const complex&);
         complex operator*(const complex&) const;
         complex& operator*=(const complex&);
         complex operator/(const complex&) const;
         complex& operator/=(const complex&);

         operator double() const;

         inline double norm() const;
         inline double normSquared() const;
         inline double arg() const;

         inline complex complement() const;

         friend complex operator*(double factor, const complex& rhs)
         {
            complex res;
            res.re=rhs.re*factor;
            res.im=rhs.im*factor;
            return res;
         }
         friend complex operator/(double factor, const complex& rhs)
         {
            complex res;
            res.re=rhs.re*factor/rhs.normSquared();
            res.im=-rhs.im*factor/rhs.normSquared();
            return res;
         }
         friend std::ostream& operator<<(std::ostream& output, const complex& other)
         {
            output << std::fixed << std::setprecision(FLOATPRECISION);
            if(other.im<0)
               output << other.re << other.im << "j";
            else if(other.im>0)
               output << other.re << "+" << other.im << "j";
            else 
               output << other.re;
            return output;
         }  

      private:
         double re{}, im{};
   };
}

#include "complex.tpp"
