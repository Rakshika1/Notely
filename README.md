# Notely

This is a sample project for Desktop application development. The project is based on `ImGui` (docking branch), `GLFW` and `OpenGL`. For developing this project you need following tools installed on your system,
1. Git
2. CMake
3. A build system compatible with your system, eg. Make on Linux, MSBuild on Windows or Xcode on MacOS.

Ensure ypu have the required tools installed on your system.

## Setup
To setup the project follow these steps:
1. Fork the repository and clone it, or directly clone from the command below,
```
git clone --recursive https://github.com/ragnar-vallhala/Notely.git
```
2. Build the project,
```
cd Notely
mkdir build
cd build
cmake ..
cmake --build .
```
3. Once the build is successfull, you will get the executable in build directory or any sub-directory of build based on the build system you use. You can open this application to find the deafult example of ImGui.
## Task

Now modify the project to build an application with a button and a number displayed. The number starts from 0 and is increases by 1 when you click on the button. 


