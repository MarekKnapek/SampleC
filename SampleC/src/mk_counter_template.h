#include "mk_ints.h"
#include "mk_macros.h"


#ifndef MK_T_TYPE
# error Bad template!
#endif
#ifndef MK_T_DURATION
# error Bad template!
#endif
#ifndef MK_T_PRECISION
# error Bad template!
#endif
#ifndef MK_T_UNIT
# error Bad template!
#endif


struct MK_CONCAT3(mk_counter_bucket, MK_T_TYPE, s)
{
	MK_T_TYPE m_time;
	MK_T_TYPE m_count;
};
typedef struct MK_CONCAT3(mk_counter_bucket, MK_T_TYPE, s) MK_CONCAT3(mk_counter_bucket, MK_T_TYPE, t);


struct MK_CONCAT6(mk_counter, MK_T_TYPE, MK_T_DURATION, MK_T_PRECISION, MK_T_UNIT, s)
{
	MK_CONCAT3(mk_counter_bucket, MK_T_TYPE, t) m_buckets[MK_T_DURATION / MK_T_PRECISION + 1];
	mk_uint32_t m_index;
};
typedef struct MK_CONCAT6(mk_counter, MK_T_TYPE, MK_T_DURATION, MK_T_PRECISION, MK_T_UNIT, s) MK_CONCAT6(mk_counter, MK_T_TYPE, MK_T_DURATION, MK_T_PRECISION, MK_T_UNIT, t);


void MK_CONCAT6(mk_counter, MK_T_TYPE, MK_T_DURATION, MK_T_PRECISION, MK_T_UNIT, construct)(MK_CONCAT6(mk_counter, MK_T_TYPE, MK_T_DURATION, MK_T_PRECISION, MK_T_UNIT, t)* const self);
void MK_CONCAT6(mk_counter, MK_T_TYPE, MK_T_DURATION, MK_T_PRECISION, MK_T_UNIT, destroy)(MK_CONCAT6(mk_counter, MK_T_TYPE, MK_T_DURATION, MK_T_PRECISION, MK_T_UNIT, t)* const self);

void MK_CONCAT6(mk_counter, MK_T_TYPE, MK_T_DURATION, MK_T_PRECISION, MK_T_UNIT, count)(MK_CONCAT6(mk_counter, MK_T_TYPE, MK_T_DURATION, MK_T_PRECISION, MK_T_UNIT, t)* const self, MK_T_TYPE const time, MK_T_TYPE const count);

MK_T_TYPE MK_CONCAT6(mk_counter, MK_T_TYPE, MK_T_DURATION, MK_T_PRECISION, MK_T_UNIT, get_count)(MK_CONCAT6(mk_counter, MK_T_TYPE, MK_T_DURATION, MK_T_PRECISION, MK_T_UNIT, t) const* const self, MK_T_TYPE const time);
