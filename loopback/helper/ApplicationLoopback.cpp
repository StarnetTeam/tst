#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include "LoopbackCapture.h"

int wmain(int argc, wchar_t* argv[])
{
    if (argc < 2) return 2;
    DWORD processId = wcstoul(argv[1], nullptr, 0);
    if (!processId) return 3;
    _setmode(_fileno(stdout), _O_BINARY);
    CLoopbackCapture capture;
    HRESULT hr = capture.StartCaptureAsync(processId, true, nullptr);
    if (FAILED(hr)) return static_cast<int>(hr);
    while (true) Sleep(1000);
}
