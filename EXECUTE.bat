@========================================
@rem 2023/12/26 updated by KSY.
@rem 文字化けしないように実行し，
@rem 成功したら開く，失敗したらそのまま
@rem という動作をするだけ
@========================================

@echo off
rem 最初はSJIS
rem chcp 932

rem ドロップしたファイルのフルパス（ダブルクオートなし）「C:\work dir\test.txt」
rem echo input: %~1
rem pauseで「続行するには何か押せ」を表示できる
rem pause

rem exe実行時はUTF-8
chcp 65001

rem "call"だと、exeが終了するまで待機する
call TFG_v3.exe %~1

rem 終了コードを取得0：成功, 1：エラー
if %ERRORLEVEL%==0 (
  rem 成功なら開く
  echo Success! Opening the file...
  start %~1.export.txt
)

exit /b