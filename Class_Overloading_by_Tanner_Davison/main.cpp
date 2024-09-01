#include <utility>

#include "stdafx.h"
#include "Vector.h"

namespace TEST
{
    void hello(){ cout<< "Hello" << endl; }
    enum EGameDifficulty {Easy, Normal, Hard};
}
enum ETerrainDifficulty {Easy, Normal, Hard};
void hello()
{
    std::cout << "hey!" << std::endl;
}
int main()
{
    using namespace TEST;
    EGameDifficulty difficulty = EGameDifficulty::Hard;

    Vector vec;
    ::hello();
    TEST::hello();
    Vector::toString();
    cout << "--------END OF PROGRAM----------" << endl;
    return 1;
}