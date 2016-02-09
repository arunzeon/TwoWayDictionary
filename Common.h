#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include<vector>
#include<memory>
#include<map>
#include<algorithm>
#include<typeinfo>

using namespace std;

typedef enum{
    HOME = 0,
    OFFICE,
    PERSONAL,
    END_NUM = PERSONAL
}PTYPE;

typedef map<string, PTYPE> ptypelookup;

typedef pair<string, PTYPE> myPhone;
typedef vector<myPhone> PhoneDetails;

#define DEBUG 1
#define MDEBUG 0
#define msg(x) \
    {   \
      if(DEBUG)std::cout << " MSG:" << x << std::endl; \
    } \

#define msgm(x) \
    {   \
      if(MDEBUG)std::cout << " MSG:" << x << std::endl; \
    } \

#define loop(c, it) \
    for(typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
// Forward declare
class Person;

typedef Person* OBJPTR;


//typedef unordered_map<string, shared_ptr<Person> > Myunmap;
typedef shared_ptr<Person> MyPtr;
typedef multimap<string, shared_ptr<Person> > Mymmap;
typedef multimap<string, shared_ptr<Person> > Myunmap;
typedef multimap<string, MyPtr> MyMap;
typedef multimap<string, MyPtr>::iterator ITRMyx;
typedef pair<MyMap::iterator, MyMap::iterator> ITR_MyxMap;



#endif // COMMON_H_INCLUDED
