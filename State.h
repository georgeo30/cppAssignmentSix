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

    public:
        std::vector<State> neighbours;
        State();                                //constructor for the state class
        void setValue(double value);            //setting the value for the state
        double getValue() const;                //return the value opf the state
        void assignNeighbours(State neighbour); //assigning the neighbours for a particular state
    };
} // namespace THNGEO002
#endif