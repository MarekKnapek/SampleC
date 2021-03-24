#include "mk_charconv.h"

#include "mk_assert.h"
#include "mk_macros.h"


char* mk_to_chars_sint32(char* const begin, char const* const end, mk_sint32_t const value)
{
	char* ptr;
	mk_sint32_t positive;
	mk_uint32_t uint32;
	char* ret;

	MK_ASSERT(begin < end);

	if(value < 0)
	{
		begin[0] = '-';
		ptr = begin + 1;
		positive = -value;
	}
	else
	{
		ptr = begin;
		positive = value;
	}
	uint32 = (mk_uint32_t)positive;
	ret = mk_to_chars_uint32(ptr, end, uint32);
	return ret;
}

char* mk_to_chars_uint32(char* const begin, char const* const end, mk_uint32_t const value)
{
	mk_uint32_t n;
	int places;
	int i;
	int digit;
	char* ret;

	n = value;
	if(n < 10)
	{
		places = 1;
	}
	else if(n < 100)
	{
		places = 2;
	}
	else if(n < 1000)
	{
		places = 3;
	}
	else if(n < 10000)
	{
		places = 4;
	}
	else if(n < 100000)
	{
		places = 5;
	}
	else if(n < 1000000)
	{
		places = 6;
	}
	else if(n < 10000000)
	{
		places = 7;
	}
	else if(n < 100000000)
	{
		places = 8;
	}
	else if(n < 1000000000)
	{
		places = 9;
	}
	else
	{
		places = 10;
	}
	MK_ASSERT(begin < end && end - begin >= places);
	MK_UNREFERENCED(end);

	for(i = 0; i != places - 1; ++i)
	{
		digit = n % 10;
		n = n / 10;
		begin[places - 1 - i] = (char)('0' + digit);
	}
	begin[0] = (char)('0' + n);

	ret = begin + places;
	return ret;
}
