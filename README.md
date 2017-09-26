# TwoWayDictionary
Two way dictionary without bimap 
Desing considerations:-
------------------------------------

* considered the hash function for the name and phone and point to the object of the class of interest.
	vector of hash for name [ -----------------]
				|
				v
				OBJ
				^
				|
	vector of hash for phone[-------------------]

  but need to have good hash function, 
	if new element needs to be updated , need to take care of collision 

*
  Better soultion could have been to have binary tree of name and binary tree for phone number
	and pointer pointing/referencering to each other
	reduced space
	improve run time..
	but currently my complier does not support.
	()<--------------->()
	/\	    /  \	
	()  ()<----------/---->()
	^	/
	|------------>	()

* Could have been better to use boost::bimap  or multi index , but 
  have problem with  my complier..

* two multip map with just name and phone could be have easy, however since there way type of phone.
  indicated that person class is likely to have more details than this. hence needed better solution.

Implemented:-
* Equaivalently better to have to two multimap , one for name and phone
  and pointer to common object.
  insertion of object is easy..
  since multimap , supports duplicate key's 
  run time in worst case of O(log(2*n))
  
  The dictionary would be single store, hence there was need for singleton class name FDataBase
  The person class could have additional detials such as address , passport numnber etc.. hence created 
     made if polymorphic with use of IPerson abstract class..and EPerson as specifilized class.
  since two multimap reference to same class object tried to do with shared_ptr. and created simple factory to provide object.
 since shared_ptr is used it'smostly exception safe.

NOTE:-
* Executable name is "Gppl"
* The inital dictionary data is loaded statically , 
* Have exectued simple test case for correctness of functionality 

* Had to swithc to " code block IDE 13.12 Version "for implementation. 
  on windows.
  
* to turn DEBUG, set DEBUG 1 in Common.h

* Result of  the porgam is provided as snapshot.
    

