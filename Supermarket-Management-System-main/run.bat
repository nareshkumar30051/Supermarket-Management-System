@echo off
cd /d "%~dp0"

gcc main.c inventory.c billing.c reports.c -o supermarket.exe

if errorlevel 1 (
    echo Compilation failed!
    pause
    exit /b 1
)

supermarket.exe
pause