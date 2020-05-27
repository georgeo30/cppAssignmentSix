#ifndef _STATE_H
#define _STATE_H
#include <string>
#include <vector>

namespace THNGEO002
{

    class State
    {
    private:
        double value;
        double newVal;
        const std::string name;

    public:
        std::vector<State *> neighbours;
        std::vector<double> rewards;
        State(std::string name); //constructor for the state class

        void setValue(double value);                           //setting the value for the state
        double getValue() const;                               //return the value opf the state
        void setNewValue(double value);                           //setting the value for the state
        double getNewValue() const;                               //return the value opf the state
        std::string getName() const; 
        void assignNeighbours(State * neighbour, double reward); //assigning the neighbours and its reward for a particular state in an unordered map
    };
} // namespace THNGEO002
#endif