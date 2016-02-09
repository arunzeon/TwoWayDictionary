#ifndef FDATABASE_H_INCLUDED
#define FDATABASE_H_INCLUDED

#include "Common.h"
#include "IPerson.h"
#include "IPerson.cpp"
// Lets have only ine instance of storage management
// So lets make it singleton Class.
class DataBase
{
    MyMap NameContain;
    MyMap PhoneContain;
private:
    ~DataBase();
	DataBase();
   	DataBase(const DataBase&);
	DataBase& operator=(const DataBase&);
public:
    static DataBase *instance;
	static DataBase *GetDataBase();
	static DataBase *ResetDataBase();

    friend class Display;
public:
    // Query API to the Client loading of dictionary
    void updateQ1(string pkey, MyPtr obj);
    void updateQ2(string pkey, MyPtr obj);
    void Query();
    void Display(); // could be other class taking db and achieve how it wants to display it
private:
    // the data if all in lower case .. search would be better.
    inline void convert(string &src)
    {
        transform(src.begin(), src.end(), src.begin(), ::tolower);
    }
};


// Could make LoadData as freind of Database.. or the datatype from here
class LoadData
{
    public:
           LoadData(DataBase *&db);
           LoadData();
};

PTYPE
GetType(string &src)
{
    transform(src.begin(), src.end(),src.begin(),::tolower);
    ptypelookup epyt
    {
        {"home", HOME},
        {"office", OFFICE},
        {"personal", PERSONAL}
    };

    ptypelookup::iterator itr = epyt.find(src);
    if(itr != epyt.end())
        return itr->second;
    return END_NUM;
}

static inline
bool
checkdigit(char c)
{
    return isalpha(c);

}
bool
stringisvalidnumber(string &src)
{

    return find_if(src.begin(), src.end(), checkdigit) == src.end();
}
#endif // FDATABASE_H_INCLUDED
