/***************************************************************************

MIT License

Copyright (c) 2018 FoxTeam

Permission is hereby granted, free of charge, to any person obtaining a copy
of this softwareand associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright noticeand this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*****************************************************************************/

#ifndef _VARDUMP_H
#define _VARDUMP_H

#include <io.h>
#include <stdio.h>
#include <errno.h>

// -----------------------------------------------------------
// These functions are not declared by Tiny C Compiler headers
//
// Home page:        https://bellard.org/tcc/
// Git repository:   git://repo.or.cz/tinycc.git
// -----------------------------------------------------------
#ifdef __TINYC__
errno_t __cdecl freopen_s(FILE **_File, const char *_Filename, const char *_Mode, FILE *_OldFile);
errno_t __cdecl fopen_s(FILE **_File, const char *_Filename, const char *_Mode);
#endif

#ifndef INVALID_HANDLE_VALUE
#ifdef _WIN64
#define INVALID_HANDLE_VALUE (void*)-1ULL
#else
#define INVALID_HANDLE_VALUE (void*)-1UL
#endif // _WIN64
#endif // ! INVALID_HANDLE_VALUE

void __cdecl vardump(void * ptr, size_t len, int padding);
void __cdecl fvardump(const char * filename, void * ptr, size_t len, int padding, int force);

#endif // ! _VARDUMP_H
