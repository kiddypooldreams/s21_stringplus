#include <stdint.h>

#define LEFT_ALIGN (1u << 0)      // '-'
#define SHOW_PLUS (1u << 1)       // '+'
#define SPACE_FOR_SIGN (1u << 2)  // ' '

typedef enum {
  ARGUMENT_LENGTH_NONE = 0,
  ARGUMENT_LENGTH_SHORT,
  ARGUMENT_LENGTH_LONG,
  ARGUMENT_LENGTH_MODIFIER_COUNT
} ArgumentLengthModifier;

typedef struct {
  char format_character;
  ArgumentLengthModifier length_modifier;
} ArgumentLengthModifierMapping;

static const ArgumentLengthModifierMapping
    length_modifier_mappings[ARGUMENT_LENGTH_MODIFIER_COUNT] = {
        {0, ARGUMENT_LENGTH_NONE},
        {'h', ARGUMENT_LENGTH_SHORT},
        {'l', ARGUMENT_LENGTH_LONG}};

typedef enum {
  TYPE_NONE = 0,
  TYPE_CHARACTER,
  TYPE_SIGNED_INTEGER,
  TYPE_FLOAT,
  TYPE_STRING,
  TYPE_UNSIGNED_INTEGER,
  TYPE_PERCENT,
  TYPE_SPECIFIER_COUNT
} TypeSpecifier;

typedef struct {
  char format_character;
  TypeSpecifier type_specifier;
} TypeSpecifierMapping;

static const TypeSpecifierMapping specifier_mappings[TYPE_SPECIFIER_COUNT] = {
    {0, TYPE_NONE},     {'c', TYPE_CHARACTER}, {'d', TYPE_SIGNED_INTEGER},
    {'f', TYPE_FLOAT},  {'s', TYPE_STRING},    {'u', TYPE_UNSIGNED_INTEGER},
    {'%', TYPE_PERCENT}};

typedef struct {
  uint8_t flags;
  unsigned width;
  unsigned custom_precision;
  unsigned precision;
  ArgumentLengthModifier length_modifier;
  TypeSpecifier type_specifier;
} FormatSpecificationHandler;

#define INT_BUF_SIZE \
  ((24 > format_handler->precision) ? 24 : format_handler->precision + 24)
#define UINT_BUF_SIZE \
  ((24 > format_handler->precision) ? 24 : format_handler->precision + 24)
#define FLOAT_BUF_SIZE \
  ((32 > format_handler->precision) ? 32 : format_handler->precision + 32)
