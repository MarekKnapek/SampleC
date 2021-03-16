#include "mk_ints.h"
#include "mk_macros.h"


struct MK_CONCAT3(mk_counter_bucket_, MK_T1, _s)
{
	MK_T1 m_time;
	MK_T1 m_count;
};
typedef struct MK_CONCAT3(mk_counter_bucket_, MK_T1, _s) MK_CONCAT3(mk_counter_bucket_, MK_T1, _t);


struct MK_CONCAT9(mk_counter_, MK_T1, _, MK_T2, _, MK_T3, _, MK_T4, _s)
{
	MK_CONCAT3(mk_counter_bucket_, MK_T1, _t) m_buckets[MK_T2 / MK_T3 + 1];
	mk_uint32_t m_index;
};
typedef struct MK_CONCAT9(mk_counter_, MK_T1, _, MK_T2, _, MK_T3, _, MK_T4, _s) MK_CONCAT9(mk_counter_, MK_T1, _, MK_T2, _, MK_T3, _, MK_T4, _t);


void MK_CONCAT9(mk_counter_, MK_T1, _, MK_T2, _, MK_T3, _, MK_T4, _construct)(MK_CONCAT9(mk_counter_, MK_T1, _, MK_T2, _, MK_T3, _, MK_T4, _t)* const self);
void MK_CONCAT9(mk_counter_, MK_T1, _, MK_T2, _, MK_T3, _, MK_T4, _destroy)(MK_CONCAT9(mk_counter_, MK_T1, _, MK_T2, _, MK_T3, _, MK_T4, _t)* const self);

void MK_CONCAT9(mk_counter_, MK_T1, _, MK_T2, _, MK_T3, _, MK_T4, _count)(MK_CONCAT9(mk_counter_, MK_T1, _, MK_T2, _, MK_T3, _, MK_T4, _t)* const self, MK_T1 const time, MK_T1 const count);

MK_T1 MK_CONCAT9(mk_counter_, MK_T1, _, MK_T2, _, MK_T3, _, MK_T4, _get_count)(MK_CONCAT9(mk_counter_, MK_T1, _, MK_T2, _, MK_T3, _, MK_T4, _t) const* const self, MK_T1 const time);
