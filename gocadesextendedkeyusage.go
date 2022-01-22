package gocades

/*
#cgo CFLAGS: -I${SRCDIR}/ccades
#cgo LDFLAGS: -L${SRCDIR}/ccades -Wl,-rpath=${SRCDIR}/ccades -lccades
#include <stdlib.h>
#include "CCadesExtendedKeyUsage.h"
*/
import "C"

import (
	"runtime"
)

type GoCadesExtendedKeyUsage struct {
	cobjptr *C.CCadesExtendedKeyUsage
}

func (obj *GoCadesExtendedKeyUsage) GetIsPresent() (bool, error) {
	var ret bool
	val := C.CCadesExtendedKeyUsage_get_is_present(obj.cobjptr)
	/////err := C.GoString(obj.cobjptr.err)
	/////if err != "" {
	/////	return ret, errors.New(err)
	/////}
	ret = bool(val)
	return ret, nil
}

func (obj *GoCadesExtendedKeyUsage) GetIsCritical() (bool, error) {
	var ret bool
	val := C.CCadesExtendedKeyUsage_get_is_critical(obj.cobjptr)
	/////err := C.GoString(obj.cobjptr.err)
	/////if err != "" {
	/////	return ret, errors.New(err)
	/////}
	ret = bool(val)
	return ret, nil
}

func (obj *GoCadesExtendedKeyUsage) GetEKUs() (*GoCadesEKUs, error) {
	ret := &GoCadesEKUs{C.CCadesExtendedKeyUsage_get_ekus(obj.cobjptr)}

	runtime.SetFinalizer(ret, func(obj *GoCadesEKUs) {
		C.CCadesEKUs_destroy(obj.cobjptr)
	})
	/////err := C.GoString(obj.cobjptr.err)
	/////if err != "" {
	/////	return nil, errors.New(err)
	/////}
	return ret, nil
}
