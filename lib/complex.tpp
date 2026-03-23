math::complex::complex(double _re) : re(_re), im(0)
{
}

math::complex::complex(double _re, double _im) : re(_re), im(_im)
{
}

math::complex::complex(const complex& comp) : re(comp.re), im(comp.im)
{
}

math::complex& math::complex::operator=(const complex& rhs)
{
   re=rhs.re;
   im=rhs.im;
   return *this;
}

math::complex math::complex::operator+(const complex& rhs) const
{
   complex res=*this;
   res.re+=rhs.re;
   res.im+=rhs.im;
   return res;
}

math::complex& math::complex::operator+=(const complex& rhs)
{
   re+=rhs.re;
   im+=rhs.im;
   return *this;
}

math::complex math::complex::operator-(const complex& rhs) const
{
   complex res=*this;
   res.re-=rhs.re;
   res.im-=rhs.im;
   return res;
}

math::complex& math::complex::operator-=(const complex& rhs)
{
   re-=rhs.re;
   im-=rhs.im;
   return *this;
}

math::complex math::complex::operator*(const complex& rhs) const
{
   complex res;
   res.re=re*rhs.re-im*rhs.im;
   res.im=re*rhs.im+im*rhs.re;
   return res;
}

math::complex& math::complex::operator*=(const complex& rhs)
{
   double re_t=re, im_t=im;
   re=re_t*rhs.re-im_t*rhs.im;
   im=re_t*rhs.im+im_t*rhs.re;
   return *this;
}

math::complex math::complex::operator/(const complex& rhs) const
{
   complex res=*this;
   res*=rhs.complement();
   res.re/=rhs.normSquared();
   res.im/=rhs.normSquared();
   return res;
}

math::complex& math::complex::operator/=(const complex& rhs)
{
   double re_t=re, im_t=im;
   re=re_t*rhs.re+im_t*rhs.im;
   im=im_t*rhs.re-re_t*rhs.im;
   re/=rhs.normSquared();
   im/=rhs.normSquared();
   return *this;
}

math::complex::operator double() const
{
   return re;
}

inline double math::complex::norm() const
{
   return std::sqrt(std::pow(re, 2)+std::pow(im, 2));
}

inline double math::complex::normSquared() const
{
   return std::pow(re, 2)+std::pow(im, 2);
}

inline double math::complex::arg() const
{
   return std::atan2(im, re);
}

inline math::complex math::complex::complement() const
{
   return complex(re, -im);
}
