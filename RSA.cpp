#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;
using namespace std;

int main() {
	string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	cout << "Enter the string to be encrypted: \n";
	
	string x;	
	cin >> x;

	cout << "Enter Key (n): \n";
	
	int256_t n;
	cin >> n;

	cout << "Enter Key (e): \n";
	
	int e;
	cin >> e;

	cout << "Encrypted message: \n";

	string value;

	vector<string> newValue;

	for (int i = 0; i < x.length(); i++) {
		for (int j = 0; j < alphabets.length(); j++) {
			if (x[i] == alphabets[j]) {
				if (j < 10) {
					string number = to_string(j);
					value = "0" + number;
				}
				else {
					string number = to_string(j);
					value = number;
				}
				j = 30;
			}
		}
		
		newValue.push_back(value);
	}

    	ostringstream out;
    	for (string s: newValue) {
        		out << s;
    	}
 
    	string newStringValue(out.str());

	vector<int256_t> encryptedValue;
	for (int i = 0; i < newStringValue.length(); i += 4) {

		int256_t integerValue = stoi(newStringValue.substr(i,4));
		int256_t newEncryptedValue = pow(integerValue, e) % n;

		encryptedValue.push_back(newEncryptedValue);		
	}

	for (int256_t finalEncryptedValue: encryptedValue) {
    		cout << finalEncryptedValue<< " ";
	}

	return 0;
}