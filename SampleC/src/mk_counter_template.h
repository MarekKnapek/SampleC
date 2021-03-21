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


struct MK_CONCAT3(mk_counter_bucket_, MK_T_TYPE, _s)
{
	MK_T_TYPE m_time;
	MK_T_TYPE m_count;
};
typedef struct MK_CONCAT3(mk_counter_bucket_, MK_T_TYPE, _s) MK_CONCAT3(mk_counter_bucket_, MK_T_TYPE, _t);


struct MK_CONCAT9(mk_counter_, MK_T_TYPE, _, MK_T_DURATION, _, MK_T_PRECISION, _, MK_T_UNIT, _s)
{
	MK_CONCAT3(mk_counter_bucket_, MK_T_TYPE, _t) m_buckets[MK_T_DURATION / MK_T_PRECISION + 1];
	mk_uint32_t m_index;
};
typedef struct MK_CONCAT9(mk_counter_, MK_T_TYPE, _, MK_T_DURATION, _, MK_T_PRECISION, _, MK_T_UNIT, _s) MK_CONCAT9(mk_counter_, MK_T_TYPE, _, MK_T_DURATION, _, MK_T_PRECISION, _, MK_T_UNIT, _t);


void MK_CONCAT9(mk_counter_, MK_T_TYPE, _, MK_T_DURATION, _, MK_T_PRECISION, _, MK_T_UNIT, _construct)(MK_CONCAT9(mk_counter_, MK_T_TYPE, _, MK_T_DURATION, _, MK_T_PRECISION, _, MK_T_UNIT, _t)* const self);
void MK_CONCAT9(mk_counter_, MK_T_TYPE, _, MK_T_DURATION, _, MK_T_PRECISION, _, MK_T_UNIT, _destroy)(MK_CONCAT9(mk_counter_, MK_T_TYPE, _, MK_T_DURATION, _, MK_T_PRECISION, _, MK_T_UNIT, _t)* const self);

void MK_CONCAT9(mk_counter_, MK_T_TYPE, _, MK_T_DURATION, _, MK_T_PRECISION, _, MK_T_UNIT, _count)(MK_CONCAT9(mk_counter_, MK_T_TYPE, _, MK_T_DURATION, _, MK_T_PRECISION, _, MK_T_UNIT, _t)* const self, MK_T_TYPE const time, MK_T_TYPE const count);

MK_T_TYPE MK_CONCAT9(mk_counter_, MK_T_TYPE, _, MK_T_DURATION, _, MK_T_PRECISION, _, MK_T_UNIT, _get_count)(MK_CONCAT9(mk_counter_, MK_T_TYPE, _, MK_T_DURATION, _, MK_T_PRECISION, _, MK_T_UNIT, _t) const* const self, MK_T_TYPE const time);
