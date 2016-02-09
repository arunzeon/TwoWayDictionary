#include "Common.h"


    void
    EPerson::You()
    {
        if(0)cout << " EPerson derived " << valOfDerived << endl;
        cout << endl;
        cout << " ----------------------------------------" << endl;
        cout << " Name: " << name                           << endl;
        cout << " Phone Details : "                       << endl;
        // lets have it sorted for faster access
        sort(PhoneSet.begin(),PhoneSet.end());
        for(PhoneDetails::const_iterator itr = PhoneSet.begin();
            itr != PhoneSet.end();
            itr++)
            {
                cout << "  Phone: " << itr->first;
                cout << "  Type : ";
                switch(itr->second)
                {
                case 0:
                        cout << " HOME";
                        break;
                case 1:
                        cout << " OFFICE";
                        break;
                case 2:
                        cout << " PERSONAL";
                        break;
                default :
                        cout << " UnSpecified" ;
                }
                cout << endl;
            }
        //vector<myPhone> PhoneDetails;
    }

    // to load inital ..data set..say form file..
    // but right now ..lets load manually for correctness
    void
    EPerson::loaddata(string &n, myPhone &pdetail)
    {
    }

    void
    EPerson::setName(string n)
    {
        convert(n);
        name = n;
    }

    void
    EPerson::setPhones(const myPhone &p)
    {
        PhoneSet.push_back(p);
    }

    EPerson&
    EPerson::operator=(const EPerson& rhs){
        msg(" EPERSON Assignment");
        Person::operator=(rhs);
        return *this;
    }

    EPerson::EPerson(int v):valOfDerived(v)
    {
        msg(" EPerson Con");
    }

    EPerson::EPerson(){
    }

    // for specific derived operation ..if needed..lets c
    int
    EPerson::What()
    {
            return valOfDerived;
    }

    EPerson::~EPerson()
    {
        msg(" EPerson Des");
    }

