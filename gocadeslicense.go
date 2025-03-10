package gocades

/*
#cgo CFLAGS: -I/opt/ccades
#cgo LDFLAGS: -L/opt/ccades -Wl,-rpath=/opt/ccades -lccades
#include <stdlib.h>
#include "CCadesLicense.h"
*/
import "C"

import (
	"errors"
	"runtime"
	"unsafe"
)

type GoCadesLicense struct {
	cobjptr *C.CCadesLicense
}

func License() (*GoCadesLicense, error) {
	result := C.CCadesLicense_create()
	ret := &GoCadesLicense{result}
	runtime.SetFinalizer(ret, func(obj *GoCadesLicense) {
		C.CCadesLicense_destroy(obj.cobjptr)
	})
	err := C.GoString(C.CCadesLicense_error(ret.cobjptr))
	if err != "" {
		return nil, errors.New(err)
	}
	return ret, nil
}

func (obj *GoCadesLicense) GetCompanyName(value int) (string, error) {
	var ret string
	val := C.CCadesLicense_get_company_name(obj.cobjptr, C.int(value))
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesLicense_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesLicense) GetFirstInstallDate(value int) (string, error) {
	var ret string
	val := C.CCadesLicense_get_first_install_date(obj.cobjptr, C.int(value))
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesLicense_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesLicense) GetSerialNumber(value int) (string, error) {
	var ret string
	val := C.CCadesLicense_get_serial_number(obj.cobjptr, C.int(value))
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesLicense_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesLicense) GetType(value int) (string, error) {
	var ret string
	val := C.CCadesLicense_get_type(obj.cobjptr, C.int(value))
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesLicense_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesLicense) GetValidTo(value int) (string, error) {
	var ret string
	val := C.CCadesLicense_get_valid_to(obj.cobjptr, C.int(value))
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesLicense_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesLicense) SetLicense(SerialNumber string, User string, CompanyName string) error {
	cstr1 := C.CString(SerialNumber)
	defer C.free(unsafe.Pointer(cstr1))
	cstr2 := C.CString(User)
	defer C.free(unsafe.Pointer(cstr2))
	cstr3 := C.CString(CompanyName)
	defer C.free(unsafe.Pointer(cstr3))
	C.CCadesLicense_set_license(obj.cobjptr, cstr1, cstr2, cstr3)
	err := C.GoString(C.CCadesLicense_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}
