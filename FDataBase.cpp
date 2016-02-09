#include "FDataBase.h"
#include "Common.h"

DataBase* DataBase::instance = NULL;

DataBase::DataBase()
{
    msg(" DataBase initalizing...");
}

DataBase::~DataBase()
{
    msg(" Data Uninitalizing....");
}

DataBase* DataBase::ResetDataBase()
{
	delete instance;
	instance = NULL;
	return instance;
}



class CustomDeleter{
public:
      void operator()(Person * p) {
            msgm(" In Custom Deleter");
          delete p;
      }
};

inline MyPtr make_sharedObj(Person* obj)
{
    msgm(" In Make_Shared object");
    return MyPtr(obj, CustomDeleter());
}


void
DataBase::updateQ1(string pkey,MyPtr obj)
{
    convert(pkey);
    if(MDEBUG)cout << " Inserting the contents NameContain:======" << pkey <<  endl;
    NameContain.insert(make_pair(pkey,obj));

}

// having function just to keep it clean
void
DataBase::updateQ2(string pkey,MyPtr obj)
{
    convert(pkey);
    if(MDEBUG)cout << " Inserting the contents Phone--Contain" << endl;
    PhoneContain.insert(make_pair(pkey,obj));

}

void
DataBase::Query()
{
    string input="";
    cout << endl << endl << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "  Search based upon << NAME >> or << phone number >>    " << endl;
    cout << "  Type  <<<QUIT  >>> to Exit                            " << endl;
    cout << "  Type  <<<INSERT >>> to add record                     " << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << endl << endl;
    while(input != "quit")
    {
        cout << "   Search: ";
        cin >> input;
        convert(input);
        string tmp = input;
        if(input == "insert")
        {
                int np=0;
                string iname="";
                cout << " Enter Name:";
                cin >> iname;
                convert(iname);

                cout << " Enter number of Phone numbers:";
                cin >> np;
                if((np <= 0) || (np > 10))
                {
                    msg(" Too large Invalid Entry..please try smaller");
                }
                else{
                    auto obj = make_sharedObj(new EPerson);
                    obj->setName(iname); //setPhones
                    updateQ1(iname,obj);

                    string rp,rt;
                    for(int index=0; index < np; index++)
                    {
                        cout << " Enter Phone Number and Type:";
                        cin >> rp >> rt;
                        obj->setPhones(make_pair(rp,GetType(rt)));
                        updateQ2(rp,obj);
                    }
                    cout << " AFTER:::" << endl;
                    Display();
                }

        }else
        {
            bool flag = true;
            ITR_MyxMap Itr= NameContain.equal_range(input);
            cout << endl;
            cout << " For the key word: " << tmp;
            //   cout << " ------------------------- " << endl;
            for(ITRMyx it= Itr.first; it!= Itr.second; it++)
            {
                // Works liek this too with friend cout << it->second; //need to to refine
                it->second->You();
                //cout << " Cnt:" << it->second.use_count() << endl;
                cout << endl;
                flag = false;
            }


            if(flag)
            {

                Itr= PhoneContain.equal_range(input);
                for(ITRMyx it= Itr.first; it!= Itr.second; it++)
                {
                    // Works liek this too with friend cout << it->second; //need to to refine
                    it->second->You();
                    cout << endl;
                    //cout << " Cnt:" << it->second.use_count() << endl;
                }
            }
            cout << endl;
        }
    }
}

void
DataBase::Display()
{

    vector<string> defaultrecords;
    /*
        defaultrecords.push_back("one");
        defaultrecords.push_back("two");
    */
     for(MyMap::const_iterator ct=NameContain.begin();
         ct != NameContain.end();
         ct++)
         defaultrecords.push_back((*ct).first);
    cout << "  DB Records Present:" << endl;
    for(vector<string>::const_iterator rcd=defaultrecords.begin();
        rcd != defaultrecords.end();
        rcd++)
    {

      ITR_MyxMap nt= NameContain.equal_range((*rcd));
        for(ITRMyx it= nt.first; it!= nt.second; it++){
                //if(DEBUG)cout << it->first << " --> ";
                // Works liek this too with friend cout << it->second; //need to to refine
                it->second->You();
                //if(!DEBUG)
                //    cout << " Cnt:" << it->second.use_count() << endl;

                // this is not required for this use case
                // Trying to trigger derived class function to determine the type..
                // EPerson *check = dynamic_cast<EPerson *>(it->second);
                //  if(check != NULL)
                //     cout << " Its Dervied....." << endl;
                cout << endl;
        }
    }

}


DataBase* DataBase::GetDataBase()
{
        if(!instance)
            instance = new DataBase;
        return DataBase::instance;

    // lets keep it simple for now
    //	static DataBase instancev1;
    //return instancev1;
}

LoadData::LoadData(){}

// lets have reference to pointer .. and manipulate the stuff
/*
    //vector of phone and type
    //as stuff in object
    phone type, phone type ===> [[ name, --> vector<pairs> ==> vector<string, type> (phone's and types) ]]
    vector<BasicInfo> ==> BasicInfo==> pair<phone type>
    thus vector<pair<phone,type> > == ALL
    objptr=8888888888=> name, ALL
    name --objprt
    phone -- objptr
*/
LoadData::LoadData(DataBase *&db)
{
    msg(" I am in LoadData:");
    auto _obj = make_sharedObj(new EPerson);
    _obj->setName("One"); //setPhones
    // Test case without phone numbers and type ok.
    _obj->setPhones(make_pair("12345",HOME));
    _obj->setPhones(make_pair("23456",OFFICE));

    db->updateQ1("One",_obj);
    db->updateQ2("12345",_obj);
    db->updateQ2("23456",_obj);


    _obj = make_sharedObj(new EPerson);
    _obj->setName("Two");
    _obj->setPhones(make_pair("345678",HOME));
    _obj->setPhones(make_pair("456789",OFFICE));
    db->updateQ1("Two",_obj);
    db->updateQ2("345678",_obj);
    db->updateQ2("456789",_obj);

    // Test case with duplicate names..
    _obj = make_sharedObj(new EPerson);
    _obj->setName("One");
    _obj->setPhones(make_pair("111111",HOME));
    _obj->setPhones(make_pair("222222",OFFICE));
    db->updateQ1("One",_obj);
    db->updateQ2("111111",_obj);
    db->updateQ2("222222",_obj);

    // Check the data set..
    if(DEBUG)db->Display();


}

