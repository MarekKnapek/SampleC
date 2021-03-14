#ifndef INCLUDE_GUARD_MK_COUNTER
#define INCLUDE_GUARD_MK_COUNTER


#include "mk_ints.h"


struct mk_counter_bucket_s
{
	mk_uint32_t m_time;
	mk_uint32_t m_count;
};
typedef struct mk_counter_bucket_s mk_counter_bucket_t;
#define X mk_counter_bucket_t
#include "mk_primitives_template.h"
#include "mk_vector_template.h"
#undef X


struct mk_counter_s
{
	mk_uint32_t m_duration;
	mk_uint32_t m_precision;
	mk_vector_mk_counter_bucket_t_t m_buckets;
	mk_uint32_t m_index;
};
typedef struct mk_counter_s mk_counter_t;


void mk_counter_construct(mk_counter_t* const self, mk_uint32_t const duration, mk_uint32_t const precision);
void mk_counter_destroy(mk_counter_t* const self);

void mk_counter_count(mk_counter_t* const self, mk_uint32_t const time, mk_uint32_t const count);

mk_uint32_t mk_counter_get_count(mk_counter_t const* const self, mk_uint32_t const time);


#endif
