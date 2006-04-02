/*
  tre-filter.c: Histogram filter to quickly find regexp match candidates

  Copyright (c) 2004-2006 Ville Laurikari <vl@iki.fi>.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

*/

/* The idea of this filter is quite simple.  First, let's assume the
   search pattern is a simple string.  In order for a substring of a
   longer string to match the search pattern, it must have the same
   numbers of different characters as the pattern, and those
   characters must occur in the same order as they occur in pattern. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif /* HAVE_CONFIG_H */
#include <stdio.h>
#include "tre-internal.h"
#include "tre-filter.h"

int
tre_filter_find(const unsigned char *str, size_t len, tre_filter_t *filter)
{
  unsigned short counts[256];
  unsigned int i;
  unsigned int window_len = filter->window_len;
  tre_filter_profile_t *profile = filter->profile;
  const unsigned char *str_orig = str;

  DPRINT(("tre_filter_find: %.*s\n", len, str));

  for (i = 0; i < elementsof(counts); i++)
    counts[i] = 0;

  i = 0;
  while (*str && i < window_len && i < len)
    {
      counts[*str]++;
      i++;
      str++;
      len--;
    }

  while (len > 0)
    {
      tre_filter_profile_t *p;
      counts[*str]++;
      counts[*(str - window_len)]--;

      p = profile;
      while (p->ch)
	{
	  if (counts[p->ch] < p->count)
	    break;
	  p++;
	}
      if (!p->ch)
	{
	  DPRINT(("Found possible match at %d\n",
		  str - str_orig));
	  return str - str_orig;
	}
      else
	{
	  DPRINT(("No match so far...\n"));
	}
      len--;
      str++;
    }
  DPRINT(("This string cannot match.\n"));
  return -1;
}
