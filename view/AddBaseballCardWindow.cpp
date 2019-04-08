#include "AddBaseballCardWindow.h"

#include <sstream>

#include <Fl/fl_ask.H>

#include "Utils.h"


using namespace std;

namespace view
{

AddBaseballCardWindow::AddBaseballCardWindow() : OKCancelWindow(330, 215, "Card to add")
{
    const int X_INPUT_LOCATION = 110;

    this->pCard = 0;

    begin();

    this->firstNameInput = new Fl_Input(X_INPUT_LOCATION, 15, 200, 25, "First name:");
    this->lastNameInput = new Fl_Input(X_INPUT_LOCATION, 45, 200, 25, "Last name:");
    this->yearInput = new Fl_Input(X_INPUT_LOCATION, 75, 60, 25, "Year:");
    this->conditionInput = new Fl_Input(X_INPUT_LOCATION, 105, 60, 25, "Condition:");
    this->priceInput = new Fl_Input(X_INPUT_LOCATION, 135, 60, 25, "Price:");

    this->setOKLocation(90, 170);
    this->setCancelLocation(170, 170);

    end();
}

void AddBaseballCardWindow::okHandler()
{
    string firstName = this->firstNameInput->value();
    string lastName = this->lastNameInput->value();

    BaseballCardCondition cardCondition = this->determineAndSetConditionBasedOnUserInput();

    try
    {
        int year = this->determineAndSetYearBasedOnUserInput();
        int price = this->determineAndSetPriceBasedOnUserInput();
        this->pCard = new BaseballCard(firstName, lastName, year, cardCondition, price);
        this->hide();
    }
    catch (const char* message)
    {
        fl_message("%s", message);
    }


}

BaseballCardCondition AddBaseballCardWindow::determineAndSetConditionBasedOnUserInput()
{
    string condition = this->conditionInput->value();
    condition = toUpperCase(condition);

    BaseballCardCondition cardCondition = BaseballCardCondition::UNKNOWN;

    if (condition == ENUM_TO_STR(POOR))
    {
        cardCondition = BaseballCardCondition::POOR;
    }
    else if (condition == ENUM_TO_STR(GOOD))
    {
        cardCondition = BaseballCardCondition::GOOD;
    }
    else if (condition == ENUM_TO_STR(EXCELLENT))
    {
        cardCondition = BaseballCardCondition::EXCELLENT;
    }
    else if (condition == ENUM_TO_STR(MINT))
    {
        cardCondition = BaseballCardCondition::MINT;
    }
    else if (condition == ENUM_TO_STR(PRISTINE))
    {
        cardCondition = BaseballCardCondition::PRISTINE;
    }

    return cardCondition;
}

int AddBaseballCardWindow::determineAndSetYearBasedOnUserInput()
{
    string yearStr = this->yearInput->value();
    int year = toInt(yearStr, "Error converting year to an integer.");
    return year;
}


int AddBaseballCardWindow::determineAndSetPriceBasedOnUserInput()
{
    string priceStr = this->priceInput->value();
    int price = toInt(priceStr, "Error converting price to an integer.");
    return price;
}

void AddBaseballCardWindow::cancelHandler()
{
    if (this->pCard)
    {
        delete pCard;
    }

    this->pCard = 0;
    this->hide();
}

BaseballCard* AddBaseballCardWindow::getCard() const
{
    return this->pCard;
}

AddBaseballCardWindow::~AddBaseballCardWindow()
{
    delete this->firstNameInput;
    delete this->lastNameInput;
    delete this->yearInput;
    delete this->conditionInput;
    delete this->priceInput;
}

}
