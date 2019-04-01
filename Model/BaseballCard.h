#ifndef BASEBALLCARD_H
#define BASEBALLCARD_H

#include <string>

#include "BaseballCardCondition.h"

using namespace std;

namespace model
{

/// Models a collectible baseball card, with name, year of printing, condition, and secondary market price.
class BaseballCard
{
    string firstName;
    string lastName;
    int year;
    BaseballCardCondition condition;
    int price;

public:

    /// Constructs a new BaseballCard with the given information.
    ///
    /// @param firstName
    ///             the first name of the player on the card
    /// @param lastName
    ///             the last name of the player on the card
    /// @param year
    ///             the year the card was printed
    /// @param condition
    ///             the condition of the baseball card
    /// @param price
    ///             the price of the card
    BaseballCard(const string& firstName, const string& lastName, int year, BaseballCardCondition condition, int price);

    /// Default destructor for the BaseballCard class.
    virtual ~BaseballCard();

    const string& getFirstName() const;
    const string& getLastName() const;
    BaseballCardCondition getCondition() const;
    int getYear() const;
    int getPrice() const;
};

}

#endif // BASEBALLCARD_H
