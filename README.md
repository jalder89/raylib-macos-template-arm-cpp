# MacOS Raylib ARM Setup - VS Code C++

After several days of troubleshooting and digging I was finally able to get raylib built and working in VS Code on Apple Silicon Macs. 
A big part of this was thanks to [PaperDomo101](https://github.com/Paperdomo101) and their reddit [tutorial comment](https://www.reddit.com/r/raylib/comments/sh586x/comment/hv4ezz5/?utm_source=share&utm_medium=web2x&context=3). 

## 1: Build from source: https://github.com/raysan5/raylib
THIS IS IMPORTANT FOR ARM<br><br>
The prepackaged solutions are for non-ARM based chips, you must build from source for ARM64
    - Download raylib-master
    - Open terminal to raylib-master/src
    - Run make
    - This will produce libraylib.a

## 2: Create your template folder
In the template folder create these folders:
  - lib - This is your libraries folder for includes, like raylib.h
  - bin - This is your build folder
  - src - This is your app source
  - assets - This is your app assets like images, sounds, etc

Add libraylib.a, raylib.h, and raymath.g from your built raylib source to the `lib` folder

## 3: Open your template folder in VS Code

## 4: Create a new main.cpp entry file in your `src` folder:

```
#include <raylib.h>
#include <raymath.h>

int main()
{
	InitWindow(400, 224, "Template-4.0.0");
	
	while (!WindowShouldClose()) {
        	BeginDrawing();
            	ClearBackground(RAYWHITE);
    
        	EndDrawing();
    	}
   	 CloseWindow();
   	 return 0;
}
```

## 5: Create a new makefile at the root directory of your template.
Just call the file makefile without an extension for now.

## 6: Add these arguments and variables to the make file
IMPORTANT NOTE: build recipes (build_osx) must be spaced using a tab character, copy/pasting Markdown tends to convert tabs to spaces:

```
COMPILER = clang++
SOURCE_LIBS = -Ilib/
MACOS_OPT = -std=c++17 -Llib/ -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL lib/libraylib.a
MACOS_OUT = -o "bin/build_osx"
CFILES = src/*.cpp

build_osx:
    $(COMPILER) $(CFILES) $(SOURCE_LIBS) $(MACOS_OUT) $(MACOS_OPT)
```

## 7: Open main.cpp and hit F5 to start debugging. Select the `clang` or `clang++` option, an error will occur and we’ll be editing the generated files.

## 8: Under the new hidden .vscode folder, you should find 'launch.json', 'settings.json', and 'tasks.json'

## 9: In tasks.json, change the "type" from "cppbuild" to "shell". 
- This specifies that we are running a Terminal program. Next set the "label" to "Build OSX". 
- This is just for display when we hit 'F5' to Start Debugging. 

## 10: Set the "command" to "make build_osx". 
- This tells VSCode to run our makefile. 

## 11: Lastly set "options" to {"cwd": "${workspaceFolder}"}. 
- This lets VSCode know where we are working from.
- You can remove the rest of the generated parameters ("args", "problemMatcher" etc.). 
- Save and close tasks.json.

You tasks.json file should now look similar to this:

```
{
    "tasks": [
        {
            "type": "shell",
            "label": "Build OSX",
            "command": "make build_osx",
            "options": {
                "cwd": "${workspaceFolder}"
            },
            "detail": "Raylib Debugger."
        }
    ],
    "version": "2.0.0"
}
```

## 13: Open launch.json and change the following:
- “program" from "${fileDirname}/${fileBasenameNoExtension}" to "${workspaceFolder}/bin/build_osx"
- "cwd" from "${fileDirname}" to "${workspaceFolder}"
- "preLaunchTask" from "C/C++: clang build active file" to "Build MacOS”
- Save and close launch.json.

Your launch.json should now look similar to this:

```
{
    "configurations": [
        {
            "name": "(lldb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/bin/build_osx",
            "cwd": "${workspaceFolder}",
            // This is to ensure VScode prints the program log in the debug console
            "internalConsoleOptions": "openOnSessionStart", 
            "MIMode": "lldb",
            "preLaunchTask": "Build OSX"
            }
    ],
    "version": "2.0.0"
}
```

## 14: Finally, if you chose clang++ you will have c_cpp_properties.json file, if not create it.

## 15: Once you have c_cpp_properties.json open, add or edit the configuration to match this code:

```
{
    "configurations": [
        {
            "name": "Mac",
            "includePath": [
                "${workspaceFolder}/**"
            ],
            "defines": [],
            "macFrameworkPath": [
                "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks"
            ],
            "compilerPath": "/usr/bin/clang++",
            "cStandard": "c11",
            "cppStandard": "c++17",
            "intelliSenseMode": "macos-clang-arm64"
        }
    ],
    "version": 4
}
```

You should now be able to build in VS Code with F5 and things should work, have fun developing!
