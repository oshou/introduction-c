- open, close
  - http://linuxc.info/file/file1/
- 国際化(i18n)
  - Unicode対応のためUTF-8(Unicode Transformation Format-8)、UTF-16(Unicode Transformation Format-16)の普及が進んでいる。
  - internationalizationの略。
- locale
  - 国際化のための仕組み
  - 国、地域、文字コードの組み合わせのこと。
- ディレクトリーツリーの標準規格
  - FHS

- /
  - bin
  - sbin
  - lib
  - lib64
  - etc
  - dev
  - proc
  - sys

- /bin, /sbinはディストリビューション側でいれるもの。
  ユーザー側で入れるものは/opt もしくは/usr/local/binにいれる
- tmpとvartmpの違い
  - /tmp -->再起動で消える
  - /var/tmp --> 再起動で消えない

- ディレクトリを分ける基準
  - 複数ホストで共用するか(/usr or /var)
  - 読み込み専用で運用するか
  - アーキテクチャ依存か(/usr/lib or /usr/share)

- ディレクトリもファイルの一種


## spawn.c
- zombieを回避する方法
  1. fork()したらwait()する
  2. ダブルfork
  3. sigaction()を使う
- proc
  - psやpstreeも/procの情報を使って情報を集めている。
- プロセスグループとセッション
  - すべてのプロセスはそれぞれただ1つのプロセスグループとセッションに所属している。
  - 「ps -j」でプロセスグループやセッションを確認可能
    - PID: プロセスID
    - PGID: プロセスグループID
    - SID: セッションID
  - プロセスグループとは
    - shell等のように複数プロセスをまとめて管理したい場合に使う。
    - 例えば複数パイプを挟むコマンドを使った場合は、Ctrl+Cでパイプでつながれたプロセス群をまとめて止める(停止シグナルを送る)べき
    - PID = PGIDであるプロセスはプロセスグループリーダーと呼ばれる。
  - セッションとは
    - ユーザのログインからログアウトまでの流れを管理するための概念
    - 結果として1つのセッションは1つのプロセスグループをまとめる形になる。
  - 制御端末とは
    - セッションと関連付けられた端末の事。
    - 「ps -ef」
    - tty1, tty2, pts/0等
