
#ifndef _PP_PROJ_H_
#define _PP_PROJ_H_
//***********************************************************************************
// C header for accessing PMAC Global, CSGlobal, Ptr vars
// _PPScriptMode_ for Pmac Script like access global & csglobal
// global Mypvar - access with "Mypvar"
// global Myparray(32) - access with "Myparray(i)"
// csglobal Myqvar - access with "Myqvar(i)" where "i" is Coord #
// csglobal Myqarray(16) - access with "Myqvar(i,j)" where "j" is index
// _EnumMode_ for Pmac enum data type checking on Set & Get global functions
// Example
// global Mypvar
// csglobal Myqvar
// "SetGlobalVar(Myqvar, data)" will give a compile error because its a csglobal var.
// "SetCSGlobalVar(Mypvar, data)" will give a compile error because its a global var.
//************************************************************************************

#ifdef _PPScriptMode_
enum globalP {_globalP_=-1};
enum globalParray {_globalParray_=-1};
enum csglobalQ {_csglobalQ_=-1};
enum csglobalQarray {_csglobalQarray_=-1};

enum ptrM {_ptrM_=-1};
enum ptrMarray {_ptrMarray_=-1};
#define	george	pshm->P[8192]
#define	contador	pshm->P[8193]
#define	GantryMode	pshm->P[8194]
#define	Ch2MaxAdc	pshm->P[8195]
#define	Ch2RmsPeakCur	pshm->P[8196]
#define	Ch2RmsContCur	pshm->P[8197]
#define	Ch2TimeAtPeak	pshm->P[8198]
#define	Ch4MaxAdc	pshm->P[8199]
#define	Ch4RmsPeakCur	pshm->P[8200]
#define	Ch4RmsContCur	pshm->P[8201]
#define	Ch4TimeAtPeak	pshm->P[8202]
#define	Motor4Homed	pshm->P[8203]
#define	Motor4HomeSpeed	pshm->P[8204]
#define	Motor4HomeOffset	pshm->P[8205]
#define	Motor2Homed	pshm->P[8206]
#define	Motor2HomeSpeed	pshm->P[8207]
#define	Motor2HomeOffset	pshm->P[8208]
#define	MovError	pshm->P[8209]
#define	MovError2	pshm->P[8210]
#define	VelError	pshm->P[8211]
#ifndef _PP_PROJ_HDR_
  void SetEnumGlobalVar(enum globalP var, double data)
  {
    pshm->P[var] = data;
  }

  double GetEnumGlobalVar(enum globalP var)
  {
    return pshm->P[var];
  }

  void SetEnumGlobalArrayVar(enum globalParray var, unsigned index, double data)
  {
    pshm->P[(var + index)%MAX_P] = data;
  }

  double GetEnumGlobalArrayVar(enum globalParray var, unsigned index)
  {
    return pshm->P[(var + index)%MAX_P];
  }

  void SetEnumCSGlobalVar(enum csglobalQ var, unsigned cs, double data)
  {
    pshm->Coord[cs % MAX_COORDS].Q[var] = data;
  }

  double GetEnumCSGlobalVar(enum csglobalQ var, unsigned cs)
  {
    return pshm->Coord[cs % MAX_COORDS].Q[var];
  }

  void SetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs, double data)
  {
    pshm->Coord[cs % MAX_COORDS].Q[(var + index)%MAX_Q] = data;
  }

  double GetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs)
  {
    return pshm->Coord[cs % MAX_COORDS].Q[(var + index)%MAX_Q];
  }

  void SetEnumPtrVar(enum ptrM var, double data)
  {
    im_write(pshm->Mdef + var, data, &pshm->Ldata);
  }

  double GetEnumPtrVar(enum ptrM var)
  {
    return im_read(pshm->Mdef + var, &pshm->Ldata);
  }

  void SetEnumPtrArrayVar(enum ptrMarray var, unsigned index, double data)
  {
    im_write(pshm->Mdef + ((var + index)%MAX_M), data, &pshm->Ldata);
  }

  double GetEnumPtrArrayVar(enum ptrMarray var, unsigned index)
  {
    return im_read(pshm->Mdef + ((var + index)%MAX_M), &pshm->Ldata);
  }

  #define SetGlobalVar(i, x)              SetEnumGlobalVar(i, x)
  #define SetGlobalArrayVar(i, j, x)      SetEnumGlobalArrayVar(i, j, x)
  #define GetGlobalVar(i)                 GetEnumGlobalVar(i)
  #define GetGlobalArrayVar(i, j)         GetEnumGlobalArrayVar(i, j)

  #define SetCSGlobalVar(i, j, x)         SetEnumCSGlobalVar(i, j, x)
  #define SetCSGlobalArrayVar(i, j, k, x) SetEnumCSGlobalArrayVar(i, j, k, x)
  #define GetCSGlobalVar(i, j)            GetEnumCSGlobalVar(i, j)
  #define GetCSGlobalArrayVar(i, j, k)    GetEnumCSGlobalArrayVar(i, j, k)

  #define SetPtrVar(i, x)                 SetEnumPtrVar(i, x)
  #define SetPtrArrayVar(i, j, x)         SetEnumPtrArrayVar(i, j, x)
  #define GetPtrVar(i)                    GetEnumPtrVar(i)
  #define GetPtrArrayVar(i, j)            GetEnumPtrArrayVar(i, j)

#else

  void SetEnumGlobalVar(enum globalP var, double data);
  double GetEnumGlobalVar(enum globalP var);
  void SetEnumGlobalArrayVar(enum globalParray var, unsigned index, double data);
  double GetEnumGlobalArrayVar(enum globalParray var, unsigned index);
  void SetEnumCSGlobalVar(enum csglobalQ var, unsigned cs, double data);
  double GetEnumCSGlobalVar(enum csglobalQ var, unsigned cs);
  void SetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs, double data);
  double GetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs);
  void SetEnumPtrVar(enum ptrM var, double data);
  double GetEnumPtrVar(enum ptrM var);
  void SetEnumPtrArrayVar(enum ptrMarray var, unsigned index, double data);
  double GetEnumPtrArrayVar(enum ptrMarray var, unsigned index);

  #define SetGlobalVar(i, x)              SetEnumGlobalVar(i, x)
  #define SetGlobalArrayVar(i, j, x)      SetEnumGlobalArrayVar(i, j, x)
  #define GetGlobalVar(i)                 GetEnumGlobalVar(i)
  #define GetGlobalArrayVar(i, j)         GetEnumGlobalArrayVar(i, j)

  #define SetCSGlobalVar(i, j, x)         SetEnumCSGlobalVar(i, j, x)
  #define SetCSGlobalArrayVar(i, j, k, x) SetEnumCSGlobalArrayVar(i, j, k, x)
  #define GetCSGlobalVar(i, j)            GetEnumCSGlobalVar(i, j)
  #define GetCSGlobalArrayVar(i, j, k)    GetEnumCSGlobalArrayVar(i, j, k)

  #define SetPtrVar(i, x)                 SetEnumPtrVar(i, x)
  #define SetPtrArrayVar(i, j, x)         SetEnumPtrArrayVar(i, j, x)
  #define GetPtrVar(i)                    GetEnumPtrVar(i)
  #define GetPtrArrayVar(i, j)            GetEnumPtrArrayVar(i, j)

#endif
// end of #ifdef _PPScriptMode_
#else
#ifdef _EnumMode_
enum globalP {_globalP_=-1
,george=8192
,contador=8193
,GantryMode=8194
,Ch2MaxAdc=8195
,Ch2RmsPeakCur=8196
,Ch2RmsContCur=8197
,Ch2TimeAtPeak=8198
,Ch4MaxAdc=8199
,Ch4RmsPeakCur=8200
,Ch4RmsContCur=8201
,Ch4TimeAtPeak=8202
,Motor4Homed=8203
,Motor4HomeSpeed=8204
,Motor4HomeOffset=8205
,Motor2Homed=8206
,Motor2HomeSpeed=8207
,Motor2HomeOffset=8208
,MovError=8209
,MovError2=8210
,VelError=8211};
enum globalParray {_globalParray_=-1};
enum csglobalQ {_csglobalQ_=-1};
enum csglobalQarray {_csglobalQarray_=-1};
enum ptrM {_ptrM_=-1};
enum ptrMarray {_ptrMarray_=-1};
#ifndef _PP_PROJ_HDR_
  void SetEnumGlobalVar(enum globalP var, double data)
  {
    pshm->P[var] = data;
  }

  double GetEnumGlobalVar(enum globalP var)
  {
    return pshm->P[var];
  }

  void SetEnumGlobalArrayVar(enum globalParray var, unsigned index, double data)
  {
    pshm->P[(var + index)%MAX_P] = data;
  }

  double GetEnumGlobalArrayVar(enum globalParray var, unsigned index)
  {
    return pshm->P[(var + index)%MAX_P];
  }

  void SetEnumCSGlobalVar(enum csglobalQ var, unsigned cs, double data)
  {
    pshm->Coord[cs % MAX_COORDS].Q[var] = data;
  }

  double GetEnumCSGlobalVar(enum csglobalQ var, unsigned cs)
  {
    return pshm->Coord[cs % MAX_COORDS].Q[var];
  }

  void SetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs, double data)
  {
    pshm->Coord[cs % MAX_COORDS].Q[(var + index)%MAX_Q] = data;
  }

  double GetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs)
  {
    return pshm->Coord[cs % MAX_COORDS].Q[(var + index)%MAX_Q];
  }

  void SetEnumPtrVar(enum ptrM var, double data)
  {
    im_write(pshm->Mdef + var, data, &pshm->Ldata);
  }

  double GetEnumPtrVar(enum ptrM var)
  {
    return im_read(pshm->Mdef + var, &pshm->Ldata);
  }

  void SetEnumPtrArrayVar(enum ptrMarray var, unsigned index, double data)
  {
    im_write(pshm->Mdef + ((var + index)%MAX_M), data, &pshm->Ldata);
  }

  double GetEnumPtrArrayVar(enum ptrMarray var, unsigned index)
  {
    return im_read(pshm->Mdef + ((var + index)%MAX_M), &pshm->Ldata);
  }

  #define SetGlobalVar(i, x)              SetEnumGlobalVar(i, x)
  #define SetGlobalArrayVar(i, j, x)      SetEnumGlobalArrayVar(i, j, x)
  #define GetGlobalVar(i)                 GetEnumGlobalVar(i)
  #define GetGlobalArrayVar(i, j)         GetEnumGlobalArrayVar(i, j)

  #define SetCSGlobalVar(i, j, x)         SetEnumCSGlobalVar(i, j, x)
  #define SetCSGlobalArrayVar(i, j, k, x) SetEnumCSGlobalArrayVar(i, j, k, x)
  #define GetCSGlobalVar(i, j)            GetEnumCSGlobalVar(i, j)
  #define GetCSGlobalArrayVar(i, j, k)    GetEnumCSGlobalArrayVar(i, j, k)

  #define SetPtrVar(i, x)                 SetEnumPtrVar(i, x)
  #define SetPtrArrayVar(i, j, x)         SetEnumPtrArrayVar(i, j, x)
  #define GetPtrVar(i)                    GetEnumPtrVar(i)
  #define GetPtrArrayVar(i, j)            GetEnumPtrArrayVar(i, j)

#else

  void SetEnumGlobalVar(enum globalP var, double data);
  double GetEnumGlobalVar(enum globalP var);
  void SetEnumGlobalArrayVar(enum globalParray var, unsigned index, double data);
  double GetEnumGlobalArrayVar(enum globalParray var, unsigned index);
  void SetEnumCSGlobalVar(enum csglobalQ var, unsigned cs, double data);
  double GetEnumCSGlobalVar(enum csglobalQ var, unsigned cs);
  void SetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs, double data);
  double GetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs);
  void SetEnumPtrVar(enum ptrM var, double data);
  double GetEnumPtrVar(enum ptrM var);
  void SetEnumPtrArrayVar(enum ptrMarray var, unsigned index, double data);
  double GetEnumPtrArrayVar(enum ptrMarray var, unsigned index);

  #define SetGlobalVar(i, x)              SetEnumGlobalVar(i, x)
  #define SetGlobalArrayVar(i, j, x)      SetEnumGlobalArrayVar(i, j, x)
  #define GetGlobalVar(i)                 GetEnumGlobalVar(i)
  #define GetGlobalArrayVar(i, j)         GetEnumGlobalArrayVar(i, j)

  #define SetCSGlobalVar(i, j, x)         SetEnumCSGlobalVar(i, j, x)
  #define SetCSGlobalArrayVar(i, j, k, x) SetEnumCSGlobalArrayVar(i, j, k, x)
  #define GetCSGlobalVar(i, j)            GetEnumCSGlobalVar(i, j)
  #define GetCSGlobalArrayVar(i, j, k)    GetEnumCSGlobalArrayVar(i, j, k)

  #define SetPtrVar(i, x)                 SetEnumPtrVar(i, x)
  #define SetPtrArrayVar(i, j, x)         SetEnumPtrArrayVar(i, j, x)
  #define GetPtrVar(i)                    GetEnumPtrVar(i)
  #define GetPtrArrayVar(i, j)            GetEnumPtrArrayVar(i, j)

#endif
// end of #ifdef _EnumMode_
#else
// ***** Standard default mode *****
#define george 8192
#define contador 8193
#define GantryMode 8194
#define Ch2MaxAdc 8195
#define Ch2RmsPeakCur 8196
#define Ch2RmsContCur 8197
#define Ch2TimeAtPeak 8198
#define Ch4MaxAdc 8199
#define Ch4RmsPeakCur 8200
#define Ch4RmsContCur 8201
#define Ch4TimeAtPeak 8202
#define Motor4Homed 8203
#define Motor4HomeSpeed 8204
#define Motor4HomeOffset 8205
#define Motor2Homed 8206
#define Motor2HomeSpeed 8207
#define Motor2HomeOffset 8208
#define MovError 8209
#define MovError2 8210
#define VelError 8211
#endif
#endif
#endif //_PP_PROJ_H_
