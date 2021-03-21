#include "mk_assert.h"
#include "mk_check_ret.h"
#include "mk_macros.h"
#include "mk_allocator_global.h"


void MK_CONCAT3(mk_vector, X, construct)(MK_CONCAT3(mk_vector, X, t)* const self)
{
	self->m_array = MK_NULL;
	self->m_size = 0;
	self->m_capacity = 0;
}

void MK_CONCAT3(mk_vector, X, move_construct)(MK_CONCAT3(mk_vector, X, t)* const self, MK_CONCAT3(mk_vector, X, t)* const other)
{
	MK_ASSERT(self != other);
	MK_CONCAT3(mk_vector, X, construct)(self);
	MK_CONCAT3(mk_vector, X, swap)(self, other);
}

void MK_CONCAT3(mk_vector, X, move_assign)(MK_CONCAT3(mk_vector, X, t)* const self, MK_CONCAT3(mk_vector, X, t)* const other)
{
	MK_ASSERT(self != other);
	MK_CONCAT3(mk_vector, X, swap)(self, other);
}

void MK_CONCAT3(mk_vector, X, swap)(MK_CONCAT3(mk_vector, X, t)* const self, MK_CONCAT3(mk_vector, X, t)* const other)
{
	X* tmp_array;
	mk_size_t tmp_size;
	mk_size_t tmp_capacity;

	MK_ASSERT(self != other);

	tmp_array = self->m_array;
	self->m_array = other->m_array;
	other->m_array = tmp_array;

	tmp_size = self->m_size;
	self->m_size = other->m_size;
	other->m_size = tmp_size;

	tmp_capacity = self->m_capacity;
	self->m_capacity = other->m_capacity;
	other->m_capacity = tmp_capacity;
}

void MK_CONCAT3(mk_vector, X, destroy)(MK_CONCAT3(mk_vector, X, t)* const self)
{
	mk_size_t i;
	mk_size_t idx;
	X* value;

	for(i = 0; i != self->m_size; ++i)
	{
		idx = self->m_size - 1 - i;
		value = self->m_array + idx;
		MK_CONCAT(X, destroy)(value);
	}
	mk_allocator_global_deallocate(self->m_array);
}


mk_size_t MK_CONCAT3(mk_vector, X, size)(MK_CONCAT3(mk_vector, X, t) const* const self)
{
	return self->m_size;
}

mk_size_t MK_CONCAT3(mk_vector, X, capacity)(MK_CONCAT3(mk_vector, X, t) const* const self)
{
	return self->m_capacity;
}

mk_bool_t MK_CONCAT3(mk_vector, X, is_empty)(MK_CONCAT3(mk_vector, X, t) const* const self)
{
	return self->m_size == 0 ? MK_TRUE : MK_FALSE;
}

mk_bool_t MK_CONCAT3(mk_vector, X, is_full)(MK_CONCAT3(mk_vector, X, t) const* const self)
{
	return self->m_size == self->m_capacity ? MK_TRUE : MK_FALSE;
}

mk_size_t MK_CONCAT3(mk_vector, X, space)(MK_CONCAT3(mk_vector, X, t) const* const self)
{
	return self->m_capacity - self->m_size;
}

X const* MK_CONCAT3(mk_vector, X, cat)(MK_CONCAT3(mk_vector, X, t) const* const self, mk_size_t const idx)
{
	MK_ASSERT(idx < self->m_size);
	return self->m_array + idx;
}

X const* MK_CONCAT3(mk_vector, X, cbegin)(MK_CONCAT3(mk_vector, X, t) const* const self)
{
	return self->m_array;
}

X const* MK_CONCAT3(mk_vector, X, cend)(MK_CONCAT3(mk_vector, X, t) const* const self)
{
	return self->m_array + self->m_size;
}


X* MK_CONCAT3(mk_vector, X, at)(MK_CONCAT3(mk_vector, X, t)* const self, mk_size_t const idx)
{
	MK_ASSERT(idx < self->m_size);
	return self->m_array + idx;
}

X* MK_CONCAT3(mk_vector, X, begin)(MK_CONCAT3(mk_vector, X, t)* const self)
{
	return self->m_array;
}

X* MK_CONCAT3(mk_vector, X, end)(MK_CONCAT3(mk_vector, X, t)* const self)
{
	return self->m_array + self->m_size;
}

void MK_CONCAT3(mk_vector, X, reserve)(MK_CONCAT3(mk_vector, X, t)* const self, mk_size_t const size)
{
	mk_size_t double_capacity;
	mk_size_t new_capacity;
	mk_size_t real_allocation;
	X* new_array;
	mk_size_t i;
	X* old_value;
	X* new_value;

	if(size <= self->m_capacity)
	{
		return;
	}
	double_capacity = self->m_capacity * 2;
	new_capacity = double_capacity < size ? size : double_capacity;
	new_array = (X*)mk_allocator_global_allocate(new_capacity * sizeof(X), &real_allocation);
	MK_CHECK_CRASH(new_array);
	new_capacity = real_allocation / sizeof(X);
	for(i = 0; i != self->m_size; ++i)
	{
		old_value = self->m_array + i;
		new_value = new_array + i;
		MK_CONCAT(X, move_construct)(new_value, old_value);
		MK_CONCAT(X, destroy)(old_value);
	}
	mk_allocator_global_deallocate(self->m_array);
	self->m_array = new_array;
	self->m_capacity = new_capacity;
}

void MK_CONCAT3(mk_vector, X, resize)(MK_CONCAT3(mk_vector, X, t)* const self, mk_size_t const size)
{
	mk_size_t diff;
	mk_size_t i;
	mk_size_t idx;
	X* value;

	if(size < self->m_size)
	{
		diff = self->m_size - size;
		for(i = 0; i != diff; ++i)
		{
			idx = self->m_size - 1 - i;
			value = self->m_array + idx;
			MK_CONCAT(X, destroy)(value);
		}
		self->m_size -= diff;
	}
	else if(size > self->m_size)
	{
		MK_CONCAT3(mk_vector, X, reserve)(self, size);
		diff = size - self->m_size;
		for(i = 0; i != diff; ++i)
		{
			value = self->m_array + self->m_size + i;
			MK_CONCAT(X, construct)(value);
		}
		self->m_size += diff;
	}
}

X* MK_CONCAT3(mk_vector, X, push_back)(MK_CONCAT3(mk_vector, X, t)* const self, X const* const value)
{
	/* Beware, will not work with vec.push_back(vec[42]); but we don't care. */

	X* new_value;

	MK_CONCAT3(mk_vector, X, reserve)(self, self->m_size + 1);
	new_value = self->m_array + self->m_size;
	MK_CONCAT(X, copy_construct)(new_value, value);
	++self->m_size;
	return new_value;
}

void MK_CONCAT3(mk_vector, X, pop_back)(MK_CONCAT3(mk_vector, X, t)* const self)
{
	X* value;

	MK_ASSERT(self->m_size >= 1);
	value = self->m_array + self->m_size - 1;
	MK_CONCAT(X, destroy)(value);
	--self->m_size;
}

void MK_CONCAT3(mk_vector, X, clear)(MK_CONCAT3(mk_vector, X, t)* const self)
{
	mk_size_t i;
	mk_size_t idx;
	X* value;

	for(i = 0; i != self->m_size; ++i)
	{
		idx = self->m_size - 1 - i;
		value = self->m_array + idx;
		MK_CONCAT(X, destroy)(value);
	}
	self->m_size = 0;
}
