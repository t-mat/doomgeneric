@echo off
pushd "%~dp0"

rmdir /s /q .vs 2>nul
rmdir /s /q x64 2>nul

popd
