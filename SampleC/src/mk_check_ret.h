#ifndef INCLUDE_GUARD_MK_CHECK_RET
#define INCLUDE_GUARD_MK_CHECK_RET


#define MK_CHECK_RET(X) do{ if(!(X)){ mk_report(__LINE__); return; } }while(MK_FALSE, MK_FALSE)
#define MK_CHECK_RET_F(X) do{ if(!(X)){ mk_report(__LINE__); return MK_FALSE; } }while(MK_FALSE, MK_FALSE)
#define MK_CHECK_CRASH(X) do{ if(!(X)){ mk_report(__LINE__); mk_crash(); } }while(MK_FALSE, MK_FALSE)


void mk_report(int const line);
void mk_crash(void);


#endif
