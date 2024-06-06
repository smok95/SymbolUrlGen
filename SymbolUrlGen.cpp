#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <shlwapi.h>
#include <wininet.h>
#include <dbghelp.h>

#pragma comment(lib, "shlwapi")
#pragma comment(lib, "dbghelp")

void PrintUsage()
{
	_tprintf(_T("Usage: SymbolUrlGen.exe <file path>\n"));
}

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc <= 1)
	{
		PrintUsage();
		return 1;
	}

#if defined(UNICODE) || defined(_UNICODE)
	SYMSRV_INDEX_INFOW sii = { 0 };
	sii.sizeofstruct = sizeof(sii);
	if (SymSrvGetFileIndexInfoW(argv[1], &sii, 0))
#else
	SYMSRV_INDEX_INFO sii = { 0 };
	sii.sizeofstruct = sizeof(sii);
	if (SymSrvGetFileIndexInfo(argv[1], &sii, 0))
#endif
	{
		TCHAR szUrl[INTERNET_MAX_URL_LENGTH];
		wnsprintf(
			szUrl, ARRAYSIZE(szUrl),
			_T("http://msdl.microsoft.com/download/symbols/%s/%08x%04x%04x%02x%02x%02x%02x%02x%02x%02x%02x%x/%s"),
			sii.pdbfile,
			sii.guid.Data1, sii.guid.Data2, sii.guid.Data3,
			sii.guid.Data4[0], sii.guid.Data4[1],
			sii.guid.Data4[2], sii.guid.Data4[3],
			sii.guid.Data4[4], sii.guid.Data4[5],
			sii.guid.Data4[6], sii.guid.Data4[7],
			sii.age, sii.pdbfile);
		_tprintf(_T("URL: %s\n"), szUrl);
	}
	else
	{
		_tprintf(_T("Failed to get symbol information.\n"));
	}

	return 0;
}
