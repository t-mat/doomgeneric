@setlocal enabledelayedexpansion
@echo off
pushd "%~dp0"
set /a errorno=1

set "EXEPATH=.\x64\Release"

call .\build.bat || goto :END

if not exist DOOM1.WAD (
  curl -LOJ https://distro.ibiblio.org/slitaz/sources/packages/d/doom1.wad
)

set "EXE="
for /f "tokens=*" %%i in ('where /f "%EXEPATH%:*.exe"') do ( set EXE=%%i )
if "%EXE%" == "" (
  echo ERROR - Can't find executable file in %EXEPATH%
  set /a errorno=1
  goto :ERROR
)

echo %EXE%
     %EXE% || goto :END

set /a errorno=0

:END
popd
exit /B %errorno%
