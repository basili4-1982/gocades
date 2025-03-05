package gocades

/*
#cgo CFLAGS: -I${SRCDIR}/ccades
#cgo LDFLAGS: -L${SRCDIR}/ccades -Wl,-rpath=${SRCDIR}/ccades -lccades
#include <stdlib.h>
#include "CCadesEnvelopedData.h"
*/
import "C"

import (
	"errors"
	"runtime"
	"unsafe"
)

type GoCadesEnvelopedData struct {
	cobjptr *C.CCadesEnvelopedData
}

func EnvelopedData() (*GoCadesEnvelopedData, error) {
	result := C.CCadesEnvelopedData_create()
	ret := &GoCadesEnvelopedData{result}
	runtime.SetFinalizer(ret, func(obj *GoCadesEnvelopedData) {
		C.CCadesEnvelopedData_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesEnvelopedData_error(ret.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesEnvelopedData) GetAlgorithm() (*GoCadesAlgorithm, error) {
	ret := &GoCadesAlgorithm{C.CCadesEnvelopedData_get_algorithm(obj.cobjptr)}

	runtime.SetFinalizer(ret, func(obj *GoCadesAlgorithm) {
		C.CCadesAlgorithm_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesEnvelopedData_error(obj.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesEnvelopedData) PutContent(value string) error {
	cstr := C.CString(value)
	defer C.free(unsafe.Pointer(cstr))
	C.CCadesEnvelopedData_put_content(obj.cobjptr, cstr)
	err := C.GoString(C.CCadesEnvelopedData_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesEnvelopedData) GetContent() (string, error) {
	var ret string
	val := C.CCadesEnvelopedData_get_content(obj.cobjptr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesEnvelopedData_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesEnvelopedData) GetRecipients() (*GoCadesRecipients, error) {
	ret := &GoCadesRecipients{C.CCadesEnvelopedData_get_recipients(obj.cobjptr)}

	runtime.SetFinalizer(ret, func(obj *GoCadesRecipients) {
		C.CCadesRecipients_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesEnvelopedData_error(obj.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesEnvelopedData) PutContentEncoding(value int) error {
	C.CCadesEnvelopedData_put_content_encoding(obj.cobjptr, C.int(value))
	err := C.GoString(C.CCadesEnvelopedData_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesEnvelopedData) Decrypt(value string) error {
	cstr := C.CString(value)
	defer C.free(unsafe.Pointer(cstr))
	C.CCadesEnvelopedData_decrypt(obj.cobjptr, cstr)
	err := C.GoString(C.CCadesEnvelopedData_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesEnvelopedData) Encrypt(value int) (string, error) {
	var ret string
	val := C.CCadesEnvelopedData_encrypt(obj.cobjptr, C.int(value))
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesEnvelopedData_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesEnvelopedData) StreamEncrypt(value string, final bool) (string, error) {
	var ret string
	cstr := C.CString(value)
	defer C.free(unsafe.Pointer(cstr))
	val := C.CCadesEnvelopedData_stream_encrypt(obj.cobjptr, cstr, C.bool(final))
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesEnvelopedData_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesEnvelopedData) StreamDecrypt(value string, final bool) (string, error) {
	var ret string
	cstr := C.CString(value)
	defer C.free(unsafe.Pointer(cstr))
	val := C.CCadesEnvelopedData_stream_decrypt(obj.cobjptr, cstr, C.bool(final))
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesEnvelopedData_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesEnvelopedData) GetContentEncoding() (int, error) {
	var ret int
	val := C.CCadesEnvelopedData_get_content_encoding(obj.cobjptr)
	err := C.GoString(C.CCadesEnvelopedData_error(obj.cobjptr))
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}
