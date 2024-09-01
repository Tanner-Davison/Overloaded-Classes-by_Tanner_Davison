//
// Created by Tanner on 8/30/2024.
//

#include "Family.h"

House
    ::House(int const sqftP, const Vector2D& vec)
    :sqft(sqftP), coord(vec){};
void House
    ::printHouse()const
{
    std::cout<<"Sqft: "<< sqft << "\n" << "Coordinates: " << coord.x << " " << coord.y << std::endl;
}

Family
    ::Family(string headP, string wealth_statusP):head(std::move(headP)), wealth_status(std::move(wealth_statusP)){}

Family
    ::Family(int const membersP, std::string headP): members(membersP), head(std::move(headP)){}

Family
    ::Family(const House& houseP, int const membersP, std::string headP)
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
void Family
    ::printFamilyInfo() const
{
    std::cout << "Head Of House: " << head << "\nTotal Members: " << members <<  std::endl;
    House::printHouse();
    std::cout << "Status: " << wealth_status << std::endl;
}
ExtendedFamily
    ::ExtendedFamily()
        :grandpa("unkown"), grandma("unknown"){};

ExtendedFamily
    ::ExtendedFamily(std::string grandpaP, std::string grandmaP)
        :grandpa(std::move(grandpaP)), grandma(std::move(grandmaP)){};

ExtendedFamily
    ::ExtendedFamily(const Family& familyP, std::string grandpaP, std::string grandmaP)
       :Family(familyP), grandpa(std::move(grandpaP)), grandma(std::move(grandmaP)){};

void ExtendedFamily
    ::wholeFamily()const
{
    std::cout << "Grandparents: " << grandpa << " " << grandma << "\nSon of grandparents: " << head << std::endl;
}
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
void ExtendedFamily::toString(const Family& familyP)
{
    std::cout << familyP.members;
}