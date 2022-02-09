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

# Sample
This sample demonstrates creating and verifying CAdES-BES signature. 
```
package main

import (
	"fmt"

	"github.com/zxcvden/gocades"
)

func main() {
	// error handling omitted
	subjectName := "TestSubjectName"
	dataToSign := "Test data to be signed"

	store, _ := gocades.Store()
	defer store.Close()
	store.Open(gocades.CADESCOM_CONTAINER_STORE, "My", gocades.CAPICOM_STORE_OPEN_MAXIMUM_ALLOWED)
	certificates, _ := store.GetCertificates()
	certificates, _ = certificates.Find(gocades.CAPICOM_CERTIFICATE_FIND_SUBJECT_NAME, subjectName, true)
	certificate, _ := certificates.GetItem(1)
	signer, _ := gocades.Signer()
	signer.PutCertificate(*certificate)
	signedData, _ := gocades.SignedData()
	signedData.PutContent(dataToSign)
	signedMessage, _ := signedData.SignCades(*signer, gocades.CADESCOM_CADES_BES, false, gocades.CADESCOM_ENCODE_BASE64)
	fmt.Println("Signed message:")
	fmt.Println("======")
	fmt.Println(signedMessage)
	fmt.Println("======")
	fmt.Println()

	{
		fmt.Println("Verify result:")
		fmt.Println("======")
		signedData, _ := gocades.SignedData()
		signedData.VerifyCades(signedMessage, gocades.CADESCOM_CADES_BES, false)
		content, _ := signedData.GetContent()

		fmt.Println("Content:", content)
		certificates, _ := signedData.GetCertificates()
		fmt.Println("Signers:\n")
		count, _ := certificates.GetCount()
		for i := 1; i <= count; i++ {
			certificate, _ := certificates.GetItem(i)
			subjectName, _ := certificate.GetSubjectName()
			fmt.Println("SubjectName\t", subjectName)
			issuerName, _ := certificate.GetIssuerName()
			fmt.Println("IssuerName\t", issuerName)
			serialNumber, _ := certificate.GetSerialNumber()
			fmt.Println("SerialNumber\t", serialNumber)
			thumbprint, _ := certificate.GetThumbprint()
			fmt.Println("Thumbprint\t", thumbprint)
			validFrom, _ := certificate.GetValidFromDate()
			fmt.Println("Valid from\t", validFrom)
			validTo, _ := certificate.GetValidToDate()
			fmt.Println("Valid to\t", validTo)
			fmt.Println()
		}
		fmt.Println("======")
	}

}
```

Possible output
```
Signed message:
======
MIIF0gYJKoZIhvcNAQcCoIIFwzCCBb8CAQExDDAKBggqhQMHAQECAjA7BgkqhkiG9w0BBwGgLgQs
VABlAHMAdAAgAGQAYQB0AGEAIAB0AG8AIABiAGUAIABzAGkAZwBuAGUAZACgggMZMIIDFTCCAsSg
AwIBAgITEgBd1fbF2ZbppQocKgABAF3V9jAIBgYqhQMCAgMwfzEjMCEGCSqGSIb3DQEJARYUc3Vw
cG9ydEBjcnlwdG9wcm8ucnUxCzAJBgNVBAYTAlJVMQ8wDQYDVQQHEwZNb3Njb3cxFzAVBgNVBAoT
DkNSWVBUTy1QUk8gTExDMSEwHwYDVQQDExhDUllQVE8tUFJPIFRlc3QgQ2VudGVyIDIwHhcNMjIw
MjA5MTkyMDM4WhcNMjIwNTA5MTkzMDM4WjAaMRgwFgYDVQQDDA9UZXN0U3ViamVjdE5hbWUwZjAf
BggqhQMHAQEBATATBgcqhQMCAiQABggqhQMHAQECAgNDAARAxLmoiNX4yhhNyaE11aX1hthQi6NC
HsEghAd7/2BGF3Q7FnPxNQnbaL3ltfA204KIelzrdFhi/nMvnd6/KL+EmqOCAXcwggFzMA8GA1Ud
DwEB/wQFAwMH8AAwEwYDVR0lBAwwCgYIKwYBBQUHAwIwHQYDVR0OBBYEFO8nEp/1oB/ZaO+lsGer
2ULlqcFhMB8GA1UdIwQYMBaAFE6DPhRp7+xdepUrXxH+NzIWSVUrMFwGA1UdHwRVMFMwUaBPoE2G
S2h0dHA6Ly90ZXN0Y2EuY3J5cHRvcHJvLnJ1L0NlcnRFbnJvbGwvQ1JZUFRPLVBSTyUyMFRlc3Ql
MjBDZW50ZXIlMjAyKDEpLmNybDCBrAYIKwYBBQUHAQEEgZ8wgZwwZAYIKwYBBQUHMAKGWGh0dHA6
Ly90ZXN0Y2EuY3J5cHRvcHJvLnJ1L0NlcnRFbnJvbGwvdGVzdC1jYS0yMDE0X0NSWVBUTy1QUk8l
MjBUZXN0JTIwQ2VudGVyJTIwMigxKS5jcnQwNAYIKwYBBQUHMAGGKGh0dHA6Ly90ZXN0Y2EuY3J5
cHRvcHJvLnJ1L29jc3Avb2NzcC5zcmYwCAYGKoUDAgIDA0EAOvVCzZVF4m97FBcDP7Pu5j64hw9R
hvHDeF1zQDa+uffn0c34wfHZTn5Ww20dRx8AiJ35otRRdme2ndJgtQ1vszGCAlAwggJMAgEBMIGW
MH8xIzAhBgkqhkiG9w0BCQEWFHN1cHBvcnRAY3J5cHRvcHJvLnJ1MQswCQYDVQQGEwJSVTEPMA0G
A1UEBxMGTW9zY293MRcwFQYDVQQKEw5DUllQVE8tUFJPIExMQzEhMB8GA1UEAxMYQ1JZUFRPLVBS
TyBUZXN0IENlbnRlciAyAhMSAF3V9sXZlumlChwqAAEAXdX2MAoGCCqFAwcBAQICoIIBUjAYBgkq
hkiG9w0BCQMxCwYJKoZIhvcNAQcBMBwGCSqGSIb3DQEJBTEPFw0yMjAyMDkyMTIzNDNaMC8GCSqG
SIb3DQEJBDEiBCC9PLgTiuzgYxFXSnQxaEGZXbzUrTHni1UuUKcECfQQ9zCB5gYLKoZIhvcNAQkQ
Ai8xgdYwgdMwgdAwgc0wCgYIKoUDBwEBAgIEID5QTT/QBlFXg9lty9c9dtsG+ALSsVT+dV2Q0IC5
bmm+MIGcMIGEpIGBMH8xIzAhBgkqhkiG9w0BCQEWFHN1cHBvcnRAY3J5cHRvcHJvLnJ1MQswCQYD
VQQGEwJSVTEPMA0GA1UEBxMGTW9zY293MRcwFQYDVQQKEw5DUllQVE8tUFJPIExMQzEhMB8GA1UE
AxMYQ1JZUFRPLVBSTyBUZXN0IENlbnRlciAyAhMSAF3V9sXZlumlChwqAAEAXdX2MAoGCCqFAwcB
AQEBBEA2n4JDNgUaqgiFsapJjfYRiLxLoNusyghCvIdAVW+TNAq3PUg+K4Qnvdbq/i27floeaqOH
WdPMVh0QKxvsvHpx
======

Verify result:
======
Content: Test data to be signed
Signers:

SubjectName	 CN=TestSubjectName
IssuerName	 CN=CRYPTO-PRO Test Center 2, O=CRYPTO-PRO LLC, L=Moscow, C=RU, E=support@cryptopro.ru
SerialNumber	 12005DD5F6C5D996E9A50A1C2A0001005DD5F6
Thumbprint	 9B8B945AE90C060A147199B79BBE6A7B2AFF74A4
Valid from	 09.02.2022 19:20:38
Valid to	 09.05.2022 19:30:38

======
```

For more sample check samples folder or [official documentation samples](https://docs.cryptopro.ru/cades/plugin/plugin-samples)