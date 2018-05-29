//#include "main.h"
#include <iostream>

using namespace std;

class FlyBehavior{
public:
    void fly(){}
};

class FlyRocket: public FlyBehavior{
public:
    /*
    void fly(){
        cout << "I'm flying with a rocket!" << endl;
    }*/
};

/*
class FlyWithWings: public FlyBehavior{
public:
    void fly() override{
        cout << "fly~~~~~~~~duck wing" <<endl;
    }
};

class NoFly: public FlyBehavior{
public:
    void fly()override{
        cout << "I can't fly!" <<endl;
    }
};
*/
/*
///////////////////////////////////////////////////
class QuackBehavior{
public:
    void quack();
};
///////////////////////////////////////////////////

class Duck{
public:
    FlyBehavior* flyBehavior;
    QuackBehavior* quackBehavior;


    void performFly(){
        flyBehavior->fly();
    }
    void performQuack(){
        quackBehavior->quack();
    }
    void setFly(FlyBehavior* fb){
        flyBehavior = fb;
    }
    void setQuack(QuackBehavior* qb){
        quackBehavior = qb;
    }
    void swim(){
    }
    void display(){
    }
};

class MallardDuck: public Duck
{
public:
    MallardDuck(){
        flyBehavior = new FlyWithWings();
        //quackBehavior = new
    }
};

class ModelDuck: public Duck
{
public:
    ModelDuck(){
        flyBehavior = new NoFly();
    };
};
//////////////////////////////////////////////////
*/
extern int cnt;
int main()
{
    /*
    MallardDuck* miniDuck = new MallardDuck();
    miniDuck->performFly();

    ModelDuck* modelDuck = new ModelDuck();
    modelDuck->performFly();
    */
    //modelDuck->setFly(new FlyRocket());//false
    //FlyBehavior fb;
    //fb.fly();
    FlyRocket fr;//true
    fr.fly();
    /*
    FlyBehavior* p_fb;
    p_fb = new FlyRocket();//false


    FlyRocket* p_fr = new FlyRocket();
    p_fr->fly();
    */
    //cnt++;
    cout << cnt;
    return 0;
}
