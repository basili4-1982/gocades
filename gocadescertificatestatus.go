package gocades

/*
#cgo CFLAGS: -I${SRCDIR}/ccades
#cgo LDFLAGS: -L${SRCDIR}/ccades -Wl,-rpath=${SRCDIR}/ccades
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
