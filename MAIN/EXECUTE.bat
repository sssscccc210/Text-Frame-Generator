@========================================
@rem 2023/12/26 updated by KSY.
@rem �����������Ȃ��悤�Ɏ��s���C
@rem ����������J���C���s�����炻�̂܂�
@rem �Ƃ�����������邾��
@========================================

@echo off
rem �ŏ���SJIS
rem chcp 932

rem �h���b�v�����t�@�C���̃t���p�X�i�_�u���N�I�[�g�Ȃ��j�uC:\work dir\test.txt�v
rem echo input: %~1
rem pause�Łu���s����ɂ͉��������v��\���ł���
rem pause

rem exe���s����UTF-8
chcp 65001

rem "call"���ƁAexe���I������܂őҋ@����
call TFG_v3.exe %~1

rem �I���R�[�h���擾0�F����, 1�F�G���[
if %ERRORLEVEL%==0 (
  rem �����Ȃ�J��
  echo Success! Opening the file...
  start %~1.export.txt
)

exit /b