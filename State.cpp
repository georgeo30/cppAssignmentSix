#include "State.h"

namespace THNGEO002
{
    State::State(std::string name):name(name)
    {
        value = 0;
        newVal=0;
    }
    void State::setValue(double value)
    {
        this->value = value;
    }
    double State::getValue() const
    {
        return value;
    }
    std::string State::getName() const
    {
        return name;
    }
    void State::setNewValue(double newValue)
    {
        this->newVal = newValue;
    }
    double State::getNewValue() const
    {
        return newVal;
    }
    void State::assignNeighbours(State * neighbour, double reward)
    {
        neighbours.push_back(neighbour);
        rewards.push_back(reward);

    }
} // namespace THNGEO002