#include <utility>

#include "stdafx.h"


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

    extendedFamily.toString(family);

}