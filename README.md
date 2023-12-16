[JA](#ja)<br>
[EN](#en)

# *JA*
ZIPファイルに同封の[Readme](MAIN/01-ReadMe.txt)に本ツールに関する詳細が載っています．
## 概要
UTF-8N（UTF-8のBOMなし）で保存されたtxt, Cファイル等のテキストを枠囲みします．<br>
日本語（全角）と半角が混在しているファイルにも対応しています．

## インストール
[Releases](https://github.com/sssscccc210/Text-Frame-Generator/releases)より，最新バージョンのZIPをダウンロードし，展開してください．

## 使用方法

1. 展開したフォルダに枠囲みしたいファイルを移動します（ **`EXECUTE.bat`** と同一のフォルダに移動）．
2. 枠囲みしたいファイルを **`EXECUTE.bat`** にドラッグ＆ドロップします．
3. 枠囲み処理されたtxtファイルが出力されます（**`XXX.export.txt`**）．<br>
出力に成功した場合，自動でファイルを開きます．<br>
エラーが発生した場合，コンソールに表示されます．

## 注意
1. ファイルは，**UTF-8N**（UTF-8のBOMなし）で保存してください．BOMありのUTF-8では，先頭部分にバグが起こります（手作業で取り除けますが）．
2. ファイルを複数D&Dしても，一つのファイルに対してのみ実行されます．
3. 同一フォルダ内で作業してください．<br>
※展開したフォルダ内に枠囲みするファイルを移動すると良いです

---

# *En*
## Overview
Frame text in txt, C, ..., that is saved as UTF-8N (without UTF-8 BOM file).<br>
Files with mixed Japanese (full-width) and half-width characters are also supported.

## Install
Download and extract the latest version of the ZIP from [Releases](https://github.com/sssscccc210/Text-Frame-Generator/releases).

## How to use
1. Move the file you want to frame in the expanded folder (move it to the same folder as **`EXECUTE.bat`**). 
2. Drag and drop the file to be framed onto **`EXECUTE.bat`**. 
3. A framed txt file will be output (**`XXX.export.txt`**).<br>
If the output is successful, the file will be opened automatically.<br>
If an error occurs, it will be displayed in the console.

## Attention
1. Files should be saved as **UTF-8N** (UTF-8 without BOM). UTF-8 with BOM causes a bug at the beginning (which can be removed manually).
2. Even if multiple files are D&D'd, only one file will be executed.
3. Work in the same folder.<br>
It is better to move the file to be framed into the expanded folder.

---
2023/12/16.
