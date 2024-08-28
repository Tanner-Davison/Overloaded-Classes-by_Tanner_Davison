#include <utility>

#include "stdafx.h"

class Animals {
public:
    Animals() = default;
    explicit Animals(std::string nameP="undefined", int const &ageP=0)
        :name(std::move(nameP)), age(ageP) {};
    void speak()const {
        std::cout << name << " " << age << "\n";
    }
protected:
    std::string name;
    int age;
};

class Cats: public Animals {
    public:
    Cats() = default;
    explicit Cats(std::string const &nameP, int const &age):Animals(nameP, age) {};

    void speak() const {
        std::cout << "Meoww ";
        Animals::speak();
    }
};
class Tiger: public Cats {
    public:
    explicit Tiger() = delete;
    Tiger(std::string const &nameP, int const &age):Cats(nameP, age) {};

    void speak() const {
        Cats::speak();
        std::cout<<"I am a tiger"<<std::endl;
    }

};


int main() {

    Animals const donkey("Roger", 81);
        donkey.speak();
    Cats const lion("Cat", 100);
        lion.speak();
    Tiger const tiger("Tiger", 50);
        tiger.speak();
    Tiger const tiger3("Tiger 3" , 150);
        tiger3.speak();



}