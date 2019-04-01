#include "BaseballCardCondition.h"

namespace model
{
ostream& operator<<(ostream& stream, const BaseballCardCondition condition)
{
    switch (condition)
    {
    case BaseballCardCondition::POOR:
        return stream << "Poor";
    case BaseballCardCondition::GOOD:
        return stream << "Good";
    case BaseballCardCondition::EXCELLENT:
        return stream << "Excellent";
    case BaseballCardCondition::MINT:
        return stream << "Mint";
    case BaseballCardCondition::PRISTINE:
        return stream << "Pristine";
    case BaseballCardCondition::UNKNOWN:
        return stream << "Unknown";
    }
}
}
