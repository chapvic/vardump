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

#include "vardump.h"

#ifdef _WIN64
	const char * hexmask = "%08I64X: ";
#else
	const char * hexmask = "%08X: ";
#endif // ! _WIN64

static void _dump(FILE* handle, void * ptr, size_t len, int padding) {
	int pad;
	size_t l;
	unsigned char *p, *pp, c;
	const char * padstr = "   ";

	p = ptr;
	while (len) {
		fprintf_s(handle, hexmask, p);
		pp = p;
		l = len;
		pad = padding;
		do fprintf_s(handle, " %02X", *(unsigned char *)p++);
			while (--pad && --len);
		if (pad)
			while(pad--) fprintf_s(handle, padstr);
		fprintf_s(handle, padstr);
		p = pp;
		len = l;
		pad = padding;
		do {
			c = *(unsigned char *)p++;
			fprintf_s(handle, "%c", c < 32 ? '.' : c);
			--len;
		}
		while(--pad && len);
		fprintf_s(handle, "\n");
	}
}

void __cdecl fvardump(const char * filename, void * ptr, size_t len, int padding, int force) {
	FILE* handle;

	if(!ptr || !len) return;
	if(!filename) {
		if(freopen_s(&handle, "CONOUT$", "w", stdout)) return;
	} else {
		if (force) handle = fopen(filename, "a+");
		else {
			if(fopen_s(&handle, filename, "a+")) return;
		}
	}
	if(handle == INVALID_HANDLE_VALUE) return;
	_dump(handle, ptr, len, padding);
	fflush(handle);
	if (filename) fclose(handle);
}

void __cdecl vardump(void * ptr, size_t len, int padding) {
	if(!ptr || !len) return;
	_dump(stdout, ptr, len, padding);
}
