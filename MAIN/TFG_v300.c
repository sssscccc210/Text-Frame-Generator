// text読み込んで、囲む処理
// 随所でコメントアウトしている部分は、デバッグに使用可能（使用した部分）です
// 2023/12/26 updated by KSY.

#include <stdio.h>
#include <stdlib.h>// exit()のため必要
#include <string.h>// strcpy()のため必要
#define MAX_LETTER_COUNT 2048// 一行のMAX文字数

FILE *fin;// インプットされたファイル
char InputFileName[256];// ファイル名
int maxLength;// 一行の最大半角分の文字数
char tmpString[MAX_LETTER_COUNT];// 一時保存用文字列

void ErrorExitConsole(){
	// 何か文字が入力されるまでコンソールは消さない
	printf("Press Return key to terminate\n");
	getchar();
	exit(1);
}

// u8len関数（UTF8の文字数をカウントする関数）
// →半角何文字分の枠があるかをカウントするように変更
// https://qiita.com/t-yama-3/items/7cba573b4cf23322dfc8
int u8len(const char *str)
{
    int count = 0;  // 文字数のカウント用
    int isPreviousFirstByte = 0;
    while (*str != '\0' && *str != '\r' && *str != '\n') {
        if ((*str & 0xC0) != 0x80) {// ビット積が0x80でないなら＝各文字の開始バイトなら
            count = (*str == '\t')? count+4 : count+1;// タブを考慮
            //count++;
            isPreviousFirstByte = 1;
        }
        else if(isPreviousFirstByte){// マルチバイト文字の2バイト目以降なら
            count++;// マルチバイト文字の2バイト目はcountに含める
            isPreviousFirstByte = 0;
        }
        str++;
    }
    return count;
}


int getMaxLength(){
	
	int i;// 一行ごとの文字カウント
	int maxCount = 0;// 現在までの最大カウント
	while(fgets(tmpString, MAX_LETTER_COUNT, fin) != NULL){// 一行ずつ取得（改行コード含む）し、NULLまで繰り返す
		i = u8len(tmpString);// 取得した行の半角何文字分かを取得
		if(i > maxCount) maxCount = i;// i>macCountなら、最大カウントを更新する
	}
	return maxCount;
}

void PrintBox(){
	int i;// 何文字目
	int blank;// 右の空白部分
	int blankLength;
	int fixedLength = (maxLength%2==0)?maxLength:maxLength+1;
	FILE *fout;
	
/* ファイル作成 */
	sprintf(InputFileName, "%s.export.txt", InputFileName);// 文字列結合
	fout = fopen(InputFileName, "wt");
	if (fout==NULL) {
		printf("can't open file <%s>\n",InputFileName);
		ErrorExitConsole();/*ファイルオープンエラーで緊急停止*/
	}

/* header */
	fprintf(fout, "┏");
	for(i = 0; i < fixedLength/2; i++){
		fprintf(fout, "━");
	}
	fprintf(fout, "┓\n");
	//printf("スペースの文字コード：%x\n", ' ');//0x20

/* main */
	while(fgets(tmpString, MAX_LETTER_COUNT, fin) != NULL){// 一行ずつ取得（改行コード含む）し、NULLまで繰り返す
		fprintf(fout, "┃");
		i = 0;
		while(tmpString[i] != '\0' && tmpString[i] != '\n' && tmpString[i] != '\r'){
			// タブを考慮
			if(tmpString[i] == '\t') fprintf(fout, "    ", tmpString[i]);
			else fprintf(fout, "%c", tmpString[i]);
			
			i++;
		}
		blankLength = fixedLength - u8len(tmpString);
		for(blank = 0; blank < blankLength; blank++){
			fprintf(fout, " ");
		}
		//fprintf(fout, "┃letters=%d, blankLength=%d\n", u8len(tmpString), blankLength);
		fprintf(fout, "┃\n");
		
		i = 0;
	}
	
/* footer */
	fprintf(fout, "┗");
	for(i = 0; i < fixedLength/2; i++){
		fprintf(fout, "━");
	}
	fprintf(fout, "┛\n");
	
/*ファイルのクローズ*/
	fclose(fout);
}


void main(int argc, char *argv[])
{
/*ファイル取得*/
	// ドラッグアンドドロップされたファイルを取得
	/*for(int a = 0; a<argc; a++){
		printf("[%d] = %s\n", a, argv[a]);
	}*/
	if(argc < 2){
		printf("** ERROR: NO FILE **\n");
		printf("枠囲みしたいファイルをexeにドラッグ＆ドロップして実行してください．\n");
		ErrorExitConsole();
	}else{
		strcpy(InputFileName, argv[1]);
	}
	
	//printf("読み込みファイル名 : ");
	//gets(InputFileName);/*読み込みファイル名の取得*/
	fin=fopen(InputFileName,"rt");
	if (fin==NULL) {
		printf("can't open file <%s>\n",InputFileName);
		ErrorExitConsole();/*ファイルオープンエラーで緊急停止*/
	}
	
// Maxの長さ調査
	maxLength = getMaxLength();
	printf("maxLength=%d\n", maxLength);
	//maxLength/= 2;// 罫線を引くMaxの数とする：全角なので半角/2の量になる
	
// 実際に出力する
	rewind(fin);// 一回先頭に戻す
	PrintBox();
	printf("%sを出力しました．\n", InputFileName);// InputFileNameの配列内が、PrintBox()で変更されている。
												// なのでそのまま表示する。
	

/*ファイルのクローズ*/
	fclose(fin);
	
// コンソールを閉じる（直消し）
	exit(0);
	//ExitConsole();
}
