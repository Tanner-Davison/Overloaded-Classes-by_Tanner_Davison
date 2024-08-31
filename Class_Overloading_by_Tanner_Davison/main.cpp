#include <utility>

#include "stdafx.h"

class House
{
public:
    House()=default;
    House(int const sqftP, const Vector2D& vec)
    :sqft(sqftP), coord(vec){};
   ~House()=default;
    void printHouse()const
    {
        std::cout<<"Sqft: "<< sqft << "\n" << "Coordinates: " << coord.x << " " << coord.y << std::endl;
    }
public:
    int sqft{};
    Vector2D coord;
};
class Family : public House
{
public:
    Family():members(0),head("unkown head"), wealth_status("unkown"){};
    Family(int const membersP, std::string headP): members(membersP), head(std::move(headP)){};
    Family( const House& houseP, int const membersP, std::string headP)
        :House(houseP), members(membersP), head(std::move(headP))
    {
        if(houseP.sqft < 1000)
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

public:
    int members{};
    std::string head{};
    std::string wealth_status{};
};

class ExtendedFamily final : public Family{
public:
    ExtendedFamily()
        :grandpa("unkown"), grandma("unknown"){};

    ExtendedFamily(std::string grandpaP, std::string grandmaP)
        :grandpa(std::move(grandpaP)), grandma(std::move(grandmaP)){};

    ExtendedFamily(const Family& familyP, std::string grandpaP, std::string grandmaP)
       :Family(familyP), grandpa(std::move(grandpaP)), grandma(std::move(grandmaP)){};


    void wholeFamily()const
    {
        std::cout << "Grandparents: " << grandpa << " " << grandma << "\nSon of grandparents: " << head << std::endl;
    }

public:
    std::string grandpa{};
    std::string grandma{};
};
void getFamilyInfo(string& headP, string& grandFatherP, string& grandmotherP, int& familyCount)
{
    std::cout << "Enter Head of house and Total count of family members : ";
    std::getline(std::cin, headP);
    std::cin >>familyCount;
    std:: cout << "Enter the head of households parents starting with Dad and then Mom" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, grandFatherP);
    std::getline(std::cin, grandmotherP);
}
int main() {
    std::string headOfHouse{};
    std::string grandFather{};
    std::string grandmother{};
    int familyCount{};
    getFamilyInfo(headOfHouse, grandFather, grandmother, familyCount);
    const Vector2D coordinates{1700, 1500};
    House const house{1001,coordinates};
    Family const family{house, familyCount, headOfHouse};
    ExtendedFamily const extendedFamily{family, grandFather, grandmother};
    family.printFamilyInfo();
    extendedFamily.wholeFamily();
    extendedFamily.printFamilyInfo();


}