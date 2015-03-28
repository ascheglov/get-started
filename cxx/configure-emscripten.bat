@echo off
cd %~dp0

md out-js
md out-js\release
md out-js\debug

echo Generating build files for [Release]
cd %~dp0\out-js\release
cmake -G Ninja -DCMAKE_TOOLCHAIN_FILE=%EMSCRIPTEN%\CMake\Modules\Platform\Emscripten.cmake -DCMAKE_BUILD_TYPE=Release %~dp0

echo Generating build files for [Debug]
cd %~dp0\out-js\debug
cmake -G Ninja -DCMAKE_TOOLCHAIN_FILE=%EMSCRIPTEN%\CMake\Modules\Platform\Emscripten.cmake -DCMAKE_BUILD_TYPE=Debug %~dp0

cd %~dp0
