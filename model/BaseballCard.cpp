#include "BaseballCard.h"

namespace model
{
//
// NOT documented as this class should be replaced by your own BaseballCard class
//
BaseballCard::BaseballCard(const string& firstName, const string& lastName, int year, BaseballCardCondition condition, int price) :
    firstName(firstName),
    lastName(lastName),
    year(year),
    condition(condition),
    price(price)
{
}

const string& BaseballCard::getFirstName() const
{
    return this->firstName;
}

const string& BaseballCard::getLastName() const
{
    return this->lastName;
}

BaseballCardCondition BaseballCard::getCondition() const
{
    return this->condition;
}

int BaseballCard::getYear() const
{
    return this->year;
}

int BaseballCard::getPrice() const
{
    return this->price;
}

BaseballCard::~BaseballCard()
{
    //dtor
}

}
