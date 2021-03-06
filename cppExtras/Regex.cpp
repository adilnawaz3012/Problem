// Regex:
// regex_match() -This function return true if the regular expression is a match against the given string otherwise it returns false.
// https://www.geeksforgeeks.org/regex-regular-expression-in-c/

#include<iostream>
#include<regex>

using namespace std;

int main() {
    string a = "GeeksForGeeks";
    // Here b is an object of regex (regular expression)
    regex b("(Geek)(.*)");
    // regex_match function matches string a against regex b
    if(regex_match(a,b)) {
        cout << "String 'a' matches regular expression 'b' \n";
    }
    // regex_match function for matching a range in string
    // against regex b
    if(regex_match(a.begin(), a.end(), b)) {
        cout << "String 'a' matches with regular expression "
                "'b' in the range from 0 to string end\n";
    }
    return 0;
}