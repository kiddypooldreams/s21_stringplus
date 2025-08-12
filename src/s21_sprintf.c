// not sure this functions:
// isspace()
// isdigit()
// atoi()
// have to delete <string.h>

#include <stdarg.h>
#include <stdio.h>  // << delete

#include "s21_printf_lib/s21_spec.h"
#include "s21_string.h"

#define INT_BUF_SIZE \
  ((24 > format_handler->precision) ? 24 : format_handler->precision + 24)
#define UINT_BUF_SIZE \
  ((24 > format_handler->precision) ? 24 : format_handler->precision + 24)
#define FLOAT_BUF_SIZE \
  ((32 > format_handler->precision) ? 32 : format_handler->precision + 32)

int s21_sprintf(char *str, const char *format, ...);

const char *ParseFormat(const char *fmt,
                        FormatSpecificationHandler *format_handler);
const char *ParseFLags(const char *fmt, uint8_t *flags);

const char *ParseLengthModifier(const char *fmt,
                                ArgumentLengthModifier *length_modifier);
const char *ParseSpecifier(const char *fmt, TypeSpecifier *specifier);

char *PasteData(va_list args, char *out,
                FormatSpecificationHandler *format_handler);
char *PasteWithWidth(const char *data, char *out, s21_size_t width, int flags);

char *PasteChar(int c, char *out, FormatSpecificationHandler *format_handler);

long int GetSignedInt(va_list args, ArgumentLengthModifier length_modifier);
long unsigned int GetUnsignedInt(va_list args,
                                 ArgumentLengthModifier length_modifier);
char *PasteInt(long int value, char *out,
               FormatSpecificationHandler *format_handler);

int s21_isdigit(const char c);  // как будто это и не нужно
const char *s21_atoi(const char *str, unsigned int *d);
char *s21_ftoa(double n, char *out, FormatSpecificationHandler *format_handler);
void PutSign(char *str, int is_negative,
             FormatSpecificationHandler *format_handler, int is_reversed);
int RoundDecimalPart(char *decimal_str, unsigned precision);

// -----------------------------------------------------
int main() {
  char s21_str[10000];
  char b31_str[10000];
  int s21_out = s21_sprintf(s21_str, "%+12f", -213.99123193);
  int out = sprintf(b31_str, "%+12f", -213.99123193);
  printf("%s\n", b31_str);
  printf("%s\n", s21_str);

  int age = 38;
    char* name = "Tom";
    char text[50];  
    int charNumber = sprintf (text, "Name: %s  Age: %d\n", name, age);  
    printf ("%s", text);  // Name: Tom  Age: 38
    printf("text length: %d\n", charNumber);  // text length: 19


    int age2 = 38;
    char* name2 = "Tom";
    char text2[50];  
    int charNumber2 = s21_sprintf (text2, "Name: %s  Age: %d\n", name2, age2);  
    printf ("%s", text2);  // Name: Tom  Age: 38
    printf("text length: %d", charNumber2);  // text length: 19
  

  return 0;
}
// -----------------------------------------------------

int s21_sprintf(char *str, const char *format, ...) {
  const char *p = format;
  char *out = str;

  va_list args;
  va_start(args, format);

  for (; *p != '\0'; p++) {
    if (*p == '%') {
      FormatSpecificationHandler format_handler = {0};
      p = ParseFormat(p, &format_handler);
      out = PasteData(args, out, &format_handler);
    } else {
      *out++ = *p;
    }
  }
  *out = '\0';
  va_end(args);
  return out - str;
}

const char *ParseFormat(const char *fmt,
                        FormatSpecificationHandler *format_handler) {
  fmt = ParseFLags(fmt, &format_handler->flags);
  fmt = s21_atoi(fmt, &format_handler->width);
  if (*fmt == '.') {
    format_handler->custom_precision = 1;
    fmt++;
    fmt = s21_atoi(fmt, &format_handler->precision);
  }
  fmt = ParseLengthModifier(fmt, &format_handler->length_modifier);
  fmt = ParseSpecifier(fmt, &format_handler->type_specifier);
  return fmt;
}

const char *ParseFLags(const char *fmt, uint8_t *flags) {
  for (fmt++;; fmt++) {
    switch (*fmt) {
      case '-':
        *flags |= LEFT_ALIGN;
        continue;
      case '+':
        *flags |= SHOW_PLUS;
        continue;
      case ' ':
        *flags |= SPACE_FOR_SIGN;
        continue;
    }
    break;
  }

  if (*flags & SHOW_PLUS) *flags &= ~SPACE_FOR_SIGN;

  return fmt;
}

const char *s21_atoi(const char *str, unsigned int *d) {
  *d = 0;         
  int sign = 1;     
  
  while (*str == ' ') str++;

  if (*str == '-') {
      sign = -1;
      str++;
  } else if (*str == '+') {
      str++;  
  }
  
  while (s21_isdigit(*str)) {
      *d = *d * 10 + (*str - '0');
      str++;
  }
  
  if (sign == -1) {
      *d = (unsigned int)(-(int)*d);
  }
  
  return str;
}

const char *ParseLengthModifier(const char *fmt,
                                ArgumentLengthModifier *length_modifier) {
  for (int i = 0;; i++) {
    if (length_modifier_mappings[i].format_character == *fmt) {
      *length_modifier = length_modifier_mappings[i].length_modifier;
      fmt++;
    }
    if (i >= ARGUMENT_LENGTH_MODIFIER_COUNT ||
        *length_modifier == length_modifier_mappings[i].length_modifier) {
      break;
    }
  }
  return fmt;
}

const char *ParseSpecifier(const char *fmt, TypeSpecifier *specifier) {
  int i = 0;
  do {
    if (specifier_mappings[i].format_character == *fmt) {
      *specifier = specifier_mappings[i].type_specifier;
    }
    i++;
  } while (i < TYPE_SPECIFIER_COUNT &&
           specifier_mappings[i - 1].format_character != *fmt);
  return fmt;
}

char *PasteData(va_list args, char *out,
                FormatSpecificationHandler *format_handler) {
  switch (format_handler->type_specifier) {
    case TYPE_CHARACTER:
      out = PasteChar(va_arg(args, int), out, format_handler);
      break;

    case TYPE_SIGNED_INTEGER: {
      long int value = GetSignedInt(args, format_handler->length_modifier);
      out = PasteInt(value, out, format_handler);
      break;
    }

    case TYPE_UNSIGNED_INTEGER: {
      long unsigned value =
          GetUnsignedInt(args, format_handler->length_modifier);
      out = PasteInt(value, out, format_handler);
      break;
    }

    case TYPE_STRING: {
      out = PasteWithWidth(va_arg(args, char *), out, format_handler->width,
                           format_handler->flags);
      break;
    }

    case TYPE_PERCENT: {
      *out++ = '%';
      break;
    }

    case TYPE_FLOAT: {
      double value = va_arg(args, double);
      ;
      out = s21_ftoa(value, out, format_handler);
      break;
    }
  }
  return out;
}

char *PasteChar(int c, char *out, FormatSpecificationHandler *format_handler) {
  char data[2] = {c, '\0'};
  return PasteWithWidth(data, out, format_handler->width,
                        format_handler->flags);
}

long int GetSignedInt(va_list args, ArgumentLengthModifier length_modifier) {
  long value;
  switch (length_modifier) {
    case ARGUMENT_LENGTH_SHORT:
      value = (short)va_arg(args, int);
      break;

    case ARGUMENT_LENGTH_LONG:
      value = va_arg(args, long int);
      break;

    default:
      value = va_arg(args, int);
      break;
  }

  return value;
}

long unsigned int GetUnsignedInt(va_list args,
                                 ArgumentLengthModifier length_modifier) {
  long unsigned value;
  switch (length_modifier) {
    case ARGUMENT_LENGTH_SHORT:
      value = (short unsigned)va_arg(args, unsigned);
      break;

    case ARGUMENT_LENGTH_LONG:
      value = va_arg(args, long unsigned);
      break;

    default:
      value = va_arg(args, unsigned int);
      break;
  }

  return value;
}

char *PasteInt(long int value, char *out,
               FormatSpecificationHandler *format_handler) {
  unsigned long u_value;
  int is_negative = 0;
  
  if (value < 0 && format_handler->type_specifier != TYPE_UNSIGNED_INTEGER) {
    is_negative = 1;
    u_value = (unsigned long)(-(value + 1)) + 1;
  } else {
    u_value = (unsigned long)value;
  }

  char data[INT_BUF_SIZE];
  char *p = data + INT_BUF_SIZE - 1;
  s21_size_t digits_written = 0;

  *p-- = '\0';

  if (u_value == 0 && format_handler->precision != 0) {
    *p-- = '0';
    ++digits_written;
  } else {
    while (u_value != 0) {
      *p-- = (u_value % 10) + '0';
      ++digits_written;
      u_value /= 10;
    }
  }

  for (; digits_written < format_handler->precision; digits_written++) {
    *p-- = '0';
  }

  PutSign(p, is_negative, format_handler, 1);

  return PasteWithWidth(p + 1, out, format_handler->width,
                       format_handler->flags);
}

char *s21_ftoa(double n, char *out,
               FormatSpecificationHandler *format_handler) {
  char data[FLOAT_BUF_SIZE];
  s21_memset(data, '\0', FLOAT_BUF_SIZE);
  char *pdata = data;
  int is_negative = n < 0;
  unsigned int precision =
      format_handler->custom_precision ? format_handler->precision : 6;
  char decimal_str[precision + 2];
  s21_memset(decimal_str, '0', precision + 1);
  decimal_str[precision + 1] = '\0';
  if (is_negative) n = -n;
  PutSign(pdata++, is_negative, format_handler, 0);
  long long integer_part = (long long)n;
  double decimal_part = n - integer_part;

  for (unsigned int i = 0; i <= precision; i++) {
    decimal_part *= 10;
    int temp = (int)decimal_part;
    decimal_str[i] = temp + '0';
    decimal_part -= temp;
  }
  integer_part += RoundDecimalPart(decimal_str, precision);

  char int_buf[32];
  FormatSpecificationHandler int_format = *format_handler;
  int_format.precision = 0; 
  PasteInt(integer_part, int_buf, &int_format);
  
  char *src = int_buf;
  while (*src && !s21_isdigit(*src)) src++;
  while (*src) *pdata++ = *src++;

  if (precision > 0) {
    *pdata++ = '.';
    s21_strncat(data, decimal_str, precision);
  }

  return PasteWithWidth(data, out, format_handler->width,
                       format_handler->flags);
}

char *PasteWithWidth(const char *data, char *out, s21_size_t width, int flags) {
  int pad = width - s21_strlen(data);
  if (pad < 0) pad = 0;

  if (!(flags & LEFT_ALIGN)) {
    for (int i = 0; i < pad; i++) {
      *out++ = ' ';
    }
  }

  while (*data) *out++ = *data++;
  data--;

  if (flags & LEFT_ALIGN) {
    for (int i = 0; i < pad; i++) {
      *out++ = ' ';
    }
  }
  return out;
}

int s21_isdigit(const char c) { return (c >= '0' && (c) <= '9') ? 1 : 0; }

void PutSign(char *str, int is_negative,
             FormatSpecificationHandler *format_handler, int is_reversed) {
  char sign = 0;
 
   if (is_negative) {
      sign = '-';
  } else if (format_handler->type_specifier != TYPE_UNSIGNED_INTEGER) {
      if (format_handler->flags & SHOW_PLUS) {
      sign = '+';
        } else if (format_handler->flags & SPACE_FOR_SIGN) {
            sign = ' ';
        }
    }

    if (sign != 0) {
        if (is_reversed) {
            *str-- = sign;  
        } else {
            *str++ = sign;  
        }
    }
}

int RoundDecimalPart(char *decimal_str, unsigned precision) {
  int carry = 0;
  if (decimal_str[precision] >= '5') {
    carry = 1;
  }
  for (int i = precision - 1; i >= 0; i--) {
    if (carry) {
      if (decimal_str[i] < '9') {
        decimal_str[i] += 1;
        carry = 0;
      } else {
        decimal_str[i] = '0';
        carry = 1;
      }
    }
  }
  return carry;
}