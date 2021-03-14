#include "mk_counter.h"


#define X mk_counter_bucket_t
#include "mk_primitives_template.c"
#include "mk_vector_template.c"
#undef X


void mk_counter_construct(mk_counter_t* const self, mk_uint32_t const duration, mk_uint32_t const precision)
{
	mk_uint32_t bucket_count;

	self->m_duration = duration;
	self->m_precision = precision;
	mk_vector_mk_counter_bucket_t_construct(&self->m_buckets);
	self->m_index = 0;

	bucket_count = self->m_duration / self->m_precision + 1;
	mk_vector_mk_counter_bucket_t_resize(&self->m_buckets, bucket_count);
}

void mk_counter_destroy(mk_counter_t* const self)
{
	mk_vector_mk_counter_bucket_t_destroy(&self->m_buckets);
}


void mk_counter_count(mk_counter_t* const self, mk_uint32_t const time, mk_uint32_t const count)
{
	mk_uint32_t bucket_count;
	mk_uint32_t time_rounded;
	mk_counter_bucket_t* bucket;

	bucket_count = self->m_duration / self->m_precision + 1;

	time_rounded = (time / self->m_precision) * self->m_precision;
	bucket = mk_vector_mk_counter_bucket_t_at(&self->m_buckets, self->m_index);
	if(bucket->m_time == 0)
	{
		bucket->m_time = time_rounded;
		bucket->m_count = count;
	}
	else
	{
		if(bucket->m_time == time_rounded)
		{
			bucket->m_count += count;
		}
		else
		{
			if(self->m_index == bucket_count - 1)
			{
				self->m_index = 0;
			}
			else
			{
				++self->m_index;
			}
			bucket = mk_vector_mk_counter_bucket_t_at(&self->m_buckets, self->m_index);
			bucket->m_time = time_rounded;
			bucket->m_count = count;
		}
	}
}


mk_uint32_t mk_counter_get_count(mk_counter_t const* const self, mk_uint32_t const time)
{
	mk_uint32_t bucket_count;
	mk_uint32_t count;
	mk_uint32_t time_rounded;
	mk_uint32_t idx;
	mk_uint32_t i;
	mk_counter_bucket_t const* bucket;
	mk_uint32_t diff;
	mk_uint32_t delta;
	mk_uint32_t average;

	bucket_count = self->m_duration / self->m_precision + 1;

	count = 0;
	time_rounded = (time / self->m_precision) * self->m_precision;
	idx = self->m_index;
	for(i = 0; i != bucket_count - 1; ++i)
	{
		if(idx == 0)
		{
			idx = bucket_count - 1;
		}
		else
		{
			--idx;
		}
		bucket = mk_vector_mk_counter_bucket_t_cat(&self->m_buckets, idx);
		if(bucket->m_time == 0)
		{
			break;
		}
		diff = time_rounded - bucket->m_time;
		if(diff > self->m_duration)
		{
			break;
		}
		delta = diff;
		count += bucket->m_count;
	}
	if(delta == 0)
	{
		++delta;
	}
	average = (count * 1000) / delta;
	return average;
}
