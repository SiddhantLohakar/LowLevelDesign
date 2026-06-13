#include<iostream>

using namespace std;


class Talkable
{
    public:
    virtual void talk() = 0;
};

class NormalTalkable : public Talkable
{
    public:
    void talk()
    {
        cout<<"Normally Talking..."<<endl;
    }
};

class NonTalkable : public Talkable
{
    public: 
    void talk()
    {
        cout<<"This robot can't talk"<<endl;
    }
};





class Walkable
{
    public:
    virtual void walk() = 0;
};

class NormalWalkable : public Walkable
{
    public:
    void walk()
    {
        cout<<"Normally Walking..."<<endl;
    }
};

class NonWalk : public Walkable
{
    public:
    void walk()
    {
        cout<<"This robot can't talk"<<endl;
    }
};



class Flyable
{
    public:
    virtual void fly() = 0;
};

class NormalFly : public Flyable
{
    public:
    void fly()
    {
        cout<<"Normally flying..."<<endl;            
    }
};

class NonFly : public Flyable
{
    public:
    void fly()
    {
        cout<<"This robot can't fly"<<endl;
    }
};


class Robot
{

    private:
        
        Walkable *W;
        Flyable *F;
        Talkable *T;

    public:

        Robot(Walkable *W, Flyable *F, Talkable *T)
        {
            this->W = W;
            this->F = F;
            this->T = T;
        }

        void walk()
        {
            W->walk();
        }

        void fly()
        {
            F->fly();
        }

        void talk()
        {
            T->talk();
        }
};





int main(){

    Robot *R1 = new Robot(new NormalWalkable(), new NormalFly(), new NonTalkable());
    R1->fly();
    R1->talk();
    R1->walk();
    
}