

LambdaConcept lcsniff software for [USB2Sniffer hardware](http://docs.lambdaconcept.com/usb2sniffer/) ([buy](http://shop.lambdaconcept.com/home/35-usb2-sniffer.html)).

![LCSniff running on macOS](docs/lcsniff-mac.png)

## Dependencies

Qt >=5.10

## Build instructions

### Qt Creator

Open lcsniff.pro with Qt Creator

### Linux

```
git submodule init
git submodule update
mkdir build
cd build
qmake ../lcsniff.pro
make -j
```

### macOS

```
git submodule init
git submodule update
brew install qt
mkdir build
cd build
qmake ../lcsniff.pro
make -j
```

### Windows Cross Compilation from Linux

#### Build MXE toolchain

https://mxe.cc

```
git clone https://github.com/mxe/mxe.git
cd mxe
make -j cc qt5
```

#### Install MXE or set PATH

```
export PATH=/xxx/mxe/usr/bin:$PATH
```

#### Cross compile (Static 32bits)

```
mkdir build-win-32
cd build-win-32
i686-w64-mingw32.static-qmake-qt5 ../lcsniff.pro
make -j

DIR=lcsniff-win-32
mkdir $DIR
cp release/lcsniff.exe $DIR
cp ../xbar/ft60x/FTD3XXLibrary/Win32/FTD3XX.dll $DIR
zip -r $DIR.zip $DIR
```

#### Cross compile (Static 64bits)

```
mkdir build-win-64
cd build-win-64
x86_64-w64-mingw32.static-qmake-qt5 ../lcsniff.pro
make -j

DIR=lcsniff-win-64
mkdir $DIR
cp release/lcsniff.exe $DIR
cp ../xbar/ft60x/FTD3XXLibrary/x64/FTD3XX.dll $DIR
zip -r $DIR.zip $DIR
```
