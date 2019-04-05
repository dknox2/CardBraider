#ifndef OKCANCELWINDOW_H
#define OKCANCELWINDOW_H

#include <Fl/Fl_Window.H>
#include <Fl/Fl_Button.H>

namespace view
{

/// Abstract class that can be used for any window that needs Ok and Cancel buttons on it.
class OKCancelWindow : public Fl_Window
{
public:

    /// Represents how the window was closed.
    enum WindowResult {OK, CANCEL, NONE};

private:
    Fl_Button* okButton;
    Fl_Button* cancelButton;

    WindowResult buttonInvoked;

public:

    /// Constructs a ok/cancel window creating and initializing all the widgets taht will be displayed
    ///
    /// @param width The width of the window
    /// @param height The height of the window
    /// @param title The title to display for the window
    ///
    /// @pre width > 0 AND height > 0
    /// @post none
    OKCancelWindow(int width, int height, const char* title);

    /// Destructor that cleans up all allocated resources for the window
    virtual ~OKCancelWindow();

    /// Sets the (x,y) location of the OK button
    ///
    /// @pre none
    /// @post none
    void setOKLocation(int x, int y);

    /// Sets the (x,y) location of the Cancel button
    ///
    /// @pre none
    /// @post none
    void setCancelLocation(int x, int y);

    /// The handler when OK is invoked
    ///
    /// @pre widget != 0 AND data != 0
    /// @post getWindowResult() == OKCancelWindow::OK
    static void cbOk(Fl_Widget* widget, void* data);

    virtual void okHandler() = 0;

    /// The handler when Cancel is invoked
    ///
    /// @pre widget != 0 AND data != 0
    /// @post getWindowResult() == OKCancelWindow::CANCEL
    static void cbCancel(Fl_Widget* widget, void* data);

    virtual void cancelHandler() = 0;

    /// Sets the WindowResult which indicates how the window was closed via OK or Cancel button or X'd out.
    ///
    /// @param result The window result
    ///
    /// @pre none
    /// @post getWindowResult() == result
    OKCancelWindow::WindowResult setWindowResult(OKCancelWindow::WindowResult result);

    /// Gets the sort window result which indicates how the window was closed via OK or Cancel button or X'd out.
    ///
    /// @pre none
    /// @post none
    ///
    /// @return The window result of how the window was closed
    OKCancelWindow::WindowResult getWindowResult();
};

}

#endif // OKCANCELWINDOW_H
