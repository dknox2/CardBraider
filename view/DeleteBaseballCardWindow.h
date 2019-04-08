#ifndef DELETEBASEBALLCARDWINDOW_H
#define DELETEBASEBALLCARDWINDOW_H

#include "OKCancelWindow.h"

#include <Fl/Fl_Input.H>

#include <string>
using namespace std;

namespace view
{

/// Defines the window where the user can enter the last name of a player card
class DeleteBaseballCardWindow : public OKCancelWindow
{
private:
    Fl_Input* lastNameInput;
    string lastName;

public:

    /// Constructs a delete card window creating and initializing all the widgets that will be displayed
    ///
    /// @pre none
    /// @post none
    DeleteBaseballCardWindow();

    /// Destructor that cleans up all allocated resources for the window
    virtual ~DeleteBaseballCardWindow();

    /// The instance handler when OK is invoked
    ///
    /// @pre none
    /// @post getLastName() == name user entered
    void okHandler();

    /// The instance handler when Cancel is invoked
    ///
    /// @pre none
    /// @post getLastName() == ""
    void cancelHandler();

    /// Gets the last name entered
    ///
    /// @pre none
    /// @post none
    ///
    /// @return The last name entered
    const string getLastName() const;
};

}

#endif // DELETEBASEBALLCARDWINDOW_H
