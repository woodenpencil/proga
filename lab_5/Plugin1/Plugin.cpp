#include "dll.h"
#include <stdio.h>

BOOLEAN GetAuthor(LPSTR buffer, DWORD dwBufferSize, DWORD *pdwBytesWritten) 
{
	int result = _snprintf_s(buffer, dwBufferSize, 20, "Anton Antonov");
	*pdwBytesWritten = result;
	return result;
}

BOOLEAN GetDescription(LPSTR buffer, DWORD dwBufferSize, DWORD *pdwBytesWritten)
{
	int result = _snprintf_s(buffer, dwBufferSize, 17, "Executes ipconfig and shows network info");
	*pdwBytesWritten = result;
	return result;
}

VOID Execute() 
{
	system("ipconfig");
	printf("\n");
}