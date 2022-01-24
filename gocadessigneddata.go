package gocades

/*
#cgo CFLAGS: -I${SRCDIR}/ccades
#cgo LDFLAGS: -L${SRCDIR}/ccades -Wl,-rpath=${SRCDIR}/ccades -lccades
#include <stdlib.h>
#include "CCadesSignedData.h"
*/
import "C"

import (
	"errors"
	"runtime"
	"unsafe"
)

type GoCadesSignedData struct {
	cobjptr *C.CCadesSignedData
}

func SignedData() (*GoCadesSignedData, error) {
	result := C.CCadesSignedData_create()
	ret := &GoCadesSignedData{result}
	runtime.SetFinalizer(ret, func(obj *GoCadesSignedData) {
		C.CCadesSignedData_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesSignedData_error(ret.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesSignedData) GetCertificates() (*GoCadesCertificates, error) {
	ret := &GoCadesCertificates{C.CCadesSignedData_get_certificates(obj.cobjptr)}

	runtime.SetFinalizer(ret, func(obj *GoCadesCertificates) {
		C.CCadesCertificates_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesSignedData_error(obj.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesSignedData) PutContent(value string) error {
	cstr := C.CString(value)
	defer C.free(unsafe.Pointer(cstr))
	C.CCadesSignedData_put_content(obj.cobjptr, cstr)
	err := C.GoString(C.CCadesSignedData_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesSignedData) GetContent() (string, error) {
	var ret string
	val := C.CCadesSignedData_get_content(obj.cobjptr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesSignedData_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesSignedData) GetSigners() (*GoCadesSigners, error) {
	ret := &GoCadesSigners{C.CCadesSignedData_get_recipients(obj.cobjptr)}

	runtime.SetFinalizer(ret, func(obj *GoCadesSigners) {
		C.CCadesSigners_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesSignedData_error(obj.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesSignedData) PutContentEncoding(value int) error {
	C.CCadesSignedData_put_content_encoding(obj.cobjptr, C.int(value))
	err := C.GoString(C.CCadesSignedData_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesSignedData) GetContentEncoding() (int, error) {
	var ret int
	val := C.CCadesSignedData_get_content_encoding(obj.cobjptr)
	err := C.GoString(C.CCadesSignedData_error(obj.cobjptr))
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}

func (obj *GoCadesSignedData) PutDisplayData(value int) error {
	C.CCadesSignedData_put_display_data(obj.cobjptr, C.int(value))
	err := C.GoString(C.CCadesSignedData_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesSignedData) GetDisplayData() (int, error) {
	var ret int
	val := C.CCadesSignedData_get_display_data(obj.cobjptr)
	err := C.GoString(C.CCadesSignedData_error(obj.cobjptr))
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}

func (obj *GoCadesSignedData) CoSign(signer GoCadesSigner, encoding int) (string, error) {
	var ret string
	val := C.CCadesSignedData_cosign(obj.cobjptr, signer.cobjptr, C.int(encoding))
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesSignedData_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesSignedData) Sign(signer GoCadesSigner, detached bool, encoding int) (string, error) {
	var ret string
	val := C.CCadesSignedData_sign(obj.cobjptr, signer.cobjptr, C.bool(detached), C.int(encoding))
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesSignedData_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesSignedData) Verify(value string, detached bool, flag int) error {
	cstr := C.CString(value)
	defer C.free(unsafe.Pointer(cstr))
	C.CCadesSignedData_verify(obj.cobjptr, cstr, C.bool(detached), C.int(flag))
	err := C.GoString(C.CCadesSignedData_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesSignedData) CoSignCades(signer GoCadesSigner, cadestype int, encoding int) (string, error) {
	var ret string
	val := C.CCadesSignedData_cosign_cades(obj.cobjptr, signer.cobjptr, C.int(cadestype), C.int(encoding))
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesSignedData_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesSignedData) EnhanceCades(cadestype int, tsaaddress string, encoding int) (string, error) {
	var ret string
	cstr := C.CString(tsaaddress)
	defer C.free(unsafe.Pointer(cstr))
	val := C.CCadesSignedData_enhance_cades(obj.cobjptr, C.int(cadestype), cstr, C.int(encoding))
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesSignedData_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesSignedData) SignCades(signer GoCadesSigner, cadestype int, detached bool, encoding int) (string, error) {
	var ret string
	val := C.CCadesSignedData_sign_cades(obj.cobjptr, signer.cobjptr, C.int(cadestype), C.bool(detached), C.int(encoding))
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesSignedData_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesSignedData) VerifyCades(value string, cadestype int, detached bool) error {
	cstr := C.CString(value)
	defer C.free(unsafe.Pointer(cstr))
	C.CCadesSignedData_verify_cades(obj.cobjptr, cstr, C.int(cadestype), C.bool(detached))
	err := C.GoString(C.CCadesSignedData_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesSignedData) CoSignHash(hashed GoCadesHashedData, signer GoCadesSigner, cadestype int, encoding int) (string, error) {
	var ret string
	val := C.CCadesSignedData_cosign_hash(obj.cobjptr, hashed.cobjptr, signer.cobjptr, C.int(cadestype), C.int(encoding))
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesSignedData_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesSignedData) SignHash(hashed GoCadesHashedData, signer GoCadesSigner, cadestype int, encoding int) (string, error) {
	var ret string
	val := C.CCadesSignedData_sign_hash(obj.cobjptr, hashed.cobjptr, signer.cobjptr, C.int(cadestype), C.int(encoding))
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesSignedData_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesSignedData) VerifyHash(hashed GoCadesHashedData, value string, cadestype int) error {
	cstr := C.CString(value)
	defer C.free(unsafe.Pointer(cstr))
	C.CCadesSignedData_verify_hash(obj.cobjptr, hashed.cobjptr, cstr, C.int(cadestype))
	err := C.GoString(C.CCadesSignedData_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}
