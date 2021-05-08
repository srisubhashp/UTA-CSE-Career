// Treat or Tricker class header file template

/* add the necessary includes */

/* add an include guard called _TOT_H */

class TrickOrTreater
{
	/* create friend function prototype */
	
	public :
		/* create the prototype for the constructor based on TrickOrTreater.cpp */
		std::string getName();
		void startThread();
		void joinThread();
		void GoTrickOrTreating();
		void Walk(int); 
		std::string getPath();
		static int ImDone;
		
		
	private :
		std::string name;
		std::ostringstream path;
		std::thread *TOTThreadPtr = nullptr;
		/* declare a map named Bucket of type string,int */
		/* declare a vector name ListOfHouses of type pointer to House */
};
