# ScreenPointPixel
C++ OpenGL/ES Plugin used to get the color of pixel on a screen point.

This was tested on Windows and Android and should work when complied. You can try for iOS and other platforms but they are not tested.

If you can't setup C++ with Android Studio, simply use the Android Studio project already setup here 
https://github.com/programmercert/ScreenPointPixel/tree/master/AndroidProject

This 

When compiled/built from Android Studio, it should give you two 
folders (armeabi-v7a and x86 at ```<ProjectDirectory>\app\build\intermediates\cmake\release\obj``` directory. They should both contain the shared *.so library. If you can't compile this for Android Studio then use the copy of Android Studio project I made for this here.

Place both folders in your Unity project folders at ```Assets\Plugins\Android\libs```.

You should now have:

```
Assets\Plugins\Android\libs\armeabi-v7a\libScreenPointPixel-lib.so.
```

and

```
Assets\Plugins\Android\libs\x86\libScreenPointPixel-lib.so.
```

TEST:

Create a small simple RawImage component and position it to the top-right of the screen. 
Drag that RawImage to the rawImageColor slot from the script in ScreenPointPixel/Csharp/ScreenPointPixel.cs. When you click anywhere on the screen, 
the pixel color of that screen point should shown on that rawImageColor RawImage.
