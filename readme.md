
# colorchange
画像を読み込み、RGB値やYSH値を取得し、任意の数値を使用して再計算することで元画像の色を調整します。  
画像読み込み、GUIにはQtを使用しています。  

## Demo
加工前の画像  
![base](https://user-images.githubusercontent.com/12496951/181926016-4fbb045e-80c4-4409-a979-fc4b326cb1cf.PNG)  
  
RGBにゲインとオフセットを加えて赤っぽく加工した画像  
![ColorChange_RGB](https://user-images.githubusercontent.com/12496951/181926017-dc45a286-3143-45fe-9bb6-496cb70db79f.PNG)  
  
RGBからY, Cr, Cbを求め、さらにYSHを求めて色合いを調整後、Y, Cr, CbからRGBに戻して青っぽく加工した画像  
![ColorChange_YSH](https://user-images.githubusercontent.com/12496951/181926019-59728529-cec7-4a2a-ac20-bb9beab28af1.PNG)  
  

## Dependency
- MSVC 15+  
- Qt 5.13.1

## Build
CMakeLists.txtではQTDIRを環境変数から取得して使用しています。  
また、ここではWSL2とPowerShell、CMakeを使用したビルド方法を記述します。  
CMakeは環境変数のPATHへ追加しています。  

1. このリポジトリをクローンします。  
2. 以下のコマンドでビルドします。  
   ex. VS2017 の場合  
   powershell.exe cmake -S . -B build -G "\\"Visual Studio 15 2017 Win64\\""  
   powershell.exe cmake --build build  

   ex. VS2019以上の場合  
   powershell.exe cmake -S . -B build  
   powershell.exe cmake --build build  

3. 実行時に必要なDLL群はコピーしていません。実行の際には注意してください。


## License
This software is released under the MIT License, see LICENSE.

## References
[C言語で学ぶ実践CG・映像合成](https://www.ohmsha.co.jp/book/9784274500169/)  
[コンピュータ画像処理(改訂2版)](https://www.ohmsha.co.jp/book/9784274228193/)  
[ベッドの下で元カノの帰りを待っていたストーカー化する元カレの写真素材](https://www.pakutaso.com/20160432099post-7538.html)

