#include "mk_macros.h"


void MK_CONCAT(X, _construct)(X* const self);
void MK_CONCAT(X, _copy_construct)(X* const self, X const* const other);
void MK_CONCAT(X, _move_construct)(X* const self, X* const other);
void MK_CONCAT(X, _destroy)(X* const self);
