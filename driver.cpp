#include "State.h"
#include <string>
#include <iostream>


int main(int argc, char *argv[])
{
    
    const double dReward=0.8;
    THNGEO002::State s1,s2,s3,s4,s5,s6;
    //s1 neighbours and rewards
    s1.assignNeighbours(&s2,0);
    s1.assignNeighbours(&s4,0);
    //s2 neighbours and rewards
    s2.assignNeighbours(&s1,0);
    s2.assignNeighbours(&s5,0);
    s2.assignNeighbours(&s3,50);
    //s4 neighbours and rewards
    s4.assignNeighbours(&s1,0);
    s4.assignNeighbours(&s5,0);
    //s5 neighbour and rewards
    s5.assignNeighbours(&s4,0);
    s5.assignNeighbours(&s2,0);
    s5.assignNeighbours(&s6,0);
    //s6 neighbours and rewards
    s6.assignNeighbours(&s5,0);
    s6.assignNeighbours(&s3,100);
    
    //Putting all the states in a vector to loop easier
    std::vector<  THNGEO002::State *> states;
    states.push_back(&s1);
    states.push_back(&s2);
    states.push_back(&s3);
    states.push_back(&s4);
    states.push_back(&s5);
    states.push_back(&s6);

    //For each state calculate its (max) value
    for (int i = 0; i < states.size(); i++)
    {
        double stateValue=states[i]->getValue();
        std::cout<<"Initial state val for  "<<i<<" is "<<stateValue<<std::endl;

        for (int j = 0; j < states[i]->neighbours.size(); j++)
        {   
            double rwrd=states[i]->rewards[j];
            std::cout<<"Rewards from state "<<i<<" to state "<<j<<" is "<<rwrd<<std::endl;
            double optVal=dReward*(states[i]->neighbours[j]->getValue());
            std::cout<<"optimal value of state "<<j<<" is "<<optVal<<std::endl;

            double cVal=rwrd+optVal;
            if (cVal>stateValue)
            {
                stateValue=cVal;
            }
            
        }
        std::cout<<"new state vaalue  for state "<<i<<" is "<<stateValue<<std::endl;

        states[i]->setValue(stateValue);
        std::cout<<"================================"<<std::endl;

    }


    
    for (int i = 0; i < states.size(); i++)
    {
        std::cout<<states[i]->getValue()<<std::endl;
    }
    
    // std::cout<<states[0]->neighbours[0]->getValue()<<std::endl;
    //     std::cout<<states[1]->getValue()<<std::endl;

    // std::cout<<(&states[0]->neighbours[0]==&states[1])<<std::endl;
    


}