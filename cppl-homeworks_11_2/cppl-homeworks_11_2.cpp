#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

class big_integer
{
public:
std::string str_;
std::vector <int> data_;
big_integer (std::string in_str_):str_(in_str_)
{
    for (int i=0;i<size(str_);i++) data_.push_back(int(str_[i])-48);
    std::reverse(data_.begin(),data_.end());
}

big_integer (big_integer&& other) 
{
    str_ = std::move(other.str_);
    data_ = std::move(other.data_);
}

big_integer& operator= (big_integer&& other) 
{
    if (this == &other) 
        return *this;
    str_ = std::move(other.str_);
    data_ = std::move(other.data_);
    // std::vector <int> ().swap(data_);
    // data_=other.data_;
    // str_=other.str_;
    // std::vector <int>(). swap(other.data_);
    return *this;
}

    std::string operator + ( big_integer& other)
    {
        std::string str_out ="";
        std::vector <int> temp((data_.size()>=other.data_.size())?data_:other.data_);
        if(data_.size()>=other.data_.size())
        {
        for (int i=0;i<other.data_.size();i++)
        {
            if((i==(other.data_.size()-1))&&((temp[i]+other.data_[i])/10)) temp.push_back (1);
                else temp[i+1]=temp[i+1]+((temp[i]+other.data_[i])/10);
            temp[i]=((temp[i]+other.data_[i])%10);
        }
        }
        else 
        {
            for (int i=0;i<data_.size();i++)
            {
                temp[i+1]+=((temp[i]+other.data_[i])/10);
                temp[i]=((temp[i]+other.data_[i])%10);
            }  
        }
        std::reverse(temp.begin(),temp.end());
        for (int i=0;i<temp.size();i++) str_out = str_out+std::to_string(temp[i]);   
        return str_out;
    }
};

int main ()
{
auto number1 = big_integer("114575");
auto number2 = big_integer("78524");
auto result = number1 + number2;
std::cout << result << std::endl; 
return 0;
}