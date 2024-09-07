bool isPalindrome(int x) {
    if (x < 0) {
        return false;  // Negative numbers are not palindromes
    }
    
    int original = x;  // Store the original number
    int result = 0;
    
    while (x != 0) {
        if ((result > INT_MAX / 10) || (result < INT_MIN / 10)) {
            return false;  // Prevent overflow
        }
        result = result * 10 + (x % 10);
        x = x / 10;
    }
    
    return original == result;  // Check if reversed number equals the original
}
