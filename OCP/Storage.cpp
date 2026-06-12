#include<iostream>

using namespace std;

class Persistence{
    
    public:
    virtual void save() = 0;

};


class MongoDBPersistence: public Persistence{
    public:

    void save() override{
        cout<<"Saving to MongoDB"<<endl;
    }
};

class SQLPersistence: public Persistence {
    
    public:
    
    void save() override{
        cout<<"Saving to SQL DB"<<endl;
    }
};

class Client{

    private:
    Persistence *p;

    public:
    Client(Persistence *p){
        this->p = p;
    }

    void saveData(){
        p->save();
    }
};

int main(){
    
    Persistence *P1 = new MongoDBPersistence();
    Persistence *P2 = new SQLPersistence();

    Client *C1 = new Client(P1);
    C1->saveData();
    
}