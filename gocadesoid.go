package gocades

/*
#cgo CFLAGS: -I${SRCDIR}/ccades
#cgo LDFLAGS: -L${SRCDIR}/ccades -Wl,-rpath=${SRCDIR}/ccades -lccades
#include <stdlib.h>
#include "CCadesOID.h"
*/
import "C"
import (
	"unsafe"
)

type GoCadesOID struct {
	cobjptr *C.CCadesOID
}

func (obj *GoCadesOID) GetFriendlyName() (string, error) {
	var ret string
	val := C.CCadesOID_get_friendly_name(obj.cobjptr)
	defer C.free(unsafe.Pointer(val))
	/////err := C.GoString(obj.cobjptr.err)
	/////if err != "" {
	/////	return "", errors.New(err)
	/////}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesOID) SetFriendlyName(FriendlyName string) error {
	cstr := C.CString(FriendlyName)
	defer C.free(unsafe.Pointer(cstr))
	C.CCadesOID_set_friendly_name(obj.cobjptr, cstr)
	/////err := C.GoString(obj.cobjptr.err)
	/////if err != "" {
	/////	return errors.New(err)
	/////}
	return nil
}

func (obj *GoCadesOID) GetValue() (string, error) {
	var ret string
	val := C.CCadesOID_get_value(obj.cobjptr)
	defer C.free(unsafe.Pointer(val))
	/////err := C.GoString(obj.cobjptr.err)
	/////if err != "" {
	/////	return "", errors.New(err)
	/////}
	ret = C.GoString(val)
	return ret, nil
}

func (obj *GoCadesOID) SetValue(Value string) error {
	cstr := C.CString(Value)
	defer C.free(unsafe.Pointer(cstr))
	C.CCadesOID_set_value(obj.cobjptr, cstr)
	/////err := C.GoString(obj.cobjptr.err)
	/////if err != "" {
	/////	return errors.New(err)
	/////}
	return nil
}

func (obj *GoCadesOID) GetName() (int, error) {
	var ret int
	val := C.CCadesOID_get_name(obj.cobjptr)
	/////err := C.GoString(obj.cobjptr.err)
	/////if err != "" {
	/////	return ret, errors.New(err)
	/////}
	ret = int(val)
	return ret, nil
}

func (obj *GoCadesOID) SetName(Value int) error {
	C.CCadesOID_set_name(obj.cobjptr, C.int(Value))
	/////err := C.GoString(obj.cobjptr.err)
	/////if err != "" {
	/////	return errors.New(err)
	/////}
	return nil
}
