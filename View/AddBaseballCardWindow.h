#ifndef ADDBASEBALLCARDWINDOW_H
#define ADDBASEBALLCARDWINDOW_H

#include <Fl/Fl_Input.H>

#include "BaseballCard.h"

#include "OKCancelWindow.h"

using namespace model;


namespace view
{

//
// Defines the window where the user can enter the player's name, year, condition, and price of a baseball card.
//
class AddBaseballCardWindow : public OKCancelWindow
{
private:
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
    AddBaseballCardWindow();
    virtual ~AddBaseballCardWindow();

    void okHandler();
    void cancelHandler();

    BaseballCard* getCard() const;
};

}

#endif // ADDBASEBALLCARDWINDOW_H
