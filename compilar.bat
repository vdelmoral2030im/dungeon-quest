@echo off
REM ==========================================================================
REM compilar.bat  -  Compila Dungeon Quest en Windows (cmd o PowerShell).
REM Uso: doble clic, o escribe  .\compilar.bat  en la terminal.
REM ==========================================================================
setlocal enabledelayedexpansion

set FUENTES=
for %%f in (src\*.c) do set FUENTES=!FUENTES! %%f

gcc -Wall -Wextra -std=c99 -Iinclude -o dungeon.exe !FUENTES! -lm
if errorlevel 1 (
    echo.
    echo   Hubo errores. Lee el PRIMERO: suele causar todos los demas.
    pause
    exit /b 1
)

echo.
echo   Listo. Ejecuta:   .\dungeon.exe
echo.
pause
