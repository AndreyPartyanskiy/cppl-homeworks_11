#include <iostream>
#include <vector>

template <class T>
void move_vectors(T& in_two,T& in_one)
{
in_two = std::move (in_one);
}

int main()
{
std::vector <std::string> one = { "test_string1", "test_string2" };
std::vector <std::string> two;

std::cout << "ONE :" << one[0] << " " << one[1] << " "<< &one << std::endl;
std::cout << "TWO :" << &two << std::endl;

move_vectors <std::vector <std::string>>(two,one);

std::cout << "ONE :" << &one << std::endl;
std::cout << "TWO :" << two[0] << " " << two[1] << " " << &two << std::endl;
return 0;
}