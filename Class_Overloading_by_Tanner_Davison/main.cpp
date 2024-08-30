#include <utility>

#include "stdafx.h"

class House
{
public:
    House()=default;
    House(int const sqftP, const Vector2D& vec)
    :sqft(sqftP), coord(vec){};
    virtual ~House()=default;
    void printHouse()const
    {
        std::cout<<"Sqft: "<< sqft << "\n" << "Coordinates: " << coord.x << " " << coord.y << std::endl;
    }

protected:
    int sqft{};
    Vector2D coord;
};
class Family : public House
{
public:
    Family()=default;
    Family(int const membersP, std::string const headP): members(membersP), head(headP){};
    void printFamilyHead()
    {
        std::cout << "Head Of House: " << head<< std::endl;
    }

    int members{};
    std::string head{};
};
int main() {

    const Vector2D coordinates{1700, 1500};
    House house{1500,coordinates};
    Family family{3, "Tanner"};

}