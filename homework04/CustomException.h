/* CustomException.h models customs exceptions.
 * Algorithm taken from:
 * Joel Adams, for CS 112 at Calvin College.
 * Modified by: Valeria Martinez (vam6), James Eapen (jpe4)
 *
 */

#ifndef CUSTOMEXCEPTION
#define CUSTOMEXCEPTION
#include <iostream>
using namespace std;
 
class CustomException {
public:
   CustomException(const string& whereThrown,
                  const string& message) { 
       myLocation = whereThrown; 
       myMessage = message; 
   }
   string asString() const {
       return "*** CustomException in " +
               myLocation + ": " + myMessage; 
   }
private:
   string myLocation;
   string myMessage;
};  

/* Function to allow a CustomException (or a subclass) to be displayed
 * via an ostream.
 * Parameters: out, an ostream;
 *             se, a CustomException.
 * Postcondition: the string representation of se has been inserted
 * into out
 *             && return-value == out.
 */
inline ostream& operator<<(ostream& out, const CustomException& ce) {
      out << ce.asString();
      return out;
}
#endif
