#include <limits.h> // For INT_MAX and INT_MIN

int divide(int dividend, int divisor) {
    // Handle overflow case specifically
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX; // To avoid overflow
    }
    
    // Compute the quotient
    long int quotient = (long int) dividend / divisor;
    
    // Check for overflow
    if (quotient > INT_MAX) {
        return INT_MAX;
    } else if (quotient < INT_MIN) {
        return INT_MIN;
    }
    
    return (int)quotient;
}
