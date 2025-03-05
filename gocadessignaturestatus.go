package gocades

/*
#cgo CFLAGS: -I${SRCDIR}/ccades
#cgo LDFLAGS: -L${SRCDIR}/ccades -Wl,-rpath=${SRCDIR}/ccades
#include <stdlib.h>
#include "CCadesSignatureStatus.h"
*/
import "C"
import "errors"

type GoCadesSignatureStatus struct {
	cobjptr *C.CCadesSignatureStatus
}

func (obj *GoCadesSignatureStatus) IsValid() (bool, error) {
	var ret bool
	val := C.CCadesSignatureStatus_is_valid(obj.cobjptr)
	err := C.GoString(C.CCadesSignatureStatus_error(obj.cobjptr))
	if err != "" {
		return ret, errors.New(err)
	}
	ret = bool(val)
	return ret, nil
}
