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


