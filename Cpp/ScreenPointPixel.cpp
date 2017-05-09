#include "ScreenPointPixel.h"

#include <string>
#include <stdlib.h>

//For Debugging
//#include "DebugCPP.h"
//http://stackoverflow.com/questions/43732825/use-debug-log-from-c/43735531#43735531

//Unity Headers
#include "UnityPluginHeaders/IUnityInterface.h"
#include "UnityPluginHeaders/IUnityGraphics.h"


//Headers for Windows
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN64) || defined(WINAPI_FAMILY)
#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <stdlib.h>
#include "glext.h"
#pragma comment(lib, "opengl32.lib")

//--------------------------------------------------

//Headers for Android
#elif defined(ANDROID) || defined(__ANDROID__)
#include <jni.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
//Link lGLESv2 in the CMakeList.txt file
//LOCAL_LDLIBS += -lGLESv2

//--------------------------------------------------

//Headers for MAC and iOS
//http://nadeausoftware.com/articles/2012/01/c_c_tip_how_use_compiler_predefined_macros_detect_operating_system
#elif defined(__APPLE__) && defined(__MACH__)
//Apple OSX and iOS (Darwin)
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR == 1
//iOS in Xcode simulator
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
#elif TARGET_OS_IPHONE == 1
//iOS on iPhone, iPad, etc.
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
#elif TARGET_OS_MAC == 1
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#endif

//--------------------------------------------------

//Headers for Linux
#elif defined(__linux__)
#include <GL/gl.h>
#include <GL/glu.h>
#endif

static void* screenPointPixelData = nullptr;
static int _x;
static int _y;
static int _width;
static int _height;

//----------------------------Enable Screenshot-----------------------------
void initScreenPointPixel(void* buffer, int x, int y, int width, int height) {
    screenPointPixelData = buffer;
    _x = x;
    _y = y;
    _width = width;
    _height = height;
}

void updateScreenPointPixelBufferPointer(void* buffer) {
    screenPointPixelData = buffer;
}

void updateScreenPointPixelCoordinate(int x, int y) {
    _x = x;
    _y = y;
}

void updateScreenPointPixelSize(int width, int height) {
    _width = width;
    _height = height;
}

int GetScreenPixels(void* buffer, int x, int y, int width, int height) {
    if (glGetError())
        return -1;

    //glReadPixels(x, y, width, height, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, buffer);
    glReadPixels(x, y, width, height, GL_RGBA, GL_UNSIGNED_BYTE, buffer);

    if (glGetError())
        return -2;
    return 0;
}

//----------------------------UNITY RENDERING CALLBACK-----------------------------

// Plugin function to handle a specific rendering event
static void UNITY_INTERFACE_API OnRenderEventScreenPointPixel(int eventID)
{
    //Put rendering code below
    if (screenPointPixelData == nullptr) {
        //Debug::Log("Pointer is null", Color::Red);
        return;
    }
    int result = GetScreenPixels(screenPointPixelData, _x, _y, _width, _height);

    //std::string log_msg = "Cobol " + std::to_string(result);
    //Debug::Log(log_msg, Color::Green);
}

// Freely defined function to pass a callback to plugin-specific scripts
extern "C" UnityRenderingEvent UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API
GetRenderEventScreenPointPixelFunc()
{
    return OnRenderEventScreenPointPixel;
}

//------------------------------------