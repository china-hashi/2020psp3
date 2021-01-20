# 課題5 レポート
学生番号：35319032　氏名：橋本千夏


## 課題
本課題では、以下の3つのプログラムを作成する。なお、出発駅、到着駅は、適宜変更しても良い。
- 赤迫駅を出発点として、深さ優先探索ですべての駅に到達可能なことを確認するプログラム。到達した駅名を出力するなど、各駅に1回到達したことを確認すること。  
- 赤迫駅を出発点として、幅優先探索ですべての駅に到達可能なことを確認するプログラム。到達した駅名を出力するなど、各駅に1回到達したことを確認すること。  
- 赤迫駅を出発点として、蛍茶屋駅までの最短所要時間ルートをダイクストラ法で見つけ、出力するプログラム
路線図、および、駅間の所要時間は下記のようになっている。  

1.使用するデータ  
路線図、及び、駅間の所要時間は下記のようになっている。なお、プログラムにおいて、駅名はArrayStation、グラフは隣接行列AdjacencyMatrixに保存されている。  

<img src=images/routemap.png width=600>  

```
typedef struct tagStation {
    char name[20];
    char kanji[16];
} Station;

Station ArrayStation[MAX_STATIONS] = {
    {"akasako", "赤迫"},
    {"nagasakidaigakumae", "長崎大学前"},
    {"nagasakiekimae", "長崎駅前"},
    {"shinchichukagai", "新地中華街"},
    {"ishibashi", "石橋"},
    {"sofukuji", "崇福寺"},
    {"shiminkaikan", "市民会館"},
    {"hotarujaya", "蛍茶屋"},
};

int AdjacencyMatrix[MAX_STATIONS][MAX_STATIONS] = {
    {0,  5,  0,  0,  0,  0,  0,  0},
    {5,  0, 16,  0,  0,  0,  0,  0},
    {0, 16,  0,  7,  0,  0,  5,  0},
    {0,  0,  7,  0,  7,  6, 10,  0},
    {0,  0,  0,  7,  0,  0,  0,  0},
    {0,  0,  0,  6,  0,  0, 10,  0},
    {0,  0,  5, 10,  0, 10,  0,  6},
    {0,  0,  0,  0,  0,  0,  6,  0},
};
```


2. 必須問題：実装する関数  
本課題では、以下の関数を実装する。  
(1) DepthFirstSearch: 深さ優先探索ですべての駅に到達可能なことを確認する  
    [入力]
    - int size: 駅の数　　
    - int matrix[size][size]: 隣接行列
    - int start: 出発駅のインデックス  

    [出力]  
    - なし。関数の出力はないが、関数内でprintf文を使うなど、すべての駅に到達可能なことをチェックすること。  


    (2) BreadthFirstSearch: 幅優先探索ですべての駅に到達可能なことを確認する  
    [入力]
    - int size: 駅の数　　
    - int matrix[size][size]: 隣接行列
    - int start: 出発駅のインデックス  

    [出力]  
    - なし。関数の出力はないが、関数内でprintf文を使うなど、すべての駅に到達可能なことをチェックすること。

    (3) SearchGraphByDijkstra: ダイクストラ法で、出発駅から到着駅までの最短所要時間ルートを探索する。  
    [入力]  
    - int start: 出発駅のインデックス
    - int goal: 到着駅のインデックス  
    - int size: 駅数  
    - int matrix[size][size]: 隣接行列  
    - NodeInfo arrayNodeInfo[size]:  

    [出力]  
    - return値: 出発駅から到着駅までの所要時間 
    - 関数内でprintf文を使い、最短ルートを出力すること

3. 補助関数  
以下の関数はすでに実装されており、利用することができる。
- PrintStationName: indexで指定される駅名を出力する
- StackInit: スタックを初期化する
- StackPush: スタックに値をプッシュする
- StackPop: スタックから値をポップする
- StackTop: スタックの先頭の値を取得する(スタックポインタは移動しない)
- StackIsEmpty: スタックが空か判断する。空の場合はTRUE、空でなければFALSEを返す。
- InitQueue: キューを初期化する
- EnQueue: キューに値を入れる
- DeQueue: キューから値を取り出す
- QueueIsEmpty: キューが空か判断する。空の場合はTRUE、空でなければFALSEを返す。
- main: メイン関数。深さ優先探索、幅優先探索、ダイクストラ法による最短経路探索処理を呼び出す。

4. チャレンジ課題  
赤迫駅を起点として、各駅にたどり着くまでのルートを、深さ優先探索、幅優先探索のそれぞれの場合で出力するようにプログラムを修正する。  
- 深さ優先探索のルート表示(10点)
- 幅優先探索のルート表示(10点)

## ソースコードの説明

l.112,113: visitedを初期化

1.117: 出発点をスタックにプッシュ

l.119: スタックが空でなければ以下の処理を繰り返す

l.120: スタックから1つポップ

l.122: ポップしたものが行ったことのない場所であれば以下の処理をする

l.123: 行ったことにする

l.127~129: そこから行ける場所をスタックにプッシュ

l.135~139: もしすべての場所に行っていなければエラー文を出力


l.212,213: visitedを初期化

l.217: 出発点をキューに入れる

l.219: キューが空でなければ以下の処理を繰り返す

l.220: キューから1つ取り出す

l.222: 取り出したものが行ったことのない場所であれば以下の処理をする

l.223: 行ったことにする

l.227~229: そこから行ける場所をキューにいれる

l.235~239: もしすべての場所に行っていなければエラー文を出力


l.255,256: costの値を無限大にする

l.258: スタート地点のcostを0にする

l.260,261: fixedの値を0にする

l.266~273: 行ったことのない場所の中から最小のcostを探す

l.276: 最小のcostの場所を確定

l.278,279: 確定した場所がgoalならばcostを返す

l.281~283: そこから行ける確定していない場所を探す

l.284~286: costを更新する

## 出力結果

```
===== Searched by Depth =====
Current station is 赤迫
Current station is 長崎大学前
Current station is 長崎駅前
Current station is 市民会館
Current station is 蛍茶屋
Current station is 崇福寺
Current station is 新地中華街
Current station is 石橋
All station was visited.
===== Searched by Breadth =====
Current station is 赤迫
Current station is 長崎大学前
Current station is 長崎駅前
Current station is 新地中華街
Current station is 市民会館
Current station is 石橋
Current station is 崇福寺
Current station is 蛍茶屋
All station was visited.
===== Searched by Dijkstra =====
Current station is 赤迫
Current station is 長崎大学前
Current station is 長崎駅前
Current station is 市民会館
Current station is 新地中華街
Current station is 蛍茶屋
Time Required: 32
```

## 修正履歴

