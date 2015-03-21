@echo off
cd %~dp0

md out-vc
cd out-vc

cmake ..

cd ..
pause
