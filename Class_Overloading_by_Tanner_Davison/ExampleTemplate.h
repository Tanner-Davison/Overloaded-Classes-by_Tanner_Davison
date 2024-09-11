//
// Created by Tanner on 9/11/2024.
//

#pragma once


template <typename T>
class ExampleTemplate {
public:
    explicit ExampleTemplate(T memberP=0);
    ~ExampleTemplate()=default;
    void setMember(const T& memberP);
    T getMember()const;

private:
    T member;

};

template <typename T>
ExampleTemplate<T>::ExampleTemplate(T memberP):member(memberP)
{
    std::cout << "Example Template class Created" << endl;
}

template <typename T>
void ExampleTemplate<T>::setMember(const T& memberP)
{
    this->member = memberP;
}

template <typename T>
T ExampleTemplate<T>::getMember()const
{
    return this->member;
}




