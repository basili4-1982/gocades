package gocades

/*
#cgo CFLAGS: -I${SRCDIR}/ccades
#cgo LDFLAGS: -L${SRCDIR}/ccades -Wl,-rpath=${SRCDIR}/ccades
#include <stdlib.h>
#include "CCadesSignedXML.h"
*/
import "C"

import (
	"errors"
	"runtime"
	"unsafe"
)

type GoCadesSignedXML struct {
	cobjptr *C.CCadesSignedXML
}

func SignedXML() (*GoCadesSignedXML, error) {
	result := C.CCadesSignedXML_create()
	ret := &GoCadesSignedXML{result}
	runtime.SetFinalizer(ret, func(obj *GoCadesSignedXML) {
		C.CCadesSignedXML_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesSignedXML_error(ret.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesSignedXML) GetSigners() (*GoCadesSigners, error) {
	ret := &GoCadesSigners{C.CCadesSignedXML_get_signers(obj.cobjptr)}

	runtime.SetFinalizer(ret, func(obj *GoCadesSigners) {
		C.CCadesSigners_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesSignedXML_error(obj.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesSignedXML) PutContent(value string) error {
	cstr := C.CString(value)
	defer C.free(unsafe.Pointer(cstr))
	C.CCadesSignedXML_put_content(obj.cobjptr, cstr)
	err := C.GoString(C.CCadesSignedXML_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesSignedXML) GetContent() (string, error) {
	var ret string
	val := C.CCadesSignedXML_get_content(obj.cobjptr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesSignedXML_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesSignedXML) PutSignatureType(value int) error {
	C.CCadesSignedXML_put_signature_type(obj.cobjptr, C.int(value))
	err := C.GoString(C.CCadesSignedXML_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesSignedXML) PutSignatureMethod(value string) error {
	cstr := C.CString(value)
	defer C.free(unsafe.Pointer(cstr))
	C.CCadesSignedXML_put_signature_method(obj.cobjptr, cstr)
	err := C.GoString(C.CCadesSignedXML_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesSignedXML) PutDigestMethod(value string) error {
	cstr := C.CString(value)
	defer C.free(unsafe.Pointer(cstr))
	C.CCadesSignedXML_put_digest_method(obj.cobjptr, cstr)
	err := C.GoString(C.CCadesSignedXML_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesSignedXML) Sign(signer GoCadesSigner, xpath string) (string, error) {
	var ret string
	cstr := C.CString(xpath)
	defer C.free(unsafe.Pointer(cstr))
	val := C.CCadesSignedXML_sign(obj.cobjptr, signer.cobjptr, cstr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesSignedXML_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesSignedXML) Verify(value string, xpath string) error {
	cstr := C.CString(value)
	defer C.free(unsafe.Pointer(cstr))
	cstr2 := C.CString(xpath)
	defer C.free(unsafe.Pointer(cstr2))
	C.CCadesSignedXML_verify(obj.cobjptr, cstr, cstr2)
	err := C.GoString(C.CCadesSignedXML_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}
