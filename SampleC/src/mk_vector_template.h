#include "mk_types.h"
#include "mk_macros.h"


struct MK_CONCAT3(mk_vector_, X, _s)
{
	X* m_array;
	mk_size_t m_size;
	mk_size_t m_capacity;
};
typedef struct MK_CONCAT3(mk_vector_, X, _s) MK_CONCAT3(mk_vector_, X, _t);


void MK_CONCAT3(mk_vector_, X, _construct)(MK_CONCAT3(mk_vector_, X, _t)* const self);
void MK_CONCAT3(mk_vector_, X, _move_construct)(MK_CONCAT3(mk_vector_, X, _t)* const self, MK_CONCAT3(mk_vector_, X, _t)* const other);
void MK_CONCAT3(mk_vector_, X, _move_assign)(MK_CONCAT3(mk_vector_, X, _t)* const self, MK_CONCAT3(mk_vector_, X, _t)* const other);
void MK_CONCAT3(mk_vector_, X, _swap)(MK_CONCAT3(mk_vector_, X, _t)* const self, MK_CONCAT3(mk_vector_, X, _t)* const other);
void MK_CONCAT3(mk_vector_, X, _destroy)(MK_CONCAT3(mk_vector_, X, _t)* const self);

mk_size_t MK_CONCAT3(mk_vector_, X, _size)(MK_CONCAT3(mk_vector_, X, _t) const* const self);
mk_size_t MK_CONCAT3(mk_vector_, X, _capacity)(MK_CONCAT3(mk_vector_, X, _t) const* const self);
mk_bool_t MK_CONCAT3(mk_vector_, X, _is_empty)(MK_CONCAT3(mk_vector_, X, _t) const* const self);
mk_bool_t MK_CONCAT3(mk_vector_, X, _is_full)(MK_CONCAT3(mk_vector_, X, _t) const* const self);
mk_size_t MK_CONCAT3(mk_vector_, X, _space)(MK_CONCAT3(mk_vector_, X, _t) const* const self);
X const* MK_CONCAT3(mk_vector_, X, _cat)(MK_CONCAT3(mk_vector_, X, _t) const* const self, mk_size_t const idx);
X const* MK_CONCAT3(mk_vector_, X, _cbegin)(MK_CONCAT3(mk_vector_, X, _t) const* const self);
X const* MK_CONCAT3(mk_vector_, X, _cend)(MK_CONCAT3(mk_vector_, X, _t) const* const self);

X* MK_CONCAT3(mk_vector_, X, _at)(MK_CONCAT3(mk_vector_, X, _t)* const self, mk_size_t const idx);
X* MK_CONCAT3(mk_vector_, X, _begin)(MK_CONCAT3(mk_vector_, X, _t)* const self);
X* MK_CONCAT3(mk_vector_, X, _end)(MK_CONCAT3(mk_vector_, X, _t)* const self);
void MK_CONCAT3(mk_vector_, X, _reserve)(MK_CONCAT3(mk_vector_, X, _t)* const self, mk_size_t const size);
void MK_CONCAT3(mk_vector_, X, _resize)(MK_CONCAT3(mk_vector_, X, _t)* const self, mk_size_t const size);
X* MK_CONCAT3(mk_vector_, X, _push_back)(MK_CONCAT3(mk_vector_, X, _t)* const self, X const* const value);
void MK_CONCAT3(mk_vector_, X, _pop_back)(MK_CONCAT3(mk_vector_, X, _t)* const self);
void MK_CONCAT3(mk_vector_, X, _clear)(MK_CONCAT3(mk_vector_, X, _t)* const self);
