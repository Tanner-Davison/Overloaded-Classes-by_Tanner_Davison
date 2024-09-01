//
// Created by Tanner on 8/30/2024.
//

#ifndef FAMILY_H
#define FAMILY_H

class House
{
    public:
        House()=default;
        House(int sqftP, const Vector2D& vec);
        ~House()=default;
        void printHouse()const;
        friend class Family;
private:
        int sqft{};
        Vector2D coord;
};
class Family : public House
{
    public:
        explicit Family(string headP="unkown head", string wealth_statusP="unknown");

        Family(int membersP, std::string headP);
        Family(const House& houseP, int  membersP, std::string headP);
        void printHouse() const
        {
            std::cout << "printing from family: " << std:: endl;
            House::printHouse();
        }
        void printFamilyInfo() const;
        friend class ExtendedFamily;
    private:
        int members{};
        std::string head{};
        std::string wealth_status{};
};

class ExtendedFamily final : public Family{
    public:
        ExtendedFamily();

        ExtendedFamily(std::string grandpaP, std::string grandmaP);

        ExtendedFamily(const Family& familyP, std::string grandpaP, std::string grandmaP);

        static void toString(const Family& familyP);

        void wholeFamily()const;

        std::string grandpa{};
        std::string grandma{};
};

void getFamilyInfo(string& headP, string& grandFatherP, string& grandmotherP, int& familyCount);


#endif //FAMILY_H
