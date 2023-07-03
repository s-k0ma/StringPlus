int s21_isspace(int c) {
  return (c == ' ' || c == '\0' || c == '\t' || c == '\n' || c == '\v' ||
          c == '\f' || c == '\r');
}