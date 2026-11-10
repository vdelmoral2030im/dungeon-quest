@echo off
REM ==========================================================================
REM probar.bat  -  Corre todas las pruebas de tests\ en Windows.
REM Uso: doble clic, o escribe  .\probar.bat  en la terminal.
REM ==========================================================================
setlocal enabledelayedexpansion

set MODULOS=
for %%f in (src\*.c) do (
    if /I not "%%~nxf"=="main.c" set MODULOS=!MODULOS! %%f
)

if not exist bin mkdir bin
set FALLAS=0

for %%t in (tests\test_*.c) do (
    echo.
    echo   ===== %%~nt =====
    gcc -Wall -Wextra -std=c99 -Iinclude -Itests -o bin\%%~nt.exe %%t !MODULOS! -lm
    if errorlevel 1 (
        echo   No compila: lee los errores de arriba.
        set /a FALLAS+=1
    ) else (
        bin\%%~nt.exe
        if errorlevel 1 set /a FALLAS+=1
    )
)

echo.
if !FALLAS!==0 (
    echo   TODAS LAS PRUEBAS PASAN
) else (
    echo   Archivos de prueba con fallas: !FALLAS!
)
echo.
pause
