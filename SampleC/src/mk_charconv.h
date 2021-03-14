#ifndef INCLUDE_GUARD_MK_CHARCONV
#define INCLUDE_GUARD_MK_CHARCONV


#include "mk_ints.h"


char* mk_to_chars_sint32(char* const begin, char const* const end, mk_sint32_t const value);
char* mk_to_chars_uint32(char* const begin, char const* const end, mk_uint32_t const value);


#endif
