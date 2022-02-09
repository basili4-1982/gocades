package main

import (
	"fmt"

	"github.com/zxcvden/gocades"
)

func GetCertificate(subjectName string) (certificate *gocades.GoCadesCertificate, e error) {
	store, err := gocades.Store()
	if err != nil {
		return nil, err
	}
	defer store.Close()
	err = store.Open(gocades.CADESCOM_CONTAINER_STORE, "My", gocades.CAPICOM_STORE_OPEN_MAXIMUM_ALLOWED)
	if err != nil {
		return nil, err
	}
	certificates, err := store.GetCertificates()
	if err != nil {
		return nil, err
	}
	certificates, err = certificates.Find(gocades.CAPICOM_CERTIFICATE_FIND_SUBJECT_NAME, subjectName, true)
	if err != nil {
		return nil, err
	}
	certificate, err = certificates.GetItem(1)
	if err != nil {
		return nil, err
	}
	return certificate, nil
}

func Sign(certificate *gocades.GoCadesCertificate, data string) (signedMessage string, e error) {
	signer, err := gocades.Signer()
	if err != nil {
		return "", err
	}
	err = signer.PutCertificate(*certificate)
	if err != nil {
		return "", err
	}
	signedData, err := gocades.SignedData()
	if err != nil {
		return "", err
	}
	err = signedData.PutContent(data)
	if err != nil {
		return "", err
	}
	signedMessage, err = signedData.SignCades(*signer, gocades.CADESCOM_CADES_BES, false, gocades.CADESCOM_ENCODE_BASE64)
	if err != nil {
		return "", err
	}
	return signedMessage, nil
}

func Verify(signedMessage string) error {
	signedData, err := gocades.SignedData()
	if err != nil {
		return err
	}
	err = signedData.VerifyCades(signedMessage, gocades.CADESCOM_CADES_BES, false)
	if err != nil {
		return err
	}
	content, err := signedData.GetContent()
	if err != nil {
		return err
	}
	fmt.Println("Content:", content)
	certificates, err := signedData.GetCertificates()
	if err != nil {
		return err
	}
	fmt.Println("Signers:\n")
	count, err := certificates.GetCount()
	if err != nil {
		return err
	}
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
	return err
}

func main() {
	subjectName := "TestSubjectName"
	dataToSign := "Test data to be signed"

	certificate, err := GetCertificate(subjectName)
	if err != nil {
		fmt.Println("Failed to get certificate SN =", subjectName, "\nError:", err)
		return
	}

	signedMessage, err := Sign(certificate, dataToSign)
	if err != nil {
		fmt.Println("Failed to sign message", "\nError:", err)
		return
	}

	fmt.Println("Signed message:")
	fmt.Println("======")
	fmt.Println(signedMessage)
	fmt.Println("======")
	fmt.Println()

	fmt.Println("Verify result:")
	fmt.Println("======")
	err = Verify(signedMessage)
	if err != nil {
		fmt.Println("Failed to verify message", "\nError:", err)
		return
	}
	fmt.Println("======")
}
