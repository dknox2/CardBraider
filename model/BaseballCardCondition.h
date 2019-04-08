#ifndef BASEBALLCARDCONDITION_H
#define BASEBALLCARDCONDITION_H

#include <ostream>

using namespace std;

namespace model
{
/// Enumerated type representing the condition of a baseball card.
enum class BaseballCardCondition
{
    /// Poor condition
    POOR,

    /// Good condition
    GOOD,

    /// Excellent condition
    EXCELLENT,

    /// Mint condition
    MINT,

    /// Pristine condition
    PRISTINE,

    /// Unknown condition
    UNKNOWN
};

/// Overload the stream insertion operator to allow for variants of the
/// BaseballCardCondition enum to be used in stream insertion.
///
/// @see ostream::operator<<
ostream& operator<<(ostream& stream, const BaseballCardCondition condition);

}

#endif // BASEBALLCARDCONDITION_H
