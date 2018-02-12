/*
	Copyright (C) 2002  Mathieu Olivier

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 2
	of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to:

		Free Software Foundation, Inc.
		59 Temple Place - Suite 330
		Boston, MA  02111-1307, USA

*/

#ifndef JPEG_H
#define JPEG_H

#ifndef NO_JPEG

qboolean JPEG_OpenLibrary (void);
void JPEG_CloseLibrary (void);
qboolean JPEG_SaveImage_preflipped (const char *filename, int width, int height, unsigned char *data);

#else
#define JPEG_OpenLibrary() false
#define JPEG_CloseLibrary()
#define JPEG_SaveImage_preflipped(F,W,H,D) false
#endif

unsigned char* JPEG_LoadImage (const unsigned char *f, int filesize, int matchwidth, int matchheight);

#endif
