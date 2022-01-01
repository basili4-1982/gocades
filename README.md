GoCades
===

GoCades implements CryptoPro ECP Browser-Plugin interface for Go programming language.
Can be used for
- digitally signing/verifying data of CAdES-BES, CAdES-T, CAdES-X Long Type 1 types
- encrypting/decrypting data
- corresponding certificate operations

Requires CryptoPro CSP installed.

# Installation

Installation process described for Ubuntu 21.04
1. Install building tools:
```
sudo apt install cmake build-essential
```
2. Download [CryptoPro CSP](https://cryptopro.ru/products/csp/downloads), unpack and install:
```
tar xvf linux-amd64_deb.tgz
cd linux-amd64_deb
sudo ./install.sh
```
3. Install cprocsp-devel package:
```
sudo apt install ./lsb-cprocsp-devel_5.0*.deb
```
4. Download [CryptoPro ECP SDK](https://cryptopro.ru/products/cades/downloads), unpack and install:
```
tar xvf cades_linux_amd64.tar.gz
cd cades_linux_amd64
sudo apt install ./cprocsp-pki-cades*.deb ./cprocsp-pki-phpcades*.deb
```
5. Download and build Go package:
```
go get -d github.com/zxcvden/gocades
cd $GOPATH/src/github.com/zxcvden/gocades/ccades
mkdir build
cd build
cmake ..
make
```
6. Run GoCades tests:
```
go test github.com/zxcvden/gocades
```