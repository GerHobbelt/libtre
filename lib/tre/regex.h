/*
  Kludge to allow other apps and libraries to load the TRE-specific regex.h header file
  using this line on MSVC platforms too:
  
  #include <tre/regex.h>
  
  Windows does not support file links, so this is 'faking' it.
  (Actually, Windows 2K/XP/... _do_ support links, but that's not a very common
   feature used [on dev boxes] anyhow.)
*/

#ifndef LIBTRE_TRE_REGEX_H
#define LIBTRE_TRE_REGEX_H 1

#include "../regex.h"

#endif


