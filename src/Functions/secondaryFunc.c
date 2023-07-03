#include "s21_string.h"

void write(char current, char *buffer) { s21_strncat(buffer, &current, 1); }

void strAppend(char *str1, char *buffer) {
  int length = s21_strlen(str1);
  s21_strncat(buffer, str1, length);
}

char *intToString(int num) {
  int sign = 1;
  if (num < 0) {
    sign = -1;
    num = -num;
  }
  int tempNum = num;
  int numDigits = 0;
  while (tempNum > 0) {
    tempNum /= 10;
    numDigits++;
  }
  int strLength = numDigits + (sign == -1 ? 1 : 0);
  char *str = (char *)malloc((strLength + 1) * sizeof(char));
  int i = 0;
  if (sign == -1) {
    str[i++] = '-';
  }
  for (int j = numDigits - 1; j >= 0; j--) {
    str[i++] = '0' + (num % 10);
    num /= 10;
  }
  str[strLength] = '\0';

  // Reverse the string
  int start = sign == -1 ? 1 : 0;
  int end = strLength - 1;
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }

  return str;
}

char *unsignedIntToString(int num) {
  unsigned int unsignedNum = (unsigned int)num;

  if (num < 0) {
    unsignedNum = (~((unsigned int)(-num))) + 1;
  }

  int numDigits = 0;
  unsigned int tempNum = unsignedNum;
  do {
    tempNum /= 10;
    numDigits++;
  } while (tempNum != 0);

  int strLength = numDigits;
  char *str = (char *)malloc((strLength + 1) * sizeof(char));

  int i = 0;
  do {
    str[i++] = '0' + (unsignedNum % 10);
    unsignedNum /= 10;
  } while (unsignedNum != 0);

  str[strLength] = '\0';

  // Reverse the string
  int start = 0;
  int end = strLength - 1;
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }

  return str;
}

char *doubleToString(double num) {
  int sign = 1;
  if (num < 0) {
    sign = -1;
    num = -num;
  }

  int integerPart = (int)num;
  double fractionalPart = num - integerPart;

  int intDigits = integerPart == 0 ? 1 : (int)log10(integerPart) + 1;
  int totalDigits = intDigits + 6;  // Assuming 6 decimal places

  char *str = (char *)malloc((totalDigits + 2) * sizeof(char));

  if (str == NULL) {
    return NULL;  // Handle allocation error
  }

  int index = 0;

  // Convert integer part to string
  if (integerPart == 0) {
    str[index++] = '0';
  } else {
    int temp = integerPart;
    while (temp > 0) {
      str[index++] = '0' + (temp % 10);
      temp /= 10;
    }
  }

  // Add decimal point
  str[index++] = '.';

  // Convert fractional part to string
  for (int i = 0; i < 6; i++) {
    fractionalPart *= 10;
    int digit = (int)fractionalPart;
    str[index++] = '0' + digit;
    fractionalPart -= digit;
  }

  str[index] = '\0';

  if (sign == -1) {
    // Add sign if negative
    char *result = (char *)malloc((totalDigits + 3) * sizeof(char));
    if (result == NULL) {
      free(str);
      return NULL;  // Handle allocation error
    }
    result[0] = '-';
    for (int i = 0; i < index + 1; i++) {
      result[i + 1] = str[i];
    }
    result[index + 2] = '\0';
    free(str);
    return result;
  }

  return str;
}

///////////////////////////// round

char *roundDoubleString(const char *numberString) {
  double number = atof(numberString);

  // Find the position of the decimal point
  char *decimalPoint = s21_strchr(numberString, '.');

  // Calculate the number of decimal places
  int decimalPlaces = decimalPoint ? s21_strlen(decimalPoint + 1) : 0;

  // Round the number
  double roundedNumber = round(number * 1000) / 1000;

  // Convert the rounded number back to a string
  char *roundedString = malloc(50 * sizeof(char));
  snprintf(roundedString, 50, "%.*f", decimalPlaces, roundedNumber);

  return roundedString;
}