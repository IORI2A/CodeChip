/**************** Error handling ***************/
void DispalyErrorInfor(LPTSTR lpszFunction) 
{
    // Retrieve the system error message for the last-error code
    DWORD dw = GetLastError(); 
	LPVOID lpMsgBuf;
	FormatMessage(
	   FORMAT_MESSAGE_ALLOCATE_BUFFER | 
	   FORMAT_MESSAGE_FROM_SYSTEM |
	   FORMAT_MESSAGE_IGNORE_INSERTS,
	   NULL,
	   dw,
	   MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
	   (LPTSTR) &lpMsgBuf,
	   0, NULL );

	// Display the error message
	printf("%s failed with error %d: %s", lpszFunction, dw, (LPTSTR)lpMsgBuf);
	LocalFree(lpMsgBuf);

	/*****************************************************/
	//errno = GetLastError(); 
	//perror(lpszFunction);
	//errno = 0;
}