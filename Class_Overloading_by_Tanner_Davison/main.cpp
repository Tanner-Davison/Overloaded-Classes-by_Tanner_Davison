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

    int sqft{};
    Vector2D coord;
};
class Family : public House
{
public:
    Family()=default;
    Family(int const membersP, std::string headP): members(membersP), head(std::move(headP)){};
    Family(int const membersP, std::string headP, const House& house)
        :members(membersP), head(std::move(headP))
    {
        if(house.sqft < 1000)
        {
            wealth_status = "poor";
        }else
        {
            wealth_status = "wealthy";
        }
    };
    void printFamilyInfo() const
    {
        std::cout << "Head Of House: " << head << "\nTotal Members: " << members <<  std::endl;
        House::printHouse();
        std::cout << "Status: " << wealth_status << std::endl;
    }

protected:
    int members{};
    std::string head{};
    std::string wealth_status{};
};

int main() {
    std::string headOfHouse{};
    int familyCount{};
    std::cout << "Enter Head of house and Total count of family members : ";
    std::cin >> headOfHouse >> familyCount;
    const Vector2D coordinates{1700, 1500};
    House const house{1001,coordinates};
    Family const family{familyCount, headOfHouse, house};

    family.printFamilyInfo();

}