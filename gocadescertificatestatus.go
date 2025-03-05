package gocades

/*
#cgo CFLAGS: -I$/opt/ccades
#cgo LDFLAGS: -L$/opt/ccades -Wl,-rpath=$/opt/ccades -lccades
#include <stdlib.h>
#include "CCadesCertificateStatus.h"
*/
import "C"
import "errors"

type GoCadesCertificateStatus struct {
	cobjptr *C.CCadesCertificateStatus
}

func (obj *GoCadesCertificateStatus) GetResult() (bool, error) {
	var ret bool
	val := C.CCadesCertificateStatus_get_result(obj.cobjptr)
	err := C.GoString(C.CCadesCertificateStatus_error(obj.cobjptr))
	if err != "" {
		return ret, errors.New(err)
	}
	ret = bool(val)
	return ret, nil
}
