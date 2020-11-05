# 課題1 レポート
学籍番号:35319032　氏名:橋本千夏


## 課題
長崎県にある市町村別人口データを読み込み、IDを用いて検索し、該当する市町村名、人口を出力するプログラムを作成する。

1. 使用するデータ
長崎県の人口データは、nagasaki.csvに保存されている。
nagasaki.csvには、csv形式で以下のデータが含まれる
    - ID
    - 県名
    - 市町村名
    - 人口
    - 男性人口
    - 女性人口

    長崎県の市町村別人口データは、下記に構造体の配列に読み込まれる。

```C: 市町村別データ構造体
typedef struct {  
    int id;  
    char pref[13];  // UTF-8対応  
    char name[19];  // UTF-8対応  
    int population;  
    int m_population;  
    int f_population;  
} City;  
```



2. 必須問題：実装する関数  
本課題では、以下の関数を実装する。  
   (1) LinearSearch：IDをキーとし、リニアサーチで市町村を検索する。  
    [入力]
    - int key: 検索する市町村のID
    - City arrayCity[]: 検索対象の都市別人口データ(配列)
    - int size: データの数  

    [出力]  
    - return値: IDが合致した配列データのindex。IDが一致するデータがない場合は-1。

    (2) BinarySearch: IDをキーとし、バイナリサーチで市町村を検索する。  
    [入力]
    - int key: 検索する市町村のID
    - City arrayCity[]: 検索対象の都市別人口データ(配列)
    - int left: バイナリサーチを行う配列のindex(左端)
    - int right: バイナリサーチを行う配列のindex(右端)  

    [出力]  
    - return値: IDが合致した配列データのindex。IDが一致するデータがない場合は-1。


3. 補助関数
以下の関数はすでに実装されており、利用することができる。  
- PrintCity: 特定の市町村別人口データを出力する  
- PrintArray: 市町村別人口データをすべて出力する  
- LoadData: 市町村別人口データを読み込み、City型の配列に格納する  
- main: メイン関数。データをロードし、リニアサーチ、バイナリサーチを呼び出す  


## ソースコードの説明
l.71: posがsizeより小さい場合、以下の処理を繰り返す

l.72: もしkeyとarrayCity[pos].idが同じであれば以下の処理をする

l.73: 変数resultにposを代入

l.74: if関数をbreakする

l.78: 変数resultを返す

l.87: right-leftが0以上ならば以下の処理を繰り返す

l.88: posの値をリストの中心にする

l.89: もしkeyとarrayCity[pos].idが同じであれば以下の処理をする

l.90: 変数resultにposを代入

l.91: if関数をbreakする

l.92: もしkeyがarrayCity[pos].idより大きければ以下の処理をする

l.93: leftにpos+1を代入

l.95: 上記２つ以外ならばrightにpos-1を代入

l.99: 変数resultを返す

## 出力結果
```
===== linear search =====
City ID?42321
42321, 長崎県, 東彼杵町, 8298, 3886, 4412

===== binary search =====
City ID?42321
42321, 長崎県, 東彼杵町, 8298, 3886, 4412

```
===== linear search =====
City ID?43321
city was not found

===== binary search =====
City ID?43321
city was not found

## 修正履歴

