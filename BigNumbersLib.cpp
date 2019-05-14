/**
*@file
*@brief Library Methods for BigNumbers
*/
#include "stdafx.h"
#include "BigNumbersLib.h"
#include <math.h>
#include <iostream>

namespace BigNumbers {
	/**
	*@brief	Default constructor
	*/
	BigNumber::BigNumber() {
		digits.push_back(0);
	}
	/**
	*@brief	Main constructor, converts string into digits vector
	*/
	BigNumber::BigNumber(std::string s) {
		for (int x = 0; x < s.length(); x++) {
			digits.push_back(int(s[x])-'0');
		}
	}
	/**
	*@brief	//Unused constructor
	*/
	BigNumber::BigNumber(std::vector<int> v) {
		digits = v;
	}
	BigNumber::~BigNumber() {

	}

	/**
	*@brief	Returns the digits vector
	*/
	std::vector<int> BigNumber::getDigits() {
		return digits;
	}
	/**
	*@brief Prints out the individual digits in order
	*/
	void BigNumber::printDigits() {
		for (int x = 0; x < digits.size(); x++) {
			std::cout << digits[x];
		}
		std::cout << std::endl;
	}
	/**
	*@brief	Addition operator, adds BigNumber parameter n to this BigNumber, returns result as BigNumber
	*/
	BigNumber BigNumber::operator+(BigNumber n) {
		BigNumber result;	//Holds resulting BigNumber
		int sum = 0;		//Holds sum of individual digit additions
		int carry = 0;		//Holds the carry
		int thisIndex = digits.size()-1;		//Holds index of this vector
		int otherIndex = n.getDigits().size()-1;		//Holds index of other vector

		//Iterate through the vectors, adding individual digits up until one runs out
		while (thisIndex >= 0 && otherIndex >= 0) {
			sum = digits.at(thisIndex) + n.getDigits().at(otherIndex) + carry;
			if (carry == 1) {
				carry = 0;
			}
			//Set carry equal to one if sum of digits exceeds 10
			if (sum >= 10) {
				carry = 1;
				sum = sum - 10;
			}
			//Append sum to start of result vector
			result.digits.insert(result.digits.begin(),sum);
			thisIndex--;		//Decrement thisIndex
			otherIndex--;		//Decrement otherIndex as well
		}
		//if this vector had longer length, fill out rest of result vector with remaining digits from this vector
		if (thisIndex > -1) {
			for (int x = thisIndex; x >= 0; x--) {
				if (digits.at(x)+carry < 10) {
					result.digits.insert(result.digits.begin(), digits.at(x)+carry);
					if (carry == 1) {
						carry = 0;
					}
				}
				else {
					carry = 1;
					result.digits.insert(result.digits.begin(), 0);
				}
			}
			if (carry == 1) {
				result.digits.insert(result.digits.begin(), 1);
				carry = 0;
			}
		}
		//else if other vector isn't done, do the same
		else if (otherIndex > -1) {
			for (int x = otherIndex; x >= 0; x--) {
				if (n.getDigits().at(x)+carry < 10) {
					result.digits.insert(result.digits.begin(), n.getDigits().at(x)+carry);
					if (carry == 1) {
						carry = 0;
					}
				}
				else {
					carry = 1;
					result.digits.insert(result.digits.begin(), 0);
				}
			}
			if (carry == 1) {
				result.digits.insert(result.digits.begin(), 1);
				carry = 0;
			}
		}

		result.digits.pop_back();
		return result;
	}
	/**
	*@brief Subtraction operator, subtracts BigNumber parameter n from this BigNumber, returns result as BigNumber
	*/
	BigNumber BigNumber::operator-(BigNumber n) {
		BigNumber result;	//Holds resulting BigNumber
		std::vector<int> larger = digits;
		std::vector<int> smaller = n.digits;
		int difference = 0;		//Holds sum of individual digit additions
		int carry = 0;		//Holds the carry
		
		//check which number is bigger
		if (digits.size() < n.digits.size()) {
			smaller = digits;
			larger = n.digits;
		}
		else if (digits.size() == n.digits.size()) {
			for (int x = 0; x < digits.size(); x++) {
				if (n.digits.at(x) > digits.at(x)) {
					smaller = digits;
					larger = n.digits;
					break;
				}
				else if (n.digits.at(x) < digits.at(x)) {
					smaller = n.digits;
					larger = digits;
					break;
				}
			}
		}
		else {
			smaller = n.digits;
			larger = digits;
		}

		int thisIndex = larger.size() - 1;		//Holds index of this vector
		int otherIndex = smaller.size() - 1;		//Holds index of other vector

		//Iterate through the vectors, subtracting individual digits up until one runs out
		while (thisIndex >= 0 && otherIndex >= 0) {
			difference = larger.at(thisIndex) - smaller.at(otherIndex) - carry;
			if (carry == 1) {
				carry = 0;
			}
			//Set carry equal to one if difference of digits is less than 0
			if (difference < 0) {
				carry = 1;
				if (thisIndex >= 0 || otherIndex >= 0) {
					difference = 10 + difference;
				}
			}
			//Append difference to start of result vector
			result.digits.insert(result.digits.begin(), difference);
			thisIndex--;		//Decrement thisIndex
			otherIndex--;		//Decrement otherIndex as well
		}
		//if this vector had longer length, fill out rest of result vector with remaining digits from this vector
		if (thisIndex > -1) {
			for (int x = thisIndex; x >= 0; x--) {
				if (larger.at(x) - carry > 0) {		//if difference with carry is greater than 0
					result.digits.insert(result.digits.begin(), larger.at(x) - carry);	//just place difference in vector
					carry = 0;
				}
				else if (larger.at(x) - carry == 0) {	//if difference is equal to 0
					if (x > 0) {	//place zero in vector if not at the end of vector, else do nothing
						result.digits.insert(result.digits.begin(), 0);
						carry = 0;
					}
				}
				else {	//if difference is less than zero
					if (x > 0) {	//if not at vector end, place 9 in vector
						result.digits.insert(result.digits.begin(), 9);
						carry = 1;
					}
					else {		//else place -1 at start if at the end of the vector
						result.digits.insert(result.digits.begin(), -1);
					}
				}
			}
		}

		result.digits.pop_back();
		return result;
	}
	/**
	*@brief Multiplication operator, multiplies BigNumber parameter n by this BigNumber, returns result as BigNumber
	*/
	BigNumber BigNumber::operator*(BigNumber n) {
		BigNumber result;	//Holds resulting BigNumber



		result.digits.pop_back();
		return result;
	}
	/**
	*@brief	Division operator, divides this BigNumber by BigNumber parameter n, returns result as BigNumber
	*/
	BigNumber BigNumber::operator/(BigNumber n) {
		BigNumber result;	//Holds resulting BigNumber
		
		//if divisor is larger than dividend, result is 0
		if (digits.size() < n.digits.size()) {
			result.digits.push_back(0);
		}
		else {
			for (int x = 0; x < digits.size(); x++) {
				if (n.digits.at(x) > digits.at(x)) {
					result.digits.push_back(0);
					break;
				}
				else if (n.digits.at(x) < digits.at(x)) {

				}
			}
		}

		result.digits.pop_back();
		return result;
	}
	/**
	*@brief	Modulus operator, divides this BigNumber by BigNumber parameter n and finds remainder, returns result as BigNumber
	*/
	BigNumber BigNumber::operator%(BigNumber n) {
		BigNumber result;	//Holds resulting BigNumber

		//if divisor is larger than dividend, remainder is dividend
		if (digits.size() < n.digits.size()) {
			result = digits;
		}
		else {
			for (int x = 0; x < digits.size(); x++) {
				if (n.digits.at(x) > digits.at(x)) {
					result = digits;
					break;
				}
				else if (n.digits.at(x) < digits.at(x)) {

				}
			}
		}

		result.digits.pop_back();
		return result;
	}
}
