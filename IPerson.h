#ifndef IPERSON_H_INCLUDED
#define IPERSON_H_INCLUDED

#include "Common.h"

class Person
{
protected:
        string name;
        PhoneDetails PhoneSet;
public:
        virtual void You() = 0;
        virtual ~Person(){
            msgm(" person Des");
        }
        virtual void loaddata(string &n, myPhone &pdetail){
            // Some defauling...
        }
        virtual void setName(string n){}
        virtual void setPhones(const myPhone &p){}
        Person(){
            msgm("Person Con");
        }
         //virtual int What();
        friend ostream& operator << (ostream& os, const Person& instance);
        friend class CustomDeleter;
protected:
       // the data if all in lower case .. search would be better.
        inline void convert(string &src)
        {
            transform(src.begin(), src.end(), src.begin(), ::tolower);
        }

};



// Class to have specialized implementation of person details..
class EPerson:public Person{
    // Could be other details such as address or etc..
    int valOfDerived;
public:
    void You();
    // to load inital ..data set.. but not required now
    virtual void loaddata(string &n, myPhone &pdetail);
    virtual void setName(string n);
    virtual void setPhones(const myPhone &p);
    EPerson& operator=(const EPerson& rhs);
    EPerson(int v);
    EPerson();
    int What();
    ~EPerson();
    friend ostream& operator << (ostream& os, const Person& instance);
};


// could use for display for specific type..
ostream& operator << (ostream& os, const Person& instance)
{
        os << " Display";
        Person *tmp;
        if(tmp == dynamic_cast<const Person*>(&instance))
                cout << " Dis person";
        else
                cout << " Dis EPerson";
        return os;
}



#endif // IPERSON_H_INCLUDED
