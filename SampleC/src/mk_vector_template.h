#include "mk_types.h"
#include "mk_macros.h"


struct MK_CONCAT3(mk_vector, X, s)
{
	X* m_array;
	mk_size_t m_size;
	mk_size_t m_capacity;
};
typedef struct MK_CONCAT3(mk_vector, X, s) MK_CONCAT3(mk_vector, X, t);


void MK_CONCAT3(mk_vector, X, construct)(MK_CONCAT3(mk_vector, X, t)* const self);
void MK_CONCAT3(mk_vector, X, move_construct)(MK_CONCAT3(mk_vector, X, t)* const self, MK_CONCAT3(mk_vector, X, t)* const other);
void MK_CONCAT3(mk_vector, X, move_assign)(MK_CONCAT3(mk_vector, X, t)* const self, MK_CONCAT3(mk_vector, X, t)* const other);
void MK_CONCAT3(mk_vector, X, swap)(MK_CONCAT3(mk_vector, X, t)* const self, MK_CONCAT3(mk_vector, X, t)* const other);
void MK_CONCAT3(mk_vector, X, destroy)(MK_CONCAT3(mk_vector, X, t)* const self);

mk_size_t MK_CONCAT3(mk_vector, X, size)(MK_CONCAT3(mk_vector, X, t) const* const self);
mk_size_t MK_CONCAT3(mk_vector, X, capacity)(MK_CONCAT3(mk_vector, X, t) const* const self);
mk_bool_t MK_CONCAT3(mk_vector, X, is_empty)(MK_CONCAT3(mk_vector, X, t) const* const self);
mk_bool_t MK_CONCAT3(mk_vector, X, is_full)(MK_CONCAT3(mk_vector, X, t) const* const self);
mk_size_t MK_CONCAT3(mk_vector, X, space)(MK_CONCAT3(mk_vector, X, t) const* const self);
X const* MK_CONCAT3(mk_vector, X, cat)(MK_CONCAT3(mk_vector, X, t) const* const self, mk_size_t const idx);
X const* MK_CONCAT3(mk_vector, X, cbegin)(MK_CONCAT3(mk_vector, X, t) const* const self);
X const* MK_CONCAT3(mk_vector, X, cend)(MK_CONCAT3(mk_vector, X, t) const* const self);

X* MK_CONCAT3(mk_vector, X, at)(MK_CONCAT3(mk_vector, X, t)* const self, mk_size_t const idx);
X* MK_CONCAT3(mk_vector, X, begin)(MK_CONCAT3(mk_vector, X, t)* const self);
X* MK_CONCAT3(mk_vector, X, end)(MK_CONCAT3(mk_vector, X, t)* const self);
void MK_CONCAT3(mk_vector, X, reserve)(MK_CONCAT3(mk_vector, X, t)* const self, mk_size_t const size);
void MK_CONCAT3(mk_vector, X, resize)(MK_CONCAT3(mk_vector, X, t)* const self, mk_size_t const size);
X* MK_CONCAT3(mk_vector, X, push_back)(MK_CONCAT3(mk_vector, X, t)* const self, X const* const value);
void MK_CONCAT3(mk_vector, X, pop_back)(MK_CONCAT3(mk_vector, X, t)* const self);
void MK_CONCAT3(mk_vector, X, clear)(MK_CONCAT3(mk_vector, X, t)* const self);
