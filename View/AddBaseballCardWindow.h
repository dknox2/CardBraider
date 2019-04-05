#ifndef ADDBASEBALLCARDWINDOW_H
#define ADDBASEBALLCARDWINDOW_H

#include <Fl/Fl_Input.H>

#include "BaseballCard.h"

#include "OKCancelWindow.h"

using namespace model;


namespace view
{

/// Defines the window where the user can enter the player's name, year, condition, and price of a baseball card.
class AddBaseballCardWindow : public OKCancelWindow
{
    Fl_Input* firstNameInput;
    Fl_Input* lastNameInput;
    Fl_Input* yearInput;
    Fl_Input* conditionInput;
    Fl_Input* priceInput;

    BaseballCard* pCard;

    BaseballCardCondition determineAndSetConditionBasedOnUserInput();
    int determineAndSetYearBasedOnUserInput();
    int determineAndSetPriceBasedOnUserInput();

public:

    /// Constructs an add card window creating and initializing all the widgets that will be displayed
    ///
    /// @pre none
    /// @post none
    AddBaseballCardWindow();

    /// Destructor that cleans up all allocated resources for the window
    virtual ~AddBaseballCardWindow();

    /// The instance handler when OK is invoked
    ///
    /// @pre none
    /// @post getCard() == baseball card object created from data user entered
    void okHandler();

    /// The instance handler when cancel is invoked
    ///
    /// @pre none
    /// @post getCard() == 0
    void cancelHandler();

    /// Gets the new baseball card object based on what user entered
    ///
    /// @pre none
    /// @post none
    ///
    /// @return The baseball card object
    BaseballCard* getCard() const;
};

}

#endif // ADDBASEBALLCARDWINDOW_H
