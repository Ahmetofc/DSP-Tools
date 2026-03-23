namespace math
{
   constexpr complex::complex(double _re) noexcept : re(_re), im(0)
   {
   }

   constexpr complex::complex(double _re, double _im) noexcept : re(_re), im(_im)
   {
   }

   constexpr complex::complex(const complex& comp) noexcept : re(comp.re), im(comp.im)
   {
   }

   complex& complex::operator=(const complex& rhs) noexcept
   {
      re=rhs.re;
      im=rhs.im;
      return *this;
   }

   complex complex::operator+(const complex& rhs) const noexcept
   {
      complex res=*this;
      res.re+=rhs.re;
      res.im+=rhs.im;
      return res;
   }

   complex& complex::operator+=(const complex& rhs) noexcept
   {
      re+=rhs.re;
      im+=rhs.im;
      return *this;
   }

   complex complex::operator-(const complex& rhs) const noexcept
   {
      complex res=*this;
      res.re-=rhs.re;
      res.im-=rhs.im;
      return res;
   }

   complex& complex::operator-=(const complex& rhs) noexcept
   {
      re-=rhs.re;
      im-=rhs.im;
      return *this;
   }

   complex complex::operator*(const complex& rhs) const noexcept
   {
      complex res;
      res.re=re*rhs.re-im*rhs.im;
      res.im=re*rhs.im+im*rhs.re;
      return res;
   }

   complex& complex::operator*=(const complex& rhs) noexcept
   {
      double re_t=re, im_t=im;
      re=re_t*rhs.re-im_t*rhs.im;
      im=re_t*rhs.im+im_t*rhs.re;
      return *this;
   }

   complex complex::operator/(const complex& rhs) const
   {
      if(rhs==complex{})
         throw std::domain_error("Division by zero.\n");
      complex res=*this;
      res*=rhs.complement();
      res.re/=rhs.normSquared();
      res.im/=rhs.normSquared();
      return res;
   }

   complex& complex::operator/=(const complex& rhs)
   {
      if(rhs==complex{})
         throw std::domain_error("Division by zero.\n");
      double re_t=re, im_t=im;
      re=re_t*rhs.re+im_t*rhs.im;
      im=im_t*rhs.re-re_t*rhs.im;
      re/=rhs.normSquared();
      im/=rhs.normSquared();
      return *this;
   }

   bool complex::operator==(const complex& rhs) const noexcept
   {
      return re==rhs.re && im==rhs.im;
   }

   complex::operator double() const noexcept
   {
      return re;
   }

   constexpr double complex::real() const noexcept
   {
      return re;
   }

   constexpr double complex::imaginary() const noexcept
   {
      return im;
   }

   double complex::norm() const noexcept
   {
      return std::sqrt(std::pow(re, 2)+std::pow(im, 2));
   }

   double complex::normSquared() const noexcept
   {
      return std::pow(re, 2)+std::pow(im, 2);
   }

   double complex::arg() const noexcept
   {
      return std::atan2(im, re);
   }

   complex complex::complement() const noexcept
   {
      return complex(re, -im);
   }
}
