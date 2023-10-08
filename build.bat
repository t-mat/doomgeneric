@setlocal enabledelayedexpansion
@echo off
pushd "%~dp0"
set /a errorno=1
for /F "delims=#" %%E in ('"prompt #$E# & for %%E in (1) do rem"') do set "esc=%%E"

rem
rem Set Visual C++ environment for Windows, desktop, x64.
rem
rem https://github.com/Microsoft/vswhere
rem https://github.com/microsoft/vswhere/wiki/Find-VC#batch
rem

set "vswhere=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
if not exist "%vswhere%" (
  echo Can't find "vswhere.exe".   Please install the latest version of Visual Studio.
  goto :ERROR
)

set "InstallDir="
for /f "usebackq tokens=*" %%i in (`"%vswhere%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do (
  set "InstallDir=%%i"
)
if "%InstallDir%" == "" (
  echo Can't find Visual C++.   Please install the latest version of Visual C++.
  goto :ERROR
)

rem Set -no_logo
rem For details, see %InstallDir%\Common7\Tools\vsdevcmd\core\parse_cmd.bat
set __VSCMD_ARG_NO_LOGO=1

echo call "%InstallDir%\VC\Auxiliary\Build\vcvars64.bat"
call "%InstallDir%\VC\Auxiliary\Build\vcvars64.bat" || goto :ERROR


rem Build each *.sln file by msbuild for x64 with release configuration.
rem
rem https://docs.microsoft.com/visualstudio/msbuild/msbuild-command-line-reference

for %%i in (*.sln) do (
  echo msbuild "%%i"
  msbuild "%%i" /nologo /v:minimal /m /p:Configuration=Release /p:Platform=x64 /t:Clean,Build || goto :ERROR
)
echo Build Status -%esc%[92m SUCCEEDED %esc%[0m
set /a errorno=0
goto :END


:ERROR
echo Abort by error.
echo Build Status -%esc%[91m ERROR %esc%[0m


:END
popd
exit /B %errorno%
