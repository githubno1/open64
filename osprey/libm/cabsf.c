/*
 * Copyright 2003, 2004, 2005, 2006 PathScale, Inc.  All Rights Reserved.
 */

/*

  Copyright (C) 2000, 2001 Silicon Graphics, Inc.  All Rights Reserved.

  This program is free software; you can redistribute it and/or modify it
  under the terms of version 2.1 of the GNU Lesser General Public License 
  as published by the Free Software Foundation.

  This program is distributed in the hope that it would be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

  Further, this software is distributed without any warranty that it is
  free of the rightful claim of any third person regarding infringement 
  or the like.  Any license provided herein, whether implied or 
  otherwise, applies only to this software file.  Patent licenses, if
  any, provided herein do not apply to combinations of this program with 
  other software, or any other product whatsoever.  

  You should have received a copy of the GNU Lesser General Public 
  License along with this program; if not, write the Free Software 
  Foundation, Inc., 59 Temple Place - Suite 330, Boston MA 02111-1307, 
  USA.

  Contact information:  Silicon Graphics, Inc., 1600 Amphitheatre Pky,
  Mountain View, CA 94043, or:

  http://www.sgi.com

  For further information regarding this notice, see:

  http://oss.sgi.com/projects/GenInfo/NoticeExplan

*/



/* ====================================================================
 * ====================================================================
 *
 * Module: cabsf.c
 * $Revision: 1.5 $
 * $Date: 04/12/21 14:58:20-08:00 $
 * $Author: bos@eng-25.internal.keyresearch.com $
 * $Source: /home/bos/bk/kpro64-pending/libm/SCCS/s.cabsf.c $
 *
 * Revision history:
 *  20-Jun-93 - Original Version
 *
 * Description:	source code for cabsf function
 *
 * ====================================================================
 * ====================================================================
 */

static char *rcs_id = "$Source: /home/bos/bk/kpro64-pending/libm/SCCS/s.cabsf.c $ $Revision: 1.5 $";

#include "libm.h"

struct __fcabs_s { float r, i; };

extern	float	__hypotf(float, float);

#if defined(mips) && !defined(__GNUC__)
extern	float	fcabs(struct __fcabs_s);
extern	float	cabsf(struct __fcabs_s);

#pragma weak fcabs = __cabsf
#pragma weak cabsf = __cabsf
#endif

#if defined(BUILD_OS_DARWIN) /* Mach-O doesn't support aliases */
#elif defined(__GNUC__)
extern  float  __cabsf(struct __fcabs_s);
float    cabsf() __attribute__ ((weak, alias ("__cabsf")));
#endif

float
__cabsf( z )
struct __fcabs_s z;
{

	return __hypotf(z.r, z.i);
}

