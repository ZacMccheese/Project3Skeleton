#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.cpp

#include "GraphObject.h"

class Actor : public GraphObject
{
    
public:
    Actor(int imageID, int startX, int startY, StudentWorld *sw, Direction dir = right, int depth = 0) : GraphObject(imageID, startX, startY, dir, depth), m_sw(sw), m_actions(0), m_isAlive(true)
    {
    };
    
    virtual ~Actor(){};
    
    //Called every tick
    virtual void doSomething()
    {
        m_actions++;
    };
    
    //Called when actor is bitten, poisoned or stunned
    virtual void getHurt(int damageType, int damage) = 0;
    
    //Idetifying object
    virtual bool blocksInsect() = 0;
    virtual bool isInsect() = 0;
    virtual bool isDamagingObject() = 0;
    
    bool isAlive() const {return m_isAlive;};
    StudentWorld* getStudentWorld(){return m_sw;};

protected:
    virtual void setDead()
    {
        m_isAlive = false;
    }
    
    int getActionsTaken(){return m_actions;};
    bool alreadyMovedThisTurn();
    
    
private:
    bool m_isAlive;
    int m_actions;
    StudentWorld *m_sw;

    
};
