#include "State.h"
#include <string>
#include <iostream>

bool converge(std::vector<THNGEO002::State *> s, std::vector<double> prevVals)
{
    for (int i = 0; i < prevVals.size(); i++)
    {
        if(prevVals[i] != s[i]->getValue()){
            return false;
        }
    }
    return true;
    
}

int main(int argc, char *argv[])
{

    const double dReward = 0.8;
    THNGEO002::State s1("s1"), s2("s2"), s3("s3"), s4("s4"), s5("s5"), s6("s6");
    //s1 neighbours and rewards
    s1.assignNeighbours(&s2, 0);
    s1.assignNeighbours(&s4, 0);
    //s2 neighbours and rewards
    s2.assignNeighbours(&s1, 0);
    s2.assignNeighbours(&s5, 0);
    s2.assignNeighbours(&s3, 50);
    //s4 neighbours and rewards
    s4.assignNeighbours(&s1, 0);
    s4.assignNeighbours(&s5, 0);
    //s5 neighbour and rewards
    s5.assignNeighbours(&s4, 0);
    s5.assignNeighbours(&s2, 0);
    s5.assignNeighbours(&s6, 0);
    //s6 neighbours and rewards
    s6.assignNeighbours(&s5, 0);
    s6.assignNeighbours(&s3, 100);

    //Putting all the states in a vector to loop easier
    std::vector<THNGEO002::State *> states = {&s1, &s2, &s3, &s4, &s5, &s6};
    std::vector<double> prevVals={-1,-1,-1,-1,-1,-1};

    bool check = false;
    int count=0;
    while (!check)
    {
        count++;
        for (int st = 0; st < states.size(); st++)
        {
           prevVals[st]=states[st]->getValue();
        }
        


        //For each state calculate its (max) value
        for (int i = 0; i < states.size(); i++)
        {
            double stateValue = states[i]->getValue();
            //std::cout << "Initial state val for  " << i << " is " << stateValue << std::endl;

            for (int j = 0; j < states[i]->neighbours.size(); j++)
            {
                double rwrd = states[i]->rewards[j];
                //std::cout << "Rewards from state " << i << " to state " << j << " is " << rwrd << std::endl;
                double optVal = dReward * (states[i]->neighbours[j]->getValue());
                //std::cout << "optimal value of state " << j << " is " << optVal << std::endl;

                double cVal = rwrd + optVal;
                if (cVal > stateValue)
                {
                    stateValue = cVal;
                }
            }
            //std::cout << "new state vaalue  for state " << i << " is " << stateValue << std::endl;

            states[i]->setNewValue(stateValue);
            //std::cout << "================================" << std::endl;
        }
        for (int i = 0; i < states.size(); i++)
        {
            states[i]->setValue(states[i]->getNewValue());
        }

        check=converge(states,prevVals);
    }



    std::cout<<"Number of iterations to converge: "<<count<<std::endl;

    for (int i = 0; i < states.size(); i++)
    {
        std::cout <<"V*(s"<<i+1<<") = "<< states[i]->getValue() << std::endl;
    }



    //optimal iteration
        std::cout<<std::endl;
    std::cout<<"Optimal Iteration Grid"<<std::endl;
    std::cout<<"This grid shows the action to be taken by the current state to obtain optimal policy"<<std::endl;
    for (int i = 0; i < states.size(); i++)
        {
            double stateValue = 0;
            std::string poop;
            //std::cout << "Initial state val for  " << i << " is " << stateValue << std::endl;

            for (int j = 0; j < states[i]->neighbours.size(); j++)
            {
                 double rwrd = states[i]->rewards[j];
                // //std::cout << "Rewards from state " << i << " to state " << j << " is " << rwrd << std::endl;
                 double optVal = dReward * (states[i]->neighbours[j]->getValue());
                // //std::cout << "optimal value of state " << j << " is " << optVal << std::endl;

                double cVal =  rwrd + optVal;
                if (cVal > stateValue)
                {
                    stateValue = cVal;
                    poop=states[i]->neighbours[j]->getName();
                }
            }
            //std::cout << "new state vaalue  for state " << i << " is " << stateValue << std::endl;

            if (poop=="")
            {
                std::cout << poop<< "end| ";
            }
            else
            {
            std::cout << poop<< " | ";
            }
            
            
            if (i==2)
            {
                std::cout<<std::endl;
            }
            
        }

        std::cout<<std::endl;
}