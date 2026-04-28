@echo off
setlocal

if "%~1"=="" (
    echo =======================================================
    echo                   MENU DE TESTES
    echo =======================================================
    set choice=T
    set /p choice="Qual teste deseja executar? (Numero do teste ou 'T' para todos) [T]: "
) else (
    set choice=%~1
)

if /i "%choice%"=="T" (
    echo.
    echo Executando todos os testes da pasta...
    echo.
    for %%f in (teste*.cpp) do (
        call :run_test "%%f"
    )
    goto :end
)

if not exist "teste%choice%.cpp" (
    echo.
    echo [ERRO] O arquivo teste%choice%.cpp nao foi encontrado.
    goto :end
)

echo.
call :run_test "teste%choice%.cpp"
goto :end

:run_test
echo =======================================================
echo Compilando %~1...
g++ -Wall -Wextra -std=c++17 bigint.cpp "%~1" -o "%~n1.exe"
if %ERRORLEVEL% NEQ 0 (
    echo.
    echo [ERRO] Falha ao compilar %~1!
    echo.
) else (
    echo [OK] Compilacao concluida. Executando %~n1.exe:
    echo -------------------------------------------------------
    "%~n1.exe"
    echo -------------------------------------------------------
    echo.
)
exit /b

:end
pause