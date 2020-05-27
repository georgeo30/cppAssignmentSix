#include "State.h"
#include <string>
#include <iostream>


int main(int argc, char *argv[])
{
    const double dReward=0.8;
    THNGEO002::State s1,s2,s3,s4,s5,s6;
    //s1 neighbours and rewards
    s1.assignNeighbours(s2,0);
    s1.assignNeighbours(s4,0);
    //s2 neighbours and rewards
    s2.assignNeighbours(s1,0);
    s2.assignNeighbours(s5,0);
    s2.assignNeighbours(s3,50);
    //s4 neighbours and rewards
    s4.assignNeighbours(s1,0);
    s4.assignNeighbours(s5,0);
    //s5 neighbour and rewards
    s5.assignNeighbours(s4,0);
    s5.assignNeighbours(s2,0);
    s5.assignNeighbours(s6,0);
    //s6 neighbours and rewards
    s6.assignNeighbours(s5,0);
    s6.assignNeighbours(s3,100);
    
    
    
    


}