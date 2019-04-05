#ifndef UTILS_H
#define UTILS_H

#include <string>
using namespace std;

#define ENUM_TO_STR(ENUM) std::string(#ENUM)

/// Converts and returns string in uppercase
///
/// @pre none
/// @post none
///
/// @param text the text to convert to upper case
///
/// @return Uppercase version of the string
const string toUpperCase(string text);

/// Converts passed in string to an int
///
/// @param text text to convert to an int
/// @param errorMessage message thrown if a problem occurs when converting text to an int
///
/// @pre none
/// @post none
///
/// @throw Exception if text cannot be converted to an int
///
/// @return text converted to an int
int toInt(const string& text, const char* errorMessage);

#endif // UTILS_H
