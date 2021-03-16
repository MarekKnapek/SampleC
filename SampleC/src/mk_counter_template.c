void MK_CONCAT9(mk_counter_, MK_T1, _, MK_T2, _, MK_T3, _, MK_T4, _construct)(MK_CONCAT9(mk_counter_, MK_T1, _, MK_T2, _, MK_T3, _, MK_T4, _t)* const self)
{
	mk_uint32_t i;
	MK_CONCAT3(mk_counter_bucket_, MK_T1, _t)* bucket;

	for(i = 0; i != MK_T2 / MK_T3 + 1; ++i)
	{
		bucket = self->m_buckets + i;
		bucket->m_time = 0;
		bucket->m_count = 0;
	}
	self->m_index = 0;
}

void MK_CONCAT9(mk_counter_, MK_T1, _, MK_T2, _, MK_T3, _, MK_T4, _destroy)(MK_CONCAT9(mk_counter_, MK_T1, _, MK_T2, _, MK_T3, _, MK_T4, _t)* const self)
{
}


void MK_CONCAT9(mk_counter_, MK_T1, _, MK_T2, _, MK_T3, _, MK_T4, _count)(MK_CONCAT9(mk_counter_, MK_T1, _, MK_T2, _, MK_T3, _, MK_T4, _t)* const self, MK_T1 const time, MK_T1 const count)
{
	MK_T1 time_rounded;
	MK_CONCAT3(mk_counter_bucket_, MK_T1, _t)* bucket;

	time_rounded = time / MK_T3;
	bucket = self->m_buckets + self->m_index;
	if(bucket->m_time == time_rounded)
	{
		bucket->m_count += count;
	}
	else
	{
		if(self->m_index == MK_T2 / MK_T3)
		{
			self->m_index = 0;
		}
		else
		{
			++self->m_index;
		}
		bucket = self->m_buckets + self->m_index;
		bucket->m_time = time_rounded;
		bucket->m_count = count;
	}
}


MK_T1 MK_CONCAT9(mk_counter_, MK_T1, _, MK_T2, _, MK_T3, _, MK_T4, _get_count)(MK_CONCAT9(mk_counter_, MK_T1, _, MK_T2, _, MK_T3, _, MK_T4, _t) const* const self, MK_T1 const time)
{
	mk_uint32_t count;
	mk_uint32_t time_rounded;
	mk_uint32_t idx;
	mk_uint32_t i;
	MK_CONCAT3(mk_counter_bucket_, MK_T1, _t) const* bucket;
	mk_uint32_t diff;
	mk_uint32_t average;

	count = 0;
	time_rounded = time / MK_T3;
	idx = self->m_index;
	for(i = 0; i != MK_T2 / MK_T3; ++i)
	{
		if(idx == 0)
		{
			idx = MK_T2 / MK_T3;
		}
		else
		{
			--idx;
		}
		bucket = self->m_buckets + idx;
		if(bucket->m_time == 0)
		{
			break;
		}
		diff = time_rounded - bucket->m_time;
		if(diff > MK_T2 / MK_T3)
		{
			break;
		}
		count += bucket->m_count;
	}
	average = (count * MK_T4) / MK_T2;
	return average;
}
