#include "DeleteBaseballCardWindow.h"

#include <iostream>
using namespace std;

namespace view {

DeleteBaseballCardWindow::DeleteBaseballCardWindow() : OKCancelWindow(330, 90, "Card to delete")
{
    begin();

    this->lastNameInput = new Fl_Input(105, 15, 200, 25, "Last name:");
    this->setOKLocation(90, 50);
    this->setCancelLocation(170, 50);

    end();
}

void DeleteBaseballCardWindow::okHandler()
{
    this->lastName = this->lastNameInput->value();
    this->hide();
}

void DeleteBaseballCardWindow::cancelHandler()
{
    this->lastName = "";
    this->hide();
}

const string DeleteBaseballCardWindow::getLastName() const
{
    return this->lastName;
}

DeleteBaseballCardWindow::~DeleteBaseballCardWindow()
{
    delete this->lastNameInput;
}

}
