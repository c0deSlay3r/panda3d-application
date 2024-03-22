# Panda3D application



## Build

### Unix

```
cd panda3d-application/
mkdir build
cd build
cmake -B . -S ../ -DPANDA3D_LIBS_DIR=<Path to Panda libs> -DPANDA3D_INCLUDE_DIR=<Path to Panda include>
cmake --build . --config <Build type> -j<Threads>
cd bin/
./PandaProg
```

### Windows
```
cd panda3d-application/
mkdir build
cd build
cmake -B . -S ../ -DPANDA3D_LIBS_DIR=<Path to Panda libs> -DPANDA3D_INCLUDE_DIR=<Path to Panda include>
cmake --build . --config <Build type> -j<Threads>
cd bin/
cp <Build type>/PandaProg.exe .
./PandaProg.exe
```
