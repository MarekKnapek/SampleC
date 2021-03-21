#include "mk_math.h"


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


void MK_CONCAT6(mk_counter, MK_T_TYPE, MK_T_DURATION, MK_T_PRECISION, MK_T_UNIT, construct)(MK_CONCAT6(mk_counter, MK_T_TYPE, MK_T_DURATION, MK_T_PRECISION, MK_T_UNIT, t)* const self)
{
	mk_uint32_t i;
	MK_CONCAT3(mk_counter_bucket, MK_T_TYPE, t)* bucket;

	for(i = 0; i != MK_T_DURATION / MK_T_PRECISION + 1; ++i)
	{
		bucket = self->m_buckets + i;
		bucket->m_time = 0;
		bucket->m_count = 0;
	}
	self->m_index = 0;
}

void MK_CONCAT6(mk_counter, MK_T_TYPE, MK_T_DURATION, MK_T_PRECISION, MK_T_UNIT, destroy)(MK_CONCAT6(mk_counter, MK_T_TYPE, MK_T_DURATION, MK_T_PRECISION, MK_T_UNIT, t)* const self)
{
}


void MK_CONCAT6(mk_counter, MK_T_TYPE, MK_T_DURATION, MK_T_PRECISION, MK_T_UNIT, count)(MK_CONCAT6(mk_counter, MK_T_TYPE, MK_T_DURATION, MK_T_PRECISION, MK_T_UNIT, t)* const self, MK_T_TYPE const time, MK_T_TYPE const count)
{
	MK_T_TYPE time_rounded;
	MK_CONCAT3(mk_counter_bucket, MK_T_TYPE, t)* bucket;

	time_rounded = time / MK_T_PRECISION;
	bucket = self->m_buckets + self->m_index;
	if(bucket->m_time == time_rounded)
	{
		bucket->m_count += count;
	}
	else
	{
		if(self->m_index != MK_T_DURATION / MK_T_PRECISION + 1 - 1)
		{
			++self->m_index;
		}
		else
		{
			self->m_index = 0;
		}
		bucket = self->m_buckets + self->m_index;
		bucket->m_time = time_rounded;
		bucket->m_count = count;
	}
}


MK_T_TYPE MK_CONCAT6(mk_counter, MK_T_TYPE, MK_T_DURATION, MK_T_PRECISION, MK_T_UNIT, get_count)(MK_CONCAT6(mk_counter, MK_T_TYPE, MK_T_DURATION, MK_T_PRECISION, MK_T_UNIT, t) const* const self, MK_T_TYPE const time)
{
	MK_T_TYPE count;
	MK_T_TYPE time_rounded;
	mk_uint32_t idx;
	mk_uint32_t i;
	MK_CONCAT3(mk_counter_bucket, MK_T_TYPE, t) const* bucket;
	MK_T_TYPE diff;
	MK_T_TYPE unit_reduced;
	MK_T_TYPE duration_reduced;
	MK_T_TYPE ret;

	count = 0;
	time_rounded = time / MK_T_PRECISION;
	idx = self->m_index;
	for(i = 0; i != MK_T_DURATION / MK_T_PRECISION + 1 - 1; ++i)
	{
		if(idx != 0)
		{
			--idx;
		}
		else
		{
			idx = MK_T_DURATION / MK_T_PRECISION;
		}
		bucket = self->m_buckets + idx;
		diff = time_rounded - bucket->m_time;
		if(diff > MK_T_DURATION / MK_T_PRECISION)
		{
			break;
		}
		count += bucket->m_count;
	}
	unit_reduced = MK_REDUCE_FRACTION_A(MK_T_UNIT, MK_T_DURATION);
	duration_reduced = MK_REDUCE_FRACTION_B(MK_T_UNIT, MK_T_DURATION);
	ret = (count * unit_reduced) / duration_reduced;
	return ret;
}
