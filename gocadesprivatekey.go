package gocades

/*
#cgo CFLAGS: -I/opt/ccades
#cgo LDFLAGS: -L/opt/ccades -Wl,-rpath=/opt/ccades -lccades
#include <stdlib.h>
#include "CCadesPrivateKey.h"
*/
import "C"
import (
	"errors"
	"unsafe"
)

type GoCadesPrivateKey struct {
	cobjptr *C.CCadesPrivateKey
}

func (obj *GoCadesPrivateKey) GetContainerName() (string, error) {
	var ret string
	val := C.CCadesPrivateKey_get_container_name(obj.cobjptr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesPrivateKey_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesPrivateKey) GetUniqueContainerName() (string, error) {
	var ret string
	val := C.CCadesPrivateKey_get_unique_container_name(obj.cobjptr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesPrivateKey_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesPrivateKey) GetProviderName() (string, error) {
	var ret string
	val := C.CCadesPrivateKey_get_provider_name(obj.cobjptr)
	defer C.free(unsafe.Pointer(val))
	err := C.GoString(C.CCadesPrivateKey_error(obj.cobjptr))
	if err != "" {
		return "", errors.New(err)
	}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesPrivateKey) GetProviderType() (int, error) {
	var ret int
	val := C.CCadesPrivateKey_get_provider_type(obj.cobjptr)
	err := C.GoString(C.CCadesPrivateKey_error(obj.cobjptr))
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}

func (obj *GoCadesPrivateKey) GetKeySpec() (int, error) {
	var ret int
	val := C.CCadesPrivateKey_get_key_spec(obj.cobjptr)
	err := C.GoString(C.CCadesPrivateKey_error(obj.cobjptr))
	if err != "" {
		return ret, errors.New(err)
	}
	ret = int(val)
	return ret, nil
}

func (obj *GoCadesPrivateKey) GetIsDefaultPin() (bool, error) {
	var ret bool
	val := C.CCadesPrivateKey_get_is_default_pin(obj.cobjptr)
	err := C.GoString(C.CCadesPrivateKey_error(obj.cobjptr))
	if err != "" {
		return ret, errors.New(err)
	}
	ret = bool(val)
	return ret, nil
}

func (obj *GoCadesPrivateKey) ChangePin() error {
	C.CCadesPrivateKey_change_pin(obj.cobjptr)
	err := C.GoString(C.CCadesPrivateKey_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesPrivateKey) SetCache(value bool) error {
	C.CCadesPrivateKey_set_cache(obj.cobjptr, C.bool(value))
	err := C.GoString(C.CCadesPrivateKey_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}

func (obj *GoCadesPrivateKey) SetKeyPin(value string) error {
	cstr := C.CString(value)
	defer C.free(unsafe.Pointer(cstr))
	C.CCadesPrivateKey_set_key_pin(obj.cobjptr, cstr)
	err := C.GoString(C.CCadesPrivateKey_error(obj.cobjptr))
	if err != "" {
		return errors.New(err)
	}
	return nil
}
