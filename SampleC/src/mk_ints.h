#ifndef INCLUDE_GUARD_MK_INTS
#define INCLUDE_GUARD_MK_INTS


typedef signed int mk_sint32_t;
typedef unsigned int mk_uint32_t;


struct mk_sint64_parts_s
{
	unsigned int m_lo;
	signed int m_hi;
};
typedef struct mk_sint64_parts_s mk_sint64_parts_t;
union mk_sint64_u
{
	mk_sint64_parts_t m_parts;
	double m_double;
};
typedef union mk_sint64_u mk_sint64_t;

struct mk_uint64_parts_s
{
	unsigned int m_lo;
	unsigned int m_hi;
};
typedef struct mk_uint64_parts_s mk_uint64_parts_t;
union mk_uint64_u
{
	mk_uint64_parts_t m_parts;
	double m_double;
};
typedef union mk_uint64_u mk_uint64_t;


#endif
