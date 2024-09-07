

char* multiply(char* num1, char* num2) {
    // If either number is "0", the result is "0"
    if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0) {
        char* result = (char*)malloc(2);
        strcpy(result, "0");
        return result;
    }

    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len_result = len1 + len2;

    // Allocate space for the result
    int* result = (int*)calloc(len_result, sizeof(int));

    // Perform multiplication
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j;
            int p2 = i + j + 1;
            int sum = mul + result[p2];

            result[p2] = sum % 10;
            result[p1] += sum / 10;
        }
    }

    // Convert the result to a string
    char* result_str = (char*)malloc(len_result + 1);
    int k = 0, i = 0;

    // Skip leading zeros
    while (i < len_result && result[i] == 0) {
        i++;
    }

    while (i < len_result) {
        result_str[k++] = result[i++] + '0';
    }

    result_str[k] = '\0';
    free(result);

    return result_str;
}

