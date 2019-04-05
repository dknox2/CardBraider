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
    ///
    /// @pre none
    /// @post getFirstName() == firstName && getLastName() == lastName() && getYear() == year && getCondition() == condition && getPrice() == price
    BaseballCard(const string& firstName, const string& lastName, int year, BaseballCardCondition condition, int price);

    /// Default destructor for the BaseballCard class.
    virtual ~BaseballCard();

    /// Returns the first name of the player depicted on the baseball card.
    ///
    /// @pre none
    /// @post none
    ///
    /// @return the first name of the player
    const string& getFirstName() const;

    /// Returns the last name of the player depicted on the baseball card.
    ///
    /// @pre none
    /// @post none
    ///
    /// @return the last name of the player
    const string& getLastName() const;

    /// Returns the physical condition of the baseball card.
    ///
    /// @pre none
    /// @post none
    ///
    /// @return the condition of the baseball card
    BaseballCardCondition getCondition() const;

    /// Returns the year the card was printed.
    ///
    /// @pre none
    /// @post none
    ///
    /// @return the year the card was printed
    int getYear() const;

    /// Returns the price of the card, rounded to the nearest whole number price.
    ///
    /// @pre none
    /// @post none
    ///
    /// @return the price of the card
    int getPrice() const;
};

}

#endif // BASEBALLCARD_H
