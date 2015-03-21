@echo off
cd %~dp0

md out
md out\release
md out\debug

echo Generating build files for [Release]
cd %~dp0\out\release
cmake -G Ninja -DCMAKE_BUILD_TYPE=Release %~dp0

echo Generating build files for [Debug]
cd %~dp0\out\debug
cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug %~dp0

cd %~dp0
