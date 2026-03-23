template <typename T>
constexpr math::matrix<T>::matrix(u16 _row, u16 _col) : row(_row), col(_col), data(std::vector<std::vector<T> >{_col})
{
   for(auto& column : data)
      column=std::vector<T>(row, 0);
}

template <typename T>
constexpr math::matrix<T>::matrix(const std::initializer_list<std::initializer_list<T> >& _data) : row(std::data(_data)[0].size()), col(_data.size()), data(std::vector<std::vector<T> >{_data.size()})
{
   size_t _size=std::data(_data)[0].size();
   for(u16 i{}; i<col; i++)
   {
      assert(std::data(_data)[i].size()==_size);
      data[i]=std::data(_data)[i];
   }
}

template <typename T>
constexpr math::matrix<T>::matrix(const math::matrix<T>& rhs) : row(rhs.row), col(rhs.col), data(rhs.data)
{
}

template <typename T>
math::matrix<T>& math::matrix<T>::operator=(const math::matrix<T>& rhs)
{
   row=rhs.row;
   col=rhs.col;
   data=rhs.data;
   return *this;
}

template <typename T>
math::matrix<T> math::matrix<T>::operator+(const math::matrix<T>& rhs) const
{
   assert(col==rhs.col && row==rhs.row);
   matrix res=*this;
   for(u16 i{}; i<col; i++)
      for(u16 j{}; j<row; j++)
         res.data[i][j]+=rhs.data.at(i).at(j);
   return res;
}

template <typename T>
math::matrix<T>& math::matrix<T>::operator+=(const math::matrix<T>& rhs) 
{
   assert(col==rhs.col && row==rhs.row);
   for(u16 i{}; i<col; i++)
      for(u16 j{}; j<row; j++)
         data[i][j]+=rhs.data.at(i).at(j);
   return *this;
}

template <typename T>
math::matrix<T> math::matrix<T>::operator-(const math::matrix<T>& rhs) const
{
   assert(col==rhs.col && row==rhs.row);
   matrix res=*this;
   for(u16 i{}; i<col; i++)
      for(u16 j{}; j<row; j++)
         res.data[i][j]-=rhs.data.at(i).at(j);
   return res;
}

template <typename T>
math::matrix<T>& math::matrix<T>::operator-=(const math::matrix<T>& rhs) 
{
   assert(col==rhs.col && row==rhs.row);
   for(u16 i{}; i<col; i++)
      for(u16 j{}; j<row; j++)
         data[i][j]-=rhs.data.at(i).at(j);
   return *this;
}

template <typename T>
math::matrix<T> math::matrix<T>::operator*(const math::matrix<T>& rhs) const
{
   assert(col==rhs.row);
   matrix res{row, rhs.col};
   for(u16 i{}; i<rhs.col; i++)
      for(u16 j{}; j<row; j++)
         for(u16 k{}; k<col; k++)
            res.data[i][j]+=data[k][j]*rhs.data[i][k];
   return res;
}

template <typename T>
math::matrix<T>& math::matrix<T>::operator*=(const math::matrix<T>& rhs) 
{
   assert(col==rhs.row);
   matrix res{row, rhs.col};
   for(u16 i{}; i<rhs.col; i++)
      for(u16 j{}; j<row; j++)
         for(u16 k{}; k<col; k++)
            res.data[i][j]+=data[k][j]*rhs.data[i][k];
   col=rhs.col;
   data=res.data;
   return *this;
}

template <typename T>
math::matrix<T> math::matrix<T>::operator/(const math::matrix<T>& rhs) const
{
   assert(col==rhs.col && row==rhs.row);
   matrix res=*this;
   for(u16 i{}; i<col; i++)
      for(u16 j{}; j<row; j++)
         res.data[i][j]/=rhs.data.at(i).at(j);
   return res;
}

template <typename T>
math::matrix<T>& math::matrix<T>::operator/=(const math::matrix<T>& rhs) 
{
   assert(col==rhs.col && row==rhs.row);
   for(u16 i{}; i<col; i++)
      for(u16 j{}; j<row; j++)
         data[i][j]/=rhs.data.at(i).at(j);
   return *this;
}

template <typename T>
math::matrix<T> math::matrix<T>::getSubMatrix(math::intRange rows, math::intRange cols) const
{
   assert(row>rows.end && col>cols.end);
   matrix res{rows.span(), cols.span()};
   for(u16 i{cols.start}; i<cols.end+1; i++)
      for(u16 j{rows.start}; j<rows.end+1; j++)
         res.data[i-cols.start][j-rows.start]=data.at(i).at(j);
   return res;
}