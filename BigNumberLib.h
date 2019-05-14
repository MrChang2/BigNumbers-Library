/**
*@file
*@brief Library header file for BigNumbers
*/
#pragma once
#include <vector>
#include <string>

namespace BigNumbers {
	class BigNumber {
	private:
		std::vector<int> digits;	/**<Vector to hold all the digits*/
	public:
		BigNumber();	/**<Default Constructor, does nothing*/
		BigNumber(std::string s);	/**<Main Constructor, converts string into int vector*/
		BigNumber(std::vector<int> v);
		~BigNumber();	/**<Main Destructor*/
		std::vector<int> getDigits();	/**<Accessor for the digits vector*/
		void printDigits();		/**<Prints out the vector's digits in order*/
		BigNumber operator+(BigNumber n);	/**<Addition operator, adds two BigNumbers*/
		BigNumber operator-(BigNumber n);	/**<Subtraction operator, subtracts two BigNumbers*/
		BigNumber operator*(BigNumber n);	/**<Multiplecation operator, multiplies two BigNumbers*/
		BigNumber operator/(BigNumber n);	/**<Division operator, divides two BigNumbers*/
		BigNumber operator%(BigNumber n);	/**<Modulus opeartor, returns remainder of two BigNumbers*/
	};
}
