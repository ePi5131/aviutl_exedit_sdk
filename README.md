# aviutl_exedit_sdk v1.2
## これは何？
AviUtlと拡張編集の中身をガチャガチャするときに使うライブラリ

## 使用方法
`aviutl.hpp`と`exedit.hpp`があるディレクトリをインクルードパスに追加
AviUtlっぽいことをしたければとりあえず`aviutl.hpp`を、拡張編集っぽいことをしたければ`exedit.hpp`を読めば全部持ってくる
欲しい型を個別に`aviutl/*.hpp`などから取ってきてもよい

## ライセンス
1条項BSD
詳細は LICENSE を見ること

## 更新履歴

### v1.2
- 変更: `ExEdit::FilterProcInfo`の詳細を反映
- 変更: `ExEdit::Filter::Flag::bit11`を削除
- 修正: `PixelBGRA`→`PixelYCA`の変換係数がおかしかった
- 修正: `ExEdit::ExdataUse::Type`の基底を指定してなかったのでレイアウトが壊れてた

### v1.1
- 変更: `AviUtl::Exfunc`の1.10での共有メモリ関連の追加関数の詳細を反映
- 変更: `ExEdit::Cache`の詳細を反映
- 変更: `ExEdit::UndoInfo`の詳細を反映
- 変更: `Exedit::Exdata`の`efAudioFile,efWaveForm`の詳細を反映
- 変更: `ExEdit::FilterProcInfo`の`unknown_camera_idx`を`v_func_idx`に変更
- 修正: `AviUtl::OutputPlugin`の`name2,information2,filefilter2`の型は`char[256]`ではなく`char[260]`
- 修正: `AviUtl::Exfunc::yc2rgb`の引数型が壊れてた
- 修正: 規格外のVLAISを1要素配列にした (これでも範囲外参照はダメなんだけど)
- 修正: 実装依存であるところのmulticharacter literalを排除
- 修正: MS拡張であるところのP1280依存を排除
- 修正: `ExEdit::Filter::func_window_init`の戻り値型は`BOOL`ではなく`int`
