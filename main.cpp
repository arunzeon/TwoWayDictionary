#include <iostream>
#include<vector>
#include<memory>
#include<map>
#include "Common.h"
#include "FDataBase.h"
#include "FDataBase.cpp"
#include "IPerson.h"


int main()
{
    try
    {

       // need to have more eligaent way to do this
        DataBase *db = DataBase::GetDataBase();
        // Load the dictionary
        LoadData ld(db);

        db->Query();

        db->ResetDataBase();
    }catch(...)
    {
        msg(" Something went wrong");
    }

    return 0;
}

