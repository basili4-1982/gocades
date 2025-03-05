package gocades

/*
#cgo CFLAGS: -I/opt/ccades
#cgo LDFLAGS: -L/opt/ccades -Wl,-rpath=/opt/ccades -lccades
#include <stdlib.h>
#include "CCadesSigner.h"
*/
import "C"

import (
	"errors"
	"runtime"
	"unsafe"
)

type GoCadesSigner struct {
	cobjptr *C.CCadesSigner
}

func Signer() (*GoCadesSigner, error) {
	result := C.CCadesSigner_create()
	ret := &GoCadesSigner{result}
	runtime.SetFinalizer(ret, func(obj *GoCadesSigner) {
		C.CCadesSigner_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesSigner_error(ret.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesSigner) GetAuthenticatedAttributes2() (*GoCadesAttributes, error) {
	ret := &GoCadesAttributes{C.CCadesSigner_get_authenticated_attributes2(obj.cobjptr)}

	runtime.SetFinalizer(ret, func(obj *GoCadesAttributes) {
		C.CCadesAttributes_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesSigner_error(obj.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesSigner) PutAuthenticatedAttributes2(value GoCadesAttributes) error {
	C.CCadesSigner_put_authenticated_attributes2(obj.cobjptr, value.cobjptr)
	err := C.GoString(C.CCadesSigner_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesSigner) GetUnauthenticatedAttributes() (*GoCadesAttributes, error) {
	ret := &GoCadesAttributes{C.CCadesSigner_get_unauthenticated_attributes(obj.cobjptr)}

	runtime.SetFinalizer(ret, func(obj *GoCadesAttributes) {
		C.CCadesAttributes_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesSigner_error(obj.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesSigner) PutUnauthenticatedAttributes(value GoCadesAttributes) error {
	C.CCadesSigner_put_unauthenticated_attributes(obj.cobjptr, value.cobjptr)
	err := C.GoString(C.CCadesSigner_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesSigner) GetCertificate() (*GoCadesCertificate, error) {
	ret := &GoCadesCertificate{C.CCadesSigner_get_certificate(obj.cobjptr)}

	runtime.SetFinalizer(ret, func(obj *GoCadesCertificate) {
		C.CCadesCertificate_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesSigner_error(obj.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesSigner) PutCertificate(value GoCadesCertificate) error {
	C.CCadesSigner_put_certificate(obj.cobjptr, value.cobjptr)
	err := C.GoString(C.CCadesSigner_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesSigner) GetOCSPResponses() (*GoCadesBlobs, error) {
	ret := &GoCadesBlobs{C.CCadesSigner_get_ocsp_responses(obj.cobjptr)}

	runtime.SetFinalizer(ret, func(obj *GoCadesBlobs) {
		C.CCadesBlobs_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesSigner_error(obj.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesSigner) GetCRLs() (*GoCadesBlobs, error) {
	ret := &GoCadesBlobs{C.CCadesSigner_get_crls(obj.cobjptr)}

	runtime.SetFinalizer(ret, func(obj *GoCadesBlobs) {
		C.CCadesBlobs_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesSigner_error(obj.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesSigner) PutOptions(value int) error {
	C.CCadesSigner_put_options(obj.cobjptr, C.int(value))
	err := C.GoString(C.CCadesSigner_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesSigner) GetOptions() (int, error) {
	var ret int
	val := C.CCadesSigner_get_options(obj.cobjptr)
	err := C.GoString(C.CCadesSigner_error(obj.cobjptr))
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}

func (obj *GoCadesSigner) PutTSAAddress(value string) error {
	cstr := C.CString(value)
	defer C.free(unsafe.Pointer(cstr))
	C.CCadesSigner_put_tsa_address(obj.cobjptr, cstr)
	err := C.GoString(C.CCadesSigner_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesSigner) GetTSAAddress() (string, error) {
	var ret string
	val := C.CCadesSigner_get_tsa_address(obj.cobjptr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesSigner_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesSigner) GetSignatureTimestampTime() (string, error) {
	var ret string
	val := C.CCadesSigner_get_signature_timestamp_time(obj.cobjptr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesSigner_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesSigner) GetSigningTime() (string, error) {
	var ret string
	val := C.CCadesSigner_get_signing_time(obj.cobjptr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesSigner_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesSigner) PutKeyPin(value string) error {
	cstr := C.CString(value)
	defer C.free(unsafe.Pointer(cstr))
	C.CCadesSigner_put_key_pin(obj.cobjptr, cstr)
	err := C.GoString(C.CCadesSigner_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesSigner) GetSignatureStatus() (*GoCadesSignatureStatus, error) {
	ret := &GoCadesSignatureStatus{C.CCadesSigner_get_signature_status(obj.cobjptr)}

	runtime.SetFinalizer(ret, func(obj *GoCadesSignatureStatus) {
		C.CCadesSignatureStatus_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesSigner_error(obj.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesSigner) PutCheckCertificate(value bool) error {
	C.CCadesSigner_put_check_certificate(obj.cobjptr, C.bool(value))
	err := C.GoString(C.CCadesSigner_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesSigner) GetCheckCertificate() (bool, error) {
	var ret bool
	val := C.CCadesSigner_get_check_certificate(obj.cobjptr)
	err := C.GoString(C.CCadesSigner_error(obj.cobjptr))
	if err != "" {
		return ret, errors.New(err)
	}
	ret = bool(val)
	return ret, nil
}
