#include "mk_charconv.h"

#include "mk_assert.h"


char* mk_to_chars(char* const begin, char* const end, int const value)
{
	int n;
	int places;
	char* ptr;
	int digit;
	int i;

	MK_ASSERT(begin <= end);

	if(value < 0)
	{
		n = -value;
	}
	else
	{
		n = value;
	}
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
	MK_ASSERT(end - begin >= places + (value < 0 ? 1 : 0));

	ptr = begin;
	if(value < 0)
	{
		ptr[0] = '-';
		++ptr;
	}
	for(i = 0; i != places - 1; ++i)
	{
		digit = n % 10;
		n = n / 10;
		ptr[places - 1 - i] = (char)('0' + digit);
	}
	ptr[0] = (char)('0' + n);

	ptr += places;
	return ptr;
}
