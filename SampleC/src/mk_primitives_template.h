#include "mk_macros.h"


void MK_CONCAT(X, construct)(X* const self);
void MK_CONCAT(X, copy_construct)(X* const self, X const* const other);
void MK_CONCAT(X, move_construct)(X* const self, X* const other);
void MK_CONCAT(X, destroy)(X* const self);
