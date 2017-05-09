#ifndef ANDROIDSCREENSHOT_NATIVE_LIB_H
#define ANDROIDSCREENSHOT_NATIVE_LIB_H

#define DLLExport __declspec(dllexport)

extern "C"
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN64) || defined(WINAPI_FAMILY)
DLLExport void initScreenPointPixel(void* buffer, int x, int y, int width, int height);
DLLExport void updateScreenPointPixelBufferPointer(void* buffer);
DLLExport void updateScreenPointPixelCoordinate(int x, int y);
DLLExport void updateScreenPointPixelSize(int width, int height);
int GetScreenPixels(void* buffer, int x, int y, int width, int height);

#else
void initScreenPointPixel(void *buffer, int x, int y, int width, int height);
void updateScreenPointPixelBufferPointer(void *buffer);
void updateScreenPointPixelCoordinate(int x, int y);
void updateScreenPointPixelSize(int width, int height);

int GetScreenPixels(void *buffer, int x, int y, int width, int height);
#endif
}
#endif //ANDROIDSCREENSHOT_NATIVE_LIB_H
